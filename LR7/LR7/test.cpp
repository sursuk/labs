#include<ctime>
#include<limits>
#include"my_lab.h"
#include <iostream>

using namespace std;
long random()
{
	return (rand() % (1-(-1)+1) + (-1) ) * rand() | (rand() * (rand() % 10000));
}
void test(int lenght)
{
	char *string = new char[8];
	long rannum;

	srand(time(0));
	cout << dec << LONG_MAX << " - "; ltoah(LONG_MAX, string); cout << "|" << " true number: " << hex << LONG_MAX << endl;
	cout << dec << LONG_MIN<< " - "; ltoah(LONG_MIN, string); cout << "|" << " true number: " << hex << LONG_MIN << endl;
	cout << "0 - "; ltoah(0, string); cout << "|" << " true number: " << hex << "00000000" << endl << endl;;
	for (int i = 0; i < lenght; i++)
	{
		rannum = random();
		std::cout << dec << rannum << " - ";
		ltoah(rannum, string);
		cout << "|" << " true number: " << hex << rannum << endl;
	}
}