//
// Created by adminA on 25-5-19.
//

#ifndef MDTRANSLATOR_BASETRANSLATOR_H
#define MDTRANSLATOR_BASETRANSLATOR_H

#include "pch.h"

class BaseTranslator{
public:
    virtual ~BaseTranslator() = default;
    virtual std::string translate(std::string) = 0;
};

#endif //MDTRANSLATOR_BASETRANSLATOR_H
