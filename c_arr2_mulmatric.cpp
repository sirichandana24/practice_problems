/*program to perform multiplication of 2 matrices*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int** mat_mul(int**, int, int, int**, int, int);
void main()
{
	int **arr1, **arr2,**res,i;
	int rows1, rows2, cols1, cols2;
	printf("enter no of rows for matrix1");
	scanf("%d", &rows1);
	printf("enter no of columns for matrix1");
	scanf("%d", &cols1);
	printf("enter no of rows for matrix2");
	scanf("%d", &rows2);
	printf("enter no of columns for matrix2");
	scanf("%d", &cols2);
	if (rows1 < 0 || cols1 < 0 || rows2 < 0 || cols2 < 0)
		printf("invalid input");
	else{
	if (cols1 != rows2)
		printf("matrix multiplication is not possible");
	else
	{
		arr1 = (int **)malloc(rows1 * sizeof(int *));
		for (i = 0; i < rows1; i++)
			arr1[i] = (int *)malloc(cols1 * sizeof(int));
		arr2 = (int **)malloc(rows2 * sizeof(int *));
		for (i = 0; i < rows2; i++)
			arr2[i] = (int *)malloc(cols2 * sizeof(int));
		printf("enter elements of 1st matrix:");
		for (i = 0; i < rows1; i++)
			for (int j = 0; j < cols1; j++)
				scanf("%d", &arr1[i][j]);
		printf("enter elements of 2nd matrix");
		for (i = 0; i < rows2; i++)
			for (int j = 0; j < cols2; j++)
				scanf("%d", &arr2[i][j]);
		res = mat_mul(arr1, rows1, cols1, arr2, rows2, cols2);
		for (i = 0; i < rows1; i++){
			printf("\n");
			for (int j = 0; j < cols2; j++){
				printf("%d\t", res[i][j]);
			}
		}
	}
		_getch();
	}
}
int** mat_mul(int **arr1, int rows1, int cols1, int **arr2, int rows2, int cols2)
{//code used for multiplying 2 matrices
	int sum = 0,i,j,k,**res;
	res = (int **)malloc(rows1 * sizeof(int *));
	for (i = 0; i<rows1; i++)
		res[i] = (int *)malloc(cols2 * sizeof(int));
	for (i = 0; i < rows1; i++){
		for (j = 0; j < cols2; j++){
			sum = 0;
			for (k = 0; k < rows2; k++)
				sum = sum + arr1[i][k]*arr2[k][j];
			res[i][j] = sum;
		}
	}
	return res;
}