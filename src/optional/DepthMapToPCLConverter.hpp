#pragma once

#include <lib_init/PointCloudProvider.hpp>
#include <lib_init/DepthMapProvider.hpp>
#include <depth_map_preprocessing/cbProxies/PointcloudConverter.hpp>

namespace init 
{

class DepthMapToPCLConverter : public PointCloudProvider
{
    DepthMapProvider &velodyne;
public:
    DepthMapToPCLConverter(DepthMapProvider &velodyne, const std::string &converterTaskName);
    virtual ~DepthMapToPCLConverter();
    virtual bool connect();
    
    virtual cbProxies::OutputPort< base::samples::Pointcloud >& getPointCloudPort();
    DependentTask<depth_map_preprocessing::cbProxies::PointcloudConverter> converter;
};

}

