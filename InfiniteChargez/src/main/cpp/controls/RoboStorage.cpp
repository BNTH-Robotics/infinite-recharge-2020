#include "RoboStorage.h"

#include <cmath>
#include <thread>

    void RoboStorage::raise()
    {
        m_tankMotor->Set(tankRaiseSpeed);
    }

    void RoboStorage::lower()
    {
        manual = false;
        m_tankMotor->Set(tankLowerSpeed);
    }

    void RoboStorage::intakeIn()
    {
        manual = false;
        m_intakeMotor->Set(intakeInSpeed);
    }

    void RoboStorage::intakeEject()
    {
        m_intakeMotor->Set(intakeEjectSpeed);
    }

    void RoboStorage::intakeStop()
    {
        m_intakeMotor->Set(0);
    }

    void RoboStorage::setTankMotorManual(double vel)
    {
        manual = true;
        m_intakeMotor->Set(vel);
    }

    void RoboStorage::tankHandler()
    {
        double frame{0};
        double motorVal{0};
        while(true)
        {
           if (!manual) 
           {
               if (m_raising)
               {
                   frame += changeRate;
                    if (frame > 1)
                    {
                        frame = 1;
                    }
               }
               if (!m_raising)
               {
                   frame -= changeRate;
                   if (frame < 0)
                   {
                       frame = 0;
                   }
               }
               m_tankMotor->Set(tankRaiseStop + frame * (tankRaiseStart - tankRaiseStop));
           }
           std::this_thread::sleep_for(std::chrono::duration<double>{0.5}); 
        }
    }