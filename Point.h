#pragma once
#include<iostream>
#include <vector>
#include <cmath>

using namespace std;
class Point
{
private:
	double x;
	double y;
	double z;
public:

	//Constructor of point class
	Point(double x, double y, double z) :x(x), y(y), z(z){}

	//set get functions
	void setPoint(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	double getZ()
	{
		return z;
	}
	//Distance Calculation Function
	double distance(const Point& p)
	{
		return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
	}
	//Overloading the '==' operator
	bool operator==(const Point& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	//Destructor of point class
	~Point()
	{

	}



};