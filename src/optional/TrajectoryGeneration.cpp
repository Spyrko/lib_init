#include "TrajectoryGeneration.hpp"
#include <trajectory_generation/cbProxies/Task.hpp>

namespace init
{
    
TrajectoryGeneration::TrajectoryGeneration(JointDriver& jd, const std::string& trajCtrlTaskName)
    : TrajectoryControl("TrajectoryGeneration")
    , jointDriver(jd)
    , trajCtrlTask(this, trajCtrlTaskName)
{
    registerDependency(jointDriver);
}

bool TrajectoryGeneration::connect()
{
    jointDriver.getStatusPort().connectTo(trajCtrlTask.getConcreteProxy()->joint_state);
    trajCtrlTask.getConcreteProxy()->cmd.connectTo(jointDriver.getCommandPort());
    
    return Base::connect();
}

cbProxies::InputPort< base::samples::Joints >& TrajectoryGeneration::getPositionTargetPort()
{
    return trajCtrlTask.getConcreteProxy()->position_target;
}

cbProxies::InputPort< base::JointsTrajectory >& TrajectoryGeneration::getTrajectoryTargetPort()
{
    return trajCtrlTask.getConcreteProxy()->trajectory_target;
}

cbProxies::OutputPort< base::samples::Joints >& TrajectoryGeneration::getJointStatusPort()
{
    return jointDriver.getStatusPort();
}

}