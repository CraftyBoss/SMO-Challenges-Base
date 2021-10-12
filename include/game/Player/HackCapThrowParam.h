#pragma once

#include "types.h"
#include "al/LiveActor/LiveActor.h"

class HackCapThrowParam { // stores parameters used in calculating the way HackCap is thrown
    public:
        HackCapThrowParam(al::LiveActor *);

        f32 hackThrowHeight; // 投げる高さ
        f32 maxVel; // 最高速度
        f32 constThrowSpeed; // 連続投げ速度
        s32 breakTime; // ブレーキ時間
        f32 maxDist; // 到達距離
        s32 endpointStopTime; // 端点停止時間
        s32 maxEndpointStopTime; // 最大端点停止時間
        f32 returnStrength; // 戻り強さ
        f32 maxRetSpeed; // 戻り最高速度
        f32 turnAngleLimit; // ターン限界角度
        f32 waterMaxSpeed; // [水中]最高速度
        f32 waterDist; // [水中]到達距離
        s32 waterBreakTime; // [水中]ブレーキ時間
        f32 waterMaxRetSpeed; // [水中]戻り最高速度
        f32 tornadoDist; // [竜巻投げ]到達距離
        f32 tornadoMaxDist; // [竜巻投げ]最高到達距離
        s32 tornadoReflectTime; // [竜巻投げ]反射時間
        f32 rollSpeed; // [転がし投げ]速度
        f32 rollDistTop; // [転がし投げ]到達距離[上]
        f32 rollDistBottom; // [転がし投げ]到達距離[下]
        s32 rollBrakeTimeTop; // [転がし投げ]ブレーキ時間[上]
        s32 rollBrakeTimeBottom; // [転がし投げ]ブレーキ時間[下]
        f32 rollGroundGroundedPoseTrack; // [転がし投げ]姿勢追従[接地]
        f32 rollGroundAerialPoseTrack; // [転がし投げ]姿勢追従[空中]
};