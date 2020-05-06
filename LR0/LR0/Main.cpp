#include<stdio.h>

int main()
{
	int a, b, c;
	//Ввод трех целых чисел
	printf("Input number a: "); scanf("%d",&a);
	printf("Input number b: "); scanf("%d",&b);
	printf("Input number c: "); scanf("%d",&c);

	//Вывод суммы первого и второго числа
	printf("%d + %d = %d \n ", a, b, a + b );

	//ДОП
	//Вывод средне-арифметического значения
	printf("(%d + %d + %d) / 3 = %f", a, b, c, (a + b + c) / 3.0);
	return 0;
}