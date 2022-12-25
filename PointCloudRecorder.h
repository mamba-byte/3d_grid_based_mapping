#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include <cmath>
#include "Point.h"
#include "PointCloud.h"

using namespace std;

class PointCloudRecorder :public PointCloud
{
private:
	string filename;
public:
	//Constructor of PointCloudRecorder
	PointCloudRecorder(string filename) :filename(filename) {}
	//set get functions
	void setFileName(string filename)
	{
		this->filename = filename;
	}
	string getFileName()
	{
		return filename;
	}
	bool save(const PointCloud& pc)
	{
		ofstream file(filename);
		if (file.is_open())
		{
			file << pc.getPointNumber() << endl;
			for (int i = 0; i < pc.getPointNumber(); i++)
			{
				file << pc.getPoint(i).getX() << " " << pc.getPoint(i).getY() << " " << pc.getPoint(i).getZ() << endl;
			}
			file.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	//Destructor of PointCloudRecorder
	~PointCloudRecorder()
	{

	}
};
