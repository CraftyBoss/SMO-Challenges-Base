#include <string>
#include <cstring>
#include "types.h"

#include "sead/math/seadVector.h"
#include "sead/math/seadQuat.h"

#include "logger.hpp"

bool isPartOf(const char* w1, const char* w2);

int indexOf(char *w1, char c1);

void logVector(const char *vectorName, sead::Vector3f vector);

sead::Vector3f QuatToEuler(sead::Quatf *quat);
