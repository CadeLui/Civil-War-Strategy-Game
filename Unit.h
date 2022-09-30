#pragma once

#include <string>

class Unit
{
	private:
		int health = 2;
		std::string team;
		std::string symbol;
	public:
		Unit(std::string t, std::string s)
		{
			team = t;
			symbol = s;
		}
		std::string getSymbol() { return (symbol); }
		bool isDead() { return (health <= 0); }
		int currentHealth() { return (health); }
		bool damage(int x)
		{ 
			if (x < 1) return false;
			health -= x;
			return (isDead());
		}
};