#pragma once

#include <lib_init/Base.hpp>
#include <orocos_cpp/Deployment.hpp>
#include <mars/cbProxies/Task.hpp>

namespace init
{

class Simulator : public Base
{
protected:
public:
    Simulator(const std::string& simTaskName, const boost::shared_ptr< orocos_cpp::Deployment >& simDeployment);
    
    DependentTask<mars::cbProxies::Task> simulator;
};
}
