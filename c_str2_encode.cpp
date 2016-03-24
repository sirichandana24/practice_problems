/*program to encode a given string i.e replace space with %20 & dot with %21*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void encode(char*);
void main()
{
	char *str;
	str = (char*)malloc(100 * sizeof(char));
	printf("enter string:");
	gets(str);
	encode(str);
	puts(str);
	_getch();
}
void encode(char *str)
{
	int i = 0,count_space_dot=0,len,len1;
	while (str[i] != '\0')
	{
		
		if (str[i] == ' ' || str[i]=='.')
		count_space_dot++;//counts the dots or spaces in a string.
		i++;
	}
	len = i;
	i = 0;
	len1 = len + count_space_dot * 2;//initializes length with that length+count*2 so it fits %20 or %21
	*(str + len1) = '\0';
	for (i = len - 1; i >= 0; i--)
	{
		if (str[i] == ' ')//for space replaces with %20
		{
			str[len1 - 1] = '0';
			str[len1 - 2] = '2';
			str[len1 - 3] = '%';
			len1 = len1 - 3;
		}
		else if (str[i] == '.')//for dot with %21
		{
			str[len1 - 1] = '1';
			str[len1 - 2] = '2';
			str[len1 - 3] = '%';
			len1 = len1 - 3;
		}
		else
		{
			str[len1 - 1] = str[i];//else puts same character
			len1 = len1 - 1;
		}
	}
}