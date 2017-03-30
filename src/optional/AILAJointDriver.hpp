#pragma once

#include <lib_init/JointDriver.hpp>
#include "NDLComSerial.hpp"
#include <ndlcom_aila_joints/cbProxies/AILAJointTask.hpp>


namespace init
{

class AILAJointDriver : public JointDriver
{
private:
    init::NDLComSerial& ndlcomSerial;
public:
    AILAJointDriver(init::NDLComSerial&, const std::string &AILAJointsTaskName);
    
    virtual bool connect();
    virtual bool start();

    virtual cbProxies::OutputPort<base::samples::Joints> &getStatusPort();
    virtual cbProxies::InputPort<base::commands::Joints> &getCommandPort();

    DependentTask<ndlcom_aila_joints::cbProxies::AILAJointTask> jointTask;
};
}
