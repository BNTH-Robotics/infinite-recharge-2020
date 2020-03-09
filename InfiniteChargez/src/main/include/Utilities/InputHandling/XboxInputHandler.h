#ifndef YEET_XBOX_INPUT_HANDLER_H
#define YEET_XBOX_INPUT_HANDLER_H
#include "InputHandler.h"
#include "Pair2D.h"

#include <inttypes.h>
#include <string>
#include <frc/XboxController.h>
namespace utilities
{
class XboxInputHandler : public InputHandler
{
public:
    using joystick_t = utilities::Pair2D<double>;
    using bitmask_t = std::uint8_t;
    using button_t = std::uint8_t;
    using trigger_t = double;

private:
    static constexpr bitmask_t ButtonStateMask{1 << 0};
    static constexpr bitmask_t ButtonPressedMask{1 << 1};
    static constexpr bitmask_t ButtonReleasedMask{1 << 2};

public:
    snapshot_t getSnapshot();
    void operator=(frc::XboxController &XboxController);
    void operator=(const snapshot_t &snapshot);

    void setJoystickLeft(joystick_t &axis) { m_joystickLeft = axis; }
    joystick_t getJoystickLeft() { return m_joystickLeft; }

    void setJoystickRight(joystick_t &axis) { m_joystickRight = axis; }
    joystick_t getJoystickRight() { return m_joystickRight; }

    //Button Functions
    //Button A
    void setButtonAState(bool state) { (state) ? m_buttonA |= ButtonStateMask : m_buttonA &= ~ButtonStateMask; }
    bool getButtonAState() { return m_buttonA & ButtonStateMask; }

    void setButtonAPressed(bool state) { (state) ? m_buttonA |= ButtonPressedMask : m_buttonA &= ~ButtonPressedMask; }
    bool getButtonAPressed() { return m_buttonA & ButtonPressedMask; }

    void setButtonAReleased(bool state) { (state) ? m_buttonA |= ButtonReleasedMask : m_buttonA &= ~ButtonReleasedMask; }
    bool getButtonAReleased() { return m_buttonA & ButtonReleasedMask; }

    //ButtonB
    void setButtonBState(bool state) { (state) ? m_buttonB |= ButtonStateMask : m_buttonB &= ~ButtonStateMask; }
    bool getButtonBState() { return m_buttonB & ButtonStateMask; }

    void setButtonBPressed(bool state) { (state) ? m_buttonB |= ButtonPressedMask : m_buttonB &= ~ButtonPressedMask; }
    bool getButtonBPressed() { return m_buttonB & ButtonPressedMask; }

    void setButtonBReleased(bool state) { (state) ? m_buttonB |= ButtonReleasedMask : m_buttonB &= ~ButtonReleasedMask; }
    bool getButtonBReleased() { return m_buttonB & ButtonReleasedMask; }

    //ButtonX
    void setButtonXState(bool state) { (state) ? m_buttonX |= ButtonStateMask : m_buttonX &= ~ButtonStateMask; }
    bool getButtonXState() { return m_buttonX & ButtonStateMask; }

    void setButtonXPressed(bool state) { (state) ? m_buttonX |= ButtonPressedMask : m_buttonX &= ~ButtonPressedMask; }
    bool getButtonXPressed() { return m_buttonX & ButtonPressedMask; }

    void setButtonXReleased(bool state) { (state) ? m_buttonX |= ButtonReleasedMask : m_buttonX &= ~ButtonReleasedMask; }
    bool getButtonXReleased() { return m_buttonX & ButtonReleasedMask; }

    //ButtonY
    void setButtonYState(bool state) { (state) ? m_buttonY |= ButtonStateMask : m_buttonY &= ~ButtonStateMask; }
    bool getButtonYState() { return m_buttonY & ButtonStateMask; }

    void setButtonYPressed(bool state) { (state) ? m_buttonY |= ButtonPressedMask : m_buttonY &= ~ButtonPressedMask; }
    bool getButtonYPressed() { return m_buttonY & ButtonPressedMask; }

    void setButtonYReleased(bool state) { (state) ? m_buttonY |= ButtonReleasedMask : m_buttonY &= ~ButtonReleasedMask; }
    bool getButtonYReleased() { return m_buttonY & ButtonReleasedMask; }

    //Triggers
    void setTriggerLeft(double axis) { m_triggerLeft = axis; }
    double getTriggerLeft() { return m_triggerLeft; }

    void setTriggerRight(double axis) { m_triggerRight = axis; }
    double getTriggerRight() { return m_triggerRight; }

    //Bumpers
    //Left Bumper
    void setBumperLeftState(bool state) { (state) ? m_bumperLeft |= ButtonStateMask : m_bumperLeft &= ~ButtonStateMask; }
    bool getBumperLeftState() { return m_bumperLeft & ButtonStateMask; }

    void setBumperLeftPressed(bool state) { (state) ? m_bumperLeft |= ButtonPressedMask : m_bumperLeft &= ~ButtonPressedMask; }
    bool getBumperLeftPressed() { return m_bumperLeft & ButtonPressedMask; }

    void setBumperLeftReleased(bool state) { (state) ? m_bumperLeft |= ButtonReleasedMask : m_bumperLeft &= ~ButtonReleasedMask; }
    bool getBumperLeftReleased() { return m_bumperLeft & ButtonReleasedMask; }

    //Right Bumper
    void setBumperRightState(bool state) { (state) ? m_bumperRight |= ButtonStateMask : m_bumperRight &= ~ButtonStateMask; }
    bool getBumperRightState() { return m_bumperRight & ButtonStateMask; }

    void setBumperRightPressed(bool state) { (state) ? m_bumperRight |= ButtonPressedMask : m_bumperRight &= ~ButtonPressedMask; }
    bool getBumperRightPressed() { return m_bumperRight & ButtonPressedMask; }

    void setBumperRightReleased(bool state) { (state) ? m_bumperRight |= ButtonReleasedMask : m_bumperRight &= ~ButtonReleasedMask; }
    bool getBumperRightReleased() { return m_bumperRight & ButtonReleasedMask; }

    //StickButtons
    //Left Stick
    void setButtonLeftStickState(bool state) { (state) ? m_buttonLeftStick |= ButtonStateMask : m_buttonLeftStick &= ~ButtonStateMask; }
    bool getButtonLeftStickState() { return m_buttonLeftStick & ButtonStateMask; }

    void setButtonLeftStickPressed(bool state) { (state) ? m_buttonLeftStick |= ButtonPressedMask : m_buttonLeftStick &= ~ButtonPressedMask; }
    bool getButtonLeftStickPressed() { return m_buttonLeftStick & ButtonPressedMask; }

    void setButtonLeftStickReleased(bool state) { (state) ? m_buttonLeftStick |= ButtonReleasedMask : m_buttonLeftStick &= ~ButtonReleasedMask; }
    bool getButtonLeftStickReleased() { return m_buttonLeftStick & ButtonReleasedMask; }
    //Right Stick
    void setButtonRightStickState(bool state) { (state) ? m_buttonRightStick |= ButtonStateMask : m_buttonRightStick &= ~ButtonStateMask; }
    bool getButtonRightStickState() { return m_buttonRightStick & ButtonStateMask; }

    void setButtonRightStickPressed(bool state) { (state) ? m_buttonRightStick |= ButtonPressedMask : m_buttonRightStick &= ~ButtonPressedMask; }
    bool getButtonRightStickPressed() { return m_buttonRightStick & ButtonPressedMask; }

    void setButtonRightStickReleased(bool state) { (state) ? m_buttonRightStick |= ButtonReleasedMask : m_buttonRightStick &= ~ButtonReleasedMask; }
    bool getButtonRightStickReleased() { return m_buttonRightStick & ButtonReleasedMask; }

    //Back and Start Button
    //Back Button
    void setButtonBackState(bool state) { (state) ? m_buttonBack |= ButtonStateMask : m_buttonBack &= ~ButtonStateMask; }
    bool getButtonBackState() { return m_buttonBack & ButtonStateMask; }

    void setButtonBackPressed(bool state) { (state) ? m_buttonBack |= ButtonPressedMask : m_buttonBack &= ~ButtonPressedMask; }
    bool getButtonBackPressed() { return m_buttonBack & ButtonPressedMask; }

    void setButtonBackReleased(bool state) { (state) ? m_buttonBack |= ButtonReleasedMask : m_buttonBack &= ~ButtonReleasedMask; }
    bool getButtonBackReleased() { return m_buttonBack & ButtonReleasedMask; }
    //Start
    void setButtonStartState(bool state) { (state) ? m_buttonStart |= ButtonStateMask : m_buttonStart &= ~ButtonStateMask; }
    bool getButtonStartState() { return m_buttonStart & ButtonStateMask; }

    void setButtonStartPressed(bool state) { (state) ? m_buttonStart |= ButtonPressedMask : m_buttonStart &= ~ButtonPressedMask; }
    bool getButtonStartPressed() { return m_buttonStart & ButtonPressedMask; }

    void setButtonStartReleased(bool state) { (state) ? m_buttonStart |= ButtonReleasedMask : m_buttonStart &= ~ButtonReleasedMask; }
    bool getButtonStartReleased() { return m_buttonStart & ButtonReleasedMask; }

private:
    joystick_t m_joystickLeft{0, 0};
    joystick_t m_joystickRight{0, 0};

    button_t m_buttonA{0};
    button_t m_buttonB{0};
    button_t m_buttonX{0};
    button_t m_buttonY{0};

    trigger_t m_triggerLeft{0};
    trigger_t m_triggerRight{0};

    button_t m_bumperLeft{0};
    button_t m_bumperRight{0};

    button_t m_buttonLeftStick{0};
    button_t m_buttonRightStick{0};

    button_t m_buttonBack{0};
    button_t m_buttonStart{0};
};
} // namespace utilities
#endif
