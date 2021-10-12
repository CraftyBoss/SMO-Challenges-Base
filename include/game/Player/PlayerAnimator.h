#pragma once

#include "PlayerAnimFrameCtrl.h"
#include "sead/prim/seadSafeString.h"

class PlayerAnimator {
    public:
        void startAnim(const sead::SafeStringBase<char> &animName);
        void startAnimDead(void); // chooses one of the 5 death animations and starts that animation
        void endSubAnim(void);
        
        bool isAnim(const sead::SafeStringBase<char> &animName) const;

        unsigned char padding_18[0x18];
        PlayerAnimFrameCtrl *mAnimFrameCtrl;
};