#include "al/LiveActor/LiveActor.h"
#include "al/util.hpp"
#include "al/sensor/SensorMsg.h"
#include "al/util/NerveUtil.h"
#include "logger.hpp"

// cal = custom actor libray
namespace cal
{
    class DeathBlockBrick : public al::LiveActor
    {
    public:
        DeathBlockBrick(const char *name);
        virtual void init(al::ActorInitInfo const &) override;
        virtual void initAfterPlacement(void) override;
        virtual bool receiveMsg(const al::SensorMsg *message, al::HitSensor *source, al::HitSensor *target) override;
        virtual bool attackSensor(al::HitSensor *source, al::HitSensor *target) override;
        virtual void control(void) override;

        void exeWait();
        void exeDead();
    };

    namespace
    {
        NERVE_HEADER(DeathBlockBrick, Wait)
        NERVE_HEADER(DeathBlockBrick, Dead)
    }

}
