#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include <cmath>
#include "Point.h"
#include "PointCloud.h"

using namespace std;

class Transform :public PointCloud
{
private:
	//data of the transform class
	double angles[3];
	double trans[3];
	double transmatrix[4][4];
public:
	//Consructor of the transform class
	Transform() {
		for (int i = 0; i < 3; i++)
		{
			angles[i] = 0;	//initializing		
			trans[i] = 0;
		};
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				transmatrix[i][j] = 0;
			}
		}
	}
	//set and get functions
	void setRotation(double angle[])
	{
		for (int i = 0; i < 3; i++)
		{
			angles[i] = angle[i];
		}
	}
	void setTranslation(double transi[]) {
		for (int i = 0; i < 3; i++)
		{
			trans[i] = transi[i];
		}
	}
	double* getRotation()
	{
		return angles;
	}
	double* getTranslation()
	{
		return trans;
	}
	//Function to calculate the transformation for the point
	Point doTransform(Point p);
	//Function to calculate the transformation for the pointcloud
	PointCloud doTransform(PointCloud pc);
		
	//Destructor of the transform class
	~Transform()
	{

	}

};