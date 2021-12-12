#include "al/factory/ProjectActorFactory.h"

ProjectActorFactory::ProjectActorFactory() : ActorFactory("アクター生成") {
    this->actorTable = actorEntries;
    this->factoryCount = sizeof(actorEntries)/sizeof(actorEntries[0]); // 570 actors in factory in 1.0.0
};