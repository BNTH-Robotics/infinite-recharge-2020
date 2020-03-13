#ifndef YEET_ROBOT_DRIVE_MOTORZ_H
#define YEET_ROBOT_DRIVE_MOTORZ_H
#include "Pair2D.h"


#include <frc/SpeedController.h>

#include <algorithm>
/**
 * Better DifferentialDrive than WPILib because DifferentialDrive is stupidly sensitive
 * Last year everything had to be halved to be usable.
 * This Differential Drive algorithm allows full speed while being controlled
 * Ahhh... The power of software... ehh?
 */
class RoboDrive
{
    using controller_t = frc::SpeedController;
public:
    RoboDrive(frc::SpeedController &leftMotors, frc::SpeedController &rightMotors):
        m_leftMotors{&leftMotors}, m_rightMotors{&rightMotors}
    {
    }

    /**
     * The movement map is a simple way of storing movement information
     * The y axis controls how fast the robot is going forwards/backwards
     * The x axis controls how fast the rotation of the robot is in either direction
     */
    void setMovementMap(utilities::Pair2D<double> &&movementMap)
    {
        m_leftMotors->Set(std::clamp(movementMap.y - movementMap.x, -1.0, 1.0));
        m_rightMotors->Set(std::clamp(movementMap.y + movementMap.x, -1.0, 1.0));//FIGURE OUT WHY A NEGATIVE IS NEEDED!!!!
    };
    //void setForwardMovement(double forwards);
    //void setRotationMovement(double clockwise);
private:
    controller_t *m_leftMotors;
    controller_t *m_rightMotors;
};
#endif