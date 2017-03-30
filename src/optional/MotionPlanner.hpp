#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/MotionPlannerProvider.hpp>
#include "PoseProvider.hpp"
#include <lib_init/TraversabilityMapProvider.hpp>

namespace motion_planning_libraries {
     namespace cbProxies {
         class Task;
     }
}

namespace init
{

class MotionPlanner : public MotionPlannerProvider {
    PoseProvider &poseProvider;
    TraversabilityMapProvider &travMapProvider;
    
public:
    DependentTask< motion_planning_libraries::cbProxies::Task > motionPlanningTask;
    MotionPlanner(PoseProvider &poseProvider, TraversabilityMapProvider &travMapProvider, const std::string &motionPlanningTaskName);
    virtual bool connect();
    virtual cbProxies::OutputPort< std::vector< base::Trajectory > >& getTrajectories();
};

}