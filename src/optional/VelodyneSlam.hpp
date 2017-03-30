#pragma once

#include <lib_init/PositionProvider.hpp>
#include <lib_init/MapProvider.hpp>
#include "VelodyneDriver.hpp"
#include "SimVelodyneDriver.hpp"
#include <graph_slam/GraphSlamDebugTypes.hpp>
#include <envire/core/EventTypes.hpp>

namespace graph_slam {
     namespace cbProxies {
         class VelodyneSLAM;
     }
}

namespace init
{

class VelodyneSlam : public PositionProvider, public MapProvider
{
protected:
    VelodyneDriver *velodyne;
    SimVelodyneDriver *simVelodyne;
    PositionProvider &odometry;

public:
    DependentTask< graph_slam::cbProxies::VelodyneSLAM > velodyneSlamTask;
    virtual ~VelodyneSlam();
    VelodyneSlam(VelodyneDriver &vd, PositionProvider &odometry, const std::string &velodyneSlamTaskName);
    VelodyneSlam(SimVelodyneDriver &vd, PositionProvider &odometry, const std::string &velodyneSlamTaskName);
    virtual bool connect();
    
    virtual cbProxies::OutputPort< base::samples::RigidBodyState >& getPositionSamples();
    virtual cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< envire::BinaryEvents > >& getMapPort();
};

}
