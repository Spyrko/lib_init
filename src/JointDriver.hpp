#pragma once

#include <base/samples/Joints.hpp>
#include <base/commands/Joints.hpp>
#include <orocos_callback_base/Port.hpp>
#include "Base.hpp"

namespace init
{

class JointDriver : public Base
{
public:
    JointDriver(const std::string& name) : Base(name) {};
    virtual ~JointDriver() {};
    virtual cbProxies::OutputPort<base::samples::Joints> &getStatusPort() = 0;
    virtual cbProxies::InputPort<base::commands::Joints> &getCommandPort() = 0;

};

}