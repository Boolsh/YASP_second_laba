#include "Angle.h"
#include <cmath>

constexpr double pi = 3.14159265358979323846;


void Angle::print(std::string message)
{
    std::cout << message << " " << val_degrees << "° " << val_minutes << "'\n";

}

float Angle::to_radians()
{
    Angle tmp(this->val_degrees, this->val_minutes);
    tmp.to_360();
    return (tmp.val_degrees + tmp.val_minutes / 60.0) * (pi / 180.0);
    //return (val_degrees + val_minutes / 60.0) * (pi / 180.0);
}

void Angle::to_360() {

    val_degrees += val_minutes / 60;
    val_minutes %= 60; 


    if (val_degrees < 0) {
        val_degrees = (val_degrees % 360 + 360) % 360; 
    }
    else {
        val_degrees %= 360; 
    }
}

void Angle::angle_up(int adding_deg, int adding_mins) {
    val_degrees += adding_deg;
    val_minutes += adding_mins;
    if (val_minutes / 60 >= 1)
    {
        val_degrees += val_minutes / 60;
        val_minutes %= 60;
    }
    //to_360(); 
}

void Angle::angle_down(int adding_deg, int adding_mins) {
    val_degrees -= adding_deg;
    val_minutes -= adding_mins;
    if (abs(val_minutes) / 60 >= 1)
    {
        val_degrees -= abs(val_minutes) / 60;
        if (abs(val_minutes) % 60 > 0)
        {
            val_minutes = 60 - abs(val_minutes) % 60;
            val_degrees--;
        }
        else val_minutes = 0;
    }
    //to_360(); 
}


float Angle::get_sin()
{
    float res = sinf(to_radians());
    if (0 - abs(res) < 0.00000000001)
        return 0;
    return sinf(to_radians());
}
