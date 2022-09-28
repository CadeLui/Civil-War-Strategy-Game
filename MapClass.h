#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Unit.h"

class MapClass
{
	private:
		std::vector<std::vector<char>> graphicMap;
		std::vector<std::vector<Unit*>> entityMap;
	public:
		MapClass(int size)
		{
			graphicMap.resize(size);
			for (int i=0; i<graphicMap.size(); i++) 
				graphicMap[i].resize(graphicMap.size());

			entityMap.resize(graphicMap.size());
			for (int i=0; i<entityMap.size(); i++) 
				entityMap[i].resize(graphicMap.size());

			for (int i=0; i<graphicMap.size(); i++) 
				for (int i2=0; i2<graphicMap.size(); i2++) 
					graphicMap[i][i2] = ' ';
			for (int i=0; i<graphicMap.size(); i++) 
			{
				graphicMap[i][0] = i+47; 
				graphicMap[0][i] = i+47;
			}
			graphicMap[0][0] = '/';
		}
		void draw()
		{
			for (int i2=0; i2<(graphicMap.size()*2)+5; i2++)
				std::cout << "-";
			std::cout << "\n";
			for (int i=0; i<graphicMap.size(); i++)
			{
				std::cout << "| ";
				for (int i2=0; i2<graphicMap[i].size(); i2++)
					std::cout << graphicMap[i][i2] << " | ";

				std::cout << "\n";

				for (int i2=0; i2<(graphicMap.size()*4)+1; i2++)
					std::cout << "-";
				std::cout << "\n";
			}
		}
		void place(int x, int y, Unit *entity)
		{
			entityMap[x][y] = entity;
			graphicMap[x][y] = entity->getSymbol();
		}
		void remove(int x, int y)
		{
			entityMap[x][y] = NULL;
			graphicMap[x][y] = ' ';
		}
		Unit* returnEntity(int x, int y) { return entityMap[x][y]; }
};