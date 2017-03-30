#pragma once

#include <lib_init/Base.hpp>
#include <base/samples/Joints.hpp>
#include <orocos_callback_base/Port.hpp>

namespace init {
    class TrajectoryControl : public Base
    {
    public:
        TrajectoryControl(const std::string& name) : Base(name) {};
        virtual cbProxies::OutputPort< base::samples::Joints >& getJointStatusPort() = 0;
    };
}