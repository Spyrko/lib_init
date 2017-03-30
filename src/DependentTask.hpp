#pragma once

#include <string>
#include <orocos_cpp/Deployment.hpp>
#include <boost/shared_ptr.hpp>
#include <orocos_callback_base/TaskProxy.hpp>

namespace init {

class Base;
    
class DependentTaskBase
{
protected:
    std::string taskName;
    std::string taskModel;
    boost::shared_ptr<orocos_cpp::Deployment> deployment;
    std::vector<std::string> config;

    cbProxies::TaskProxy *proxy;
public:
    DependentTaskBase(Base *parent, const std::string &taskName, const std::string &modelName);
    
    virtual ~DependentTaskBase();
    
    const std::string &getTaskName() const      //TODO hier ff. evtl. direkt auf Proxy arbeiten?
    {
        if(proxy) return proxy->getTaskName();
        return taskName;
    }

    const std::string &getModelName() const
    {
        if(proxy) return proxy->getModelName();
        return taskModel;
    }

    void setName(const std::string &newName)
    {
        if(proxy) proxy->setTaskName(newName);
        taskName = newName;
    }
    
    void setDeployment(const boost::shared_ptr<orocos_cpp::Deployment> &newDeployment);

    const boost::shared_ptr<orocos_cpp::Deployment> &getDeployment() const
    {
        return deployment;
    }
    
    const std::vector<std::string> &getConfig() const 
    {
        return config;
    }
    
    void setConfig(const std::vector<std::string> &configs);
    void setConfig(const std::string &config);
    void setConfig(const std::string &config, const std::string &config2);
    void setConfig(const std::string& config, const std::string& config2, const std::string& config3);

    
    virtual cbProxies::TaskProxy *getProxy();
    
};
    
template <class TASK>
class DependentTask : public DependentTaskBase
{
public:
    DependentTask(Base *parent, const std::string &taskName) : DependentTaskBase(parent, taskName, TASK::ModelName)
    {
    }
    
    virtual cbProxies::TaskProxy* getProxy()
    {
        if(!proxy)
            proxy = new TASK(taskName);
        
        return proxy;
    };
    
    TASK* getConcreteProxy()
    {
        if(!proxy)
            proxy = new TASK(taskName);
        
        return static_cast<TASK *>(proxy);
    };
    
    //TODO wo soll ich das cbi erstellen?
    
    
};
    
    
}