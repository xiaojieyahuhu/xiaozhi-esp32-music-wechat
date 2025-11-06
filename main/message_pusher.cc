#include "message_pusher.h"
#include "board.h"
#include <esp_log.h>
#include <cstring>
#include <algorithm>

#define TAG "MessagePusher"

void MessagePusher::SetConfig(const std::string& app_token, const std::string& uid) {
    app_token_ = app_token;
    uid_ = uid;
    ESP_LOGI(TAG, "MessagePusher configured with appToken: %s, uid: %s", 
             app_token_.c_str(), uid_.c_str());
}

// URL 编码函数
static std::string UrlEncode(const std::string& value) {
    std::string result;
    result.reserve(value.size() * 3); // 预分配足够的空间
    
    for (unsigned char c : value) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            result += c;
        } else {
            char hex[4];
            snprintf(hex, sizeof(hex), "%%%02X", c);
            result += hex;
        }
    }
    return result;
}

bool MessagePusher::SendMessage(const std::string& content) {
    if (app_token_.empty() || uid_.empty()) {
        ESP_LOGE(TAG, "微信推送器未配置，请先设置 appToken 和 uid");
        return false;
    }
    
    // URL 编码内容
    std::string encoded_content = UrlEncode(content);
    
    // 构建 URL
    std::string url = "https://wxpusher.zjiecode.com/api/send/message/?appToken=" + 
                      app_token_ + "&content=" + encoded_content + "&uid=" + uid_;
    
    ESP_LOGI(TAG, "发送消息到微信推送器: %s", content.c_str());
    
    // 使用 Board 的网络接口创建 HTTP 客户端（支持 WiFi 和 ML307）
    auto& board = Board::GetInstance();
    auto network = board.GetNetwork();
    if (!network) {
        ESP_LOGE(TAG, "网络接口不可用");
        return false;
    }
    
    auto http = network->CreateHttp(0);
    if (!http) {
        ESP_LOGE(TAG, "无法创建 HTTP 客户端");
        return false;
    }
    
    // 设置超时
    http->SetTimeout(10000);
    
    // 发送 GET 请求
    if (!http->Open("GET", url)) {
        ESP_LOGE(TAG, "无法打开 HTTP 连接");
        return false;
    }
    
    // 获取状态码
    int status_code = http->GetStatusCode();
    ESP_LOGI(TAG, "HTTP GET Status = %d", status_code);
    
    bool success = false;
    if (status_code == 200) {
        // 读取响应内容
        std::string response = http->ReadAll();
        ESP_LOGI(TAG, "消息发送成功，响应: %s", response.c_str());
        success = true;
    } else {
        ESP_LOGE(TAG, "消息发送失败，HTTP状态码: %d", status_code);
    }
    
    // 关闭连接
    http->Close();
    
    return success;
}

