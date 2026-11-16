#include <stdio.h>
#include <stdlib.h>
#define max 5
int queue[max];
int rear=-1,front=0;
void enqueue(int value){
	if(rear==max-1){
		printf("Queue is overflow");
		return;
	}
	queue[++rear]=value;
}
void display(){
	int i;
	printf("Printing elements\n");
	for(i=front;i<=rear;i++){
		printf("%d",queue[i]);
	}
	printf("\n");
}
int dequeue(){
	if(front=-1||front>rear){
		printf("Queue is overflow");
	}
	return queue[front++];
}

int main(){
	int choice,value;
	while(1){
	printf("1.insert\n 2.display\n 3.delete\n 4.exit");
	printf("Enter your choice");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("Enter value to insert");
			scanf("%d",&value);
			insert(value);
			break;
		case 2:
			printf("display value\n");
			display();
			break;
		case 3:
			printf("Enter to delete\n");
			dequeue(value);
			printf("Element deleted:%d");
			break;
		case 4:
			exit(0);
			
		default:
			printf("Invalid choice!\n");
		
	    }
    }
}
