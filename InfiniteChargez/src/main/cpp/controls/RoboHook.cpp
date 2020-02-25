#include "RoboHook.h";

    void RoboHook::hookUp()
    {
        m_hookMotor->Set(hookUpSpeed);
    }

    void RoboHook::hookDown()
    {
        m_hookMotor->Set(hookDownSpeed);
    }

    void RoboHook::hookStop()
    {
        m_hookMotor->Set(0);
    }
