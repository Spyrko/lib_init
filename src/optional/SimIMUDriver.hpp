#pragma once

#include <lib_init/IMUDriver.hpp>
#include "Simulator.hpp"

#include <mars/cbProxies/IMU.hpp>

namespace init 
{

class SimIMUDriver : public IMUDriver
{
public:
    SimIMUDriver(const std::string& imuTaskName, init::Simulator& sim);
    virtual cbProxies::OutputPort< base::samples::RigidBodyState > getOrientationSamples();
    virtual cbProxies::OutputPort< base::samples::IMUSensors > getSensorSamples();
    
    DependentTask<mars::cbProxies::IMU> imuTask;
};

}


