#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "ObjectHolder.h"

class ObjectMatrix
{
	private:
		std::vector<std::vector<ObjectHolder*>*> objectVector;
	public:
		ObjectMatrix(int rows, int cols)
		{
			for (int r = 0; r < rows; r++)
			{
				objectVector.push_back(new std::vector<ObjectHolder*>);
				for (int c = 0; c < cols; r++)
					objectVector[r]->push_back(new ObjectHolder());
			}
		}
		void placeObject(void* newObj, std::string newSym, int r, int c)
		{
			objectVector[r]->at(c) = new ObjectHolder(newObj, newSym);
		}
		int pickAndPlace(int r1, int c1, int r2, int c2)
		{
			if (!objectVector[r2]->at(c2)->getObject()) return 1;
			objectVector[r2][c2] = objectVector[r1][c1];
			objectVector[r1]->at(c2) = new ObjectHolder();
			return 0;
		}
};