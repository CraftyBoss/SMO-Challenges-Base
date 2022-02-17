#include "al/LiveActor/LiveActor.h"
#include "al/util.hpp"
#include "al/sensor/SensorMsg.h"
#include "al/util/NerveUtil.h"
#include "logger.hpp"

// ca = custom actor(s)
namespace ca
{
    class BlockShine : public al::LiveActor
    {
    public:
        BlockShine(const char *name);
        virtual void init(al::ActorInitInfo const &) override;
        virtual void initAfterPlacement(void) override;
        virtual bool receiveMsg(const al::SensorMsg *message, al::HitSensor *source, al::HitSensor *target) override;
        virtual void attackSensor(al::HitSensor *source, al::HitSensor *target) override;
        virtual void control(void) override;

        void exeWait();
        void exeReaction();
        void exeReactionHipDrop();
        void exeDead();
    };

    namespace
    {
        NERVE_HEADER(BlockShine, Wait)
        NERVE_HEADER(BlockShine, Dead)
        NERVE_HEADER(BlockShine, Reaction)
        NERVE_HEADER(BlockShine, ReactionHipDrop)
    }

}
