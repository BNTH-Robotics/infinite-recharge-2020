#include "RoboHook.h"

    void RoboHook::advance()
    {
        m_hookMotor->Set(hookUpSpeed);
    }

    void RoboHook::down()
    {
        m_hookMotor->Set(hookDownSpeed);
    }

    void RoboHook::stop()
    {
        m_hookMotor->Set(0);
    }
