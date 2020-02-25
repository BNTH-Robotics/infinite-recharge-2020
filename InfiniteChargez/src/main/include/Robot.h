/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef YEET_LE_MOST_AMAZING_ROBOT_IN_THE_WORLD
#define YEET_LE_MOST_AMAZING_ROBOT_IN_THE_WORLD
#include "XboxInputHandler.h"
#include "Pair2D.h"

#include "RoboData.h"
#include "RoboDrive.h"
#include "RoboHook.h"
#include "RoboStorage.h"

#include "InputRecordAndPlay.h"
#include "HandlesChecksAndExecs.h"

#include <adi/ADIS16448_IMU.h>

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

#include <frc/BuiltInAccelerometer.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Pose2d.h>
#include <frc/TimedRobot.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>


#include <fstream>
#include <string>

class Robot : public frc::TimedRobot, public utilities::HandlesChecksAndExecs
{
private:
  const std::string inputRecordFileName{"/home/lvuser/InputRecord.rcd"};
  std::ofstream m_recordFile{};
  std::ifstream m_recordReadFile{};
  bool tankMode{false};
  //Configuration constants will go here until a configuration system can be set up
  using driveMotor_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;
  using intakeMotor_t = driveMotor_t;
  using storageMotor_t = driveMotor_t;
  using hookMotor_t = driveMotor_t;

  using gyroscope_t = frc::ADIS16448_IMU;

  using controller_t = frc::XboxController;
  //Automation Type Aliases
  using accelerometer_t = frc::BuiltInAccelerometer;

  //Chrono Alisases
  using clock_t = std::chrono::steady_clock;
  using timePoint_t = std::chrono::steady_clock::time_point;
  using duration_t = std::chrono::duration<double>;

  using handler_t = utilities::XboxInputHandler;
  private:
  //Ports for Motors and Controllers
private:
  static constexpr int controllerPort{0};
  static constexpr int leJoystickLeftPort{0};

  static constexpr int portDriveFrontLeft{1};
  static constexpr int portDriveFrontRight{3};
  static constexpr int portDriveBackLeft{2};
  static constexpr int portDriveBackRight{4};
  static constexpr int portIntakeLeft{5};
  static constexpr int portIntakeRight{6};
  static constexpr int portStorage{7};
  static constexpr int portHook{8};

public:
  Robot();
  void checkAndExec();
  void OdometryTests();
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;

  utilities::InputHandler& getInputHandler() {return leInputHandler;}
  private:
  bool isRecording{false}; //Really hacky, will remain until the deeper WPLIB api documentation can be discovered *Indiana Jones Music*
  bool recordingEnabled{true};
  long double meanDelta{0};

public:
  void TestPeriodic() override;
 private:
      //RobotDataPooints
    RoboData leRoboData{leGyroscope, leAccelerometer};
    RoboDrive leDrive{driveMotorsLeft, driveMotorsRight};
    RoboStorage leStorage{intakeMotorLeft, intakeMotorRight};
    RoboHook leHook{hookMotor};

     controller_t leController{controllerPort}; //Of epic dankness
     handler_t leInputHandler{};
  //Declare Motors
  driveMotor_t driveMotorFrontLeft{portDriveFrontLeft};
  driveMotor_t driveMotorFrontRight{portDriveFrontRight};
  driveMotor_t driveMotorBackLeft{portDriveBackLeft};
  driveMotor_t driveMotorBackRight{portDriveBackRight};

  intakeMotor_t intakeMotorLeft{portIntakeLeft};
  intakeMotor_t intakeMotorRight{portIntakeRight};

  storageMotor_t storageMotor{portStorage};

  hookMotor_t hookMotor{portHook};
  //Non-motor components
  gyroscope_t leGyroscope{};
  accelerometer_t leAccelerometer{};

  //Declare Motor Groups
    frc::SpeedControllerGroup driveMotorsLeft{driveMotorFrontLeft, driveMotorBackLeft};
    frc::SpeedControllerGroup driveMotorsRight{driveMotorFrontRight, driveMotorBackRight};

    //Recording Utilities
    utilities::InputRecordAndPlay m_leRecordScribe{};
    void recordActionsExec(utilities::XboxInputHandler &leInputHandler);

    //Input checking funcitons
    void recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta);
    void joystickPosition(utilities::XboxInputHandler::joystick_t &&joystickLeft, utilities::XboxInputHandler::joystick_t &&joystickRight);
    void buttonA();
    void buttonB();
    void buttonX();
    void buttonY();
    void bumper();  
    //Movement Functions
    void intakeIn();
    void intakeOut();
    void intakeStop();
  //Declare Time Variables
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Yeeter McYeeterson";
  const std::string kAutoNameCustom = "Yeeter McYeeterson";
  std::string m_autoSelected;
};
#endif
