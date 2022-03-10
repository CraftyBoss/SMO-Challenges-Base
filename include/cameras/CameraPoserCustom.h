#pragma once

#include "al/camera/CameraPoser.h"
#include "al/camera/alCameraPoserFunction.h"
#include "al/camera/CameraAngleVerticalCtrl.h"

#include "sead/math/seadVector.h"

#include "al/util.hpp"

// cc = custom cameras

namespace cc {
    class CameraPoserCustom : public al::CameraPoser {
        public:
            CameraPoserCustom(char const*);
            virtual void loadParam(al::ByamlIter const&) override;
            virtual void start(al::CameraStartInfo const&) override;
            virtual void init() override;
            void reset(void);
            virtual void update(void) override;
            virtual void movement(void) override;

            float mOffsetY = 120.0f; // 0x140
            float mDist = 1600.0f; // 0x144
            float mAngle = 20.0f;   // 0x148
            bool mIsRotateH = false; // 0x14C
            bool mIsResetAngleIfSwitchTarget = false; // 0x14D
    };
}