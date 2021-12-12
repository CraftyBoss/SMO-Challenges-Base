#pragma once

#include "sead/gfx/seadCamera.h"
#include "sead/math/seadVector.h"
#include "al/camera/CameraPoser.h"

namespace alCameraPoserFunction
{
    void makeCameraKeepInFrameV(sead::LookAtCamera *, sead::Vector3f const &, al::CameraPoser const*, float, float);
    void setCameraAngleV(al::CameraPoser *, float);
    float *getCameraAngleH(al::CameraPoser const *);
    float *getCameraAngleV(al::CameraPoser const *);
} // namespace alCameraPoserFunction
