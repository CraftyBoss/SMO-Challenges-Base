#pragma once

#include "sead/container/seadOffsetList.h"
#include "sead/container/seadPtrArray.h"
#include "sead/controller/seadController.h"
#include "sead/framework/seadCalculateTask.h"
#include "sead/framework/seadTaskMgr.h"
#include "sead/heap/seadDisposer.h"

namespace sead
{
class Controller;
class NinJoyNpadDevice;

class ControllerMgr : public CalculateTask
{
    SEAD_TASK_SINGLETON(ControllerMgr)
public:
    explicit ControllerMgr(const TaskConstructArg& arg);
    ControllerMgr();

    void calc() override;
    void finalize();
    void finalizeDefault();
    int findControllerPort(const Controller* controller);
    NinJoyNpadDevice* getControlDevice(ControllerDefine::DeviceId device_id);
    // unknown return type
    void* getControllerAddon(int, ControllerDefine::AddonId addon_id);
    // unknown return type
    void* getControllerAddonByOrder(int, ControllerDefine::AddonId addon_id, int);
    Controller* getControllerByOrder(ControllerDefine::ControllerId controller_id, int);
    // unknown return type, probably inherited from TaskBase
    void* getFramework();
    void initialize(int, Heap* heap);
    void initializeDefault(Heap* heap);
    void prepare() override;

    Controller* getController(int port) { return mArray[port]; }

private:
    OffsetList<NinJoyNpadDevice> mList;
    PtrArray<Controller> mArray;
};

}  // namespace sead
