
optional_init(ndlcom_force_torque_sensor-cbProxies 
    SOURCES
        NDLComForceTorqueSensor.cpp
    HEADERS
        NDLComForceTorqueSensor.hpp
)

optional_init(hbridge-cbProxies 
    SOURCES
        HBridge.cpp    
    HEADERS
        HBridge.hpp    
)

optional_init(camera_usb-cbProxies
    SOURCES
        UsbCameraDriver.cpp
    HEADERS
        UsbCameraDriver.hpp
)

optional_init(canbus-cbProxies 
    SOURCES
        Canbus.cpp    
    HEADERS
        Canbus.hpp
)

optional_init(envire_maps    
    HEADERS
        MLSProvider.hpp
)

optional_init(imu_xsens-cbProxies
    SOURCES
        IMUXsensDriver.cpp
    HEADERS
        IMUXsensDriver.hpp
)

optional_init(robot_frames-cbProxies
    SOURCES
        RobotFrames.cpp
    HEADERS
        RobotFrames.hpp
)

optional_init(mars-cbProxies
    SOURCES
        SimCameraDriver.cpp
        SimForceTorqueSensor.cpp
        SimIMUDriver.cpp
        SimJointDriver.cpp
        SimLaserDriver.cpp
        Simulator.cpp
        SimVelodyneDriver.cpp
    HEADERS
        SimCameraDriver.hpp
        SimForceTorqueSensor.hpp
        SimIMUDriver.hpp
        SimJointDriver.hpp
        SimLaserDriver.hpp
        Simulator.hpp
        SimVelodyneDriver.hpp
)

optional_init(odometry-cbProxies
    SOURCES
        SkidOdometry.cpp
        LateralOdometry.cpp
        ContactPointOdometry.cpp
    HEADERS
        BodyContactsProvider.hpp
        SkidOdometry.hpp
        LateralOdometry.hpp
        ContactPointOdometry.hpp
)

optional_init(velodyne_lidar-cbProxies
    SOURCES
        VelodyneDriver.cpp
    HEADERS
        VelodyneDriver.hpp
)

optional_init(ndlcom_device_driver-cbProxies
    SOURCES
        NDLComJointDriver.cpp
    HEADERS
        NDLComJointDriver.hpp
)


optional_init(serial_ndlcom-cbProxies
    SOURCES
        NDLComSerial.cpp
    HEADERS
        NDLComSerial.hpp
)

optional_init(manipulator_motion_planner-cbProxies
    SOURCES
        ArmPlannerCartesianSpace.cpp
        ArmPlannerJointSpace.cpp
    HEADERS
        ArmPlanner.hpp
        ArmPlannerCartesianSpace.hpp
        ArmPlannerJointSpace.hpp
)

optional_init(tilt_scan-cbProxies
    SOURCES
        TiltScan.cpp
    HEADERS
        TiltScan.hpp
)

optional_init(projection-cbProxies
    SOURCES
        ColorizedPointcloud.cpp
    HEADERS
        ColorizedPointcloud.hpp
)


optional_init(hokuyo-cbProxies
    SOURCES
        HokuyoLaserDriver.cpp
    HEADERS
        HokuyoLaserDriver.hpp
)

optional_init(laser_filter-cbProxies)

optional_init(graph_slam-cbProxies
    SOURCES
        VelodyneSlam.cpp
    HEADERS
        VelodyneSlam.hpp
)

optional_init(trajectory_follower-cbProxies
    SOURCES
        TrajectoryFollower.cpp
    HEADERS
        TrajectoryFollower.hpp
)

optional_init(servo_dynamixel-cbProxies
    SOURCES
        Dynamixel.cpp
    HEADERS
        Dynamixel.hpp
)

optional_init(ugv_nav4d-cbProxies 
    SOURCES
        UGVNav4d.cpp    
    HEADERS
        UGVNav4d.hpp    
)

optional_init(motion_planning_libraries-cbProxies
    SOURCES
        MotionPlanner.cpp
    HEADERS
        MotionPlanner.hpp
)

optional_init(localization-cbProxies)

optional_init(simple_pose_integrator-cbProxies
    SOURCES
        PoseProvider.cpp
    HEADERS
        PoseProvider.hpp
)

optional_init(traversability-cbProxies
    SOURCES
        TraversabilitySimple.cpp
    HEADERS
        TraversabilitySimple.hpp
)

optional_init(wbc-cbProxies
    SOURCES
        WholeBodyControl.cpp
    HEADERS
        WholeBodyControl.hpp
)
optional_init(kccd-cbProxies)

optional_init(ctrl_lib-cbProxies)

optional_init(waypoint_provider-cbProxies)

optional_init(trajectory_generation-cbProxies
    SOURCES
        TrajectoryGeneration.cpp
        TrajectoryGenerationVelocity.cpp
    HEADERS
        TrajectoryGeneration.hpp
        TrajectoryGenerationVelocity.hpp
)

optional_init(ndlcom_aila_joints-cbProxies
    SOURCES
        AILAJointDriver.cpp
    HEADERS
        AILAJointDriver.hpp
)

optional_init(slam3d-cbProxies
    SOURCES
        Slam3d.cpp
    HEADERS
        Slam3d.hpp
)

optional_init(depth_map_preprocessing-cbProxies
    SOURCES
        DepthMapToPCLConverter.cpp
    HEADERS
        DepthMapToPCLConverter.hpp
)
