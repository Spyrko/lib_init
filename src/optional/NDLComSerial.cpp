#include "NDLComSerial.hpp"
#include <serial_ndlcom/cbProxies/Task.hpp>

namespace init 
{

NDLComSerial::NDLComSerial(const std::string &taskName) 
    : Base("NDLComSerial")
    , serial_ndlcom(this, taskName)
{

}
    
}
