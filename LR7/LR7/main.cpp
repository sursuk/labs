//Написать функцию для перевода переменной типа long в символьную строку в шестнадцатеричном представлении
//(ltoah(long num, char s[])) и тестирующую программу к ней.

#include<iostream>
#include"my_lab.h"

using namespace std;

int main()
{
	long number;
	char* string = new char[8];
	int flip_flop, lenght;

	cout << "input 1 if you want using test program for testing programm: "; cin >> flip_flop;
	cin.ignore(32767, '\n');
	if (flip_flop == 1)
	{
		cout << "Input quantity random number: "; cin >> lenght;
		test(lenght);
	}
	else {
		cout << "input long number: "; cin >> number; cout << endl;
		ltoah(number, string);
		cout << endl;
	}
	delete [] string;
	return 0;
}