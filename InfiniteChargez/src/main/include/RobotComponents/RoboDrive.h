#ifndef YEET_ROBOT_DRIVE_MOTORZ_H
#define YEET_ROBOT_DRIVE_MOTORZ_H
#include "Pair2D.h"


#include <frc/SpeedController.h>

#include <algorithm>
class RoboDrive
{
    using controller_t = frc::SpeedController;
public:
    RoboDrive(frc::SpeedController &leftMotors, frc::SpeedController &rightMotors):
        m_leftMotors{&leftMotors}, m_rightMotors{&rightMotors}
    {
    }

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