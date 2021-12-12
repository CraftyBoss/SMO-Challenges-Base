#pragma once

#include "al/LiveActor/LiveActor.h"
#include "PlayerCostumeInfo.h"

class PlayerFunction
{
    public:
        static int getPlayerInputPort(const al::LiveActor *);
        static bool tryActivateAmiiboPreventDamage(const al::LiveActor *);
        static bool isPlayerDeadStatus(const al::LiveActor *player);

        static PlayerCostumeInfo *initMarioModelActor(al::LiveActor *player, const al::ActorInitInfo &initInfo, const char *modelName, const char *capType, al::AudioKeeper *keeper, bool isCloset);
};