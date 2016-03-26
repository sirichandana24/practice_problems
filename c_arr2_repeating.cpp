/*program that finds first repeating number in an array*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int repeating(int*,int);
void main()
{
	int *arr, len,i;
	printf("enter length of array:");
	scanf("%d", &len);
	if (len < 1)
		printf("invalid input");
	else{
		arr = (int*)malloc(len*sizeof(int));
		printf("enter array elements:");
		for (i = 0; i < len; i++)
			scanf("%d", &arr[i]);
			int res = repeating(arr, len);
			if (res == 'a')
				printf("no repeating element");
			else
				printf("the first repeating element is:%d", res);
	}
	_getch();
}
int repeating(int *arr, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (arr[i] == arr[j])//if equal returns the number
				return arr[i];
		}
	}
	return 'a';//if no number is repeating returns 'a'
}