#ifndef CLASS_H
#define CLASS_H

/*
Header for Civil War Strategy Game by Cade Luinenburg
Created February 10th, 2020
Last updated February 12th, 2020
*/

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class General;
class Unit;
class MapClass;

class General
{
	private:
		int moral, soldierAccuracy, artilleryAccuracy;
		bool organization;
		// Moral determines whether you can move a unit
		// Soldier Accuracy is a buff to normal unit accuracy
		// Artillery Accuracy is the same but specifically for artillery
		// Organization determines if you can choose your unit's starting position

	public:
		General(int m, int sA, int aA, bool o)
		{
			moral = m;
			soldierAccuracy = sA;
			artilleryAccuracy = aA;
			organization = o;
		}
};

class Unit
{
	private:
		int health = 2;
		std::string team;
		char symbol;
	public:
		Unit(std::string t, char s)
		{
			team = t;
			symbol = s;
		}
		char getSymbol() { return (symbol); }
		bool isDead() { return (health <= 0); }
		int currentHealth() { return (health); }
		bool damage(int x)
		{ 
			if (x < 1) return false;
			health -= x;
			return (isDead());
		}
};

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
#endif