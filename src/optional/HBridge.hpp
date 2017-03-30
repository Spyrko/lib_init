#pragma once

#include <lib_init/Base.hpp>
#include "Canbus.hpp"

#include <hbridge/cbProxies/CommandWriter.hpp>
#include <hbridge/cbProxies/SensorReader.hpp>
#include <lib_init/JointDriver.hpp>

namespace init 
{
    
class HBridge : public JointDriver
{
    Canbus &canbus;
public:
    HBridge(const std::string& sensorReaderName, const std::string& commandWriterName, Canbus& canbus);
    virtual ~HBridge() {};    
    
    virtual void initProxies();
    virtual bool connect();
    DependentTask<hbridge::cbProxies::SensorReader> sensorReader;
    DependentTask<hbridge::cbProxies::CommandWriter> commandWriter;
    
    virtual cbProxies::InputPort< base::commands::Joints >& getCommandPort();
    virtual cbProxies::OutputPort< base::samples::Joints >& getStatusPort();
    
};
    
    
    
}