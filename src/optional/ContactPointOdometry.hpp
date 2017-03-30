#pragma once

#include <lib_init/PositionProvider.hpp>
#include <odometry/cbProxies/ContactPointTask.hpp>
#include "BodyContactsProvider.hpp"
#include <lib_init/IMUDriver.hpp>

namespace init
{

class ContactPointOdometry : public PositionProvider
{
    BodyContactsProvider &bodyContacts;
    IMUDriver &imu;
public:
    ContactPointOdometry(const std::string &odometryName, BodyContactsProvider &bodyContacts, IMUDriver &imu);
    virtual ~ContactPointOdometry();
    virtual bool connect();
    DependentTask<odometry::cbProxies::ContactPointTask> contactPointOdometry;
    
    virtual cbProxies::OutputPort< base::samples::RigidBodyState >& getPositionSamples();
};

}

