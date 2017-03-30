#include "SimIMUDriver.hpp"

init::SimIMUDriver::SimIMUDriver(const std::string &imuTaskName, init::Simulator& sim) : IMUDriver("SimIMUDriver"), imuTask(this, imuTaskName)
{
    imuTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

cbProxies::OutputPort< base::samples::RigidBodyState > init::SimIMUDriver::getOrientationSamples()
{
    return imuTask.getConcreteProxy()->orientation_samples;
}

cbProxies::OutputPort< base::samples::IMUSensors > init::SimIMUDriver::getSensorSamples()
{
    return imuTask.getConcreteProxy()->calibrated_sensors;
}
