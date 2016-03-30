/*program to find out the triplets which sum to a given number*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int** find_triplets(int *, int ,int,int* );
void main()
{
	int *arr, len, i, **res,sum,index=0;
	printf("enter length of array:");
	scanf("%d", &len);
	if (len < 0)
		printf("invalid input");
	else{
		arr = (int*)malloc(len*sizeof(int));
		printf("enter array elements:");
		for (i = 0; i < len; i++)
			scanf("%d", &arr[i]);
		printf("enter the value of sum:");
		scanf("%d", &sum);
		int **res = find_triplets(arr, len, sum, &index);
		if (res == NULL)
			printf("no triplets");
		else{
			printf("triplets are:");
			for (i = 0; i < index; i++)
			{
				for (int j = 0; j < 3; j++){
					printf("%d ", res[i][j]);
				}
				printf("\n");
			}
		}
	}
	_getch();
}
int** find_triplets(int *arr, int len,int sum,int *index)
{
	int **a;
	a = (int**)malloc(len*sizeof(int));
	for (int i = 0; i < 3; i++)
		a[i] = (int*)malloc(3 * sizeof(int));
	if (len >= 3){
		for (int i = 0; i < len - 2; i++)
		{
			for (int j = i + 1; j < len - 1; j++)
			{
				for (int k = j + 1; k < len; k++)
				{
					if (arr[i] + arr[j] + arr[k] == sum)
					{
						a[*index][0] = arr[i];//for finding triplets and then storing them into a 2D array
						a[*index][1] = arr[j];
						a[*index][2] = arr[k];
						(*index)++;
					}
				}
			}
		}
		return a;//returns the array
	}
	else
		return NULL;
}
