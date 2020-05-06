#include<iostream>
#include<ctime>
#include"Header.h"

using namespace std;


int main()
{
    int order;
    int temp;
    srand(time(0));
    cout << "input order of matrix: "; cin >> order;

    int** matrix;
    matrix = new int* [order];
    for (int i = 0; i < order; i++)
        matrix[i] = new int[order];


    cout << "input 1 for test: "; cin >> temp;
    if (temp == 1)
    {
        for (int i = 0; i < order; i++)
            for (int j = 0; j < order; j++)
            {
                int rannum = rand() % 26 -10;
                cout << "(" << j << ";" << i << "): ";
                matrix[j][i] = rannum;
                cout << matrix[j][i]<<endl;
            }
    }
    else 
    {
        for (int i = 0; i < order; i++)
            for (int j = 0; j < order; j++)
            {
                cout << "(" << j << ";" << i << "): ";
                cin >> matrix[j][i];
            }
    }
    cout << endl << det_function(matrix, order) << endl;

    for (int j = 0; j < order; j++)
        delete[] matrix[j];
    delete[] matrix;
    return 0;
}