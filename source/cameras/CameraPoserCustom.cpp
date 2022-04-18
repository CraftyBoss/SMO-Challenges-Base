#include "cameras/CameraPoserCustom.h"
#include "al/camera/CameraAngleVerticalCtrl.h"
#include "al/camera/CameraPoser.h"
#include "al/camera/alCameraPoserFunction.h"
#include "al/util/MathUtil.h"
#include "logger.hpp"
#include "sead/gfx/seadCamera.h"
#include "sead/math/seadVector.h"

namespace cc {

// Most of the code here is the reversed code for CameraPoserFollowSimple (unused), but i've modified it to allow vertical angle changes as well as horizontal.

CameraPoserCustom::CameraPoserCustom(const char* poserName) : CameraPoser(poserName) {

    this->initOrthoProjectionParam();
}

void CameraPoserCustom::init(void) {
    alCameraPoserFunction::initSnapShotCameraCtrlZoomRollMove(
        this);  // this makes the snapshot camera have the abilities of the normal snapshot cam, but
                // is locked rotationally
    alCameraPoserFunction::initCameraVerticalAbsorber(this);
    alCameraPoserFunction::initCameraAngleCtrl(this);
}

void CameraPoserCustom::loadParam(al::ByamlIter const& paramIter) {
    al::tryGetByamlF32(&mOffsetY, paramIter, "OffsetY");
    al::tryGetByamlF32(&mDist, paramIter, "Distance");
    al::tryGetByamlF32(&mAngle, paramIter, "Angle");
    al::tryGetByamlBool(&mIsRotateH, paramIter, "IsRotateH");
    al::tryGetByamlBool(&mIsResetAngleIfSwitchTarget, paramIter, "IsResetAngleIfSwitchTarget");
}

void normalize2(sead::Vector3f &v, float inv) {
    float len = sead::Vector3CalcCommon<float>::length(v);

    if (len > 0)
    {
        float inv_len = inv / len;
        v.x *= inv_len;
        v.y *= inv_len;
        v.z *= inv_len;
    }
}

void CameraPoserCustom::start(al::CameraStartInfo const&) {

    sead::Vector3f faceDir;
    sead::Vector3f targetFront;

    if (alCameraPoserFunction::isSceneCameraFirstCalc(this)) {
        alCameraPoserFunction::calcTargetTrans(&mTargetTrans, this);
        mTargetTrans.y += mOffsetY;
        targetFront = sead::Vector3f(0, 0, 0);
        alCameraPoserFunction::calcTargetFront(&targetFront, this);

        faceDir = mTargetTrans - (mDist * targetFront);

    } else {
        sead::LookAtCamera* curLookCam = alCameraPoserFunction::getLookAtCamera(this);

        sead::Vector3f curPos = curLookCam->getPos();

        sead::Vector3f curAt = curLookCam->getAt();

        targetFront = sead::Vector3f(curPos.x - curAt.x, 0.0, curPos.z - curAt.z);

        al::tryNormalizeOrDirZ(&targetFront);

        faceDir = (mDist * targetFront) + mTargetTrans;
    }

    mPosition = faceDir;
}

void CameraPoserCustom::update(void) {
    sead::Vector3f targetDir;

    if (alCameraPoserFunction::isChangeSubTarget(this) && mIsResetAngleIfSwitchTarget) {
        alCameraPoserFunction::calcTargetTrans(&mTargetTrans, this);
        mTargetTrans.y += mOffsetY;
        targetDir = sead::Vector3f(0,0,0);
        alCameraPoserFunction::calcTargetFront(&targetDir, this);
        mPosition = mTargetTrans - (mDist * targetDir);
    }

    // calculates camera offset from target trans using the cameras up direction
    alCameraPoserFunction::calcTargetTrans(&mTargetTrans, this);
    mTargetTrans += mCameraUp * mOffsetY;

    // calculates the targets direction through only the X and Z axis
    targetDir = sead::Vector3f(mPosition.x - mTargetTrans.x, 0.0f, mPosition.z - mTargetTrans.z);
    al::tryNormalizeOrDirZ(&targetDir);

    sead::Vector2f playerInput(0, 0);
    alCameraPoserFunction::calcCameraRotateStick(&playerInput, this);

    // rotates target direction by the cameras X input
    if (mIsRotateH) {
        al::rotateVectorDegreeY(&targetDir, (playerInput.x > 0.0f ? playerInput.x : -playerInput.x) < 0.3f ? 0.0f : playerInput.x * -2.0f);
    }

    // sets vertical angle to +- 90 degrees
    mAngle += playerInput.y * -2.0f;
    mAngle = al::clamp(mAngle, -89.9f, 89.9f);

    sead::Vector3f rotatedVec = targetDir;

    // calculates cross product of target direction and cameras current up direction
    sead::Vector3f crossVec;
    crossVec.setCross(targetDir, mCameraUp);
    // rotates target direction by the cross product and vertical angle
    al::rotateVectorDegree(&rotatedVec, rotatedVec, crossVec, mAngle);
    
    // calculates new camera offset relative to the distance set in mDist
    normalize2(rotatedVec, mDist);

    // set new camera position to the target translation offset by new position vector
    mPosition = mTargetTrans + rotatedVec;
}

void CameraPoserCustom::movement() {
    al::CameraPoser::movement();
}

}