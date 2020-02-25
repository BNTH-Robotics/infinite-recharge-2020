#include "RoboHook.h";

    void RoboHook::Up()
    {
        m_hookMotor->Set(hookUpSpeed);
    }

    void RoboHook::Down()
    {
        m_hookMotor->Set(hookDownSpeed);
    }

    void RoboHook::Stop()
    {
        m_hookMotor->Set(0);
    }
