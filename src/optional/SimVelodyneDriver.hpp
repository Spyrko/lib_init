#pragma once

#include <lib_init/PointCloudProvider.hpp>
#include <orocos_callback_base/Port.hpp>
#include "Simulator.hpp"
#include <base/samples/Pointcloud.hpp>
#include <mars/cbProxies/RotatingLaserRangeFinder.hpp>

namespace init
{

class SimVelodyneDriver : public PointCloudProvider {
protected:
    cbProxies::OutputPort< base::samples::Pointcloud > *simulatedPointcloudPort;

public:
    
    SimVelodyneDriver(Simulator &sim, const std::string &velodyneTaskName);

    virtual ~SimVelodyneDriver();
    virtual void initProxies();

    virtual cbProxies::OutputPort< base::samples::Pointcloud >& getPointCloudPort();
    
    DependentTask<mars::cbProxies::RotatingLaserRangeFinder> velodyneTask;
};

}