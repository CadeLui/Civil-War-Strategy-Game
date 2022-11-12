#pragma once
#include "Unit.h"

class Cannon: private Unit
{
    private:
        Unit* containedUnit;
    public:
        int loadUnit(Unit* loadingUnit)
        { containedUnit = loadingUnit; }
};