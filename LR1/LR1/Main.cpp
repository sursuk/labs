#include<stdio.h>

int A()
{
	int number;
	int i;
	printf("input number: "); scanf("%d", &number);

	for (i = 2; i < number; i += 2)
	{
		if (number % i == 0)
			printf("%d\n", i);
	}
	return 0;
}

int B() 
{
	int number, sum=0;
	int i;
	printf("input number: "); scanf("%d", &number);
	for (i = 1; i <= number; i++)
	{
		sum += i * i;
	}
	printf("%d", sum);
	return 0;
}

int C()
{
	int number;
	printf("input number: "); scanf("%d", &number);
	for ( ; number != 0; number /= 10)
	{
		if (((number % 10) % 2) != 0)
			printf("%d\n", number % 10);
	}
	return 0;
}

int D()
{
	char number[100], c;
	int i;
	printf("input number: "); 

	c = getchar();
	for (i = 0; ((c = getchar()) != '\n') && (i < 100); i++) 
	{
		number[i] = c;
	}
	number[i] = '\0';

	for (i=0; number[i] != '\0'; i++)
	{
		if ((i % 2) != 0)
			printf("%c\n", number[i]);
	}
	return 0;
}

int E()
{
	int number;
	int result = 1;

	printf("input number: "); scanf("%d", &number);

	for (; number != 0; number /= 10)
	{
		result *= (number % 10);
	}
	printf("%d\n", result);
	return 0;
}

int F()
{
	int number;
	int max = 0;

	printf("input number: "); scanf("%d", &number);

	for (; number != 0; number /= 10)
	{
		if ((number % 10) > max)
			max = number % 10;
	}
	printf("%d\n", max);
	return 0;
}

int G()
{
	char number[6], c;
	int i;
	printf("input number: ");

	c = getchar();
	for (i = 0; ((c = getchar()) != '\n') && (i < 6); i++)
	{
		number[i] = c;
	}
	number[i] = '\0';
	
	printf("%c\n", number[2]);
	return 0;
}

int H()
{
	int M, N;
	int i;

	printf("input M: "); scanf("%d", &M);
	printf("input N: "); scanf("%d", &N);

	for (i=1; (i<=N) && (i<=M); i++)
	{
		if (((M % i) == 0) && ((N % i) == 0))
			printf("%d\n", i);
	}
	return 0;
}

int I()
{
	int M, N;
	int i;

	printf("input M: "); scanf("%d", &M);
	printf("input N: "); scanf("%d", &N);

	for (i = 1; (i <= N) || (i <= M); i++)
	{
		if (((M % i) == 0) != ((N % i) == 0))
			printf("%d\n", i);
	}
	return 0;
}

int J()
{
	int number;
	int i;

	printf("input number: "); scanf("%d", &number);

	for (i = 2; i < number; i *= 2)
	{
		printf("%d\n", i);
	}
	return 0;
}

int K()
{
	int number;
	int i, j;

	printf("input number: "); scanf("%d", &number);

	for (i = 1; i <= number; i++)
	{
		for(j=1; j <= number; j++)
			if ((i * j) == number)
				printf("%d * %d\n", i, j);
	}
	return 0;
}

int L()
{
	int M, N;
	int i;
	int count0 = 0, count1 = 0;

	printf("input M: "); scanf("%d", &M);
	printf("input N: "); scanf("%d", &N);

	for (i = 1; i <= M; i++)
	{
		if ((M % i) == 0)
			count0++;
	}
	for (i = 1; i <= N; i++)
	{
		if ((N % i) == 0)
			count1++;
	}
	if (count0 < count1)
		printf("%d\n", N);
	else
		printf("%d\n", M);
	return 0;
}

int M()
{
	int number;
	int i, j;

	printf("input number: "); scanf("%d", &number);

	for (i = 0; i <= number; i++)
	{
		for (j = 0; j <= number; j++)
			if ((i + j) == number)
				printf("%d + %d\n", i, j);
	}
	return 0;
}

int N()
{
	char number[100], c;
	int i, j;
	int count = 0, size = 0;

	printf("input number: ");

	c = getchar();
	for (i = 0; ((c = getchar()) != '\n') && (i < 100); i++)
	{
		number[i] = c;
	}
	number[i] = '\0';

	for (i = 0; number[i] != '\0'; i++)
	{
		for (j = 0; number[j] != '\0'; j++)
		{
			if (i != j)
			{
				size++;
				if (number[i] == number[j])
				{
					count++;
				}
			}
		}
	}

	if (count == size)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

int main()
{
	char letter;
	int check = 1;
	do
	{
	printf("input letter of task: "); scanf("%c", &letter);
	switch (letter)
	{
	case 'A':
		check = A();
		break;
	case 'B':
		check = B();
		break;
	case 'C':
		check = C();
		break;
	case 'D':
		check = D();
		break;
	case 'E':
		check = E();
		break;
	case 'F':
		check = F();
		break;
	case 'G':
		check = G();
		break;
	case 'H':
		check = H();
		break;
	case 'I':
		check = I();
		break;
	case 'J':
		check = J();
		break;
	case 'K':
		check = K();
		break;
	case 'L':
		check = L();
		break;
	case 'M':
		check = M();
		break;
	case 'N':
		check = N();
		break;

	default:
		check = 1;
		break;
	}
	}while (check);
return 0;
}