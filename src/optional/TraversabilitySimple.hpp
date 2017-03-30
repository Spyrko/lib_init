#pragma once

#include <lib_init/TraversabilityMapProvider.hpp>
#include <lib_init/MapProvider.hpp>
#include "VelodyneSlam.hpp"

namespace traversability {
     namespace cbProxies {
         class Simple;
     }
}


namespace init
{

class TraversabilitySimple : public TraversabilityMapProvider {
    MapProvider &slam;
    
public:
    DependentTask< traversability::cbProxies::Simple > traversabilityTask;
    TraversabilitySimple(MapProvider &slam, const std::string &traversabilityTaskName);
    
    virtual cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< envire::BinaryEvents > >& getTraversabilityMapPort();
    virtual bool connect();
};

}