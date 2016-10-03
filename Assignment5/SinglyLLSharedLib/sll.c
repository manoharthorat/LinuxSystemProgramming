#include"sll.h"
//#include<stdio.h>
//#include<stdlib.h>

int InsertFirst(struct node ** head, int no)
{
	struct node * newnode=(struct node*)malloc(sizeof(struct node ));
	if(newnode==NULL)
	{
		printf("Error while creating newnode \n");
		return -1;
	}
	newnode->data=no;
	newnode->next=NULL;
	if(*head==NULL)
	{
		*head=newnode;
	}
	else
	{
		newnode->next=*head;
		*head=newnode;
	}
return 0;
}

void Display(struct node * head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
return ;
}
