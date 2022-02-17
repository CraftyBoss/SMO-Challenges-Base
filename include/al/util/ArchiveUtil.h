#pragma once

#include <sead/prim/seadSafeString.h>
#include <sead/resource/seadResource.h>

namespace al {
sead::ArchiveRes* loadArchive(const sead::SafeStringBase<char>&);
};