#ifndef YEET_ROBOT_STORAGE_H
#define YEET_ROBOT_STORAGE_H

#include <frc/SpeedController.h>


class RoboStorage
{
public:
    RoboStorage(frc::SpeedController &intakeMotor, frc::SpeedController &tankMotor):
      m_intakeMotor{&intakeMotor}, m_tankMotor{&tankMotor} {}
    void setIntakeSpeed()
    {}
    void raise();
    void lower();
    void intakeIn();
    void intakeEject();
    void intakeStop();
    //void setAngle();

    void setTankMotorManual(double vel);
private:
  frc::SpeedController* m_intakeMotor;
  frc::SpeedController* m_tankMotor;

    static constexpr double tankRaiseSpeed{1.0};
    static constexpr double tankLowerSpeed{0.0};
    static constexpr double intakeInSpeed{-1.0};
    static constexpr double intakeEjectSpeed{1.0};
};
#endif