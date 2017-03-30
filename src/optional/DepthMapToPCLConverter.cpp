#include "DepthMapToPCLConverter.hpp"

init::DepthMapToPCLConverter::DepthMapToPCLConverter(init::DepthMapProvider& velodyne, const std::string &converterTaskName):
    PointCloudProvider("DepthMapToPCLConverter"), 
    velodyne(velodyne), 
    converter(this, converterTaskName)
{
    registerDependency(velodyne);
}
init::DepthMapToPCLConverter::~DepthMapToPCLConverter()
{

}

bool init::DepthMapToPCLConverter::connect()
{
    velodyne.getDepthMapPort().connectTo(converter.getConcreteProxy()->depth_map);
    return init::PointCloudProvider::connect();
}

cbProxies::OutputPort< base::samples::Pointcloud >& init::DepthMapToPCLConverter::getPointCloudPort()
{
    return converter.getConcreteProxy()->pointcloud;
}
