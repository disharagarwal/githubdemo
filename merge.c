#include<stdio.h>
#include<stdlib.h>
typedef struct sll
{
	int data;
	struct sll *link;
}node;
node* createnode(int ele)
{
	node *newnode;
	newnode=malloc(sizeof(node));
	newnode->data=ele;
	newnode->link=NULL;
	return newnode;
}
void append(node** head_ref, int ele)
{
	node* new_node,*last=*head_ref;
	new_node=createnode(ele);
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }   
    while (last->link != NULL)
        last = last->link;

    last->link = new_node;
    return;   
}

void insert_front(node **start1,int ele)
{
	node* new_node;
	new_node=createnode(ele);
	if(*start1==NULL)
		*start1=createnode(ele);
	else
	{
		new_node->link=(*start1);
		*start1=new_node;
	}
}
void display(node *head)
{
   while(head!=NULL)
   {
     printf("%d->",head->data);
     head=head->link;
   }
   printf("\n");
}

node* merge(node *start1,node *start2)
{
	node *newnode,*newlist,*dstart1,*dstart2;
	dstart1=start1;
	dstart2=start2;
	newlist=NULL;
	while (dstart1!=NULL)
	{
		int ele=dstart1->data;
		newnode=createnode(ele);
		append(&newlist,ele);
		dstart1=dstart1->link;
	}
	while (dstart2!=NULL)
	{
		int ele=dstart2->data;
		newnode=createnode(ele);
		append(&newlist,ele);
		dstart2=dstart2->link;
	}
	return newlist;
}


int main()
{
    node* start1;
	start1=NULL;
	insert_front(&start1,30);
	insert_front(&start1,10);
	insert_front(&start1,20);
	insert_front(&start1,50);
	printf("the first list is\n");
	display(start1);
	node* start2;
	start2=NULL;
	insert_front(&start2,1);
	insert_front(&start2,12);
	insert_front(&start2,22);
	insert_front(&start2,53);
	printf("\nthe second list is\n");
	display(start2);
	node *newlist=NULL;
	newlist=merge(start1,start2);
	printf("\nmerged list is \n");
	display(newlist);
	printf("........");
	return 0;
}
