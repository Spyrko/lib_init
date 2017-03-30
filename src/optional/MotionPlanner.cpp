#include "MotionPlanner.hpp"

#include <motion_planning_libraries/cbProxies/Task.hpp>
#include <simple_pose_integrator/cbProxies/Task.hpp>

namespace init
{


MotionPlanner::MotionPlanner(PoseProvider &poseProvider, TraversabilityMapProvider &travMapProvider, const std::string &motionPlanningTaskName)
    : MotionPlannerProvider("MotionPlanner")
    , poseProvider(poseProvider)
    , travMapProvider(travMapProvider)
    , motionPlanningTask(this, motionPlanningTaskName)
{
    registerDependency(poseProvider);
    registerDependency(travMapProvider);
}

bool MotionPlanner::connect()
{
    poseProvider.getPositionSamples().connectTo(motionPlanningTask.getConcreteProxy()->start_pose_samples);
    travMapProvider.getTraversabilityMapPort().connectTo(motionPlanningTask.getConcreteProxy()->traversability_map);
    return init::Base::connect();
}


cbProxies::OutputPort< std::vector< base::Trajectory > >& MotionPlanner::getTrajectories()
{
    return motionPlanningTask.getConcreteProxy()->trajectory;
}


}