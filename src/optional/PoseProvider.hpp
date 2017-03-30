#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <lib_init/PositionProvider.hpp>

namespace simple_pose_integrator {
     namespace cbProxies {
         class Task;
     }
}

namespace init
{

class PoseProvider : public PositionProvider {
protected:
    PositionProvider &irregular_pose_provider;
    
public:
    DependentTask< simple_pose_integrator::cbProxies::Task > poseProviderTask;
    PoseProvider(PositionProvider &irregular_pose_provider, const std::string &poseProviderTaskName);
    virtual bool connect();
    virtual cbProxies::OutputPort< base::samples::RigidBodyState >& getPositionSamples();
};

}