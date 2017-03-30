#pragma once

#include "Base.hpp"
#include <orocos_callback_base/Port.hpp>
#include <envire/core/EventTypes.hpp>
#include <rtt/extras/ReadOnlyPointer.hpp>

namespace init {

class TraversabilityMapProvider : public Base
{
public:
    TraversabilityMapProvider(const std::string& name) : Base(name) {};

    virtual cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< envire::BinaryEvents > >& getTraversabilityMapPort() = 0;
};

    
}
