#pragma once
#include<iostream>
#include <vector>
#include <cmath>
#include "Point.h"

using namespace std;

class PointCloud : public Point
{private:
	Point* points;
	int pointnumber;
public:
	//Constructor of pointcloud
	PointCloud(int point_number) : points(new Point[point_number]), pointnumber(point_number) {}

	//Copy Constructor 


	//set get functions
	void setPoint(int i, double x, double y, double z)
	{
		points[i].setPoint(x, y, z);
	}
	Point getPoint(int i)
	{
		return points[i];
	}
	double getPointNumber()
	{
		return pointnumber;
	}
	//'+' operator overloading
	Point operator+(const Point& other) const
	{
		return Point(x + other.x, y + other.y, z + other.z);
	}
	//'=' operator overloading
	Point operator=(const Point& other) const
	{
		return Point(x = other.x, y = other.y, z = other.z);
	}
	//Destructor of pointcloud
	~PointCloud()
	{

	}
};