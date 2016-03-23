/*program to check whether the linked list represented by a number is divisible by 11 or not*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include<conio.h>
struct node {
	int data;
	struct node *next;
}node1;
struct node *head = NULL;
struct node *last = NULL;
void create(int);
bool isdiv_by_11(struct node *head);
void main()
{
	int i, data;
	create(1);//function for creating nodes
	create(2);
	create(3);
	create(4);
	create(5);
	create(NULL);
	if (head == NULL)
		printf("linked list is empty");
	else{
		int res = isdiv_by_11(head);
		if (res == 1)
			printf("number is divisible by 11");
		else
			printf("number is not divisible by 11");
	}
	_getch();
}
void create(int data)//function for creating a linked list
{
	struct node *n, *temp;
	n = (struct node*)malloc(sizeof(node1));
	n->data = data;
	n->next = NULL;
	if (head == NULL)
	{
		head = n;
		last = n;
	}
	else
	{
		last->next = n;
		last = n;
	}
}
bool isdiv_by_11(struct node *head)//function for checking divisibility by 11
{
	struct node *temp;
	temp = head;
	int i=0,even_sum=0,odd_sum=0,sum;
	while (temp != NULL)
	{
		if (i % 2 == 0)
			even_sum = even_sum + temp->data;
		else
			odd_sum = odd_sum + temp->data;
		temp = temp->next;
		i++;
	}
	sum = even_sum - odd_sum;//divisibilty for 11:difference b/w even sum and odd sum should 
//	be divisible by 11. 
	if (sum < 0)
		sum = sum*-1;
	if (sum==0)
		return 1;
	else{
		if (sum>=11)
			while (sum > 0)
			{
				sum = sum - 11;
			}
	}
	if (sum == 0)
		return 1;
	else
		return 0;
}