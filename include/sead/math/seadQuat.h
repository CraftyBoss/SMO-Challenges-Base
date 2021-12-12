#pragma once

#include <sead/basis/seadTypes.h>
#include <sead/math/seadMathPolicies.h>

namespace sead
{
template <typename T>
struct Quat : public Policies<T>::QuatBase
{
    Quat() {}
    Quat(T x, T y, T z, T w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    constexpr bool operator==(const Quat& rhs) const
    {
        return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w;
    }

    static const Quat unit;
};

typedef Quat<f32> Quatf;

}  // namespace sead
