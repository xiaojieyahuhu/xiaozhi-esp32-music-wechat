#ifndef MESSAGE_PUSHER_H
#define MESSAGE_PUSHER_H

#include <string>

class MessagePusher {
public:
    static MessagePusher& GetInstance() {
        static MessagePusher instance;
        return instance;
    }
    
    // 删除拷贝构造函数和赋值运算符
    MessagePusher(const MessagePusher&) = delete;
    MessagePusher& operator=(const MessagePusher&) = delete;
    
    // 设置微信推送器配置
    void SetConfig(const std::string& app_token, const std::string& uid);
    
    // 直接发送消息到微信推送器
    bool SendMessage(const std::string& content);
    
private:
    MessagePusher() = default;
    ~MessagePusher() = default;
    
    std::string app_token_;
    std::string uid_;
};

#endif // MESSAGE_PUSHER_H

