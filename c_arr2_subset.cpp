/*Given an array of positive and negative numbers. Find the subset who’s sum is max among all the subsets*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int* subset_sum(int*, int);
void main()
{
	int i=0,len, *arr,*res;
	printf("enter length of array:");
	scanf("%d", &len);
	if (len < 1)
		printf("invalid input");
	arr = (int*)malloc(len*sizeof(int));
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	res = subset_sum(arr, len);
	printf("the subset with max sum is:");
	for (i = res[2]; i <= res[1]; i++)
		printf("%d ", arr[i]);
	printf("\nthe sum of subset is: %d", res[0]);
	_getch();
}
int* subset_sum(int *arr, int len)
{//outputs an array in which 1st location stores the sum.2nd&3rd locations store the 
	//indices of sub-array
	int max = 0, end = 0,count=0;
	int index = 0,*res;
	res = (int*)malloc(3 * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < 0)//checks for negative array
			count++;
	}
	if (count == len){//if all elements are negative returns max element and its index
		int max = arr[0];
		for (int i = 0; i < len; i++)
		{
			if (max < arr[i]){
				max = arr[i];
				index = i;
			}
		}
		res[0] = max;
		res[1] = index;
		res[2] = index;
		return res;
	}
	for (int i = 0; i < len; i++)//if array consists of positive and negative numbers
	{
		end = end + arr[i];
		if (end < 0)
			end = 0;
		if (max < end)
		{
			index = i;
			max = end;
		}
	}
	res[0] = max;//sum is stored
	res[1] = index;//end index value
	int sum = max;
	while (sum != 0)
	{
		sum = sum - arr[index];
		index--;
	}
	res[2] = index + 1;//start index value
	return res;
}