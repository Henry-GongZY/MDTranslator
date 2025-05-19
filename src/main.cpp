//
// Created by adminA on 25-5-19.
//

#include <iostream>
#include <string>
#include <curl/curl.h>

// 回调函数，用于收集服务器响应
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    // 1. 配置参数
    const std::string api_key = "YOUR_API_KEY";
    const std::string url = "https://generativelanguage.googleapis.com/v1beta/models/"
                            "gemini-2.0-flash:generateContent?key=" + api_key;
    const std::string json_payload = R"({
        "contents": [
            { "parts": [ { "text": "使用中文介绍一下你自己。" } ] }
        ]
    })";

    // 2. 初始化 libcurl
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL\n";
        return 1;
    }

    // 3. 设置 CURL 选项
    std::string response;
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_payload.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // 4. 发送请求
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Request failed: " << curl_easy_strerror(res) << "\n";
    } else {
        long status;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
        std::cout << "HTTP Status: " << status << "\n";
        std::cout << "Response Body:\n" << response << "\n";
    }

    // 5. 清理
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    return 0;
}
