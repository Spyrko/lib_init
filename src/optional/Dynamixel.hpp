#pragma once

#include <lib_init/JointDriver.hpp>
#include <servo_dynamixel/cbProxies/Task.hpp>

namespace init 
{

class Dynamixel : public JointDriver
{
public:
    Dynamixel(const std::string &taskName);
    virtual cbProxies::InputPort< base::commands::Joints >& getCommandPort();
    virtual cbProxies::OutputPort< base::samples::Joints >& getStatusPort();
    
    DependentTask<servo_dynamixel::cbProxies::Task> dynamixel;
};

}
