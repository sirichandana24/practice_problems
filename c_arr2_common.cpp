/*given 3 arrays in sorted order this program calculates the common elements between the three arrays*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int* common_elements(int*, int, int*, int, int*, int);
void main()
{
	int len1, len2, len3,i;
	int *arr1, *arr2, *arr3,*res;
	printf("enter length of 1st array:");
	scanf("%d", &len1);
	printf("enter length of 2nd array:");
	scanf("%d", &len2);
	printf("enter length of 3rd array:");
	scanf("%d", &len3);
	if (len1 < 1 || len2 < 1 || len3 < 1)
		printf("invalid input");
	else{
		arr1 = (int*)malloc(len1*sizeof(int));
		arr2 = (int*)malloc(len2*sizeof(int));
		arr3 = (int*)malloc(len3*sizeof(int));
		printf("enter elements of array1:");
		for (i = 0; i < len1; i++)
			scanf("%d", &arr1[i]);
		printf("enter elements of array2:");
		for (i = 0; i < len2; i++)
			scanf("%d", &arr2[i]);
		printf("enter elements of array3:");
		for (i = 0; i < len3; i++)
			scanf("%d", &arr3[i]);
		res = common_elements(arr1, len1, arr2, len2, arr3, len3);
		i = 0;
		if (res == NULL)
			printf("invalid input");
		else{
			if (res[0] == 'a')
				printf("no numbers in common");
			else{
				printf("numbers in common are:");
				while (res[i] != 'a')
				{
					printf("%d ", res[i]);
					i++;
				}
			}
		}
	}
	_getch();
}
int* common_elements(int *arr1, int len1, int *arr2, int len2, int *arr3, int len3)
{
	int i = 0, j = 0, k = 0,*arr,index=0;
	arr = (int*)malloc(10 * sizeof(int));
	if (*arr1 == NULL || *arr2 == NULL || *arr3 == NULL)
		return NULL;
	while (i < len1 && j < len2 && k < len3)
	{
		if (arr1[i] == arr2[j] && arr2[j] == arr3[k])//comparing of numbers of three arrays
		{
			arr[index] = arr1[i];
			index++;
			i++; 
			j++;
			k++;
		}
		else if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr3[k])
			j++;
		else
			k++;
	}
	arr[index]='a';//to track last element we place it as 'a' and then return array
	return arr;
}

