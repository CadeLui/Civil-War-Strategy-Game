#pragma once
#include "Unit.h"

class Cannon: protected Unit
{
    private:
        Unit* containedUnit;
    public:
        int loadUnit(Unit* loadingUnit)
        { containedUnit = loadingUnit; }
};