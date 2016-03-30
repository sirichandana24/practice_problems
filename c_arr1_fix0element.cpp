/*given an array of n numbers ranging from 1 to 500 .Now one element is changed to '0' find that element*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int fix_0_element(int *arr, int len);
void main()
{
	int *arr, len, i, res;
	printf("enter length of array:");
	scanf("%d", &len);
	if (len < 0)
		printf("invalid input");
	else{
		arr = (int*)malloc(len*sizeof(int));
		printf("enter array elements:");
		for (i = 0; i < len; i++)
			scanf("%d", &arr[i]);
		res = fix_0_element(arr, len);
		if (res != 0)
			printf("the element replaced with 0 is %d", res);
		else
			printf("no element is replaced");
	}
	_getch();
}
int fix_0_element(int *arr, int len)
{
	int i, *arr1;
	arr1 = (int*)calloc(500 , sizeof(int));
	for (i = 0; i < len; i++)
		arr1[arr[i]] = 1;//each element of buffer is allocated with 1 for element existing within input array
	for (i = 1; i <=len; i++)
	{
		if (arr1[i] == 0) //if element in buffer is 0 then that is the element which is changed to '0'
			return i;
	}
		
}