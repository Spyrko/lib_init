#pragma once

#include <orocos_callback_base/Port.hpp>
#include <base/samples/CommandSamples.hpp>
#include <lib_init/Base.hpp>

namespace init
{

class MotionControl2DProvider : public virtual Base
{
public:
    MotionControl2DProvider(const std::string& name): Base(name) {};
    virtual ~MotionControl2DProvider() {};
    virtual cbProxies::OutputPort<base::commands::Motion2D> &getCommand2DPort() = 0;
};
}
