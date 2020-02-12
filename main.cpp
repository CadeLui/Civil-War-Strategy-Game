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
Unit unionS0(false, "union", 'u');
Unit unionS1(false, "union", 'u');
Unit unionS2(false, "union", 'u');
Unit unionS3(false, "union", 'u');
Unit unionS4(false, "union", 'u');
Unit unionS5(false, "union", 'u');
Unit unionS6(false, "union", 'u');
Unit unionS7(false, "union", 'u');
Unit unionS8(false, "union", 'u');
Unit unionS9(false, "union", 'u');

Unit unionA0(true, "union", 'U');
Unit unionA1(true, "union", 'U');
Unit unionA2(true, "union", 'U');


// Confederate
Unit confS0(false, "conf", 'c');
Unit confS1(false, "conf", 'c');
Unit confS2(false, "conf", 'c');
Unit confS3(false, "conf", 'c');
Unit confS4(false, "conf", 'c');
Unit confS5(false, "conf", 'c');
Unit confS6(false, "conf", 'c');
Unit confS7(false, "conf", 'c');
Unit confS8(false, "conf", 'c');
Unit confS9(false, "conf", 'c');

Unit confA0(true, "conf", 'C');
Unit confA1(true, "conf", 'C');
Unit confA2(true, "conf", 'C');

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
	//Map.fill();
	Map.place(5,5,&unionS0);
	Map.draw();
	Map.remove(5,5);
	Map.draw();
	return 0;
}