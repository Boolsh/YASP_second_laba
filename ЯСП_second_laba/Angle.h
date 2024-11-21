#pragma once
#include<iostream>
#include<cmath>

class Angle
{
private:
	int val_degrees, val_minutes;
public:
	Angle() { val_degrees = 0; val_minutes = 0; };
	Angle(int val_degrees, int val_minutes = 0) 
	{ 
		this->val_degrees = val_degrees; 
		this->val_minutes = val_minutes;
	};
	~Angle() {};
	void print(std::string message);
	float to_radians();
	void to_360();
	void angle_up(int adding_deg, int adding_mins);
	void angle_down(int adding_deg, int adding_mins);
	float get_sin();
	std::strong_ordering operator <=> (const Angle&) const = default;

};

