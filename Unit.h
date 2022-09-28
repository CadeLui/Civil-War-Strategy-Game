#pragma once

#include <string>

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