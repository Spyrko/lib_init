#include "SimJointDriver.hpp"
#include <orocos_cpp/Spawner.hpp>

namespace init
{

SimJointDriver::SimJointDriver(Simulator& sim, const std::string &marsJointTaskName) : JointDriver("SimJointDriver"), jointTask(this, marsJointTaskName)
{
    jointTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}


cbProxies::InputPort< base::commands::Joints >& SimJointDriver::getCommandPort()
{
    return jointTask.getConcreteProxy()->command;
}

cbProxies::OutputPort< base::samples::Joints >& SimJointDriver::getStatusPort()
{
    return jointTask.getConcreteProxy()->joints_status;
}
}
