#pragma once

#include <lib_init/ForceTorqueSensor.hpp>
#include "Simulator.hpp"
#include <mars/cbProxies/ForceTorque6DOF.hpp>
namespace init {

class SimForceTorqueSensor : public ForceTorqueSensor
{
    Simulator &sim;
public:
    SimForceTorqueSensor(Simulator &sim, const std::string& taskName);
    virtual cbProxies::OutputPort< base::samples::Wrenches >& getStatusPort();

    DependentTask<mars::cbProxies::ForceTorque6DOF> sensorTask;
};

}
