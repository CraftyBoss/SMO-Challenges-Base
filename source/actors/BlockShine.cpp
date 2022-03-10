#include "actors/BlockShine.hpp"

namespace ca
{
    BlockShine::BlockShine(const char *name) : al::LiveActor(name) {}

    void BlockShine::init(al::ActorInitInfo const &info)
    {

        al::initMapPartsActor(this, info, nullptr);

        al::initNerve(this, &nrvBlockShineWait, 0);

        this->makeActorAlive();
    }

    void BlockShine::initAfterPlacement(void)
    {
        return;
    }

    bool BlockShine::receiveMsg(const al::SensorMsg *message, al::HitSensor *source, al::HitSensor *target)
    {
        if (rs::isMsgUpperPunchAll(message))
        {
            al::setNerve(this, &nrvBlockShineReaction);
            return true;
        }
        else if (rs::isMsgPlayerAndCapHipDropAll(message))
        {
            al::setNerve(this, &nrvBlockShineReactionHipDrop);
            return true;
        }
        return false;
    }

    void BlockShine::attackSensor(al::HitSensor *target, al::HitSensor *source)
    {
        return;
    }

    void BlockShine::control(void) { return; }

    void BlockShine::exeWait()
    {
        if (al::isFirstStep(this))
        {
            // do something
        }
    }

    void BlockShine::exeReaction()
    {
        if (al::isFirstStep(this))
        {
            al::startAction(this, "Reaction");
            al::setActionFrameRate(this, 0.6);
        }
        else if (al::isActionEnd(this))
        {
            al::setNerve(this, &nrvBlockShineDead);
        }
    }

    void BlockShine::exeReactionHipDrop()
    {
        if (al::isFirstStep(this))
        {
            al::startAction(this, "ReactionHipDrop");
            al::setActionFrameRate(this, 0.6);
        }
        else if (al::isActionEnd(this))
        {
            al::setNerve(this, &nrvBlockShineDead);
        }
    }

    void BlockShine::exeDead()
    {
        if (al::isFirstStep(this))
        {
            this->kill();
        }
    }

    namespace
    {
        NERVE_IMPL(BlockShine, Wait)
        NERVE_IMPL(BlockShine, Reaction)
        NERVE_IMPL(BlockShine, ReactionHipDrop)
        NERVE_IMPL(BlockShine, Dead)
    } // namespace

} // namespace ca
