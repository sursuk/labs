#include <iostream>

using namespace std;
void new_matrix_output(int** matrix, int order)
{
	cout << "---------------------------------------" << endl;
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
			cout << matrix[j][i]<<" ";
		cout << endl;
	}
	cout << "---------------------------------------" << endl;
}