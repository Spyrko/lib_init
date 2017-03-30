#pragma once

#include <orocos_callback_base/Port.hpp>
#include <base/samples/LaserScan.hpp>
#include <lib_init/Base.hpp>

namespace init
{

class LaserDriver : public Base
{
public:
    LaserDriver(const std::string& name): Base(name) {};
    virtual ~LaserDriver() {};
    virtual cbProxies::OutputPort<base::samples::LaserScan> &getLaserReadingsPort() = 0;
};
}
