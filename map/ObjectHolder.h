#pragma once

#include <string>

struct ObjectHolder
{
    public:
        void* containedObject;
        std::string symbol;
        ObjectHolder(void* containedObject = nullptr, std::string symbol = " ")
        {
            this->containedObject = containedObject;
            this->symbol = symbol;
        }
};