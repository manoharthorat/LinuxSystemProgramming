#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node * next;
	
};

int InsertFirst(struct node ** head,int no);
void Display(struct node * head);
