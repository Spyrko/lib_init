#pragma once

#include <lib_init/CameraDriver.hpp>
#include <camera_usb/cbProxies/Task.hpp>

namespace camera_usb {
 namespace cbProxies {
     class Task;
 }
}

namespace init 
{
class UsbCameraDriver : public CameraDriver
{
public: 
    UsbCameraDriver(const std::string &taskName);
    
    virtual cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > > &getFramePort();
    
    DependentTask<camera_usb::cbProxies::Task> cameraTask;
};
}