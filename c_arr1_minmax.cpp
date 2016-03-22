#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int* minmax(int *arr, int len);
void main()
{
	int *arr=NULL, len,i,*res;
	printf("enter length of array:");
	scanf("%d", &len);
	if ( len < 1)
		printf("invalid input");
	else{
		arr = (int*)malloc(len*sizeof(int));
		printf("enter array elements:");
		for (i = 0; i < len; i++)
			scanf("%d", &arr[i]);
		res = minmax(arr, len);
		printf("the min element is %d\n", res[0]);
		printf("the max element is %d", res[1]);
	}
	_getch();
}
int* minmax(int *arr, int len)
{
	int *arr1,i=0;
	arr1 = (int*)malloc(2 * sizeof(int));
	if (len % 2 == 0)
	{
		if (arr[0]>arr[1])
		{
			arr1[1] = arr[0];
			arr1[0] = arr[1];
		}
		else
		{
			arr1[0] = arr[0];
			arr1[1] = arr[1];
		}
		i = 2;
	}
	else
	{
		arr1[0] = arr[0];
		arr1[1] = arr[0];
		i = 1;
	}
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			if (arr[i] > arr1[1])
				arr1[1] = arr[i];
			if (arr[i + 1] < arr1[0])
				arr1[0] = arr[i + 1];
		}
		else
		{
			if (arr[i + 1] > arr1[1])
				arr1[1] = arr[i + 1];
			if (arr[i] < arr1[0])
				arr1[0] = arr[i];
		}
		i =i+2; 
	}
	return arr1;
}