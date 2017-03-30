#pragma once

#include <lib_init/LaserDriver.hpp>
#include <lib_init/JointDriver.hpp>
#include <base/samples/Pointcloud.hpp>

namespace tilt_scan {
    namespace cbProxies {
        class Task;
    }
}

namespace init 
{

class TiltScan : public Base
{
protected:
    LaserDriver &laserDriver;
    JointDriver &jointDriver;
public:
    TiltScan(LaserDriver &ld, JointDriver &jd, const std::string &tiltTaskName);

    virtual bool connect();
    
    DependentTask<tilt_scan::cbProxies::Task> tiltTask;
    
    cbProxies::OutputPort<base::samples::Pointcloud> getPointcloud();
};
}