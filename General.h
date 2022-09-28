#pragma once

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