#pragma once

#include <orocos_callback_base/Port.hpp>
#include <base/samples/DepthMap.hpp>
#include <lib_init/Base.hpp>

namespace init
{

class DepthMapProvider : public Base
{
public:
    DepthMapProvider(const std::string& name): Base(name) {};
    virtual ~DepthMapProvider() {};
    virtual cbProxies::OutputPort<base::samples::DepthMap> &getDepthMapPort() = 0;
};
}
