#pragma once

#include "TiltScan.hpp"
#include <lib_init/CameraDriver.hpp>
#include <base/samples/Pointcloud.hpp>

namespace projection {
     namespace cbProxies {
         class ColorizePointcloudMultiCam;
     }
}

namespace init
{
    class ColorizedPointcloud : public Base {
    protected:
        TiltScan &tiltScan;
        CameraDriver &camFront;
        CameraDriver &camTower;
        
    public:
        DependentTask< projection::cbProxies::ColorizePointcloudMultiCam > colorizePointcloudMultiCamTask;
        
        ColorizedPointcloud(TiltScan &tSc, CameraDriver &camFront, CameraDriver &camTower, const std::string &colorizePointcloudMultiCamTaskName);
        virtual bool connect();
        
        cbProxies::OutputPort<base::samples::Pointcloud> getColorizedPointcloud();
        
    };
}