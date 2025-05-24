//
// Created by adminA on 25-5-19.
//

#include "../../include/translator/GeminiTranslator.h"

std::string parse_json(std::string response) {
    return {};
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

GeminiTranslator::GeminiTranslator(std::string apikey): api_key(std::move(apikey)) {
    this->curl_handle = curl_easy_init();
    if (!this->curl_handle) {
        std::cerr << "Failed to initialize CURL\n";
    }

    // 设置 CURL 选项
    this->headers = curl_slist_append(this->headers, "Content-Type: application/json");
    curl_easy_setopt(this->curl_handle, CURLOPT_HTTPHEADER, this->headers);
    curl_easy_setopt(this->curl_handle, CURLOPT_URL, (url + api_key).c_str());
    curl_easy_setopt(this->curl_handle, CURLOPT_POST, 1L);
    curl_easy_setopt(this->curl_handle, CURLOPT_WRITEFUNCTION, WriteCallback);
}

std::string GeminiTranslator::translate(std::string input) {

    std::string json_payload = std::format(R"({{
    "contents": [
      {{
        "parts": [
          {{
            "text": "{}"
          }}
        ]
      }}
    ]
    }})", input);

    std::string response;
    curl_easy_setopt(this->curl_handle, CURLOPT_POSTFIELDS, json_payload.c_str());
    curl_easy_setopt(this->curl_handle, CURLOPT_WRITEDATA, &response);

    // 发送请求
    CURLcode res = curl_easy_perform(this->curl_handle);
    if (res != CURLE_OK) {
        std::cerr << "Request failed: " << curl_easy_strerror(res) << "\n";
    } else {
        long status;
        curl_easy_getinfo(this->curl_handle, CURLINFO_RESPONSE_CODE, &status);
        std::cout << "HTTP Status: " << status << "\n";
        std::cout << "Response Body:\n" << response << "\n";
    }

    return response;
}

GeminiTranslator::~GeminiTranslator() {
    curl_slist_free_all(this->headers);
    curl_easy_cleanup(this->curl_handle);
}