#include "VelodyneSlam.hpp"

#include <graph_slam/cbProxies/VelodyneSLAM.hpp>
#include <velodyne_lidar/cbProxies/LaserScanner.hpp>

namespace init
{

VelodyneSlam::VelodyneSlam(VelodyneDriver &vd, PositionProvider &odometry, const std::string &velodyneSlamTaskName)
    : Base("VelodyneSlam")
    , PositionProvider("VelodyneSlam")
    , MapProvider("VelodyneSlam")
    , velodyne(&vd)
    , simVelodyne(nullptr)
    , odometry(odometry)
    , velodyneSlamTask(this, velodyneSlamTaskName)
{
    registerDependency(*velodyne);
    registerDependency(odometry);
}

VelodyneSlam::VelodyneSlam(SimVelodyneDriver& vd, PositionProvider &odometry, const std::string& velodyneSlamTaskName)
    : Base("VelodyneSlam")
    , PositionProvider("VelodyneSlam")
    , MapProvider("VelodyneSlam")
    , velodyne(nullptr)
    , simVelodyne(&vd)
    , odometry(odometry)
    , velodyneSlamTask(this, velodyneSlamTaskName)
{
    registerDependency(*simVelodyne);
    registerDependency(odometry);
}

VelodyneSlam::~VelodyneSlam()
{

}

bool VelodyneSlam::connect()
{
    if(velodyne)
    {
        velodyne->getLaserScansPort().connectTo(velodyneSlamTask.getConcreteProxy()->lidar_samples, RTT::ConnPolicy::buffer(50));
    }
    if(simVelodyne)
    {
        simVelodyne->velodyneTask.getConcreteProxy()->pointcloud.connectTo(velodyneSlamTask.getConcreteProxy()->simulated_pointcloud, RTT::ConnPolicy::buffer(50));
    }
    
    return init::Base::connect();
}

cbProxies::OutputPort< base::samples::RigidBodyState >& VelodyneSlam::getPositionSamples()
{
    return velodyneSlamTask.getConcreteProxy()->pose_samples;
}

cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< envire::BinaryEvents > >& VelodyneSlam::getMapPort()
{
    return velodyneSlamTask.getConcreteProxy()->envire_map;
}

}
