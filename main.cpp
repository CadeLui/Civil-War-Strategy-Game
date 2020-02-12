#include "class.h"

/*
Civil War Strategy Game by Cade Luinenburg
Created February 10th, 2020
Last updated February 11th, 2020
*/

using namespace std;

/* 
	Generals
*/

// Union
General George_McClellan(14, 2, 1, 0);
General Wimfield_Scott  (10, 4, 2, 1);
General Ulysses_S_Grant (12, 4, 2, 0);

// Confederate
General Robert_E_Lee     (14, 3, 1, 0);
General Stonewall_Jackson(12, 3, 1, 1);

/*
	Question Cards
*/

Card card1("What was George Picket's famous attack?", "Picket Charge", 2, 1);


/*
	Units 
*/

// Union
Unit unionS0(false, "union");
Unit unionS1(false, "union");
Unit unionS2(false, "union");
Unit unionS3(false, "union");
Unit unionS4(false, "union");
Unit unionS5(false, "union");
Unit unionS6(false, "union");
Unit unionS7(false, "union");
Unit unionS8(false, "union");
Unit unionS9(false, "union");

Unit unionA0(true, "union");
Unit unionA1(true, "union");
Unit unionA2(true, "union");


// Confederate
Unit confS0(false, "conf");
Unit confS1(false, "conf");
Unit confS2(false, "conf");
Unit confS3(false, "conf");
Unit confS4(false, "conf");
Unit confS5(false, "conf");
Unit confS6(false, "conf");
Unit confS7(false, "conf");
Unit confS8(false, "conf");
Unit confS9(false, "conf");

Unit confA0(true, "conf");
Unit confA1(true, "conf");
Unit confA2(true, "conf");

/*
	Map
*/

MapClass Map;

/*
	Main
*/

int main(int argc, char *argv[])
{
	srand(time(NULL));
	Map.fill();
	Map.draw();
	return 0;
}