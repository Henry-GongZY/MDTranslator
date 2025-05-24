//
// Created by adminA on 25-5-19.
//

#include "../include/translator/BaseTranslator.h"
#include "../include/translator/GeminiTranslator.h"


int main() {
    // 1. 配置参数
    std::string api_key = "AIzaSyBpYGdQa6D8lt3tSZzVTL-iOYBH7y_95Xg";
    BaseTranslator* translator = new GeminiTranslator(api_key);
    translator->translate("Hello!");
    return 0;
}
