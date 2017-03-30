#pragma once

#include <orocos_callback_base/Port.hpp>
#include <base/samples/CommandSamples.hpp>
#include <lib_init/Base.hpp>

namespace init
{

class MotionControl2D : public virtual Base
{
public:
    MotionControl2D(const std::string& name): Base(name) {};
    virtual ~MotionControl2D() {};
    virtual cbProxies::InputPort<base::commands::Motion2D> &getCommand2DPort() = 0;
};
}
