#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/DependentTask.hpp>
#include <ugv_nav4d/proxies/Task.hpp>
#include "MLSProvider.hpp"

namespace init 
{

class UGVNav4d : public Base
{
    MLSProvider &mlsprovider;
public:
    UGVNav4d(MLSProvider &mlsprovider, const std::string& taskName);
    virtual ~UGVNav4d();
    
    virtual bool connect();
    
    DependentTask<ugv_nav4d::proxies::Task> planner;
};

}
