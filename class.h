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
		string team;
	public:
		Unit(bool art, string t)
		{
			team = t;
			artillery = art;
		}
		bool isArtillery() { return artillery; }
};

class MapClass
{
	private:
		std::vector<std::vector<char>> map;
	public:
		MapClass()
		{
			map.resize(21);
			for (int i=0; i<map.size(); i++) map[i].resize(21);
		}
		void draw()
		{
			for (int i2=0; i2<85; i2++) std::cout << "-";
			std::cout << "\n";
			for (int i=0; i<map.size(); i++)
			{
				std::cout << "| ";
				for (int i2=0; i2<map[i].size(); i2++)
				{
					std::cout << map[i][i2] << " | ";
				}
				std::cout << "\n";
				for (int i2=0; i2<85; i2++) std::cout << "-";
				std::cout << "\n";
			}
		}
		void fill()
		{
			for (int i=1; i<map.size(); i++)
			{
				for (int i2=1; i2<map[i].size(); i2++)
				{
					map[i][i2] = '#';
				}
			}
		}
};
#endif