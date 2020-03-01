#ifndef YEET_ROBOT_STORAGE_H
#define YEET_ROBOT_STORAGE_H

#include <frc/SpeedController.h>
#include <thread>


class RoboStorage
{
public:
    RoboStorage(frc::SpeedController &intakeMotor, frc::SpeedController &tankMotor):
      m_intakeMotor{&intakeMotor}, m_tankMotor{&tankMotor} 
      {
      }
    void setIntakeSpeed()
    {}
    void raise();
    void lower();
    void intakeIn();
    void intakeEject();
    void intakeStop();
    void tankHalt();
    //void startHandler()
    //{

    //    std::thread handler{&RoboStorage::tankHandler, this};
    //    handler.detach();

    //}
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
    }
    void tankHandler();
    //void setAngle();

    void setTankMotorManual(double vel);
private:
  frc::SpeedController* m_intakeMotor;
  frc::SpeedController* m_tankMotor;
    static constexpr double tankToggleUpSpeed{.6};
    static constexpr double tankToggleDownSpeed{-1.0};
    static constexpr double tankRaiseSpeed{0.75};
    static constexpr double tankRaiseStart{0.3};
    static constexpr double tankRaiseStop{-0.2};
    static constexpr double tankLowerSpeed{0.2};
    static constexpr double intakeInSpeed{-0.7};
    static constexpr double intakeEjectSpeed{0.7};
    static constexpr double changeRate{0.012};
    bool manual{false};
    bool m_raising{true};
};
#endif