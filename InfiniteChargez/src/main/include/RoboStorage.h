#ifndef YEET_ROBOT_STORAGE_H
#define YEET_ROBOT_STORAGE_H

#include <frc/SpeedController.h>


class RoboStorage
{
public:
    RoboStorage(frc::SpeedController &intakeMotorLeft, frc::SpeedController &intakeMotorRight):
      m_intakeLeft{&intakeMotorLeft}, m_intakeRight{&intakeMotorRight} {}
    void setIntakeSpeed()
    {}
    //void raise()
    //void lower()
    //void setAngle();
private:
  frc::SpeedController* m_intakeLeft;
  frc::SpeedController* m_intakeRight;
};
#endif