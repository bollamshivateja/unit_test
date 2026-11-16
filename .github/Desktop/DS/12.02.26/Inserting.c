#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
void insert_begin(){
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter data:");
	scanf("%d",&newnode->data);
	
	newnode->next=head;
	head=newnode;
	
}
//Insert at end
void insert_end(){
	struct node *newnode, *temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter data:")
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	
	if(head==NULL)
	{
		head=newnode;
	}
	else{
		temp=head;
		while(temp->next!=NULL)
	}
	temp=temp->next;
	}
	temp->next=newnode;
}

//Insert at required position
void insert_position()
{
	struct node *newnode, *temp;
	int pos,i=1;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter data:");
	scanf("%d",&newnode->data);
	scanf("%d",pos);
	
	if(pos==1)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		temp=head;
		while(i<pos-1 && temp !=NULL)
		{
			temp=temp->next;
			i++;
		}
		if(temp=NULL)
		{
			printf("Invalid position\n");
			return;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}

