/*in a sorted sting 2 letters are swapped we need to find those 2 letters and fix them*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char* fix_2_letters(char*);
void main()
{
	char *str1 = '\0',*res;
	str1 = (char*)malloc(100 * sizeof(char));
	printf("enter string1:");
	gets(str1);
	res = fix_2_letters(str1);
	if (res == NULL)
		printf("invalid input");
	else
	puts(res);
	_getch();
}
char* fix_2_letters(char *str1)
{
	char t;
	int i=0,j,len,count=0,great_count=0;
	while (str1[i] != '\0')
		i++;
	len = i;
	j = i - 1;
	i = 0;
	for (i = 0; i<len-1; i++)
	{
		if (str1[i] <= str1[i + 1])
			count++;
		else
			great_count++;//count of swapped characters-1
	}
	if (count == len - 1)
		return str1;
	else{
		if (great_count == 1)//if only 1 character is swapped with another function is performed
			//else original string is returned
		{
			i = 0;
			while ((str1[i] <= str1[i + 1]) && i<len)
				i++;
			while ((str1[j] >= str1[j - 1]) && j > 0)
				j--;
			t = str1[i];
			str1[i] = str1[j];
			str1[j] = t;
			return str1;
		}
		else
			return NULL;
	}
}