/*program that calculates the minimum element of a rotated sorted array*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int min_rotated_array(int*, int,int);
void main()
{
	int *arr, len, i, res, low = 0, high;
	printf("enter length of array:");
	scanf("%d", &len);
	if (len < 1)
		printf("invalid input");
	else{
		high = len - 1;
		arr = (int*)malloc(len*sizeof(int));
		printf("enter array elements:");
		for (i = 0; i < len; i++)
			scanf("%d", &arr[i]);//input given should be of rotated type of sorted array
		res = min_rotated_array(arr, low, high);//finds the min element
		printf("the minimum element in a rotated sorted array is:%d", res);
	}
	_getch();
}
int min_rotated_array(int arr[], int low, int high)
{
	int mid;//uses binary search algorithm and finds min element comparing to previous and next elements
	if (high < low) 
		return arr[0];
	if (high == low) return arr[low];
	 mid = (low+high)/2; 
	if (mid < high && arr[mid + 1] < arr[mid])
		return arr[mid + 1];
	if (mid > low && arr[mid] < arr[mid - 1])
		return arr[mid];
	if (arr[high] > arr[mid])
		return min_rotated_array(arr, low, mid - 1);
	return min_rotated_array(arr, mid + 1, high);
}
