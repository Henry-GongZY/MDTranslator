//
// Created by adminA on 25-5-19.
//

#ifndef MDTRANSLATOR_GEMINITRANSLATOR_H
#define MDTRANSLATOR_GEMINITRANSLATOR_H

#include "BaseTranslator.h"

class GeminiTranslator: public BaseTranslator {
public:
    explicit GeminiTranslator(std::string);
    std::string translate(std::string) override;
    ~GeminiTranslator() override;

private:
    std::string api_key;
    CURL* curl_handle;
    struct curl_slist* headers = nullptr;
    inline static std::string url = "https://generativelanguage.googleapis.com/v1beta/models/"
                                   "gemini-2.0-flash:generateContent?key=";
};


#endif //MDTRANSLATOR_GEMINITRANSLATOR_H
