/*program to find the character with maximum frequency*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char max_freq_char(char*);
void main()
{
	char *str,res;
	str = (char*)malloc(100 * sizeof(char));
	printf("enter the string:");
	gets(str);
	res = max_freq_char(str);
	printf("%c", res);
	_getch();
}
char max_freq_char(char *str)
{
	char c='a';
	int *buffer;
	int i = 0,max;
	buffer = (int*)calloc(256,sizeof(int));
	if (*str==NULL)
		return NULL;
	while (str[i] != '\0')
	{
		buffer[str[i]]++;//with the help of buffer count of each character is stored
		i++;
	}
	max = buffer[0];
	for (i = 0; i < 256; i++)
	{
		if (max < buffer[i])//max count character is returned
		{
			max = buffer[i];
			c = (char)i;
		}
	}
	return c;
}