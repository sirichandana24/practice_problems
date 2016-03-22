/*program to calculate length of a single linked list.create() function is used to add nodes into a single linked list.
in main program we can create as many nodes we want which finally calculates the length of sll.*/
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
int length_of_linkedlist();
void main()
{
	int i,len,data;
		/*create(10);
		create(20);
		create(30);
		create(40);*/
	len = length_of_linkedlist();
	if (len == NULL)
		printf("invalid input");
	else
	printf("the length of linked list is:%d", len);
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
int length_of_linkedlist()
{
	int i = 0;
	struct node *temp=head;
	if (head == NULL)
		return NULL;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}