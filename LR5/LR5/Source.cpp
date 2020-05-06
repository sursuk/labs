#include<stdio.h>

#define STR_LEN 100

//функция ввода строки
void inputstr(char* str, int lenght)
{
	int i;
	char c;
	for (i = 0; ((c = getchar()) != '\n') && (i < lenght - 1); i++)
	{
		*str = c;
		str++;
	}
	*str = '\0';
	if ((i >= lenght) || (c != '\n'))
		while (getchar() != '\n')
} 


//функция нахождения вхождения слова
int strf(char *str1, char const *str2, int start)
{
	str1 = str1 + start;

	for ( ; *str2 != '\0'; str1++, str2++)
		if (*str1 != *str2)
			return 0;
	return 1;
}

int main()
{
	char str[STR_LEN];
	char str1[STR_LEN];

	int i;
	int j = 0;

	printf("Input string: "); inputstr(str, STR_LEN);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (strf(str, "one", i))
		{
			str1[j] = '1';
			i+=2;
			j++;
		}
		else if (strf(str, "two", i))
		{
			str1[j] = '2';

			i+=2;
			j++;
		}
		else if (strf(str, "three", i))
		{
			str1[j] = '3';
			i+=4;
			j++;
		}
		else if (strf(str, "four", i))
		{
			str1[j] = '4';
			i += 3;
			j++;
		}
		else if (strf(str, "five", i))
		{
			str1[j] = '5';

			i += 3;
			j++;
		}
		else if (strf(str, "six", i))
		{
			str1[j] = '6';

			i += 2;
			j++;
		}
		else if (strf(str, "seven", i))
		{
			str1[j] = '7';

			i += 4;
			j++;
		}
		else if (strf(str, "eight", i))
		{
			str1[j] = '8';

			i += 4;
			j++;
		}
		else if (strf(str, "nine", i))
		{
			str1[j] = '9';

			i += 3;
			j++;
		}
		else if (strf(str, "zero", i))
		{
			str1[j] = '0';

			i += 3;
			j++;
		}
		else
		{
			str1[j] = str[i];
			j++;
		}
	}

	str1[j] = '\0';
	for (j = 0; str1[j] != '\0'; j++)
		printf("%c", str1[j]);
	return 0;
}