#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/JointDriver.hpp>
#include "ArmPlanner.hpp" 


namespace manipulator_motion_planner {
    namespace cbProxies {
        class CartesianSpaceTask;
    }
}

namespace init
{
    
class ArmPlannerCartesianSpace : public ArmPlanner {
    JointDriver &jointDispatcher;
public:
    ArmPlannerCartesianSpace(JointDriver &jointDispatcher, const std::string &armPlannerName);
    virtual bool connect();
    cbProxies::InputPort< ::base::samples::RigidBodyState >& getTargetPort();
    DependentTask< manipulator_motion_planner::cbProxies::CartesianSpaceTask > cartesianSpacePlanner;
    virtual cbProxies::OutputPort< ::base::JointsTrajectory >& getTrajectoryPort();
    virtual cbProxies::InputPort< base::samples::Pointcloud >& getPointCloudPort();
    virtual cbProxies::InputPort< manipulator_planner_library::ModelObject >& getObjectPort();
    virtual cbProxies::OutputPort< boost::int32_t >& getStatePort();
    virtual cbProxies::InputPort< base::samples::Joints >& getStartPort();
};

}