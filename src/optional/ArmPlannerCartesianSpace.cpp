#include "ArmPlannerCartesianSpace.hpp"

#include <manipulator_motion_planner/cbProxies/CartesianSpaceTask.hpp>
#include <manipulator_motion_planner/cbProxies/PlannerTask.hpp>

namespace init
{
 
ArmPlannerCartesianSpace::ArmPlannerCartesianSpace(init::JointDriver& jointDispatcher, const std::string& armPlannerName)
    : ArmPlanner("ArmPlannerCartesianSpace")
    , jointDispatcher(jointDispatcher)
    , cartesianSpacePlanner(this, armPlannerName)
{
    registerDependency(jointDispatcher);
}

bool ArmPlannerCartesianSpace::connect()
{
    jointDispatcher.getStatusPort().connectTo(cartesianSpacePlanner.getConcreteProxy()->joints_status);
    
    return Base::connect();
}

cbProxies::InputPort< ::base::samples::RigidBodyState >& ArmPlannerCartesianSpace::getTargetPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->target_pose;
}

cbProxies::OutputPort< ::base::JointsTrajectory >& ArmPlannerCartesianSpace::getTrajectoryPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->planned_trajectory;
}

cbProxies::InputPort< base::samples::Pointcloud>& ArmPlannerCartesianSpace::getPointCloudPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->environment_in;
}

cbProxies::InputPort< manipulator_planner_library::ModelObject>& ArmPlannerCartesianSpace::getObjectPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->known_object;
}

cbProxies::OutputPort< boost::int32_t >& ArmPlannerCartesianSpace::getStatePort()
{
    return cartesianSpacePlanner.getConcreteProxy()->state;
}

cbProxies::InputPort< base::samples::Joints >& ArmPlannerCartesianSpace::getStartPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->joints_status;
}

}