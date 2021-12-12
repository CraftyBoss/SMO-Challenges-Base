#include "helpers.hpp"

bool isPartOf(const char* w1, const char* w2) {

    int i=0;
    int j=0;

    if(strlen(w1) <= 0) {
        return false;
    }

    while(w1[i]!='\0'){
        if(w1[i] == w2[j])
        {
            int init = i;
            while (w1[i] == w2[j] && w2[j]!='\0')
            {
                j++;
                i++;
            }
            if(w2[j]=='\0'){
                return true;
            }
            j=0;
        }
        i++;
    }
    return false;
}

int indexOf(char *w1, char c1) {

    for (int i = 0; i < strlen(w1); i++)
    {
        if(w1[i] == c1) {
            return i;
        }
    }
    return -1;
}

sead::Vector3f QuatToEuler(sead::Quatf *quat) {

    f32 x = quat->z;
    f32 y = quat->y;
    f32 z = quat->x;
    f32 w = quat->w;

    f32 t0 = 2.0 * (w * x + y * z);
    f32 t1 = 1.0 - 2.0 * (x * x + y * y);
    f32 roll = atan2f(t0, t1);

    f32 t2 = 2.0 * (w * y - z * x);
    t2 = t2 > 1.0 ? 1.0 : t2;
    t2 = t2 < -1.0 ? -1.0 : t2;
    f32 pitch = asinf(t2);

    f32 t3 = 2.0 * (w * z + x * y);
    f32 t4 = 1.0 - 2.0 * (y * y + z * z);
    f32 yaw = atan2f(t3, t4);

    return sead::Vector3f(yaw, pitch, roll);
}

void logVector(const char *vectorName, sead::Vector3f vector) {
    gLogger->LOG("%s: X: %f\nY: %f\nZ: %f\n", vectorName, vector.x, vector.y, vector.z);
}