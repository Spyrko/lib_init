#pragma once

#include "Base.hpp"
#include <orocos_callback_base/Port.hpp>

namespace init {

class PositionProvider : public virtual Base
{
public:
    PositionProvider(const std::string& name) : Base(name) {};
    
    virtual cbProxies::OutputPort< ::base::samples::RigidBodyState > &getPositionSamples() = 0;
};

    
}
