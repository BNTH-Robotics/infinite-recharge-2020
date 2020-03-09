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
void Robot::OdometryTests()
{
  //std::cout << "Built Int Acceleration X: " << leAccelerometer.GetX() << " Y: " << leAccelerometer.GetY() << '\n';
  //std::cout << "Acceleration X: " << leGyroscope.GetAccelInstantX() << " Y: " << leGyroscope.GetAccelInstantY() << '\n';
  //std::cout << "Z heading: " << leGyroscope.GetGyroAngleZ() << '\n';
  //std::cout << leDifferentialOdometer.GetPose().Translation().X() << '\n';
}

Robot::Robot() : frc::TimedRobot{10_ms} 
                 
{
  hookMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  tankMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
  
}

void Robot::RobotInit()
{
  //leStorage.startHandler();
  m_chooser.SetDefaultOption("Emergency-Forward and Stop", "Emergency");
  m_chooser.AddOption("1-DumpAndYeet", "R1-DumpAndYeet.rcd");
  m_chooser.AddOption("2-DumpAndYeet", "R2-DumpAndYeet.rcd");
  m_chooser.AddOption("3-DumpAndYeet", "R3-DumpAndYeet.rcd");

  m_chooser.AddOption("1-CrossTheLine", "R1-CrossTheLine.rcd");
  m_chooser.AddOption("2-CrossTheLine", "R2-CrossTheLine.rcd");
  m_chooser.AddOption("3-CrossTheLine", "R3-CrossTheLine.rcd");
  m_chooser.AddOption("Emergency-Forward and Stop", "Emergency");

  //m_chooser.AddOption("R1", "R1.rcd");
  //m_chooser.AddOption("R2", "R2.rcd");
  //m_chooser.AddOption("R3", "R3.rcd");
  //m_chooser.AddOption("B1", "B1.rcd");
  //m_chooser.AddOption("B2", "B2.rcd");
  //m_chooser.AddOption("B3", "B3.rcd");
  driveMotorsLeft.SetInverted(true);
  driveMotorsRight.SetInverted(true);








  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic()
{
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit()
{
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
  if (m_recordFile.is_open())
  {
    std::cout << "Closed Open File \n";
    m_recordFile.close();
  }
  m_recordReadFile.clear();
  m_recordReadFile.open(inputRecordFileName + m_chooser.GetSelected());
  m_recordReadFile.seekg(0, std::ios::beg);
  assert(m_recordReadFile.is_open());

  m_leRecordScribe.loadRecording(m_recordReadFile);
  m_leRecordScribe.playLoadedRecordingToAndExec(this);

  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  //std::cout << "Auto selected: " << m_autoSelected << std::endl;

  //if (m_autoSelected == kAutoNameCustom)
  //{
  //  // Custom Auto goes here
  //}
  //else
  //{
  //  // Default Auto goes here
  //}
  }
}

void Robot::AutonomousPeriodic()
{
  if (m_autoSelected == kAutoNameCustom)
  {
    // Custom Auto goes here
  }
  else
  {
    // Default Auto goes here
  }
}

void Robot::TeleopInit()
{
  
  leRoboData.initSnap();
}

void Robot::TeleopPeriodic()
{
  duration_t delta = leRoboData.calcAndGetTimeDelta();

  leRoboData.updatePos(delta);
  OdometryTests();
  checkAndExec();

  leInputHandler = leController;

  recordActionsExec(leInputHandler, delta);
}

void Robot::TestPeriodic()
{
  OdometryTests();
}


#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
