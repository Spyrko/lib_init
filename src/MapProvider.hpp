#pragma once

#include "Base.hpp"
#include <orocos_callback_base/Port.hpp>
#include <envire/core/EventTypes.hpp>
#include <rtt/extras/ReadOnlyPointer.hpp>

namespace init
{

class MapProvider : public virtual Base
{
public:
    MapProvider(const std::string& name);
    virtual ~MapProvider();
    
    virtual cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< envire::BinaryEvents > >& getMapPort() = 0;    
};

}
