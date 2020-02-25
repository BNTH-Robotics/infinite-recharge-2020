#ifndef YEET_ROBOT_HOOK_H
#define YEET_ROBOT_HOOK_H
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

#include <frc/SpeedController.h>

class RoboHook
{
using controller_t = frc::SpeedController;
public:
    RoboHook(controller_t &hookMotor):
        m_hookMotor{&hookMotor} {}
    //setHookHeight
    void Up();
    void Down();
    void Stop();
private:
    controller_t *m_hookMotor;

    static constexpr double hookUpSpeed{1.0};
    static constexpr double hookDownSpeed{-1.0};
};
#endif