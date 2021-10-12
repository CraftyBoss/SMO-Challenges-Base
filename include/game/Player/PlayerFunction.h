#pragma once

#include "al/LiveActor/LiveActor.h"

class PlayerFunction
{
    public:
        static int getPlayerInputPort(const al::LiveActor *);
        static bool tryActivateAmiiboPreventDamage(const al::LiveActor *);
        static bool isPlayerDeadStatus(const al::LiveActor *player);
};