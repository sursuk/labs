#include <cstdio> 

#define lenght 100 
int lenstr(char* str);

// ���������� ������ ������ ������� � ������ ��� -1, ���� �� ������
int find(const char *str1, char *str)
{
	// i-� ������ ����� ������  ����
	// j-� ������ ����� ������� ����
	for (int i = 0; str[i]; ++i) {
		for (int j = 0;; ++j) {
			if (!str1[j]) return i; // ������� ������ 
			if (str[i + j] != str1[j]) break;
		}
		// ���� �� ������, ��������� ������� ����
	}
	// ������� ���
	return -1;
}

int lenstr(char *str)
{
	int len = 0;
	for (int i = 0; (str[i] != '\n') && (str[i] != '\0') && i < lenght; i++)
		len++;
	return len;
}

bool symbol(char sym)
{
	return (((sym >= 'a') && (sym <= 'z')) || ((sym >= 'A') && (sym <= 'Z')) || ((sym >= '0') && (sym <= '9')) || (sym == '_')); //|| ((sym >= '0') && (sym <= '9')));
}

int find_func(char *str, FILE *Header)
{
	char func[lenght];
	int last_symbol_func, first_symbol_function;
	int num_skob = 0; //for found arguments func

	//���������� ���������������� ������ ������ ��� ���
	if ((str[0] != '/') && (str[1] != '/'))
	{
		//������� ��� ������
		int temp = find("int \0", str);
		if(temp == -1)
			temp = find("float \0", str);
		if(temp == -1)
			temp = find("double \0", str);
		if (temp == -1)
			temp = find("char \0", str);
		if (temp == -1)
			temp = find("void \0", str);
		if (temp == -1)
			return 0;
		else
		 //����� ����� ���� ��������� ����������� � ������(���� �� �������)
		for (int j = lenstr(str); j >= 0; j--)
		{
			if (str[j] == ')')
			{
				num_skob = 1;
				last_symbol_func = j+1;
			}
			if(num_skob == 1)
				if (str[j] == '(')
				{
					num_skob = 2;
					break;
				}
		} //����� ����� � ������ � ��� ������, �� ������ ����� ����� ���� �������
		//� ���������� �� � ������ �������
		if (num_skob == 2)
		{
			int j = 0;
			for (int i = 0, arg = 0; i < last_symbol_func; i++)
			{
				if (j == 0)
				{
					if (symbol(str[i]))
					{
						func[j] = str[i];
						j++;
					}
				}
				else
				{
					func[j] = str[i];
					j++;
					if ((func[j-1] == ' ') && (arg == 0))
					{
						for (i++; str[i] != '('; i++, j++)
						{
							if (symbol(str[i]))
								func[j] = str[i];
							else
								return 0;
						}
						i--;
						func[j] == str[i];
						arg++;
					}
				}
			}
			func[j] = ';';
			j++;
			func[j] = '\n';
			j++;
			func[j] = '\0';
			fputs(func, Header);
		}
	}
	return 0;
}

int main()
{
	//opening file with c-source
	FILE* file;
	char path[] = "C://Users/Professional/Desktop/Source.c";
	if ((file = fopen(path, "r")) == NULL) 
		printf("Cannot open file.\n");
	//--------------
	//Make Header file
	FILE* Header;
	char pathtoHeader[] = "C://Users/Professional/Desktop/Header.h";
	Header = fopen(pathtoHeader, "w");
	//-----------------------------------

	char str[100];

	while (fgets(str, lenght, file) != NULL)
	{
		find_func(str, Header);
	}

	printf("-----------------------------------------------\n");

	fclose(Header);
	Header = fopen(pathtoHeader, "r");

	while (fgets(str, 10, Header) != NULL)
	{
		printf("%s", str);
	}

	fclose(Header);
	fclose(file);
	return 0;
}