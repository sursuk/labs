//Ввести матрицу размером 5х5 и найти все её седловые точки(вывести их индексы).
//Седловая точка - это максимум по строке и минимум в столбце или наоборот.

#include<iostream>
#include<limits>
#include<ctime>

#define lenght 5

using namespace std;

int found_min(int (&mas)[lenght][lenght], int position)
{
	int min = INT_MAX;
	for (int i = 0; i < lenght; i++)
	{
		if (mas[i][position] < min)
		{
			min = mas[i][position];
		}
	}
	return min;
}

int found_max(int (&mas)[lenght][lenght], int position)
{
	int max = INT_MIN;
	for (int i = 0; i < lenght; i++)
	{
		if (mas[i][position] > max)
		{
			max = mas[i][position];
		}
	}
	return max;
}



int main()
{
	int matrix[lenght][lenght];
	int min = INT_MAX, max = INT_MIN;
	int temp;

	srand(time(0));
	cout << "input 1 for test: "; cin >> temp;
	if (temp==1)
	{
		for (int i = 0; i < lenght; i++)
			for (int j = 0; j < lenght; j++)
			{
				cout << "(" << i << ";" << j << "): ";
				matrix[i][j] = rand() % 21 - 10;
				cout << matrix[i][j] << endl;
			}
	}
	else
	for (int i = 0; i < lenght; i++)
		for (int j = 0; j < lenght; j++)
		{
			cout << "(" << i << ";" << j << "): ";
			cin >> matrix[i][j];
		}

	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j < lenght; j++)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
			}
			if (matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
		}
		for (int j = 0; j < lenght; j++)
		{
			if(matrix[i][j] == max)
				if (max == found_min(matrix, j))
					cout << "(" << i << ";" << j << ")" << endl;
			if(matrix[i][j] == min)
				if (found_max(matrix, j) == min)
					cout << "(" << i << ";" << j << ")" << endl;
		}
		min = INT_MAX;
		max = INT_MIN;
	}
	return 0;
}