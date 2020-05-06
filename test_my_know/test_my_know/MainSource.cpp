#include <stdio.h> 
#include <string.h> 
int main() {
	int i, id, min, count, len;
	char s[256] = { 0 };
	printf("Entered string\n");
	fgets(s, 256, stdin);
	fflush(stdin);
	len = strlen(s);
	min = 255;
	id = 0;
	count = 0;

	
	for (i = 0; i < len; i++)
		if (s[i] != ' ')
			count++;
		else {
			if ((count < min) && (count!=0))/*я здесь добавил еще одно условие, что счетчик не равен 0*/ {
				min = count;
				id = i - count;
			}
			count = 0;
		}

	if (count < min) {
		min = count;
		id = i - count;
	}
	min += id;
	for (i = id; i < min; i++)
		putchar(s[i]);
	printf("\n");
	return 0;
}