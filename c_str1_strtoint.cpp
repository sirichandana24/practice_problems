/*program that converts a string to an integer*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int str_to_int(char*);
int length(char*);
void main()
{
	char *str = '\0';
	int res;
	str = (char*)malloc(100 * sizeof(char));
	printf("enter string1:");
	gets(str);
	if (*str == NULL)
		printf("invalid input");
	else
	{
		res = str_to_int(str);
		if (res == 'a')
			printf("invalid input");
		else
			printf("%d", res);
	}
	_getch();
}
int str_to_int(char *str)
{
	int i=0,rem,num=0,len=0,count=0;
	len = length(str);
	while (str[i] != '\0')
	{
		if (str[0]=='-'||(str[i] >= '0'&&str[i] <= '9'))
			count++;
		i++;
	}
	if (count == len)
	{
		i = 0;
		if (str[0] == '-' && str[1] == '\0')
			return 'a';
		else
			if (str[0] == '-')
			i++;
		while (str[i] != '\0')
		{
			rem = str[i] - '0';
			num = num * 10 + rem;
			i++;
		}
		if (str[0] != '-')
			return num;
		else
			return -num;
	}
	else
		return 'a';//returns a if string is other than an integer 
}
int length(char *str1)
{
	int i = 0;
	while (*str1 != '\0')
	{
		*str1++;
		i++;
	}
	return i;
}