#pragma once

#include <lib_init/LaserDriver.hpp>
#include <hokuyo/cbProxies/Task.hpp>
#include <laser_filter/cbProxies/Task.hpp>

namespace init
{

class HokuyoLaserDriver : public LaserDriver
{
public: 
    DependentTask<hokuyo::cbProxies::Task> laserTask;
    DependentTask<laser_filter::cbProxies::Task> filterTask;
    HokuyoLaserDriver(const std::string &hokuyoTaskName, const std::string &filterTaskName);

    virtual bool connect();

    virtual cbProxies::OutputPort< base::samples::LaserScan >& getLaserReadingsPort();
protected:
};
}
