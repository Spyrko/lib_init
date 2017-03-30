#include "ArmPlannerJointSpace.hpp"

#include <manipulator_motion_planner/cbProxies/JointSpaceTask.hpp>
#include <manipulator_motion_planner/cbProxies/PlannerTask.hpp>

namespace init
{
 
ArmPlannerJointSpace::ArmPlannerJointSpace(const std::string& armPlannerName)
    : ArmPlanner("ArmPlannerJointSpace")
    , jointSpacePlanner(this, armPlannerName)
{
}

bool ArmPlannerJointSpace::connect()
{
    return Base::connect();
}

cbProxies::InputPort< base::samples::Joints >& ArmPlannerJointSpace::getTargetPort()
{
    return jointSpacePlanner.getConcreteProxy()->target_joints_angle;
}

cbProxies::OutputPort< ::base::JointsTrajectory >& ArmPlannerJointSpace::getTrajectoryPort()
{
    return jointSpacePlanner.getConcreteProxy()->planned_trajectory;
}

cbProxies::InputPort< base::samples::Pointcloud>& ArmPlannerJointSpace::getPointCloudPort()
{
    return jointSpacePlanner.getConcreteProxy()->environment_in;
}

cbProxies::InputPort< manipulator_planner_library::ModelObject>& ArmPlannerJointSpace::getObjectPort()
{
    return jointSpacePlanner.getConcreteProxy()->known_object;
}

cbProxies::OutputPort< boost::int32_t >& ArmPlannerJointSpace::getStatePort()
{
    return jointSpacePlanner.getConcreteProxy()->state;
}

cbProxies::InputPort< base::samples::Joints >& ArmPlannerJointSpace::getStartPort()
{
    return jointSpacePlanner.getConcreteProxy()->joints_status;
}
    
}