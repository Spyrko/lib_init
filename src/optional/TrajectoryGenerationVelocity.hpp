#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/JointDriver.hpp>
#include <lib_init/TrajectoryControl.hpp>
#include <trajectory_generation/ConstrainedJointsTrajectory.hpp>
#include <trajectory_generation/trajectory_generationTypes.hpp>
#include <orocos_callback_base/Port.hpp>

namespace trajectory_generation {
    namespace cbProxies {
        class RMLVelocityTask;
    }
}

namespace init
{

class TrajectoryGenerationVelocity : public TrajectoryControl {   
protected:
    JointDriver &jointDriver; 
public:
    DependentTask< trajectory_generation::cbProxies::RMLVelocityTask > trajCtrlTask;
    TrajectoryGenerationVelocity(JointDriver &jd, const std::string &trajCtrlTaskName);
    
    virtual cbProxies::InputPort< base::samples::Joints >& getVelocityTargetPort();
    virtual cbProxies::InputPort< trajectory_generation::ConstrainedJointsCmd >& getConstrainedVelocityTargetPort();
    
    virtual cbProxies::OutputPort< base::samples::Joints >& getJointStatusPort();
    
    virtual bool connect();
};

}