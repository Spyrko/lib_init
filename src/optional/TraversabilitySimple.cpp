#include "TraversabilitySimple.hpp"

#include <traversability/cbProxies/Simple.hpp>
#include <graph_slam/cbProxies/VelodyneSLAM.hpp>

namespace init
{

TraversabilitySimple::TraversabilitySimple(MapProvider& slam, const std::string& traversabilityTaskName)
    : TraversabilityMapProvider("TraversabilitySimple")
    , slam(slam)
    , traversabilityTask(this, traversabilityTaskName)
{
    registerDependency(slam);
}

bool TraversabilitySimple::connect()
{
    slam.getMapPort().connectTo(traversabilityTask.getConcreteProxy()->mls_map);
    return init::Base::connect();
}

cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< std::vector< envire::BinaryEvent > > >& TraversabilitySimple::getTraversabilityMapPort()
{
    return traversabilityTask.getConcreteProxy()->traversability_map;
}
   
}