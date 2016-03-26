/*program that evaluates the first first non repeating number in an array of integers*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int non_repeating(int*, int);
void main()
{
	int *arr, len, i;
	printf("enter length of array:");
	scanf("%d", &len);
	arr = (int*)malloc(len*sizeof(int));
	printf("enter array elements:");
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	int res = non_repeating(arr, len);
	if (res == 'a')
		printf("no non repeating element");
	else
		printf("the first non repeating element is:%d", res);
	_getch();
}
int non_repeating(int *arr, int len)
{
	int i, count = 0, j = 0;
	for (i = 0; i < len; i++)
	{
		count = 0;
		for (j = 0; j < len; j++)
		{
			if (i!=j && arr[i] == arr[j]) {
				count = 1;//initializes count to 1 if repeated
				break;
			}
		}

		if (count == 0) {//checks if count is 0 and returns it if not repeated
			return arr[i];
		}
	}
	return 'a';//returns 'a' if every number is repeated
}
