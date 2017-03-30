#pragma once

#include "Base.hpp"
#include <orocos_callback_base/Port.hpp>
#include <base/samples/RigidBodyState.hpp>
#include <base/samples/IMUSensors.hpp>
namespace init
{
    class IMUDriver : public Base
    {
    public:
        IMUDriver(const std::string& name) : Base(name) {};
        virtual ~IMUDriver() {};
        virtual cbProxies::OutputPort<base::samples::RigidBodyState> getOrientationSamples() = 0;
        virtual cbProxies::OutputPort<base::samples::IMUSensors> getSensorSamples() = 0;    
    };
    
}
