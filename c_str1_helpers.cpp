/*helper functions like length,substring,concatenation,string reverse and string comparision*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int str_length(char*);
int str_compare(char*, char*);
char* str_concat(char*, char*);
bool sub_string(char*, char*);
char* str_reverse(char*);
void main()
{
	char *str,*str1,*res;
	int length;
	str = (char*)malloc(100 * sizeof(int));
	str1 = (char*)malloc(100 * sizeof(int));
	printf("enter string for which length is to be calculated:");
	gets(str);
	length = str_length(str);
	printf("the length of string is:%d", length);
	printf("\nenter string to be compared:");
	gets(str);
	printf("enter string to be compared to:");
	gets(str1);
	if (str_compare(str, str1))
		printf("strings are equal");
	else
		printf("strings are not equal");
	printf("\nenter string which is to be concatenated:");
	gets(str);
	printf("enter string for which it is to be concatenated to:");
	gets(str1);
	res = str_concat(str, str1);
	if (res == NULL)
		printf("null string is given as input");
	else
	puts(res);
	printf("enter the string in which substring is to be found:");
	gets(str);
	printf("enter the substring to be checked");
	gets(str1);
	if (sub_string(str, str1))
		printf("found substring");
	else
		printf("substring not found");
	printf("\nenter the string for which reverse is to be found:");
	gets(str);
	res = str_reverse(str);
	if (res == NULL)
		printf("null input");
	else
	puts(res);
	_getch();
}
int str_length(char *str)
{//function that calculates length of the given string
	int i=0;
	while (*str != NULL)
	{
		*str++;
		i++;
	}
	return i;
}
int str_compare(char *str, char *str1)
{//compares the 2 given strings
	int i = 0,j=0;
	while (*str != '\0' || *str1 != '\0')
	{
		if (*str == *str1)
			i++;
		else
			j++;
		*str++; *str1++;
	}
	if (j > 0)
		return 0;
	else
		return 1;
}
char* str_concat(char *str, char *str1)
{//concats the 2 given strings
	if (str == NULL && str1 == NULL)
		return NULL;
	if (str == NULL)
		return str1;
	if (str1 == NULL)
		return str1;
	int i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	int k = 0;
	while (str1[k] != '\0')
	{
		str[i++] = str1[k++];
	}
	*(str + i) = '\0';
	return str;
}
char* str_reverse(char *str)
{//calculates the reverse of string
	int i = 0;
	if (str == NULL)
		return NULL;
	while (str[i] != '\0')
	{
		i++;
	}
	int len = i;
	int j = len - 1;
	char t;
	i = 0;
	while (i < j)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
		i++;
		j--;
	}
	return str;
}
bool sub_string(char *str, char *str1)
{//finds the substring of a given string
	if (str == NULL || str1 == NULL)
		return false;
	int i = 0, length, count = 0, j = 0, freq = 0, index = 0;
	while (str1[i] != '\0')
		i++;
	length = i;
	i = 0;
	while (str[i] != '\0')
	{
		while (str1[j] != '\0')
		{
			if (str[i] == str1[j])
				count++;
			i++;
			j++;
		}
		if (count == length)
			return 1;
		index++;
		i = index;
		j = 0;
		count = 0;
	}
	return 0;
}
