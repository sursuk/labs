#include<stdio.h>

int main()
{
	int a, b, c;
	//���� ���� ����� �����
	printf("Input number a: "); scanf("%d",&a);
	printf("Input number b: "); scanf("%d",&b);
	printf("Input number c: "); scanf("%d",&c);

	//����� ����� ������� � ������� �����
	printf("%d + %d = %d \n ", a, b, a + b );

	//���
	//����� ������-��������������� ��������
	printf("(%d + %d + %d) / 3 = %f", a, b, c, (a + b + c) / 3.0);
	return 0;
}