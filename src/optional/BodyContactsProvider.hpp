#pragma once

#include <lib_init/Base.hpp>
#include <odometry/ContactState.hpp>
#include <orocos_callback_base/Port.hpp>

namespace init {

class BodyContactsProvider : public virtual Base
{
public:
    BodyContactsProvider(const std::string& name) : Base(name) {};
    
    virtual cbProxies::OutputPort< odometry::BodyContactState > &getBodyContactStates() = 0;
};

    
}
