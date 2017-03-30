#include "AILAJointDriver.hpp"
#include <orocos_cpp/Spawner.hpp>
#include <serial_ndlcom/cbProxies/Task.hpp>

namespace init
{

AILAJointDriver::AILAJointDriver(init::NDLComSerial& ndlcomSerial, const std::string &AILAJointsTaskName) 
    : JointDriver("AILAJointDriver")
    , ndlcomSerial(ndlcomSerial)
    , jointTask(this, AILAJointsTaskName)
{
    registerDependency(ndlcomSerial);
}

bool AILAJointDriver::connect()
{
    ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_out.connectTo(jointTask.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(200));
    jointTask.getConcreteProxy()->ndlcom_message_out.connectTo(ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(200));
    return init::JointDriver::connect();
}

bool AILAJointDriver::start()
{
    jointTask.getConcreteProxy()->enable();
    return init::JointDriver::start();
}

cbProxies::InputPort< base::commands::Joints >& AILAJointDriver::getCommandPort()
{
    return jointTask.getConcreteProxy()->joints_command;
}

cbProxies::OutputPort< base::samples::Joints >& AILAJointDriver::getStatusPort()
{
    return jointTask.getConcreteProxy()->joints_status;
}
}
