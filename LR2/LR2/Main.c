#include<stdio.h>
#include<locale.h>
#include<stdbool.h> //исключительно для человеческого названия bool

#define STR_LEN 101	

//функция ввода строки
int inputstr(char *str)
{
	int i, c;
	for (i = 0; ((c=getchar()) != '\n') && (i < STR_LEN-1); i++)
	{
		*str = c;
		str++;
	}
	*str = '\0';
	if (i> STR_LEN-2)
		return 1;
	else 
		return 0;
}

//функция проверки, является ли эта буква буквой
bool symbol(char sym)
{
	return (((sym >= 'a') && (sym <= 'z')) || ((sym >= 'A') && (sym <= 'Z')) || ((sym >= '0') && (sym <= '9')));
}

//функция вывода слова
void Word(char *str, int start)
{
	for (str=str+start*sizeof(char); symbol(*str)/*^*/; str++)
	{
		printf("%c",*str);
	}
	printf("\n");
}

//функция возращения размера массива включая нулевой символ
int sizestr(char* str)
{
	int i;
	for (i = 0; *str != '\0'; i++)
	{
		str++;
	}
	return i;
}


int main()
{
	setlocale(LC_ALL, "rus");
	
	char str[STR_LEN];
	int lenght, count = 0;
	int i, sc=0, sc1=0;
	int max=1, min=100;
	int start=0;
	char trash = 'a';

	printf("input string: ");
	
	if(inputstr(str)==1/*^*/)
		while (trash != '\n') //тут косячно нужен ентер, разберись
			trash = getchar();

	printf("input lenght words: ");
	scanf("%d", &lenght);


	printf("Слова не заданной длины:\n");
	for (i=0 ; i<=sizestr(str)/*^*/; i++)
	{
		if (symbol(str[i])/*^*/)
		{
			count++;
		}
		else
		{
			if (symbol(str[i-1]))
			{
				if (count == lenght)
					sc++;
				else
				{
					sc1++;
					Word(str, i - count);/*^*/
					if (max < count)
						max = count;
					if (min > count)
						min = count;
				}
			}
			count = 0;
		}
	}
	printf("Кол-во слов заданной длины: %d\n", sc);
	printf("Кол-во слов не заданной длины: %d\n", sc1);
	if(sc1!=0)
		printf("Средная длина слов не заданной длины: %d",(max+min)/2);
	return 0;
}
