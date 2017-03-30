#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <serial_ndlcom/cbProxies/Task.hpp>

namespace init
{

class NDLComSerial : public Base
{
public:
    NDLComSerial(const std::string &taskName);
    
    DependentTask<serial_ndlcom::cbProxies::Task> serial_ndlcom;
    
};

}
