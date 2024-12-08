#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include<math.h>

class Angle
{
private:
	double val_degrees{}, val_minutes{};
public:
	
	Angle() {};
	~Angle() {};
	std::string to_string();
	void fill(std::istream& stream = std::cin);
	void print(std::string message, std::ostream & stream) const;
	double to_radians();
	void to_360();
	void angle_up(double adding_deg = 0, double adding_mins = 0); // oprerator+(Angle other) 
	void angle_down(double adding_deg = 0, double adding_mins = 0); //
	float get_sin();
	double get_degrees() const { return val_degrees; };
	double get_minutes() const { return val_minutes; };
	void operator +(Angle& other)
	{
		this->val_degrees += other.val_degrees;
		this->val_minutes += other.val_minutes;
		to_360();

	}	
	void operator -(Angle& other)
	{
		this->val_degrees -= other.val_degrees;
		this->val_minutes -= other.val_minutes;
		//this->val_minutes = fabs(this->val_minutes - other.val_minutes);
		to_360();

	}
	void operator *(double a) {

		double new_degrees = (val_degrees + val_minutes / 60.) * a;

		double new_minutes = (modf(new_degrees, &new_degrees)*60);

		this->val_degrees = new_degrees;
		this->val_minutes = fabs(new_minutes);

	}
	std::partial_ordering operator <=> (const Angle&) const = default;
	
};

