#include "CommonStart.hpp"

#include <iostream>

#include <state_machine/StateMachine.hpp>
#include <state_machine/Config.hpp>

#include "states/Init.hpp"
#include "Container.hpp"

#include <lib_config/Bundle.hpp>

#include <rtt/typekit/RealTimeTypekit.hpp>
#include <rtt/transports/corba/TransportPlugin.hpp>
#include <rtt/transports/corba/TaskContextServer.hpp>
#include <rtt/transports/mqueue/TransportPlugin.hpp>
#include <QApplication>
#include <state_machine/StateMachineWidget.hpp>
#include <smurf/Robot.hpp>
#include <orocos_cpp_base/OrocosHelpers.hpp>
#include <orocos_cpp/PluginHelper.hpp>
#include <orocos_callback_base/AttributeConverter.hpp>
#include <orocos_callback_base/Port.hpp>

StartCommon::StartCommon(int argc, char** argv)
{
    RTT::corba::TaskContextServer::InitOrb(argc, argv);
    
    OrocosHelpers::initClientTask("taskManagement");
    
    orocos_cpp::PluginHelper::loadTypekitAndTransports("state_machine_tk");
        
    loggingActive = false;
    simulationActive = false;

    for (int i = 0; i<argc; i++)
    {
        if(strcmp(argv[i], "sim") == 0)
        {
            simulationActive = true;
            std::cout << "Simulation enabled" << std::endl;
        }

        if(strcmp(argv[i], "log") == 0)
        {
            loggingActive = true;
            std::cout << "Logging enabled" << std::endl;
        }
    }


    if(simulationActive)
    {
        std::cout << "Created App" << std::endl;
        
        app = new QApplication(argc, argv);
    
        widget = new StateMachineWidget();
        widget->show();
        widget->resize(800,600);
    }
    
    //FIXME, we should not need this to be hardcoded here !!!
    RTT::types::TypekitRepository::Import(new RTT::types::RealTimeTypekitPlugin);
    RTT::types::TypekitRepository::Import(new RTT::corba::CorbaLibPlugin);
    RTT::types::TypekitRepository::Import(new RTT::mqueue::MQLibPlugin);

//     state_machine::Config *config = &(state_machine::Config::getConfig(libConfig::Bundle::getInstance().getConfigurationDirectory() + "../taskmanagement.yml"));
}

void StartCommon::setLoggingExcludes(const std::vector< std::string >& excludeList)
{
    logExcludeList = excludeList;
}

int StartCommon::runCommon(state_machine::State *initialState, const std::vector< init::Base* >& toInit, cbProxies::CallbackInterface *cbi)
{
    init::Container all(toInit); 
    
    //various init transitions
    Init initializer(*transformerHelper, *configHelper, all, initialState);
    
    if(cbi)
        initializer.setCallbackInterface(cbi);
    
    cbi = initializer.getCallbackInterface();

    state_machine::StateMachine &stateMachine(state_machine::StateMachine::getInstance());

    RTT::TaskContext *clientTask = OrocosHelpers::getClientTask();
    cbProxies::OutputPort<state_machine::serialization::Event> *eventPort = cbProxies::AttributeConverter::getNewOutputPort<state_machine::serialization::Event>(cbi, "stateMachine_Events", "state_machine/serialization/Event", false);
    cbProxies::OutputPort<state_machine::serialization::StateMachine> *dumpPort = cbProxies::AttributeConverter::getNewOutputPort<state_machine::serialization::StateMachine>(cbi, "stateMachine_Dump", "state_machine/serialization/StateMachine", false);

    state_machine::serialization::StateMachine smDump(stateMachine);

//     if(simulationActive)
//     {
//         
//         widget->update(smDump);
//         widget->repaint();
//         app->processEvents();
//     }    

    int cnt = 0;
    
    stateMachine.setExecuteCallback([&](){
        
        if(cnt >= 10)
        {
            cnt = 0;
            
            dumpPort->write(smDump);
        }
        
        cnt++;

        //Events for state_machine visualisation + state_machine
        std::vector<state_machine::serialization::Event> newEvents = stateMachine.getNewEvents();
        for(auto e: newEvents)
        {
            eventPort->write(e);
            
//             if(simulationActive)
//             {
//                 //update widget
//                 widget->update(e);
//                 widget->repaint();
//             }
        }
        
//         if(simulationActive)
//         {
//             app->processEvents();
//         }
        
        std::string debugMsgs = stateMachine.getDebugStream().str();
        stateMachine.getDebugStream().str(std::string());

        if(!debugMsgs.empty())
        {
            std::cout << debugMsgs;
        }
    }
    );

    if(loggingActive)
    {
        initializer.activateLogging(logExcludeList);
    }
        
    stateMachine.start(&initializer);

    while (!stateMachine.execute())
    {
    }

    return 0;

}

smurf::Robot* StartCommon::getDefaultRobot()
{
    robot = new smurf::Robot;
    std::string smurfPath(libConfig::Bundle::getInstance().getConfigurationDirectory() + state_machine::Config::getConfig().getValue("robotSmurf"));
    std::cout << "Loading Smurf " << smurfPath << std::endl;
    robot->loadFromSmurf(smurfPath);
    
    return robot;
}


void StartCommon::startCommon(smurf::Robot *robot)
{
    this->robot = robot;

    transformerHelper = new orocos_cpp::TransformerHelper(*robot);
    configHelper = new cbProxies::ConfigurationHelper();
}



