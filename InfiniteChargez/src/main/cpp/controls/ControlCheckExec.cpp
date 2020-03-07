#include "Robot.h"
#include "Utilities.h"
#include "Pair2D.h"
#include <algorithm>
#include <iostream>
#include <math.h>

    void Robot::checkAndExec()
    {
        //Output tree X will switch the controlls to "Hook Mode"
        if (leInputHandler.getButtonXState())
        {
            if(leInputHandler.getBumperLeftState())
            {
                std::cout << "Hook advance \n";
                leHook.advance();
            }
            else
            {
                leHook.stop();
            }
        }
        else if (leInputHandler.getTriggerLeft() > triggerIntakeTolerance)
        {
            {
                double rightJoystickY = -leInputHandler.getJoystickRight().y;
                leStorage.setTankMotorManual(rightJoystickY);
            }
        }
        else
        {
            if (leInputHandler.getBumperLeftState())
            {
                //if(!(leStorage.getIntakeStatus() == -1))
                //{
                leStorage.intakeIn(leInputHandler.getTriggerRight());
                //}
                //else if (leStorage.getIntakeStatus() == -1)
                //{
                //leStorage.intakeStop();
                //}

            }
            else if (leInputHandler.getBumperRightState())
            {
                leStorage.intakeEject(leInputHandler.getTriggerRight());
            }
            if (leInputHandler.getButtonAState())
            {
                leStorage.lower();
            }
            else if (leInputHandler.getButtonBState())
            {
                leStorage.raise();
            }
            else
            {
                leStorage.tankHalt();
            }
        }
        

        std::cout << leInputHandler.getJoystickLeft().x << '\n';
        joystickPosition(leInputHandler.getJoystickLeft(), leInputHandler.getJoystickRight());
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



