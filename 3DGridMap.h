#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include <cmath>

#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"


using namespace std;


class ThreeDGridMap :public PointCloud, public DepthCamera
{
private:
	bool map[][][];
	float gridsize;
	int depth;
public:


	//constructor of the 3DGridMap
	ThreeDGridMap(int depth, float gridsize) :depth(depth), gridsize(gridsize) {}


	//set get functions
	void setDepth(int depth)
	{
		this->depth = depth;
	}
	void setGridSize(float gridsize)
	{
		this->gridsize = gridsize;
	}
	void setMap(bool map[][][])
	{
		this->map[][][] = map[][][];
	}
	int getDepth()
	{
		return depth;
	}
	float getGridSize()
	{
		return gridsize;
	}
	bool getMap()
	{
		return map[][][];
	}
	//a function to create a 3D grid map by adding point cloud to the map
	void insertPointCloud(const PointCloud& pc)
	{
		for (int i = 0; i < pc.getPointNumber(); i++)
		{
			int x = pc.getPoint(i).getX() / gridsize;
			int y = pc.getPoint(i).getY() / gridsize;
			int z = pc.getPoint(i).getZ() / gridsize;
			map[x][y][z] = true;
		}
	}


	//a function to create a 3D grid map by adding a single point to the map
	void insertPoint(const Point& p)
	{
		int x = p.getX() / gridsize;
		int y = p.getY() / gridsize;
		int z = p.getZ() / gridsize;
		map[x][y][z] = true;
	}

	bool getGrid(int x, int y, int z) const
	{
		return map[x][y][z];
	}

	//a function to save the 3D grid map to a file
	bool saveMap(filename)
	{
		ofstream file(filename);
		if (file.is_open())
		{
			file << depth << endl;
			file << gridsize << endl;
			for (int i = 0; i < depth; i++)
			{
				for (int j = 0; j < depth; j++)
				{
					for (int k = 0; k < depth; k++)
					{
						file << map[i][j][k] << " ";
					}
					file << endl;
				}
				file << endl;
			}
			file.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	// a function to load the 3D grid map from a file
	bool loadMap(filename)
	{
		ifstream file(filename);
		if (file.is_open())
		{
			file >> depth;
			file >> gridsize;
			for (int i = 0; i < depth; i++)
			{
				for (int j = 0; j < depth; j++)
				{
					for (int k = 0; k < depth; k++)
					{
						file >> map[i][j][k];
					}
				}
			}
			file.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	//Destructor of the 3DGridMap
	~ThreeDGridMap()
	{

	}
};
