#include "XboxInputHandler.h"
#include "Utilities.h"

#include <string>
#include <frc/XboxController.h>
namespace utilities
{
    void XboxInputHandler::operator=(frc::XboxController &XBoxController)
    {
        joystick_t joystickLeft{XBoxController.GetX(frc::GenericHID::JoystickHand::kLeftHand), 
            XBoxController.GetY(frc::GenericHID::kLeftHand)};
        
        joystick_t joystickRight{XBoxController.GetX(frc::GenericHID::JoystickHand::kRightHand), 
            XBoxController.GetY(frc::GenericHID::kRightHand)};
        //Joystick
        setJoystickLeft(joystickLeft);

        setJoystickRight(joystickRight);
        
        //Button Functions
        //Button A
        setButtonAState(XBoxController.GetAButton());
        setButtonAPressed(XBoxController.GetAButtonPressed());
        setButtonAReleased(XBoxController.GetAButtonReleased());
        //Button B
        setButtonBState(XBoxController.GetBButton());
        setButtonBPressed(XBoxController.GetBButtonPressed());
        setButtonBReleased(XBoxController.GetBButtonReleased());
        //Button X
        setButtonXState(XBoxController.GetXButton());
        setButtonXPressed(XBoxController.GetXButtonPressed());
        setButtonXReleased(XBoxController.GetXButtonReleased());
        //Button Y
        setButtonYState(XBoxController.GetYButton());
        setButtonYPressed(XBoxController.GetYButtonPressed());
        setButtonYReleased(XBoxController.GetYButtonReleased());

        //Triggers
        //Triger Left
        setTriggerLeft(XBoxController.GetTriggerAxis(frc::GenericHID::kLeftHand));
        //Trigger Right
        setTriggerRight(XBoxController.GetTriggerAxis(frc::GenericHID::kRightHand));

        //Bumper
        //Bumper Left
        setBumperLeftState(XBoxController.GetBumper(frc::GenericHID::kLeftHand));
        setBumperLeftPressed(XBoxController.GetBumperPressed(frc::GenericHID::kLeftHand));
        setBumperLeftReleased(XBoxController.GetBumperReleased(frc::GenericHID::kLeftHand));
        //Bumper Right
        setBumperRightState(XBoxController.GetBumper(frc::GenericHID::kRightHand));
        setBumperRightPressed(XBoxController.GetBumperPressed(frc::GenericHID::kRightHand));
        setBumperRightReleased(XBoxController.GetBumperReleased(frc::GenericHID::kRightHand));

        //Stick Buttons
        //Left Stick Button
        setButtonLeftStickState(XBoxController.GetStickButton(frc::GenericHID::kLeftHand));
        setButtonLeftStickPressed(XBoxController.GetStickButtonPressed(frc::GenericHID::kLeftHand));
        setButtonLeftStickReleased(XBoxController.GetStickButtonReleased(frc::GenericHID::kLeftHand));
        //Right Stick Button
        setButtonRightStickState(XBoxController.GetStickButton(frc::GenericHID::kRightHand));
        setButtonRightStickPressed(XBoxController.GetStickButtonPressed(frc::GenericHID::kRightHand));
        setButtonRightStickReleased(XBoxController.GetStickButtonReleased(frc::GenericHID::kRightHand));

        //Back and Start button
        //Back Button
        setButtonBackState(XBoxController.GetBackButton());
        setButtonBackPressed(XBoxController.GetBackButtonPressed());
        setButtonBackReleased(XBoxController.GetBackButtonReleased());
        //Start Button
        setButtonStartState(XBoxController.GetStartButton());
        setButtonStartPressed(XBoxController.GetStartButtonPressed());
        setButtonStartReleased(XBoxController.GetStartButtonReleased());
    }

    XboxInputHandler::snapshot_t XboxInputHandler::getSnapshot()
    {
        constexpr char pad{' '};
        snapshot_t snapshot{""};
        //Joystick
        //Left Joystick
        snapshot += std::to_string(getJoystickLeft().x) + pad;
        snapshot += std::to_string(getJoystickLeft().y) + pad;

        //Left Joystick

        snapshot += std::to_string(getJoystickRight().x) + pad;
        snapshot += std::to_string(getJoystickRight().y) + pad;

        //Button Functions
        //Button A
        snapshot += std::to_string(getButtonAState()) + pad;
        snapshot += std::to_string(getButtonAPressed()) + pad;
        snapshot += std::to_string(getButtonAReleased()) + pad;
        //Button B
        snapshot += std::to_string(getButtonBState()) + pad;
        snapshot += std::to_string(getButtonBPressed()) + pad;
        snapshot += std::to_string(getButtonBReleased()) + pad;
        //Button X
        snapshot += std::to_string(getButtonXState()) + pad;
        snapshot += std::to_string(getButtonXPressed()) + pad;
        snapshot += std::to_string(getButtonXReleased()) + pad;
        //Button Y
        snapshot += std::to_string(getButtonYState()) + pad;
        snapshot += std::to_string(getButtonYPressed()) + pad;
        snapshot += std::to_string(getButtonYReleased()) + pad;

        //Triggers
        //Triger Left
        snapshot += std::to_string(getTriggerLeft()) + pad;
        //Trigger Right
        snapshot += std::to_string(getTriggerRight()) + pad;

        //Bumper
        //Bumper Left
        snapshot += std::to_string(getBumperLeftState()) + pad;
        snapshot += std::to_string(getBumperLeftPressed()) + pad;
        snapshot += std::to_string(getBumperLeftReleased()) + pad;
        //Bumper Right
        snapshot += std::to_string(getBumperRightState()) + pad;
        snapshot += std::to_string(getBumperRightPressed()) + pad;
        snapshot += std::to_string(getBumperRightReleased()) + pad;

        //Stick Buttons
        //Left Stick Button
       snapshot += std::to_string(getButtonLeftStickState()) + pad;
       snapshot += std::to_string(getButtonLeftStickPressed()) + pad;
       snapshot += std::to_string(getButtonLeftStickReleased()) + pad;

        //Right Stick Button
        snapshot += std::to_string(getButtonRightStickState()) + pad;
        snapshot += std::to_string(getButtonRightStickPressed()) + pad;
        snapshot += std::to_string(getButtonRightStickReleased()) + pad;

        //Back and Start button
        //Start Button
        snapshot += std::to_string(getButtonStartState()) + pad;
        snapshot += std::to_string(getButtonStartPressed()) + pad;
        snapshot += std::to_string(getButtonStartReleased()) + pad;
        //Back Button
        snapshot += std::to_string(getButtonBackState()) + pad;
        snapshot += std::to_string(getButtonBackPressed()) + pad;
        snapshot += std::to_string(getButtonBackReleased()) + pad;
        return snapshot;
    }

    void XboxInputHandler::operator=(const snapshot_t &snapshot)
    {
        std::size_t i{0};
        //Joystick
        joystick_t joystickLeft{utilities::parseSSV<double>(snapshot, i), utilities::parseSSV<double>(snapshot, i)};
        joystick_t joystickRight{utilities::parseSSV<double>(snapshot, i), utilities::parseSSV<double>(snapshot, i)};
        //std::cout << getJoystickLeft().y;

        setJoystickLeft(joystickLeft);

        setJoystickRight(joystickRight);
        
        //Button Functions
        //Button A
        setButtonAState(utilities::parseSSV<int>(snapshot, i));
        setButtonAPressed(utilities::parseSSV<int>(snapshot, i));
        setButtonAReleased(utilities::parseSSV<int>(snapshot, i));
        //Button B
        setButtonBState(utilities::parseSSV<int>(snapshot, i));
        setButtonBPressed(utilities::parseSSV<int>(snapshot, i));
        setButtonBReleased(utilities::parseSSV<int>(snapshot, i));
        //Button X
        setButtonXState(utilities::parseSSV<int>(snapshot, i));
        setButtonXPressed(utilities::parseSSV<int>(snapshot, i));
        setButtonXReleased(utilities::parseSSV<int>(snapshot, i));
        //Button Y
        setButtonYState(utilities::parseSSV<int>(snapshot, i));
        setButtonYPressed(utilities::parseSSV<int>(snapshot, i));
        setButtonYReleased(utilities::parseSSV<int>(snapshot, i));

        //Triggers
        //Triger Left
        setTriggerLeft(utilities::parseSSV<double>(snapshot, i));
        //Trigger Right
        setTriggerRight(utilities::parseSSV<double>(snapshot, i));

        //Bumper
        //Bumper Left
        setBumperLeftState(utilities::parseSSV<int>(snapshot, i));
        setBumperLeftPressed(utilities::parseSSV<int>(snapshot, i));
        setBumperLeftReleased(utilities::parseSSV<int>(snapshot, i));
        //Bumper Right
        setBumperRightState(utilities::parseSSV<int>(snapshot, i));
        setBumperRightPressed(utilities::parseSSV<int>(snapshot, i));
        setBumperRightReleased(utilities::parseSSV<int>(snapshot, i));

        //Stick Buttons
        //Left Stick Button
        setButtonLeftStickState(utilities::parseSSV<int>(snapshot, i));
        setButtonLeftStickPressed(utilities::parseSSV<int>(snapshot, i));
        setButtonLeftStickReleased(utilities::parseSSV<int>(snapshot, i));
        //Right Stick Button
        setButtonRightStickState(utilities::parseSSV<int>(snapshot, i));
        setButtonRightStickPressed(utilities::parseSSV<int>(snapshot, i));
        setButtonRightStickReleased(utilities::parseSSV<int>(snapshot, i));

        //Back and Start button
        //Start Button
        setButtonStartState(utilities::parseSSV<int>(snapshot, i));
        setButtonStartPressed(utilities::parseSSV<int>(snapshot, i));
        setButtonStartReleased(utilities::parseSSV<int>(snapshot, i));
        //Back Button
        setButtonBackState(utilities::parseSSV<int>(snapshot, i));
        setButtonBackPressed(utilities::parseSSV<int>(snapshot, i));
        setButtonBackReleased(utilities::parseSSV<int>(snapshot, i));
    }
}
