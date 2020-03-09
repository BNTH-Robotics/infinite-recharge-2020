#define _USE_MATH_DEFINES

#include "Utilities.h"
#include <math.h>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include "Pair2D.h"
#include <units/units.h>
#include <chrono>
#include <frc/Filesystem.h>

#include <units/units.h>
namespace utilities
{
    Pair2D<double> squarify(double x, double y)
    {
        if (x == 0 && y ==0)
            return Pair2D<double>{0,0};
        //std::cout << "X: " << x << "Y: " << y << '\n';
        const double angle{std::atan2(y, x)}; //Why doesthe angle keep returning intermittently to 2.75099
        //std::cout << "Angle: " << angle << '\n';
        //Take the percentage from the origin to the edge of the circle
        const double circleRadiusPercent{std::clamp(std::sqrt(x * x + y * y), 0.0, 1.0)}; //Ensure that percent is maxmimum of 1 due to joystick imperfections
        //std::cout << "Percent: " << circleRadiusPercent << '\n';
        /*Find the maximum distance to a square whose sides are the diameter of the circle from the angle
        *The formula used is the radial equation for a circle by Raven Jyro Felix which uses modulo */
       
        /*Since a square has fourfold radius, the radius repeats four times.
        *Since the formula offsets the angle by pi/2, it must be added to make
        *The circle upright
        */
        const double processedAngleForSquare{(std::abs(std::fmod((angle + M_PI_4), M_PI_2))) - M_PI_4};
        //Since fmod returns negative if the input is negative, it must be made positive in order to align with mathematical modulo
        //std::cout <<  processedAngleForSquare;
        double squareRadiusMax{std::sqrt(std::pow(std::tan(processedAngleForSquare), 2.0) + 1)};
        //std::cout << squareRadiusMax;
        //Generate the radius which is the same percentage from the circle but this time from the origin to suqare square
        //https://www.desmos.com/calculator/jvgokzaevl Uses the modulo equation by Raven Jyro Felix[Jehbar Ibarra]
        const double rawSquareRadius{circleRadiusPercent * squareRadiusMax};

        return Pair2D<double> {rawSquareRadius * std::cos(angle), rawSquareRadius * std::sin(angle)};
    }

    units::meter_t simpleAccelToPos(units::meters_per_second_squared_t accel, std::chrono::duration<double> delta)
    {
        return units::meter_t{accel.to<double>() * 0.5 * (delta.count() * delta.count())};
    }

    template<class T> 
    T parseSSV(const std::string &str, std::size_t &i)
    {
        T placer;
        assert(false && "TYPE NOT SUPPORTED");
        return placer;
    }

    template<> 
    double parseSSV(const std::string &str, std::size_t &i) 
    {
        double parsed{std::stod(str.substr(i))};
        i = str.find(" ", i + 1);
        return parsed;
    }

    template<> 
    int parseSSV(const std::string &str, std::size_t &i) 
    {
        int parsed{std::stoi(str.substr(i))};
        i = str.find(" ", i + 1);
        return parsed;
    }
}