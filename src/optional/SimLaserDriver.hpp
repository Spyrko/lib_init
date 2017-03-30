#pragma once

#include <lib_init/LaserDriver.hpp>
#include <mars/cbProxies/LaserRangeFinder.hpp>
#include "Simulator.hpp"

namespace init
{

class SimLaserDriver : public LaserDriver
{
public:
    SimLaserDriver(Simulator &sim, const std::string &taskName);

    virtual void initProxies();

    virtual cbProxies::OutputPort< base::samples::LaserScan >& getLaserReadingsPort();
protected:
    DependentTask<mars::cbProxies::LaserRangeFinder> laserTask;
};
}
