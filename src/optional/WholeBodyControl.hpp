#pragma once

#include <lib_init/Base.hpp>
#include "TrajectoryGenerationVelocity.hpp"
#include <orocos_callback_base/Port.hpp>
#include <base/commands/Joints.hpp>
#include <wbc/Constraint.hpp>
#include <ctrl_lib/ControllerTask.hpp>

namespace wbc {
    namespace cbProxies {
        class WbcVelocityTask;
    }
}
namespace ctrl_lib {
    namespace cbProxies {
        class CartesianPositionController;
        class JointPositionController;
    }
}
namespace kccd {
    namespace cbProxies {
        class SelfCollisionCheck;
        class SelfCollisionCtrl;
    }
}
namespace waypoint_provider {
    namespace cbProxies {
        class JointWaypointProviderTrajectoryInput;
    }
}

namespace init {
    class WholeBodyControl : public Base {
        TrajectoryControl& trajCtrl;
    public:
        WholeBodyControl(TrajectoryControl& trajCtrl,
                         const std::string& wbcTaskName, 
                         const std::string& cartPosCtrlTaskName, 
                         const std::string& jointPosCtrlTaskName,
                         const std::string& kccdCheckTaskName,
                         const std::string& kccdCtrlTaskName,
                         const std::string& waypointProvTaskName);
        
        
        DependentTask< wbc::cbProxies::WbcVelocityTask > wbcTask;
        DependentTask< ctrl_lib::cbProxies::CartesianPositionController > cartPosCtrlTask;
        DependentTask< ctrl_lib::cbProxies::JointPositionController > jointPosCtrlTask;
        DependentTask< kccd::cbProxies::SelfCollisionCheck > kccdCheckTask;
        DependentTask< kccd::cbProxies::SelfCollisionCtrl > kccdCtrlTask;
        DependentTask< waypoint_provider::cbProxies::JointWaypointProviderTrajectoryInput > waypointProvTask;
        
        
        virtual bool connect();
        virtual bool configure();
        
        virtual cbProxies::InputPort< base::samples::RigidBodyState >& getCartPosTargetPort();
        virtual cbProxies::InputPort< base::samples::Joints >& getPositionTargetPort();
        virtual cbProxies::InputPort< base::JointsTrajectory >& getTrajectoryTargetPort();
    
        virtual cbProxies::OutputPort< trajectory_generation::ConstrainedJointsCmd >& getConstrainedCommandOutPort();
        virtual cbProxies::OutputPort< base::samples::Joints > getCommandOutPort();
    };
}