/*program to implement lcd and gcd for an array of integers*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int lcm(int, int, int);
int gcd(int, int);
void main()
{
	int len, *arr,i,l,g;
	printf("enter length of array:");
	scanf("%d", &len);
	if (len < 1)
		printf("invalid input array size");
	else{
		arr = (int*)malloc(len*sizeof(int));
		printf("enter elements:");
		scanf("%d", &arr[0]); 
			if (arr[0] < 0)//if array entered has negative numbers converts them into poisitive numbers
				arr[0] = -arr[0];
		l = arr[0];
		g = arr[0];
		for (i = 1; i < len; i++){
			scanf("%d", &arr[i]);
			if (arr[i] < 0)
				arr[i] = -arr[i];
			if (l < arr[i])
				l = lcm(arr[i], l, arr[i]);//call for lcm function
			else
				l = lcm(l, arr[i], l);
			g = gcd(g, arr[i]);//calss gcd function
		}
		printf("the lcm of array is:%d", l);
		printf("\nthe gcd of array is: %d", g);
	}
	_getch();
}
int lcm(int a, int b, int c)
{
	if (a%b!=0)
		lcm(a + c, b, c);//calls lcm function recursively
	else 
		return a;

}
int gcd(int a, int b)
{
	if (a == 0 || b == 1 || a == b)
		return b;
	if (b == 0|| a == 1)
		return a;
	if (a > b)//calls gcd function recursively
		return gcd(b,a%b);
	else
		return gcd(a,b%a);
}