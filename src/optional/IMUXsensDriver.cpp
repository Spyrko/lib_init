#include "IMUXsensDriver.hpp"

init::IMUXsensDriver::IMUXsensDriver(const std::string imuTaskName) : IMUDriver("IMUXsensDriver"), imuTask(this, imuTaskName)
{
}

cbProxies::OutputPort< base::samples::RigidBodyState > init::IMUXsensDriver::getOrientationSamples()
{
    return imuTask.getConcreteProxy()->orientation_samples;
}

cbProxies::OutputPort< base::samples::IMUSensors > init::IMUXsensDriver::getSensorSamples()
{
    return imuTask.getConcreteProxy()->calibrated_sensors;
}
