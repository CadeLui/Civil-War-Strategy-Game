#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "ObjectHolder.h"

class ObjectMatrix
{
	private:
		std::vector<std::vector<ObjectHolder*>> objectVector;
		std::string alphabet[26] = 
			{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
			 "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

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

		void emptySpot(int r, int c)
		{
			objectVector[r][c] = new ObjectHolder();
		}

		int pickAndPlace(int r1, int c1, int r2, int c2)
		{
			if (objectVector[r1][c1]->containedObject == nullptr) return 1;
			if (objectVector[r2][c2]->containedObject != nullptr) return 1;
			objectVector[r2][c2] = objectVector[r1][c1];
			objectVector[r1][c1] = new ObjectHolder();
			return 0;
		}

		int swapObject(int r1, int c1, int r2, int c2)
		{
			if (objectVector[r1][c1]->containedObject == nullptr) return 1;
			ObjectHolder* tempObj = objectVector[r2][c2];
			objectVector[r2][c2] = objectVector[r1][c1];
			objectVector[r1][c1] = tempObj;
			return 0;
		}

		int pushObject(int row, int col, int down, int right)
		{
			if (objectVector[row][col]->containedObject == nullptr ||
				objectVector[row+down][col+right]->containedObject != nullptr) return 1;
			objectVector[row+down][col+right] = objectVector[row][col];
			objectVector[row][col] = new ObjectHolder();
			return 0;
		}

		std::string toString()
		{
			std::string output = "   | ";
			for (int c = 0; c < objectVector[0].size(); c++)
			{
				output += alphabet[c] + " ";
			} output += "|\n";

			for (int r = 0; r < objectVector.size(); r++)
			{
				if (r < 10) output += "0";
				output += std::to_string(r) + " | ";
				for (int c = 0; c < objectVector[r].size(); c++)
				{
					output += objectVector[r][c]->symbol + " ";
				}
				output += "|\n";
			}
			return output;
		}
};