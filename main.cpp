#include "Unit.h"
#include <cstdlib>
#include <ctime>
#include "map/ObjectMatrix.h"
#include "Unit.h"

/*
Civil War Strategy Game by Cade Luinenburg
Created February 10th, 2020
*/

ObjectMatrix doesThisWork(10, 10);

int main(int argc, char *argv[])
{
	//srand(time(NULL));
	std::cout << doesThisWork.toString() << "\n";
	return 0;
}