#include "RoboStorage.h"

#include <cmath>
#include <thread>

void RoboStorage::raise()
{
    m_tankMotor->Set(tankToggleUpSpeed);
}

void RoboStorage::lower()
{
    m_tankMotor->Set(tankToggleDownSpeed);
}

void RoboStorage::tankHalt()
{
    m_tankMotor->Set(0);
}

void RoboStorage::intakeIn(double slowdown)
{
    m_intakeMotor->Set(intakeInSpeed * (1 - slowdown));
}

void RoboStorage::intakeEject(double slowdown)
{
    m_intakeMotor->Set(intakeEjectSpeed * (1 - slowdown));
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
    while (true)
    {
        if (!manual)
        {
            std::cout << "Not manual\n";
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
            std::cout << frame << '\n';
            m_tankMotor->Set(tankRaiseStop + frame * (tankRaiseStart - tankRaiseStop));
        }
        std::this_thread::sleep_for(std::chrono::duration<double>{0.01});
    }
}