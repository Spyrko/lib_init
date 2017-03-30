#pragma once

#include <lib_init/Base.hpp>

#include <orocos_callback_base/Port.hpp>
#include <canbus/cbProxies/Task.hpp>

namespace canbus {
    class Message;
}


namespace init 
{
    
struct CanbusWatch
{
    std::string name;
    int id;
    int mask;
};
    
class Canbus : public Base
{
    std::map<std::string, cbProxies::OutputPort<::canbus::Message >*> outputs;
    std::vector<CanbusWatch> watches;
public:
    Canbus(const std::string& canbusName);
    virtual ~Canbus() {};
    
    virtual void initProxies();
    virtual bool configure();
    
    bool watch(const std::string& name, int id, int mask);
    cbProxies::InputPort<canbus::Message> &getMsgInPort();
    cbProxies::OutputPort<canbus::Message> &getMsgOutPort(const std::string& watchedName);
    DependentTask<canbus::cbProxies::Task> canbus;
};
    
    
}
