#include "RoboStorage.h"

    void RoboStorage::raise()
    {
        m_tankMotor->Set(tankRaiseSpeed);
    }

    void RoboStorage::lower()
    {
        m_tankMotor->Set(tankLowerSpeed);
    }

    void RoboStorage::intakeIn()
    {
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
        m_intakeMotor->Set(vel);
    }
