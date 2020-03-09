#ifndef YEET_DATA_LE_ROBOT_H
#define YEET_DATA_LE_ROBOT_H
#include <adi/ADIS16448_IMU.h>

#include <frc/BuiltInAccelerometer.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Pose2d.h>

#include <chrono>
class RoboData
{
    using clock_t = std::chrono::steady_clock;
    using timepoint_t = std::chrono::time_point<clock_t>;
    using duration_t = std::chrono::duration<double>;
    using accelerometer_t = frc::BuiltInAccelerometer;
    using gyroscope_t = frc::ADIS16448_IMU;

    public:
    RoboData(gyroscope_t &Gyroscope, accelerometer_t &Accelerometer) :
	leGyroscope{&Gyroscope}, leAccelerometer{&Accelerometer} {}

    void updatePos(duration_t delta);

    void initSnap() {lastSnap = clock_t::now();}

    duration_t calcAndGetTimeDelta()
    {
	timepoint_t now = clock_t::now();
	duration_t delta{std::chrono::duration_cast<duration_t>(now - lastSnap)};
	lastSnap = now;
	return delta;
    }

    private:

    gyroscope_t *leGyroscope;
    accelerometer_t *leAccelerometer;

    frc::Pose2d leRobotPosition;
    timepoint_t lastSnap;
};
#endif
