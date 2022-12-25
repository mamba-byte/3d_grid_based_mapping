#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include <cmath>
#include "Point.h"
#include "PointCloud.h"

using namespace std;

class DepthCamera : public PointCloud,public Point
{
private:

	string filename;
public:
	//Constructor of DepthCamera
	DepthCamera(string filename) :filename(filename) {}

	//set get functions
	string getFileName()
	{
		return filename;
	}
	void setFileName(string filename)
	{
		this->filename = filename;
	}

	//Capture function which reads the file and stores the points in a pointcloud
	PointCloud capture() {
		ifstream file(filename);
		string line;
		int point_number;
		getline(file, line);
		point_number = stoi(line);
		PointCloud pointcloud(point_number);
		for (int i = 0; i < point_number; i++)
		{
			getline(file, line);
			stringstream ss(line);
			string token;
			vector<string> tokens;
			while (getline(ss, token, ' '))
			{
				tokens.push_back(token);
			}
			pointcloud.setPoint(i, stod(tokens[0]), stod(tokens[1]), stod(tokens[2]));
		}
		return pointcloud;
	}

	//Destructor of DepthCamera
	~DepthCamera()
	{

	}
};