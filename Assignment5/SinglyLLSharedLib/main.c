#include"sll.h"
#include<stdio.h>
int main()
{
	struct node * first=NULL;
	InsertFirst(&first,10);	
	InsertFirst(&first,20);
	InsertFirst(&first,30);
	Display(first);

return 0;	
}
