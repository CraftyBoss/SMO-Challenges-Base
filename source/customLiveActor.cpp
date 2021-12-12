#include "customLiveActor.hpp"

namespace cal
{
    DeathBlockBrick::DeathBlockBrick(const char *name) : al::LiveActor(name) {}

    void DeathBlockBrick::init(al::ActorInitInfo const &info)
    {

        al::initMapPartsActor(this, info, nullptr);

        al::initNerve(this, &nrvWait, 0);

        this->makeActorAlive();
    }

    void DeathBlockBrick::initAfterPlacement(void)
    {
        return;
    }

    bool DeathBlockBrick::receiveMsg(const al::SensorMsg *message, al::HitSensor *source, al::HitSensor *target)
    {
        if (al::isSensorPlayerAttack(target))
        {
            // do something
        }
        return false;
    }

    bool DeathBlockBrick::attackSensor(al::HitSensor *target, al::HitSensor *source)
    {
        return false;
    }

    void DeathBlockBrick::control(void) { return; }

    void DeathBlockBrick::exeWait()
    {
        if (al::isFirstStep(this))
        {
            // do something
        }
    }

    void DeathBlockBrick::exeDead()
    {
        if (al::isFirstStep(this))
        {
            // do something
        }
    }

    namespace
    {
        NERVE_IMPL(DeathBlockBrick, Wait)
        NERVE_IMPL(DeathBlockBrick, Dead)
    } // namespace

} // namespace cal
