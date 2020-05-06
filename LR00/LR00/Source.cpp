#include <stdio.h>
#include <math.h>
int main()
{
	/*const int N = 10;
	int A[N]; */
	int A[10]; //можно так писать
	int i;
	float min;
	float lgg;
	/*int n;
	n = 0;*/
	int n = 0; //можно так писать

	for (i = 0; i < 10; i++)
	{
		printf("A[%d]= ", i);
		scanf_s("%d", &A[i]);
	}
	while (n == 0)
	{
		for (i = 0; i < 10; i++)
		{
			if ((A[i + 1] > 0) && (A[i] > 0) && (A[i] != 1))
			{
				min = (log(A[i + 1])) / (log(A[i]));
				if (min < 0)
				{
					min = min * (-1);
				}
				n = n + 1;
			}
		}
	}
	if (n == 0)
	{
		printf("there is no minimum");
	}
	for (i = 0; i < 10 - 1; i++)
	{
		if ((A[i + 1] > 0) && (A[i] > 0) && (A[i] != 1))
		{
			lgg = (log(A[i + 1])) / (log(A[i]));
			if (lgg < 0)
			{
				lgg = lgg * (-1);
			}
			printf("%f ", lgg);
			if (lgg < min)
			{
				min = lgg;
			}
		}
		else
		{
			printf("false ");
		}
	}
	printf("\n");
	printf(" min lgg is %f ", min);
	return 0;
}