#pragma once

#include "al/area/AreaObj.h"
#include "al/area/AreaObjGroup.h"

namespace al {

    class AreaObjFactory;

    class AreaObjMtxConnecterHolder;

    class AreaObjDirector
    {
    public:
        AreaObjDirector(void);
        void init(al::AreaObjFactory const*);
        void endInit(void);
        void update(void);
        void placement(al::AreaInitInfo const&);
        void placement(al::AreaInitInfo const*,int);
        void createAreaObjGroup(al::AreaInitInfo const&);
        void createAreaObjGroupBuffer(void);
        void placementAreaObj(al::AreaInitInfo const&);
        AreaObjGroup *getAreaObjGroup(char const*) const;
        bool isExistAreaGroup(char const*) const;
        AreaObjGroup *getInVolumeAreaObj(char const*,sead::Vector3f const&);
        AreaObjMtxConnecterHolder *getMtxConnecterHolder(void);
    };

    class IUseAreaObj
    {
    public:
        virtual al::AreaObjDirector* getAreaObjDirector() const = 0;
    };
};