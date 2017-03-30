#pragma once

#include <orocos_callback_base/Port.hpp>
#include "Base.hpp"
#include <base/samples/Frame.hpp>
#include <rtt/extras/ReadOnlyPointer.hpp>

namespace init
{

class CameraDriver : public Base
{
public:
    CameraDriver(const std::string& name) : Base(name) {};
    virtual ~CameraDriver() {};
    virtual cbProxies::OutputPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > > &getFramePort() = 0;
};
}
