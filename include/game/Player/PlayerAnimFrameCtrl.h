#pragma once
#include "al/LiveActor/LiveActor.h"
#include "sead/prim/seadSafeString.h"

class PlayerAnimFrameCtrl {
    public:
        const char *getActionName(void) const;
        void startAction(al::LiveActor *actor, sead::SafeString const &actionName);
};