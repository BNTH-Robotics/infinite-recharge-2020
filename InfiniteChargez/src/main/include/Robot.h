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
		using handler_t = utilities::XboxInputHandler;

		using driveMotor_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;
		using intakeMotor_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;
		using storageMotor_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;
		using hookMotor_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;

		using controller_t = frc::XboxController;

		using accelerometer_t = frc::BuiltInAccelerometer;
		using gyroscope_t = frc::ADIS16448_IMU;

		using clock_t = std::chrono::steady_clock;
		using timePoint_t = std::chrono::steady_clock::time_point;
		using duration_t = std::chrono::duration<double>;

	private:
		static constexpr int controllerPort{0};
		static constexpr int leJoystickLeftPort{0};

		static constexpr int portDriveFrontLeft{1};
		static constexpr int portDriveFrontRight{3};
		static constexpr int portDriveBackLeft{2};
		static constexpr int portDriveBackRight{4};
		static constexpr int portIntake{5};
		static constexpr int portTank{7};
		static constexpr int portHook{8};

	public:
		Robot();
		/**
		 * Controls robot's motor depending on the state of it's input handler
		 * i.e. basic input checking code
		 */
		void checkAndExec();
		void OdometryTests();
		/**
		 * First function called after the Robot code boots
		 */
		void RobotInit() override;
		/**
		 * This function is called every robot packet, no matter the mode. Use
		 * this for items like diagnostics that you want ran during disabled,
		 * autonomous, teleoperated and test.
		 *
		 * This runs after the mode specific periodic functions, but before
		 * LiveWindow and SmartDashboard integrated updating.
		 */
		void RobotPeriodic() override;
		/**
		 * First function run when autonomous is enabled
		 */
		void AutonomousInit() override;
		/**
		 * Called at regular intervals when autonomous is enabled. Stops being called
		 * when teleop is disabled. The interval is set in the Robot's constructor function.
		 */
		void AutonomousPeriodic() override;
		/**
		 * First function called when teleop is enabled
		 */
		void TeleopInit() override;
		/**
		 * Called at regular intervals when teleop is enabled. Stops being called
		 * when teleop is disabled. The interval is set in the Robot's constructor function
		 */
		void TeleopPeriodic() override;
		/**
		 * Called at regular intervals when test mode is enabled. Stops being called
		 * when teleop is disabled. The interval is set in the Robot's constructor function
		 */
		void TestPeriodic() override;

		//Accessor function
		utilities::InputHandler& getInputHandler() {return leInputHandler;}
	private:
		//These component classes represent distinct parts of the Robot.
		RoboData leRoboData{leGyroscope, leAccelerometer};
		RoboDrive leDrive{driveMotorsLeft, driveMotorsRight};
		RoboStorage leStorage{intakeMotor, tankMotor};
		RoboHook leHook{hookMotor};

		//Hardware Stuff
		controller_t leController{controllerPort}; //Of epic dankness
		handler_t leInputHandler{};
		driveMotor_t driveMotorFrontLeft{portDriveFrontLeft};
		driveMotor_t driveMotorFrontRight{portDriveFrontRight};
		driveMotor_t driveMotorBackLeft{portDriveBackLeft};
		driveMotor_t driveMotorBackRight{portDriveBackRight};

		intakeMotor_t intakeMotor{portIntake};

		storageMotor_t tankMotor{portTank};

		hookMotor_t hookMotor{portHook};
		gyroscope_t leGyroscope{};
		accelerometer_t leAccelerometer{};

		frc::SpeedControllerGroup driveMotorsLeft{driveMotorFrontLeft, driveMotorBackLeft};
		frc::SpeedControllerGroup driveMotorsRight{driveMotorFrontRight, driveMotorBackRight};

		utilities::InputRecordAndPlay m_leRecordScribe{};
		const std::string inputRecordFileName{"/home/lvuser/"};
		std::ofstream m_recordFile{};
		std::ifstream m_recordReadFile{};
		//Internal functions
		void recordActionsExec(utilities::XboxInputHandler &leInputHandler);
		void recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta);
		static constexpr double triggerIntakeTolerance{0.9};
		bool isRecording{false}; //Really hacky, will remain until the deeper WPLIB api documentation can be discovered *Indiana Jones Music*
		bool recordingEnabled{true};
		long double meanDelta{0};

		void recordingInit();
		void resetRecordingState();
		void recordControllerToFile();
		void flushRecordingToFile();

		void hookModeExec();
		void manualTankExec();
		void regularExec();

		duration_t getFrametime() {return m_frameTime;}


		duration_t m_frameTime;
		frc::SendableChooser<std::string> m_chooser;
		const std::string kAutoNameDefault = "R1-DumpAndYeet";
		const std::string kAutoNameCustom = "Yeeter McYeeterson";
		std::string m_autoSelected;
};
#endif
