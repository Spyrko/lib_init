#include "NDLComForceTorqueSensor.hpp"

#include <serial_ndlcom/cbProxies/Task.hpp>

namespace init
{
    
NDLComForceTorqueSensor::NDLComForceTorqueSensor(NDLComSerial &ndlcomSerial, const std::string &forceTorqueSensorTaskName)
     : ForceTorqueSensor("ForceTorqueSensor")
     , ndlcomSerial(ndlcomSerial)
     , forceTorqueSensorTask(this, forceTorqueSensorTaskName)
{
    registerDependency(ndlcomSerial);
}
     
bool NDLComForceTorqueSensor::connect()
{
    ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_out.connectTo(forceTorqueSensorTask.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(300));
    return ForceTorqueSensor::connect();
}
 
cbProxies::OutputPort< base::samples::Wrenches >& NDLComForceTorqueSensor::getStatusPort()
{
    return forceTorqueSensorTask.getConcreteProxy()->ft_values;
}
 
}