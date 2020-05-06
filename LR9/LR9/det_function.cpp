#include"Header.h"
#include<iostream>

using namespace std;

int det_function(int **matrix, int order)
{
	int det = 0;
	if (order == 1)
	{
		det = matrix[0][0];
	}
	else if (order == 2)
	{
		det = matrix[0][0]*matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else 
	{
		for (int i = 0; i < order; i++)
		{
			int** new_matrix;
			new_matrix = new int * [order - 1];
			for (int j = 0; j < order - 1; j++)
				new_matrix[j] = new int[order - 1];

			for (int y = 1, y1 = 0; y < order; y++, y1++)
			{
				for (int x = 0, x1 = 0; (x < order); x++)
				{
					if (x != i)
					{
						new_matrix[x1][y1] = matrix[x][y];
						x1++;
					}
				}
			}

			if ((i % 2 != 0) && (i != 0))
			{
				det += -1 * matrix[i][0] * det_function(new_matrix, order - 1);
			}
			else
			{
				det += matrix[i][0] * det_function(new_matrix, order - 1);
			}

			for (int j = 0; j < order - 1; j++)
				delete [] new_matrix[j];
			delete [] new_matrix;
		}
	}
	return det;
}