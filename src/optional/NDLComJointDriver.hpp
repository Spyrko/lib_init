#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/JointDriver.hpp>
#include <lib_init/Base.hpp>
#include "NDLComSerial.hpp"
#include <ndlcom_device_driver/cbProxies/NDLComJointDriverBaseTask.hpp>

namespace init
{

class NDLComJointDriver : public JointDriver {
    NDLComSerial &serial;
public:
    NDLComJointDriver(NDLComSerial &serial, const std::string &jointTaskName);
    //virtual void initProxies();
    virtual bool connect();
    virtual bool configure();
    virtual bool start();
    
    virtual cbProxies::OutputPort<base::samples::Joints> &getStatusPort();
    virtual cbProxies::InputPort<base::commands::Joints> &getCommandPort();

    DependentTask<ndlcom_device_driver::cbProxies::NDLComJointDriverBaseTask> jointDriver;
};

}
