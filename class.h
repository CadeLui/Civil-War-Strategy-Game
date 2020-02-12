#ifndef CLASS_H
#define CLASS_H

/*
Header for Civil War Strategy Game by Cade Luinenburg
Created February 10th, 2020
Last updated February 11th, 2020
*/

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

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
		void modEffect(int effect, int modification)
		{
			switch (effect)
			{
				case 0:
					moral += modification;
					if (moral > 20) moral = 20;
					break;

				case 1:
					soldierAccuracy += modification;
					if (soldierAccuracy > 9) soldierAccuracy = 9;
					break;

				case 2:
					artilleryAccuracy += modification;
					if (artilleryAccuracy > 8) artilleryAccuracy = 8;
					break;

				case 3:
					if (modification == 1) organization = true;
					else organization = false;
					break;
			}
		}
};

class Card
{
	private:
		std::string question, answer;
		int stat, effect;

	public:
		Card(std::string q, std::string a, int s, int e)
		{
			question = q;
			answer = a;
			stat = s;
			effect = e;
		}
		void answerCard(std::string givenAnswer, General *player)
		{
			if (givenAnswer == answer)
			{
				player->modEffect(stat, effect);
			}
			else
			{
				player->modEffect(stat, -effect);
			}
		}
};

class Unit
{
	private:
		int health = 2;
		bool artillery;
		std::string team;
		char symbol;
	public:
		Unit(bool art, std::string t, char s)
		{
			team = t;
			artillery = art;
			symbol = s;
		}
		bool isArtillery() { return artillery; }
		char getSymbol() { return symbol; }
};

class MapClass
{
	private:
		std::vector<std::vector<char>> graphicMap;
		std::vector<std::vector<Unit*>> entityMap;
	public:
		MapClass()
		{
			graphicMap.resize(21);
			for (int i=0; i<graphicMap.size(); i++) graphicMap[i].resize(21);

			entityMap.resize(21);
			for (int i=0; i<entityMap.size(); i++) entityMap[i].resize(21);
		}
		void draw()
		{
			for (int i2=0; i2<85; i2++) std::cout << "-";
			std::cout << "\n";
			for (int i=0; i<graphicMap.size(); i++)
			{
				std::cout << "| ";
				for (int i2=0; i2<graphicMap[i].size(); i2++)
				{
					std::cout << graphicMap[i][i2] << " | ";
				}
				std::cout << "\n";
				for (int i2=0; i2<85; i2++) std::cout << "-";
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
};
#endif