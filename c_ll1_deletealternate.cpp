/*program that deletes every alternate nodes.i.e every 2nd node*/
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
struct node *delete_alternate(struct node*);
void main()
{
	int i,data;
	create(10);//creation of a linked list.create() can insert more nodes if we want
	create(20);
	create(30);
	create(40);
	create(50);
	create(60);
	struct node *temp;
	temp = delete_alternate(head);
	if (temp == NULL)
	{
		printf("list is empty");
	}
	else{
		printf("list after deleting alternate nodes:");
		while (temp != NULL)
		{
			printf("%d ", temp->data);
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
struct node* delete_alternate(struct node *head)
{
	if (head == NULL)
		return NULL;
	struct node *prev = head;
	struct node *n = head->next;
	while (prev != NULL && n != NULL)//function that deletes every alternate node
	{
		prev->next = n->next;
		prev = prev->next;
		if (prev != NULL)
			n = prev->next;
	}
	return head;
}
