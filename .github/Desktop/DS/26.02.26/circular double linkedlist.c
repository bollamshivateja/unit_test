#include<stdio.h>
#include<stdlib.h>
struct node(){
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
void create(int n){
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter data%d",i);
		scanf("%d",&value);
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	if(head==NULL){
		head=newnode;
		head->next=head;
		head->prev=head;
	}else{
		temp=head->prev;
		temp->next=newnode;
		newnode->prev=temp;
		newnode->next=head;
		head->prev=newnode;
	}
}

void display(){
	struct node *temp;
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	temp=head;
	do{
		printf("%d",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}

int main(){
	int choice,c,n;
	do{
		printf("MENU");
		printf("\n1.create");
		printf("\n2.display");
		printf("\n3.Exit");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				create(n);
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Exiting....\n");
				break;
				
			default:
                printf("Invalid choice\n");
        }

    }while(choice != 3);
		}
	}
}
