#pragma once

#include <lib_init/IMUDriver.hpp>
#include <imu_xsens/cbProxies/Task.hpp>

namespace init
{

class IMUXsensDriver : public IMUDriver
{
    public:
        IMUXsensDriver(const std::string imuTaskName);
        virtual cbProxies::OutputPort< base::samples::RigidBodyState > getOrientationSamples();
        virtual cbProxies::OutputPort< base::samples::IMUSensors > getSensorSamples();

        DependentTask<imu_xsens::cbProxies::Task> imuTask;
};

}


