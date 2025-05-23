//
// Created by adminA on 25-5-19.
//

#ifndef MDTRANSLATOR_GEMINITRANSLATOR_H
#define MDTRANSLATOR_GEMINITRANSLATOR_H

#include "BaseTranslator.h"

class GeminiTranslator: public BaseTranslator {
public:
    GeminiTranslator(std::string);
    std::string translate(std::string) override;
    ~GeminiTranslator();

private:
    std::string api_key;
    CURL* curl_handle;
    struct curl_slist* headers = nullptr;
    inline static std::string url = "https://generativelanguage.googleapis.com/v1beta/models/"
                                   "gemini-2.0-flash:generateContent?key=";
    std::string parse_json(std::string);
};


#endif //MDTRANSLATOR_GEMINITRANSLATOR_H
