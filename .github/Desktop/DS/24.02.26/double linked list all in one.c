#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
struct node *temp,*newnode;

void create(int n){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&newnode->val);
	newnode->prev=NULL;
	newnode->next=NULL;
	if(head==NULL){
		newnode->prev=NULL;
		head=temp=newnode;
	}else{
		temp->next=newnode;
		newnode->prev=temp;
		temp=newnode;
	}
}

void display(){
	struct node *temp=head;
	if(head==NULL){
		printf("List is empty:\n");
		return;
	}
	printf("Double linkedlist:\n")
	while(temp!=NULL){
		printf("%d <->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

void insert_begin(){
	newnode->prev=NULL;
	newnode->next=head;
	if(head!=NULL)
	head->prev=newnode;
	head=newnode;
}

void insert_end(){
	temp=head;
	while(temp->next!==NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}

void insert_req(){
	temp=head;
	newnode->next=temp->next;
	newnode->prev=temp;
	while(temp->next!=NULL){
	temp->next->prev=newnode;
	temp->next=newnode;
    }
}

void del_begin(){
	struct node *temp;
	if(head==NULL){
		printf("List is empty:\n");
		return;
	}
	temp=head;
	head=head->next;
	if(head!=NULL){
	head->prev=NULL;
	free(temp);
    }
}

void del_end(){
	struct node *temp;
	if(head==NULL){
		printf("List is empty:\n");
		return;
	}
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
		if(temp->prev!=NULL)
		temp->prev->next=NULL;
		}else{
			head==NULL;
			free(temp);
		}
}

void del_req(){
	struct node *temp;
	int pos,i=1;
	if(head==NULL){
		printf("List is empty:\n");
		return;
	}
	printf("Enter position:");
	scanf("%d",&pos);
	temp=head;
	if(pos==1){
		head=temp->next;
		if(head!=NULL)
		head->prev=NULL;
		free(temp);
		return;
	}
	while(i<pos&&temp!=NULL){
		temp=temp->next;
		i++;
		if(temp==NULL){
			printf("Invalid position\n");
			return;
		}
		if(temp->next!=NULL){
			temp->next->prev=temp->prev;
			if(temp->prev!=NULL){
				temp->prev->next=temp->next;
				free(temp);
			}
		}
	}
}

int main(){
	int val,choice,c;
	do{
		printf("\nMenu:");
		printf("\n1.Create");
		printf("\n2.Insert at begin");
		printf("\n3.Insert at end");
		printf("\n4.Insert at required position");
		printf("\n5.Delete at begin");
		printf("\n6.Delete at end");
		printf("\n7.Delete at required position");
		printf("\n8.Disply");
		printf("\n9.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				create();
				break;
				
			case 2:
				printf("Enter the data to insert:");
				scanf("%d",&newnode->data);
				insert_begin();
				break;
				
			case 3:
				printf("Enter the data to insert:");
				scanf("%d",&newnode->data);
				insert_end();
				break;
				
			case 4:
				printf("Enter the data to insert:");
				scanf("%d",&newnode->data);
				insert_req();
				break;
			case 5:
				
				
		}
	}
}
