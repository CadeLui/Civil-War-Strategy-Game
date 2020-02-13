#include "class.h"

/*
Civil War Strategy Game by Cade Luinenburg
Created February 10th, 2020
Last updated February 12th, 2020
*/

/* 
	Generals
*/

// Union
General George_McClellan(14, 2, 1, 0);
General Wimfield_Scott(10, 4, 2, 1);
General Ulysses_S_Grant(12, 4, 2, 0);

// Confederate
General Robert_E_Lee(14, 3, 1, 0);
General Stonewall_Jackson(12, 3, 1, 1);

/*
	Units 
*/

// Union
Unit unionS0("union", 'u');
Unit unionS1("union", 'u');
Unit unionS2("union", 'u');
Unit unionS3("union", 'u');
Unit unionS4("union", 'u');
Unit unionS5("union", 'u');
Unit unionS6("union", 'u');
Unit unionS7("union", 'u');
Unit unionS8("union", 'u');
Unit unionS9("union", 'u');

Unit *unionSList[10] = 
{ 
	&unionS0, &unionS1, &unionS2, &unionS3, &unionS4,
	&unionS5, &unionS6, &unionS7, &unionS8, &unionS9
};

// Confederate
Unit confS0("conf", 'c');
Unit confS1("conf", 'c');
Unit confS2("conf", 'c');
Unit confS3("conf", 'c');
Unit confS4("conf", 'c');
Unit confS5("conf", 'c');
Unit confS6("conf", 'c');
Unit confS7("conf", 'c');
Unit confS8("conf", 'c');
Unit confS9("conf", 'c');

Unit *confSList[10] = 
{
	&confS0, &confS1, &confS2, &confS3, &confS4,
	&confS5, &confS6, &confS7, &confS8, &confS9
};

// Holds entity.
Unit *placeholder; 

/*
	Map
*/

int mapSize = 11;
MapClass Map(mapSize);

/*
	Function declarations/prototypes
*/

void startMap();

/*
	Main
*/

int main(int argc, char *argv[])
{
	srand(time(NULL));
	startMap();
	Map.draw();
	return 0;
}

void startMap()
{
	for (int i=0; i<(mapSize-1)/2; i++) Map.place(1, (i+1)*2, unionSList[i]);
	for (int i=0; i<(mapSize-1)/2; i++) Map.place(mapSize-1, (i*2)+1, confSList[i]);
}