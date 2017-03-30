#pragma once

#include <lib_init/DepthMapProvider.hpp>
#include <base/samples/DepthMap.hpp>
#include <orocos_callback_base/Port.hpp>
#include <velodyne_lidar/cbProxies/LaserScanner.hpp>

namespace init
{

class VelodyneDriver : public DepthMapProvider {
protected:
    virtual bool connect();

public:
    VelodyneDriver(const std::string &velodyneTaskName);
    virtual ~VelodyneDriver() {};
    DependentTask< velodyne_lidar::cbProxies::LaserScanner > velodyneTask;
    cbProxies::OutputPort< base::samples::DepthMap >& getLaserScansPort();
    cbProxies::OutputPort< base::samples::DepthMap >& getDepthMapPort();
};

}