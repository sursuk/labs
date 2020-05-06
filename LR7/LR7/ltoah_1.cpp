#include<iostream>
#include"my_lab.h"

using namespace std;

void ltoah(long num, char s[])
{
	int mas[8];
	int bit;
	int bit_znak = 0;
	int temp;

	const char letter[] = "0123456789ABCDEF";
	if (num == 0)
	{
		for (int i = 0; i < 8; i++)
		{
			s[i] = '0';
		}
	}
	else
	{
		if (num < 0)
		{
			bit_znak = 8;
			num += 0x7FFFFFFF;
		}
		for (int i = 0; i < 8; i++, num /= 16)
		{
			mas[i] = num % 16;
		}

		if(bit_znak == 8)
		{
			mas[0]++;
			if (mas[0] > 15)
			{
				bit = 1;
				mas[0] = 0;
				for (int i = 1; i < 8; i++)
				{
					mas[i] += bit;
					if (mas[i] > 15)
					{
						bit = 1;
						mas[i] = 0;
					}
					else
						break;
				}
			}
		}

		mas[7] += bit_znak;

		for (int i = 0, j = 7; i < 8; i++, j--)
		{
			s[i] = letter[mas[j]];
		}
	}
	for (int i = 0; i < 8; i++)
	{
		cout << s[i];
	}
}