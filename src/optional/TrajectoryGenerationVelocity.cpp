#include "TrajectoryGenerationVelocity.hpp"
#include <trajectory_generation/cbProxies/RMLVelocityTask.hpp>

namespace init
{
    
TrajectoryGenerationVelocity::TrajectoryGenerationVelocity(JointDriver& jd, const std::string& trajCtrlTaskName)
    : TrajectoryControl("TrajectoryGenerationVelocity")
    , jointDriver(jd)
    , trajCtrlTask(this, trajCtrlTaskName)
{
    registerDependency(jointDriver);
}

bool TrajectoryGenerationVelocity::connect()
{
    jointDriver.getStatusPort().connectTo(trajCtrlTask.getConcreteProxy()->joint_state);
    trajCtrlTask.getConcreteProxy()->command.connectTo(jointDriver.getCommandPort());
    
    return Base::connect();
}

cbProxies::InputPort< base::commands::Joints >& TrajectoryGenerationVelocity::getVelocityTargetPort()
{
    return trajCtrlTask.getConcreteProxy()->velocity_target;
}

cbProxies::InputPort< trajectory_generation::ConstrainedJointsCmd >& TrajectoryGenerationVelocity::getConstrainedVelocityTargetPort()
{
    return trajCtrlTask.getConcreteProxy()->constrained_velocity_target;
}

cbProxies::OutputPort< base::samples::Joints >& TrajectoryGenerationVelocity::getJointStatusPort()
{
    return jointDriver.getStatusPort();
}

}