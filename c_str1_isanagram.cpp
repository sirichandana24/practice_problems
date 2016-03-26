/*to check whether 2 strings are anagrams or not*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
bool isanagram(char*, char*);
void main()
{
	char *str1='\0',*str2='\0';
	str1 = (char*)malloc(100 * sizeof(char));
	str2 = (char*)malloc(100 * sizeof(char));
	printf("enter the string:");
	gets(str1);
	printf("enter the string to be checked for anagram:");
	gets(str2);
	if(isanagram(str1, str2))
		printf("the strings are anagrams to each other");
	else
		printf("not anagrams");
	_getch();
}
bool isanagram(char *str1, char *str2)
{
	int *buffer1, *buffer2, i = 0;
	buffer1 = (int*)calloc(256 , sizeof(int));
	buffer2 = (int*)calloc(256 , sizeof(int));
	for (i = 0; str1[i] && str2[i]; i++)
	{
		buffer1[str1[i]]++;//takes buffers that count the characters 
		buffer2[str2[i]]++;//if each character count is equal then they are anagrams to each other
	}
	if (str1[i] || str2[i])
		return false;
	for (i = 0; i < 256; i++)
		if (buffer1[i] != buffer2[i])
			return false;
	return true;
}

