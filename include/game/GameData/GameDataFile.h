/**
 * @file GameDataFile.h
 * @brief Holds data for an individual save file.
 */

#pragma once

#include "types.h"
#include "UniqueObjInfo.h"

class GameDataFile
{
    public:
        void wearCostume(char const *);
        bool isGotShine(int) const; // int must be less than 0x3FF (1023)
        void setGotShine(int); // no idea how this one works lol
        
        undefined padding[0x5C8];
        UniqObjInfo mUniqueInfo[0x100]; // 0x5C8
};