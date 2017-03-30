#pragma once

#include <lib_init/PositionProvider.hpp>
#include <lib_init/PointCloudProvider.hpp>
#include <slam3d/cbProxies/PointcloudMapper.hpp>

namespace init
{

class Slam3d : public PositionProvider
{
    PointCloudProvider &pclProv;

public:
    Slam3d(PositionProvider &odometry, PointCloudProvider &pclProv, const std::string &mapperTaskName);
    Slam3d(PointCloudProvider &pclProv, const std::string &mapperTaskName);
    virtual ~Slam3d();
    
    virtual bool connect();
    
    virtual cbProxies::OutputPort< base::samples::RigidBodyState >& getPositionSamples();

    DependentTask<slam3d::cbProxies::PointcloudMapper> mapper;
};


}