/*given an array of N unique numbers except 1 element.we need to find that element*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int find_dup_element(int *arr, int len);
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
		res = find_dup_element(arr, len);
		if (res != 0)
			printf("the duplicate element is %d", res);
		else
			printf("no element is duplicate");
	}
	_getch();
}
int find_dup_element(int *arr, int len)
{
	int i, *arr1,max=arr[0];
	arr1 = (int*)calloc(500, sizeof(int));
	for (i = 0; i < len; i++){
		arr1[arr[i]]++;//stores count of elements into that buffer
		if (max < arr[i])
			max = arr[i];
	}
	for (i = 1; i <= max; i++)
	{
		if (arr1[i] == 2)//so as there are n unique numbers if there is a duplicate number than count will be 2
			return i;
	}
}