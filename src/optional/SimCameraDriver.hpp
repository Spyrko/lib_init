#pragma once

#include <lib_init/CameraDriver.hpp>
#include "Simulator.hpp"
#include <mars/cbProxies/Camera.hpp>


namespace init
{

class SimCameraDriver : public CameraDriver
{
public:
    SimCameraDriver(Simulator &sim, const std::string &taskName);

    virtual void initProxies();

    virtual cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > > &getFramePort();
    
    DependentTask<mars::cbProxies::Camera> cameraTask;
protected:
    cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > > *framePort;
};
}
