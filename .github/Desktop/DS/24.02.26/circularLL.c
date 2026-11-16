#include<stdio.h>
#incude<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node *head=NULL,*temp,*newnode;

void create(){
	int n,i;
	printf("\nEnter Number. of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter Data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL){
			head=temp=newnode;
		}else{
			temp->next=newnode;
			temp=newnode;
		}
	}if(temp!=NULL){
		temp->next=head;
	}
}
void display(){
		struct node*temp=head;
	if(head==NULL){
		printf("\nList is empty.");
	}
	while(temp!=NULL){
		printf("%d ->",temp->data);
		temp=temp->next;
	}printf("NULL");
}
int main(){
    int choice;

    do{
        printf("\nMenu:");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    }while(choice != 3);

    return 0;
}
