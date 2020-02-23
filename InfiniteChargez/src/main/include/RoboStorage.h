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
    //void raise()
    //void lower()
    //void setAngle();
private:
  frc::SpeedController* m_intakeMotor;
  frc::SpeedController* m_tankMotor;
};
#endif