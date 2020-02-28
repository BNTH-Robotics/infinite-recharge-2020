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
    int getIntakeStatus() 
    {
      if(m_intakeMotor->Get() > 0)
      {
        return 1;
      } 
      else if (m_intakeMotor->Get() < 0)
      {
        return -1;
      }
      else
      {
        return 0;
      }
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