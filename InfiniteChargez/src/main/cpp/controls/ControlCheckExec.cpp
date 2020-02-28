#include "Robot.h"
#include "Utilities.h"
#include "Pair2D.h"
#include <algorithm>
#include <iostream>
#include <math.h>

    void Robot::checkAndExec()
    {
        joystickPosition(leInputHandler.getJoystickLeft(), leInputHandler.getJoystickRight());
        rightBumper();
        leftBumper();
        buttonA();
        buttonB();
        triggerAndRightJoystick();
        XAndLeftRightBumper();



    }
    
    void Robot::joystickPosition(utilities::XboxInputHandler::joystick_t &&joystickLeft, utilities::XboxInputHandler::joystick_t &&joystickRight)
    {
        ////Compilar arguments and preprocessor macros can be passed to remove unused
        //const double JoystickLeftX{leInputHandler.getJoystickLeft().x};
        ////Up is negative in Xbox controllers
        //const double JoystickLeftY{-leInputHandler.getJoystickLeft().y};

        //const double JoystickRightX{joystickLeft.x};
        ////Up isnegative in Xbox controllers
        //const double JoystickRightY{-joystickLeft.y};
        
        ////Squarified Values
        //const utilities::Pair2D<double> SquareJoystickLeft{utilities::squarify(JoystickLeftX, JoystickLeftY)};
        //const utilities::Pair2D<double> SquareJoystickRight{utilities::squarify(JoystickRightX, JoystickRightY)};
        utilities::Pair2D<double> joystickValuesThatMakeSense{-leInputHandler.getJoystickLeft().y, -leInputHandler.getJoystickLeft().x};
        leInputHandler.setJoystickLeft(joystickValuesThatMakeSense); //Computer scientists are stupid. Up is down ahhhhh.

        leDrive.setMovementMap(leInputHandler.getJoystickLeft());
    }

    void Robot::leftBumper()
    {
        if (leInputHandler.getBumperLeftState() && !leInputHandler.getButtonXPressed())
        {
        leStorage.intakeIn();
        }
    }

    void Robot::rightBumper()
    {
        if (leInputHandler.getBumperRightState() && !leInputHandler.getButtonXPressed())
        {
        leStorage.intakeEject();
        }
    }

    void Robot::buttonA()
    {
        if (leInputHandler.getButtonAState())
        {
        leStorage.lower();
        }
    }

    void Robot::buttonB()
    {
        if (leInputHandler.getButtonBState())
        {
        leStorage.raise();
        }
    }

    void Robot::triggerAndRightJoystick()
    {
        if (leInputHandler.getTriggerRight() > triggerIntakeTolerance)
        {
        double rightJoystickY = -leInputHandler.getJoystickRight().y;
        leStorage.setTankMotorManual(rightJoystickY);
        }
    }

    void Robot::XAndLeftRightBumper()
    {
        if (leInputHandler.getButtonXState())
        {
            if(leInputHandler.getBumperLeftState())
            {
                leHook.up();
            }
            else if(leInputHandler.getBumperRightState())
            {
                leHook.down();
            }
            else
            {
                leHook.stop();
            }
            
        }
    }

