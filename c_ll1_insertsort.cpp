//inserting a node in a sorted order into a single linked list
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
void insert(int);
void main()
{
	int i,num,data;
	create(10);//creating a linked list
	create(20);
	create(30);
	create(40);
	create(50);
	printf("enter the number to be inserted:");
	scanf("%d", &num);//entering number to be inserted
	insert(num);
	struct node *temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	_getch();
}
void create(int data)//create function to create a linked list
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
void insert(int num)
{
	struct node *temp = head,*prev=head;
	struct node *n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = num;
	n->next = NULL;
	if (head->data >= num)//inserting a node at start
	{
		n->next = head;
		head = n;
	}
	else
		if (last->data <= num)//inserting a node in last position
		{
			last->next = n;
			last = n;
		}
		else{
			while (temp->data < num)
		{
			prev = temp;
			temp = temp->next;
		}

		prev->next = n;
		n->next = temp;
	}
}