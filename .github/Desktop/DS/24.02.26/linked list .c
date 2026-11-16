#include<stdio.h>
#include<stdlib.h>
#define max 5
int front=-1,rear=-1,data,queue[10];
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void create(){
    int n,i,value;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter data:");
        scanf("%d",&value);
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;

        if(front==NULL){
            front=rear=newnode;
        }else{
            rear->next=newnode;
            newnode->prev=rear;
            rear=newnode;
        }
    }
}
void enqueue(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&newnode->data);
	   if(front == NULL){
        front=rear=newnode;
    }else{
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
}
void dequeue(){
	 struct node*temp;
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    temp=front;
    front=front->next;
    if(front!=NULL)
        front->prev=NULL;
    else
        rear = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}
void display(){
    struct node*temp=front;
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d<-",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int choice;

    while(1){
        printf("\n1.Create");
        printf("\n2.Enqueue");
        printf("\n3.Dequeue");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: create(); break;
            case 2: enqueue(); break;
            case 3: dequeue(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
