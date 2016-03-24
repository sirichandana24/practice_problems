/*program to print all the duplicate characters within a string*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
char* duplicate_chars(char*);
void main()
{
	char *str,*res;
	str = (char*)malloc(100 * sizeof(char));
	printf("enter the string:");
	gets(str);
	res = duplicate_chars(str);
	if (res == NULL)
		printf("NULL string or no duplicate characters");
	else
	{
		printf("the duplicate characters are:");
		while (*res != '\0')
		{
			printf("%c ", *res);
			*res++;
		}

	}
		_getch();
}
char* duplicate_chars(char* str)
{
	char *dup_chars;
	int i = 0,*buffer,j=0;
	if (str == NULL)//returns null if string is null
		return NULL;
	dup_chars = (char*)malloc(10 * sizeof(char));
	buffer = (int*)calloc(256, sizeof(int));
	while (str[i] != '\0')
	{
		buffer[str[i]]++;//increments the buffer if the character occurs more than once
		i++;
	}
	j = 0;
	for (i = 0; i < 256; i++)
	{
		if (buffer[i]>1)
		{
			dup_chars[j] = i;
			j++;
		}
	}
	*(dup_chars + j) = '\0';
	if (j == 0)
		return NULL;//returns null if there are no duplicate characters
	else
		return dup_chars;
}
