/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "FileConstants.h"

#include <frc/BuiltInAccelerometer.h>
#include <frc/Filesystem.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <units/units.h>

#include <iostream>
#include <thread>

#include <cassert>

Robot::Robot() : frc::TimedRobot{10_ms}
{
    //Neutral Mode means the motor will give easily to external foces. Keeps the arm from flailing armound.
    hookMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    tankMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void Robot::RobotInit()
{
    //Adds buttons to a "Sendable Chooser" which can be used to display options
    //They represent recording files that can be chosen
    m_chooser.SetDefaultOption("Emergency-Forward and Stop", "Emergency");
    m_chooser.AddOption("1-DumpAndYeet", "R1-DumpAndYeet.rcd");
    m_chooser.AddOption("2-DumpAndYeet", "R2-DumpAndYeet.rcd");
    m_chooser.AddOption("3-DumpAndYeet", "R3-DumpAndYeet.rcd");

    m_chooser.AddOption("1-CrossTheLine", "R1-CrossTheLine.rcd");
    m_chooser.AddOption("2-CrossTheLine", "R2-CrossTheLine.rcd");
    m_chooser.AddOption("3-CrossTheLine", "R3-CrossTheLine.rcd");

    //Emergency Mode is hard-coded
    m_chooser.AddOption("Emergency-Forward and Stop", "Emergency");

    //Could be removed if the motor ports for the drive motors are switched
    driveMotorsLeft.SetInverted(true);
    driveMotorsRight.SetInverted(true);

    //Places the buttons the the Smart Dashboard
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

void Robot::RobotPeriodic()
{
}

void Robot::AutonomousInit()
{
    //Prevents multiple recordings being played simultaneously because that would be chaos
    m_leRecordScribe.stopLoadedRecording();
    std::string chosen{m_chooser.GetSelected()};
    if (chosen == "Emergency")
    {
        leDrive.setMovementMap(utilities::Pair2D<double>{0.5, 0.0});
        std::this_thread::sleep_for(std::chrono::seconds(1));
        leDrive.setMovementMap(utilities::Pair2D<double>{0.0, 0.0});
    }
    else
    {
        
        std::cout << m_chooser.GetSelected() << '\n';
        //Makes sure that no file is open because if a file is already open, the new recording will not load
        if (m_recordReadFile.is_open())
        {
            std::cout << "Closed Open File \n";
            m_recordReadFile.close();
        }
        m_recordReadFile.clear();
        m_recordReadFile.open(inputRecordFileName + m_chooser.GetSelected());
        m_recordReadFile.seekg(0, std::ios::beg);
        assert(m_recordReadFile.is_open());

        //Play recording
        m_leRecordScribe.loadRecording(m_recordReadFile);
        m_leRecordScribe.playLoadedRecordingToAndExec(this);

        m_autoSelected = m_chooser.GetSelected();
    }
}

void Robot::AutonomousPeriodic()
{
}

void Robot::TeleopInit()
{
    //Make sure no recording is playing during teleop as the controller and the playback thread would fight over the robot *spooky*
    m_leRecordScribe.stopLoadedRecording();
    leRoboData.initSnap();
}

void Robot::TeleopPeriodic()
{
    m_frameTime = leRoboData.calcAndGetTimeDelta();

    leRoboData.updatePos(m_frameTime);
    checkAndExec();

    leInputHandler = leController;

    recordActionsExec(leInputHandler, m_frameTime);
}

void Robot::TestPeriodic()
{
}

void Robot::OdometryTests()
{
    //std::cout << "Built Int Acceleration X: " << leAccelerometer.GetX() << " Y: " << leAccelerometer.GetY() << '\n';
    //std::cout << "Acceleration X: " << leGyroscope.GetAccelInstantX() << " Y: " << leGyroscope.GetAccelInstantY() << '\n';
    //std::cout << "Z heading: " << leGyroscope.GetGyroAngleZ() << '\n';
    //std::cout << leDifferentialOdometer.GetPose().Translation().X() << '\n';
}

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot>();
}
#endif
