#pragma once

#include <lib_init/JointDriver.hpp>
#include "Simulator.hpp"
#include <mars/cbProxies/Joints.hpp>

namespace init
{

class SimJointDriver : public JointDriver
{
public:
    SimJointDriver(Simulator &sim, const std::string &marsJointTaskName);

    virtual cbProxies::OutputPort<base::samples::Joints> &getStatusPort();
    virtual cbProxies::InputPort<base::commands::Joints> &getCommandPort();

    DependentTask<mars::cbProxies::Joints> jointTask;
};
}
