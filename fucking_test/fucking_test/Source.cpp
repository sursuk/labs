
#include<iostream>
#include<climits>

using namespace std;


int find_max_dote(bool **matrix, int lenght, int from_dote)
{
	int max = INT_MIN;
	for (int i = 0; i < lenght; i++)
		if (matrix[from_dote][i] == true)
			max = i;
	return max;
}

int find_quantity_ribs(bool **matrix, int lenght, int from_dote)
{
	int count = 0;
	for (int i = 0; i < lenght; i++)
	{
		if (matrix[i][from_dote] == 1)
			count++;
	}
	return count;
}

void output_bufer(int *dotes, int size)
{
	dotes -= size;
	cout << "{ ";
	for (int i = 0; i <= size; i++, dotes++)
	{
		cout << *dotes << " ";
	}
	cout << "}" << endl;
}

int find_next_dote(bool** matrix, bool *visited_dotes, int lenght, int from_dote)
{
	for (int i = 0; i < lenght; i++)
	{
		if (matrix[i][from_dote] == 1)
		{
			if (visited_dotes[i] != 1)
				return i;
		}
	}
	return -1;
}

bool check_visited_list(bool *visited, int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		if (visited[i] == 0)
			return true; //есть не посещенные точки
	}
	return false;
}

void input_adjacency_matrix(bool **matrix, int lenght)
{
	for (int i = 0, lenght1 = 1; i < lenght; i++, lenght1++)
	{
		for (int j = 0; j < lenght1; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
			{
				cout << "(" << i << ";" << j << "): "; cin >> matrix[j][i];
				matrix[i][j] = matrix[j][i];
			}
		}
	}
}

void output_adjacency_matrix(bool **matrix, int lenght)
{
	for (int i = 0; i <= lenght; i++)
	{
		for (int j = 0; j <= lenght; j++)
		{
			if (i == 0)
			{
				if (j == 0)
					cout << "  ";
				else
					cout << j-1 << " ";
			}//откудо-то появляется тройка
			else
			{
				if (j == 0)
					cout << i-1 << " ";
				else
					cout /*<< "(" << i << ";" << j << "): "*/ << matrix[i-1][j-1]<<" ";
			}
		}
		cout << endl;
	}
}

void make_adjacence_list_from_matrix(bool **matrix, int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		cout << "[" << i << "] ";
		for (int j = 0; j < lenght; j++)
		{
			if (matrix[i][j] == 1)
				cout << j <<" ";
		}
		cout << endl;
	}
}

void make_dfc_from_matrix(bool** matrix, int lenght)
{
	bool* visited = new bool[lenght] {0};
	int *dotes = new int[lenght];
	
	cout << "{}" << endl;

	*dotes = 0;
	int count = 0;
	visited[0] = 1;
	output_bufer(dotes, count);
	while ((*dotes != 0)||(check_visited_list(visited, lenght) == true))
	{
		if (find_next_dote(matrix, visited, lenght, *dotes) != -1)
		{
			dotes++;
			count++;
			*dotes = find_next_dote(matrix, visited, lenght, *(dotes-1));
			visited[*dotes] = 1;
		}
		else
		{
			dotes--;
			count--;
		}
		output_bufer(dotes, count); 
	}
	cout << "{}" << endl;
	delete[]dotes;
	delete[]visited;
}

void find_and_output_return_ribs_in_dfc(bool **matrix, int lenght)
{
	int* visited_time = new int[lenght] {0};
	bool* visited = new bool[lenght] {0};
	int* dotes = new int[lenght];

	*dotes = 0;
	int count = 0;
	visited[0] = 1;
	
	while ((*dotes != 0) || (check_visited_list(visited, lenght) == true))
	{
		if (find_next_dote(matrix, visited, lenght, *dotes) != -1)
		{
			dotes++;
			count++;
			*dotes = find_next_dote(matrix, visited, lenght, *(dotes - 1));
			visited[*dotes] = 1;
			visited_time[*dotes] = *(dotes - 1);
		}
		else
		{
			dotes--;
			count--;
		}
	}

	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j < lenght; j++)
		{
			if (matrix[i][j] == 1)
			{
				if ((visited[j] == 1) && (visited_time[j] != i) && (j != 0) && (visited_time[i] != j) && (visited_time[i] < j))
				{
					cout << "( " << i << ";" << j << " )" << endl;
				}
			}
		}
	}
	
	delete[]visited_time;
	delete[]dotes;
	delete[]visited;
} 

void make_bfc_from_matrix(bool **matrix,int lenght)
{
	bool *visited = new bool[lenght] {0};
	int* dotes = new int[lenght];
	int size = 0;

	cout << "{ }" << endl;
	visited[0] = 1;
	*dotes = 0;
	cout << "{ " << *dotes << " }" << endl;
	while ((check_visited_list(visited, lenght)) || (size != 0) )
	{
		int start_dotes = *(dotes-=size);
		if (size != 0)
			size--;//возможно вот туть size-- уходит в отрицательные значения
		for (int i = 0; i <= size - 1; i++, dotes++)
		{
			*dotes = *(dotes + 1);//обращайся не по и, а по дотес
		}//нужно обнулить сайз тут..точнее не обнулить а дополнить, и убрать лишний
		
		for (int j = 0; j < lenght; j++)
		{
			
			if ((matrix[start_dotes][j] == 1) && (visited[j] == 0))
			{
				*dotes = j;
				visited[j] = 1;
				dotes++;
				size++;
			}
		}
		output_bufer(dotes-1, size-1);
	}
	cout << endl;

	delete[]visited;
	delete[]dotes;
}

void find_and_output_return_ribs_in_bfc(bool **matrix,int lenght) //и эта
{
	int* visited_time = new int[lenght] {0};
	bool* visited = new bool[lenght] {0};
	int* dotes = new int[lenght];
	int size = 0;

	visited[0] = 1;
	*dotes = 0;
	while ((check_visited_list(visited, lenght)) || (size != 0))
	{
		int start_dotes = *(dotes -= size);
		if (size != 0)
			size--;//возможно вот туть size-- уходит в отрицательные значения
		for (int i = 0; i <= size - 1; i++, dotes++)
		{
			*dotes = *(dotes + 1);//обращайся не по и, а по дотес
		}//нужно обнулить сайз тут..точнее не обнулить а дополнить, и убрать лишний

		for (int j = 0; j < lenght; j++)
		{

			if ((matrix[start_dotes][j] == 1) && (visited[j] == 0))
			{
				*dotes = j;
				visited[j] = 1;
				visited_time[j] = start_dotes;
				dotes++;
				size++;
			}
		}
	}

	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j < lenght; j++)
		{
			if (matrix[i][j] == 1)
			{
				if ((visited[j] == 1) && (visited_time[j] != i) && (j != 0) && (visited_time[i] != j) && (visited_time[i] < j) && (i < j))
				{
					cout << "( " << i << ";" << j << " )" << endl;
				}
			}
		}
	}


	cout << endl;

	delete[]visited_time;
	delete[]visited;
	delete[]dotes;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int quantity;
	cout << "Введите кол-во вершин: "; cin >> quantity;
	bool** matrix = new bool* [quantity];
	for (int i = 0; i < quantity; i++)
		matrix[i] = new bool[quantity];
	cout << "ЕСли вершины соедены введите 1 иначе 0" << endl;
	input_adjacency_matrix(matrix, quantity);
	cout << "------------матрица смежности-------" << endl;
	output_adjacency_matrix(matrix, quantity);
	cout << "-----------список смежности------------" << endl;
	make_adjacence_list_from_matrix(matrix, quantity);
	cout << "-----------поиск графа в глубину (dfc)----------" << endl;
	make_dfc_from_matrix(matrix, quantity);
	cout << "-----------поиск в глубину (dfc) вывод обратных ребер----------" << endl;
	find_and_output_return_ribs_in_dfc(matrix, quantity);
	cout << "---------поиск в ширину (bfc)-----------" << endl;
	make_bfc_from_matrix(matrix, quantity);
	cout << "----------поиск в ширину обратные ребра(bfc)-----------" << endl;
	find_and_output_return_ribs_in_bfc(matrix, quantity);
	cout << "----------------------------------" << endl;
	
	for (int i = 0; i < quantity; i++)
		delete[]matrix[i];
	delete[]matrix;
	system("pause");
	return 0;
}