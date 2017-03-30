#include "VelodyneDriver.hpp"


namespace init
{

VelodyneDriver::VelodyneDriver(const std::string &velodyneTaskName) : DepthMapProvider("VelodyneDriver"),
    velodyneTask(this, velodyneTaskName)
{

}

bool VelodyneDriver::connect()
{
    return init::DepthMapProvider::connect();
}


cbProxies::OutputPort< base::samples::DepthMap >& VelodyneDriver::getLaserScansPort()
{
    return getDepthMapPort();
}

cbProxies::OutputPort< base::samples::DepthMap >& VelodyneDriver::getDepthMapPort()
{
    return velodyneTask.getConcreteProxy()->laser_scans;
}

}
