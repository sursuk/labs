#include<stdio.h>

int A()
{
	int number;
	int i;
	printf("input number: "); scanf("%d", &number);

	for (i = 2; i < number; i += 2)
	{
		if (number % i == 0)
			printf("%c\n", i);
	}
	return 0;
}

int B()
{

}

int C()
{

}

int main()
{
	char letter;
	printf("input letter: "); scanf("%c", &letter);
	switch (letter)
	{
	case 'A':
		A();
		break;
	default:
		break;
	}

	return 0;
}