#include "SimVelodyneDriver.hpp"

namespace init
{

SimVelodyneDriver::SimVelodyneDriver(Simulator &sim, const std::string& velodyneTaskName) : PointCloudProvider("SimVelodyneDriver"),
    velodyneTask(this, velodyneTaskName)
{
    velodyneTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

SimVelodyneDriver::~SimVelodyneDriver()
{

}

void SimVelodyneDriver::initProxies()
{
    Base::initProxies();
    simulatedPointcloudPort = new cbProxies::OutputPort< base::samples::Pointcloud >(velodyneTask.getConcreteProxy()->pointcloud);
}

cbProxies::OutputPort< base::samples::Pointcloud >& SimVelodyneDriver::getPointCloudPort()
{
    return *simulatedPointcloudPort;
}

}
