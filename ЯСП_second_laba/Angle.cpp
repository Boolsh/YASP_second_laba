#include "Angle.h"
#include <math.h>
#include <numbers>


std::string Angle::to_string()
{

    return (std::to_string(val_degrees) + " " + std::to_string(val_minutes));

}

void Angle::fill(std::istream& stream)
{
    stream >> val_degrees;
    stream >> val_minutes;
}

void Angle::print(std::string message, std::ostream& stream) const
{
    std::cout << message; 
    stream << val_degrees << " " << val_minutes << " \n";

}

double Angle::to_radians()
{
    return (val_degrees + val_minutes / 60.0) * (std::numbers::pi / 180.0);
}

void Angle::to_360() {

    if (val_minutes < 0)
    {
        val_degrees -= 1;
        val_minutes += 60;
    }

    if (val_minutes / 60 >= 1)
    {
        val_degrees += (int(val_minutes) / 60);
        val_minutes = fmod(val_minutes, 60);
    }

    if (val_degrees < 0) {
        val_degrees = fmod((fmod(val_degrees, 360) + 360), 360);
    }
    else {
        val_degrees = fmod(val_degrees, 360);
        
    }


}

void Angle::angle_up(double adding_deg, double adding_mins) {
    val_degrees += adding_deg;
    val_minutes += adding_mins;
    if (val_minutes / 60 >= 1)
    {
        val_degrees += int(val_minutes / 60);
        val_minutes = fmod(val_minutes, 60);
    }
    to_360();
 
}

void Angle::angle_down(double adding_deg, double adding_mins) {
    val_degrees -= adding_deg;
    val_minutes -= adding_mins;
    if (val_minutes < 0)
    {
        if (val_degrees >= 0)
        {
            --val_degrees;
            val_minutes = 60 + val_minutes;
        }
        else val_minutes = fabs(val_minutes);
    }
    if (fabs(val_minutes) / 60 >= 1)
    {
        val_degrees -= abs(val_minutes) / 60;
        if (fmod(fabs(val_minutes), 60) > 0)
        {
            val_minutes = 60 - fmod(fabs(val_minutes), 60);
            val_degrees--;
        }
        else val_minutes = 0;
    }
    to_360();

}


float Angle::get_sin() 
{
    float res = sinf(to_radians());
    if (abs(0 - abs(res)) < 0.0000001)
        return 0;
    return sinf(to_radians());
}
