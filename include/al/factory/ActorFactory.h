#pragma once

#include "Factory.h"

namespace al
{

    template <class T>
    al::LiveActor *createActorFunction(const char *name);

    template <class T>
    al::LiveActor *createCustomActor(const char *name)
    {
        return new T(name);
    };

    class LiveActor;

    typedef al::LiveActor *(*createActor)(const char *name);

    class ActorFactory : public al::Factory<createActor>
    {
    public:
        ActorFactory(const char *fName)
        {
            this->factoryName = fName;
            this->actorTable = nullptr;
            this->factoryCount = 0;
        };
    };
}