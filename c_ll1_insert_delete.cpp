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
struct node* insert(int,int);
struct node* deletion(int);
void main()
{
	int i, pos_insert,pos_delete, data,insert_num;
	create(10);//creating a linked list
	create(20);
	create(30);
	create(40);
	create(50);
	printf("enter the position to be inserted:");
	scanf("%d", &pos_insert);//entering position to be inserted
	printf("enter number to be inserted");
	scanf("%d", &insert_num);//entering the number that is to be inserted
	struct node *temp1,*temp;
	temp = insert(insert_num,pos_insert);
	temp1 = temp;
	
	if (temp == NULL)
		printf("invalid input");
	else{
		printf("linked list after insertion \n");
		while (temp1 != NULL)
		{
			printf("%d ", temp1->data);
			temp1 = temp1->next;
		}
	}
	printf("\nenter the position at which number is to be deleted:");
	scanf("%d", &pos_delete);
	temp = deletion(pos_delete);
	temp1 = temp;
	if (temp1 == NULL)
		printf("invalid input");
	else{
		printf("linked list after deletion:");
		while (temp1 != NULL)
		{
			printf("%d", temp1->data);
			temp1 = temp1->next;
		}
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
struct node* insert(int num,int pos_insert)
{
	struct node *temp = head, *prev = head;
	struct node *n;
	n = (struct node*)malloc(sizeof(struct node));
	temp = head;
	int count = 0,i=1;
	if (pos_insert < 1 || head==NULL)
		return NULL;
	
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	n->data = num;
	n->next = NULL;
	if (count + 1 < pos_insert)
		return NULL;
	if (pos_insert==1)//inserting a node at start
	{
		n->next = head;
		head = n;
	}
	else
		if (pos_insert==count+1)//inserting a node in last position
		{
			last->next = n;
			last = n;
		}
		else{
			temp = head;
			while (i<pos_insert)
			{
				i++;
				prev = temp;
				temp = temp->next;
			}

			prev->next = n;
			n->next = temp;
		}
		return head;
}
struct node* deletion(int pos_delete)//delete function for linked lists
{
	int count = 0;
	if (pos_delete < 0 || head == NULL)
		return NULL;
	struct node *temp = head;
	while (temp != NULL)//calculating length of linked list
	{
		count++;
		temp = temp->next;
	}
	if (pos_delete > count + 1)
		return NULL;
	if (pos_delete == 1)
	{
		temp = head;
		head = head->next;
		temp->next = NULL;
	}
	else
		if (count==pos_delete)
	{ 
		struct node *temp1;
		struct node *temp2=head;
		temp1 = head;
		while (temp1->next != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = NULL;
		last = temp2;
	}
		else
		{
			temp = head;
			int i = 1;
			while (i < pos_delete-1)
			{
				temp = temp->next;
				i++;
			}
			temp->next=temp->next->next;
		}
	return head;
}