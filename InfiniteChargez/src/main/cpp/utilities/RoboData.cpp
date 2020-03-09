#include "RoboData.h"
#include "Pair2D.h"
#include "Utilities.h"

#include <units/units.h>

#include <chrono>
#include <cmath>

void RoboData::updatePos(duration_t delta)
{
    //std::cout << leGyroscope.GetGyroAngleZ();
    units::degree_t leAngle{leGyroscope->GetGyroAngleZ()};
    units::meter_t xDelta{
        utilities::simpleAccelToPos(units::standard_gravity_t{-leAccelerometer->GetX()}, delta) * std::cos(units::radian_t{leAngle}.to<double>())  +
        utilities::simpleAccelToPos(units::standard_gravity_t{-leAccelerometer->GetY()}, delta) * std::sin(units::radian_t{leAngle}.to<double>())};

    units::meter_t yDelta{
        utilities::simpleAccelToPos(units::standard_gravity_t{-leAccelerometer->GetX()}, delta) * std::sin(units::radian_t{leAngle}.to<double>())  +
        utilities::simpleAccelToPos(units::standard_gravity_t{-leAccelerometer->GetY()}, delta) * std::cos(units::radian_t{leAngle}.to<double>())};

    frc::Translation2d leTranslate{xDelta, yDelta};


    leRobotPosition = frc::Pose2d{leTranslate + leRobotPosition.Translation(), frc::Rotation2d{leAngle}};
    //std::cout << delta.count();
    //std::cout << "LeRobotPosition: X: " << leRobotPosition.Translation().X().to<double>() << '\n'
    //    << "Le RobotPosition: Y: " << leRobotPosition.Translation().Y().to<double>() << '\n'
    //    << "Le RobotPosition: Rot: " << leRobotPosition.Rotation().Radians().to<double>() << '\n' << "***"<< '\n';
}

