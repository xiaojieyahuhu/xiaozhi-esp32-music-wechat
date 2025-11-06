# 小智开源音乐固件

（中文 | [English](README_en.md) | [日本語](README_ja.md)）

## 视频

👉 [【开源】虾哥ai小智机器音乐播放器纯固件带歌词显示](https://www.bilibili.com/video/BV19oM4zqEiz)

👉 [【开源】虾哥小智音乐播放器纯固件](https://www.bilibili.com/video/BV1RqMEzEEp1)

## 介绍

这是一个由虾哥开源的[ESP32项目](https://github.com/78/xiaozhi-esp32)，以 MIT 许可证发布，允许任何人免费使用，或用于商业用途。

本项目基于 [Maggotxy/xiaozhi-esp32-music](https://github.com/Maggotxy/xiaozhi-esp32-music) 进行二次开发，新增了微信留言推送功能，并修复了 ML307 4G 网络下的兼容性问题。

**开发时间**: 2025年11月6日

我们希望通过这个项目，让大家的小智都能播放歌曲。

如果你有任何想法或建议，请随时提出 Issues 或加入 QQ 群：826072986

项目主要贡献者：空白泡泡糖果（B站UP），硅灵造物科技（B站UP）

音乐服务器提供者（为爱发电）：一撒

### 💡注意事项

#### 1. 如果小智说找不到歌曲怎么办？
进入[小智后台](https://xiaozhi.me/)，找到对应设备，修改角色配置
- 选择 DeepSeekV3 大语言模型
- 在人物介绍中填入
  - 收到音乐相关的需求时，只使用 MPC tool `self.music.play_song` 工具，同时禁止使用 `search_music` 功能。

#### 2. 如何启用微信留言推送功能？
默认情况下，留言推送功能是关闭的。需要：
- 在 `sdkconfig` 中启用 `CONFIG_ENABLE_MESSAGE_PUSHER=y`
- 配置 WxPusher 的 AppToken 和 UID
- 详细配置步骤请参考 [微信留言推送配置](#微信留言推送配置) 章节

#### 3. 暂不支持的开发板
- ESP32C3芯片的开发板


### 项目改动范围

#### 新增
- main\boards\common\music.h
- main\boards\common\esp32_music.cc
- main\boards\common\esp32_music.h
- main\message_pusher.cc
- main\message_pusher.h

#### 修改
- main\mcp_server.cc
- main\boards\common\board.cc
- main\boards\common\board.h
- main\application.cc
- main\application.h
- main\display\display.cc
- main\display\display.h
- main\audio\audio_service.cc
- main\audio\audio_service.h
- main\idf_component.yml



### 基于 MCP 控制万物

小智 AI 聊天机器人作为一个语音交互入口，利用 Qwen / DeepSeek 等大模型的 AI 能力，通过 MCP 协议实现多端控制。

![通过MCP控制万物](docs/mcp-based-graph.jpg)

### 已实现功能

- 🎭 **丰富的角色定制系统**：支持台湾女友、土豆子、English Tutor 等多种预设角色
- 🎨 **个性化配置**：自定义助手昵称、对话语言、角色音色和性格介绍
- 🎵 **智能音乐控制**：支持 `self.music.play_song` 工具进行音乐播放控制
- 💬 **微信留言推送**：支持 `self.message.send_to_wechat` 工具，通过语音指令发送留言到微信
- 📡 Wi-Fi / ML307 Cat.1 4G 网络连接
- 🗣️ 离线语音唤醒 [ESP-SR](https://github.com/espressif/esp-sr)
- 🔗 支持两种通信协议（[Websocket](docs/websocket.md) 或 MQTT+UDP）
- 🎧 采用 OPUS 音频编解码
- 🤖 基于流式 ASR + LLM + TTS 架构的语音交互
- 👤 声纹识别，识别当前说话人的身份 [3D Speaker](https://github.com/modelscope/3D-Speaker)
- 📺 OLED / LCD 显示屏，支持表情显示
- 🔋 电量显示与电源管理
- 🌍 支持多语言（中文、英文、日文）
- 💻 支持 ESP32-C3、ESP32-S3、ESP32-P4 芯片平台
- 🏠 通过设备端 MCP 实现设备控制（音量、灯光、电机、GPIO 等）
- ☁️ 通过云端 MCP 扩展大模型能力（智能家居控制、PC桌面操作、知识搜索、邮件收发等）

## 硬件

### 面包板手工制作实践

详见飞书文档教程：

👉 [《小智 AI 聊天机器人百科全书》](https://ccnphfhqs21z.feishu.cn/wiki/F5krwD16viZoF0kKkvDcrZNYnhb?from=from_copylink)

面包板效果图如下：

![面包板效果图](docs/v1/wiring2.jpg)

### 支持 70 多个开源硬件（仅展示部分）

- <a href="https://oshwhub.com/li-chuang-kai-fa-ban/li-chuang-shi-zhan-pai-esp32-s3-kai-fa-ban" target="_blank" title="立创·实战派 ESP32-S3 开发板">立创·实战派 ESP32-S3 开发板</a>
- <a href="https://github.com/espressif/esp-box" target="_blank" title="乐鑫 ESP32-S3-BOX3">乐鑫 ESP32-S3-BOX3</a>
- <a href="https://docs.m5stack.com/zh_CN/core/CoreS3" target="_blank" title="M5Stack CoreS3">M5Stack CoreS3</a>
- <a href="https://docs.m5stack.com/en/atom/Atomic%20Echo%20Base" target="_blank" title="AtomS3R + Echo Base">M5Stack AtomS3R + Echo Base</a>
- <a href="https://gf.bilibili.com/item/detail/1108782064" target="_blank" title="神奇按钮 2.4">神奇按钮 2.4</a>
- <a href="https://www.waveshare.net/shop/ESP32-S3-Touch-AMOLED-1.8.htm" target="_blank" title="微雪电子 ESP32-S3-Touch-AMOLED-1.8">微雪电子 ESP32-S3-Touch-AMOLED-1.8</a>
- <a href="https://github.com/Xinyuan-LilyGO/T-Circle-S3" target="_blank" title="LILYGO T-Circle-S3">LILYGO T-Circle-S3</a>
- <a href="https://oshwhub.com/tenclass01/xmini_c3" target="_blank" title="虾哥 Mini C3">虾哥 Mini C3</a>
- <a href="https://oshwhub.com/movecall/cuican-ai-pendant-lights-up-y" target="_blank" title="Movecall CuiCan ESP32S3">璀璨·AI 吊坠</a>
- <a href="https://github.com/WMnologo/xingzhi-ai" target="_blank" title="无名科技Nologo-星智-1.54">无名科技 Nologo-星智-1.54TFT</a>
- <a href="https://www.seeedstudio.com/SenseCAP-Watcher-W1-A-p-5979.html" target="_blank" title="SenseCAP Watcher">SenseCAP Watcher</a>
- <a href="https://www.bilibili.com/video/BV1BHJtz6E2S/" target="_blank" title="ESP-HI 超低成本机器狗">ESP-HI 超低成本机器狗</a>

<div style="display: flex; justify-content: space-between;">
  <a href="docs/v1/lichuang-s3.jpg" target="_blank" title="立创·实战派 ESP32-S3 开发板">
    <img src="docs/v1/lichuang-s3.jpg" width="240" />
  </a>
  <a href="docs/v1/espbox3.jpg" target="_blank" title="乐鑫 ESP32-S3-BOX3">
    <img src="docs/v1/espbox3.jpg" width="240" />
  </a>
  <a href="docs/v1/m5cores3.jpg" target="_blank" title="M5Stack CoreS3">
    <img src="docs/v1/m5cores3.jpg" width="240" />
  </a>
  <a href="docs/v1/atoms3r.jpg" target="_blank" title="AtomS3R + Echo Base">
    <img src="docs/v1/atoms3r.jpg" width="240" />
  </a>
  <a href="docs/v1/magiclick.jpg" target="_blank" title="神奇按钮 2.4">
    <img src="docs/v1/magiclick.jpg" width="240" />
  </a>
  <a href="docs/v1/waveshare.jpg" target="_blank" title="微雪电子 ESP32-S3-Touch-AMOLED-1.8">
    <img src="docs/v1/waveshare.jpg" width="240" />
  </a>
  <a href="docs/v1/lilygo-t-circle-s3.jpg" target="_blank" title="LILYGO T-Circle-S3">
    <img src="docs/v1/lilygo-t-circle-s3.jpg" width="240" />
  </a>
  <a href="docs/v1/xmini-c3.jpg" target="_blank" title="虾哥 Mini C3">
    <img src="docs/v1/xmini-c3.jpg" width="240" />
  </a>
  <a href="docs/v1/movecall-cuican-esp32s3.jpg" target="_blank" title="CuiCan">
    <img src="docs/v1/movecall-cuican-esp32s3.jpg" width="240" />
  </a>
  <a href="docs/v1/wmnologo_xingzhi_1.54.jpg" target="_blank" title="无名科技Nologo-星智-1.54">
    <img src="docs/v1/wmnologo_xingzhi_1.54.jpg" width="240" />
  </a>
  <a href="docs/v1/sensecap_watcher.jpg" target="_blank" title="SenseCAP Watcher">
    <img src="docs/v1/sensecap_watcher.jpg" width="240" />
  </a>
  <a href="docs/v1/esp-hi.jpg" target="_blank" title="ESP-HI 超低成本机器狗">
    <img src="docs/v1/esp-hi.jpg" width="240" />
  </a>
</div>

## 软件

### 固件烧录

新手第一次操作建议先不要搭建开发环境，直接使用免开发环境烧录的固件。

固件默认接入 [xiaozhi.me](https://xiaozhi.me) 官方服务器，个人用户注册账号可以免费使用 Qwen 实时模型。

👉 [新手烧录固件教程](https://ccnphfhqs21z.feishu.cn/wiki/Zpz4wXBtdimBrLk25WdcXzxcnNS)

### 开发环境

- Cursor 或 VSCode
- 安装 ESP-IDF 插件，选择 SDK 版本 5.4 或以上
- Linux 比 Windows 更好，编译速度快，也免去驱动问题的困扰
- 本项目使用 Google C++ 代码风格，提交代码时请确保符合规范

### 开发者文档

- [自定义开发板指南](main/boards/README.md) - 学习如何为小智 AI 创建自定义开发板
- [MCP 协议物联网控制用法说明](docs/mcp-usage.md) - 了解如何通过 MCP 协议控制物联网设备
- [MCP 协议交互流程](docs/mcp-protocol.md) - 设备端 MCP 协议的实现方式
- [一份详细的 WebSocket 通信协议文档](docs/websocket.md)

## 大模型配置

如果你已经拥有一个的小智 AI 聊天机器人设备，并且已接入官方服务器，可以登录 [xiaozhi.me](https://xiaozhi.me) 控制台进行配置。

### 🎭 角色配置指南

在 [xiaozhi.me](https://xiaozhi.me) 控制台中，您可以：

1. **选择角色模板**：从台湾女友、土豆子、English Tutor、好奇小男孩、汪汪队队长等预设角色中选择
2. **设置助手昵称**：为您的 AI 伴侣起一个专属的名字（默认：小智）
3. **配置对话语言**：支持普通话、英语、日语等多种语言
4. **选择角色音色**：清澈小何等多种音色可供选择
5. **自定义角色介绍**：详细描述角色的性格特点和背景设定

💡 **特别功能**：收到音乐相关需求时，小智会优先使用 `self.music.play_song` 工具，确保音乐播放体验的流畅性。

👉 [后台操作视频教程（旧版界面）](https://www.bilibili.com/video/BV1jUCUY2EKM/)

## 微信留言推送配置

小智支持通过语音指令发送留言到微信，使用 [WxPusher](https://wxpusher.zjiecode.com/) 消息推送服务实现。

### 📱 配置步骤

1. **注册 WxPusher 账号**
   - 访问 [WxPusher 官网](https://wxpusher.zjiecode.com/admin/main)
   - 使用微信扫码注册并登录

2. **创建应用并获取 AppToken**
   - 在控制台创建新应用
   - 复制应用的 `AppToken`

3. **获取用户 UID**
   - 在"我的"页面找到您的 `UID`
   - 或使用微信关注"WxPusher"公众号后，在对话中获取 UID

4. **修改配置文件**
   - 打开项目根目录下的 `sdkconfig` 文件
   - 找到以下配置项并修改：
   ```
   # CONFIG_ENABLE_MESSAGE_PUSHER is not set
   ```
   修改为：
   ```
   CONFIG_ENABLE_MESSAGE_PUSHER=y
   CONFIG_MESSAGE_PUSHER_APP_TOKEN="你的AppToken"
   CONFIG_MESSAGE_PUSHER_UID="你的UID"
   ```
   - 或者使用 `idf.py menuconfig` 命令，在 `Xiaozhi Assistant` 菜单中配置

### 🎯 使用方法

配置完成后，您可以通过以下语音指令使用留言功能：

```
"给小杰说，今天晚上不回家了"
"留言我在公司加班"
"告诉小明我想你了"
"跟妈妈说，我会晚点回去"
```

小智会自动识别留言意图，提取留言内容，并通过微信推送到配置的账号。

### 🔧 技术特性

- ✅ 支持 WiFi 和 ML307 4G 网络
- ✅ 自动 URL 编码，支持中文内容
- ✅ 基于 MCP 协议的 `self.message.send_to_wechat` 工具
- ✅ 实时推送，秒级送达

## 相关开源项目

在个人电脑上部署服务器，可以参考以下第三方开源的项目：

- [xinnan-tech/xiaozhi-esp32-server](https://github.com/xinnan-tech/xiaozhi-esp32-server) Python 服务器
- [joey-zhou/xiaozhi-esp32-server-java](https://github.com/joey-zhou/xiaozhi-esp32-server-java) Java 服务器
- [AnimeAIChat/xiaozhi-server-go](https://github.com/AnimeAIChat/xiaozhi-server-go) Golang 服务器

使用小智通信协议的第三方客户端项目：

- [huangjunsen0406/py-xiaozhi](https://github.com/huangjunsen0406/py-xiaozhi) Python 客户端
- [TOM88812/xiaozhi-android-client](https://github.com/TOM88812/xiaozhi-android-client) Android 客户端
- [100askTeam/xiaozhi-linux](http://github.com/100askTeam/xiaozhi-linux) 百问科技提供的 Linux 客户端
- [78/xiaozhi-sf32](https://github.com/78/xiaozhi-sf32) 思澈科技的蓝牙芯片固件
- [QuecPython/solution-xiaozhiAI](https://github.com/QuecPython/solution-xiaozhiAI) 移远提供的 QuecPython 固件
