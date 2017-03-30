#pragma once

#include <base/samples/Pointcloud.hpp>
#include <orocos_callback_base/Port.hpp>
#include "Base.hpp"

namespace init 
{

class PointCloudProvider : public Base
{
public:
    PointCloudProvider(const std::string& name);
    virtual ~PointCloudProvider();
    virtual cbProxies::OutputPort< ::base::samples::Pointcloud > &getPointCloudPort() = 0;

};

}

