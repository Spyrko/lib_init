#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/JointDriver.hpp>
#include <lib_init/TrajectoryControl.hpp>
#include <base/JointsTrajectory.hpp>

namespace trajectory_generation {
    namespace cbProxies {
        class Task;
    }
}

namespace init
{

class TrajectoryGeneration : public TrajectoryControl {
protected:
    JointDriver &jointDriver;
public:
    DependentTask< trajectory_generation::cbProxies::Task > trajCtrlTask;
    TrajectoryGeneration(JointDriver &jd, const std::string &trajCtrlTaskName);
    
    virtual bool connect();
    
    virtual cbProxies::InputPort< base::samples::Joints >& getPositionTargetPort();
    virtual cbProxies::InputPort< base::JointsTrajectory >& getTrajectoryTargetPort();
    
    virtual cbProxies::OutputPort< base::samples::Joints >& getJointStatusPort();
};

}