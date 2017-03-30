#pragma once

#include "Base.hpp"
#include <base/samples/Wrenches.hpp>
#include <orocos_callback_base/Port.hpp>

namespace init
{

class ForceTorqueSensor : public Base
{
public:
    ForceTorqueSensor(const std::string& name) : Base(name) {};
    virtual ~ForceTorqueSensor() {};
    virtual cbProxies::OutputPort<base::samples::Wrenches> &getStatusPort() = 0;    
};
    
}