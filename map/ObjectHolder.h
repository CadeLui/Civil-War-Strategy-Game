#pragma once

#include <string>

class ObjectHolder
{
    private:
        void* containedObject;
        std::string symbol;
    public:
        ObjectHolder(void* containedObject = nullptr, std::string symbol = " ")
        {
            this->containedObject = containedObject;
            this->symbol = symbol;
        }
        void* getObject() { return this->containedObject; }
        std::string getSymbol() {return this->symbol; }
};