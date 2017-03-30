#pragma once

#include <lib_init/DependentTask.hpp>
#include "ArmPlanner.hpp"

namespace manipulator_motion_planner {
    namespace cbProxies {
        class JointSpaceTask;
    }
}

namespace init
{
    
class ArmPlannerJointSpace : public ArmPlanner {
public:
    ArmPlannerJointSpace(const std::string &armPlannerName);
    virtual bool connect();
    cbProxies::InputPort< base::samples::Joints >& getTargetPort();
    DependentTask< manipulator_motion_planner::cbProxies::JointSpaceTask > jointSpacePlanner;
    virtual cbProxies::OutputPort< ::base::JointsTrajectory >& getTrajectoryPort();
    virtual cbProxies::InputPort< base::samples::Pointcloud >& getPointCloudPort();
    virtual cbProxies::InputPort< manipulator_planner_library::ModelObject >& getObjectPort();
    virtual cbProxies::OutputPort< boost::int32_t >& getStatePort();
    virtual cbProxies::InputPort< base::samples::Joints >& getStartPort();
};

}