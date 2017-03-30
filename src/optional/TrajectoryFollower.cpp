#include "TrajectoryFollower.hpp"

#include <trajectory_follower/cbProxies/Task.hpp>

namespace init
{

    
TrajectoryFollower::TrajectoryFollower(PositionProvider &posProv, MotionControl2D &motionController, const std::string &trajectoryFollowerTaskName)
    : Base("TrajectoryFollower")
    , posProv(posProv)
    , motionController(motionController)
    , trajectoryFollowerTask(this, trajectoryFollowerTaskName)
{
    registerDependency(posProv);
    registerDependency(motionController);
}

bool TrajectoryFollower::connect()
{
    posProv.getPositionSamples().connectTo(trajectoryFollowerTask.getConcreteProxy()->robot_pose);
    trajectoryFollowerTask.getConcreteProxy()->motion_command.connectTo(motionController.getCommand2DPort());    
    return init::Base::connect();
}

cbProxies::OutputPort< base::commands::Motion2D >& TrajectoryFollower::getCommandOut()
{
    return trajectoryFollowerTask.getConcreteProxy()->motion_command;
}


}