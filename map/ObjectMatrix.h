#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "ObjectHolder.h"

class ObjectMatrix
{
	private:
		std::vector<std::vector<ObjectHolder*>> objectVector;
	public:
		ObjectMatrix(int rows, int cols)
		{
			objectVector.resize(rows);
			for (int r = 0; r < rows; r++)
			{
				objectVector[r].resize(cols);
				for (int c = 0; c < cols; c++)
				{
					objectVector[r][c] = new ObjectHolder();
				}
			}
		}
		void placeObject(void* newObj, std::string newSym, int r, int c)
		{
			objectVector[r][c] = new ObjectHolder(newObj, newSym);
		}
		int pickAndPlace(int r1, int c1, int r2, int c2)
		{
			if (objectVector[r2][c2]->getObject() != nullptr) return 1;
			objectVector[r2][c2] = objectVector[r1][c1];
			objectVector[r1][c1] = new ObjectHolder();
			return 0;
		}
		std::string toString()
		{
			std::string output;
			for (int r = 0; r < objectVector.size(); r++)
			{
				output += "| ";
				for (int c = 0; c < objectVector.size(); c++)
				{
					output += objectVector[r][c]->getSymbol() + " ";
				}
				output += "|\n";
			}
			return output;
		}
};