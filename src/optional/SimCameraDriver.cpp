#include "SimCameraDriver.hpp"

namespace init
{
    
SimCameraDriver::SimCameraDriver(Simulator& sim, const std::string& taskName) : CameraDriver("SimCameraDriver"), cameraTask(this, taskName)
{
    cameraTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

void SimCameraDriver::initProxies()
{
    init::Base::initProxies();
}

cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > >& SimCameraDriver::getFramePort()
{
    return cameraTask.getConcreteProxy()->frame;
}

}