#pragma once

#include "Base.hpp"
#include <orocos_callback_base/Port.hpp>
#include <base/Trajectory.hpp>

namespace init {

class MotionPlannerProvider : public Base
{
public:
    MotionPlannerProvider(const std::string& name) : Base(name) {};
    
    virtual cbProxies::OutputPort< std::vector<base::Trajectory> > &getTrajectories() = 0;
};

    
}
