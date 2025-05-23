//
// Created by adminA on 25-5-19.
//

#include "../include/translator/BaseTranslator.h"
#include "../include/translator/GeminiTranslator.h"

// 回调函数，用于收集服务器响应
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    // 1. 配置参数
    std::string api_key = "YOUR_API_KEY";
    BaseTranslator* translator = new GeminiTranslator(api_key);
    translator->translate("你好!");
    return 0;
}
