#pragma once

#include <sead/math/seadVector.h>

namespace al {
float normalize(float, float, float);
float normalize(signed int, signed int, signed int);

float easeIn(float);
float easeOut(float);
float easeInOut(float);

float sign(float);
int sign(int);

float squareIn(float);
float squareOut(float);

float powerIn(float, float);
float powerOut(float, float);

float lerpValue(float, float, float);

bool isNearZero(float, float);

bool isNearZero(sead::Vector3f const &, float);

template <typename T>
inline T clamp(T value, T min, T max) {
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

void separateVectorHV(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f &,
                      const sead::Vector3f &);

bool tryNormalizeOrDirZ(sead::Vector3f *, sead::Vector3f const&);
bool tryNormalizeOrZero(sead::Vector3f *, sead::Vector3f const&);
};  // namespace al