/*program that swaps alternate nodes of a given linked list.create() function is used to
add nodes into linked list*/
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
struct node* swap_alternate(struct node *head);
void swap(int*, int*);
void main()
{
	int i, data;
	create(10);//function for creating nodes
	create(20);
	create(30);
	create(40);
	create(50);
	struct node *temp;
	temp = swap_alternate(head);
	if (temp == NULL)
		printf("linked list is empty");
	else{
		printf("list after alternate swapping is:");
		while (temp != NULL)
		{
			printf("%d", temp->data);
			temp = temp->next;
		}
	}
	_getch();
}
void create(int data)
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
struct node* swap_alternate(struct node *head)//function used for swapping alternate node in linkedlist
{
	struct node *temp=head;
	if (head == NULL)
		return NULL;
	if(temp != NULL && temp->next != NULL)
	{
		swap(&temp->data, &temp->next->data);
		swap_alternate(temp->next->next);//function used for swapping data
	}
	return head;
}
void swap(int* x, int* y)//swap function used for swapping data using pointers
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
