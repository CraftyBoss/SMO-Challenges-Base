#pragma once

#include "al/LiveActor/LiveActor.h"
#include "PlayerCostumeInfo.h"
#include "game/Interfaces/IUseDimension.h"

class PlayerPainPartsKeeper;
class PlayerModelHolder;

class PlayerModelChangerHakoniwa {
    public:
        PlayerModelChangerHakoniwa(al::LiveActor const *, PlayerModelHolder *, PlayerPainPartsKeeper *, PlayerCostumeInfo *, IUseDimension const *);
};