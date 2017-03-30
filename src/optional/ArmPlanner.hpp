#pragma once

#include <lib_init/Base.hpp>

#include <orocos_callback_base/Port.hpp>
#include <base/samples/RigidBodyState.hpp>
#include <base/JointsTrajectory.hpp>
#include <base/samples/Pointcloud.hpp>
#include <manipulator_planner_library/ModelObject.hpp>
#include <base/commands/Joints.hpp>
#include <rtt/Port.hpp>

namespace manipulator_motion_planner {
    namespace cbProxies {
        class PlannerTask;
    }
}

namespace init
{

class ArmPlanner : public Base {
public:
    ArmPlanner(const std::string& name) : Base(name) {};
    virtual cbProxies::OutputPort<::base::JointsTrajectory>& getTrajectoryPort() =0;
    virtual cbProxies::InputPort<base::samples::Pointcloud>& getPointCloudPort() =0;
    virtual cbProxies::InputPort<manipulator_planner_library::ModelObject>& getObjectPort() =0;
    virtual cbProxies::OutputPort<boost::int32_t>& getStatePort() =0;
    virtual cbProxies::InputPort<base::samples::Joints>& getStartPort() =0;
};

}