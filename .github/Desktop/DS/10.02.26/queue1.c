#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int rear=-1,front=0,value;
void enqueue(int value){
	if (rear==MAX-1){
		printf("\nQueue is overflow");
		return;
	}
	queue[++rear]=value;
}
void display(){
	int i;
	printf("\nPRINTING ELEMENTS :");
	for(i=front;i<=rear;i++){
		printf("%d",queue[i]);
	}
}
int dequeue(){
	if (front==-1||front>rear){
		printf("\nQUEUE IS UNDERFLOW");
	}
	return queue[front++];
}

int main(){
	while(1){
	printf("\n1.INSERT\n \n2.DISPLAY \n3.DELETE/DEQUEUE \n4.EXIT\n");
	printf("Enter your choie:");
	int choice ,value;
	scanf("%d",&choice);
	switch(choice){
		case 1 :
			printf("\nEnter value to ENQUEUE or INSERT:");
			scanf("%d",&value);
			enqueue(value);
			break;
		case 2 :
			display();
			break;
		case 3:
			value=dequeue();
			printf("\nelement deleted:%d",value);
			break;
		case 4 :
			exit(0);
			break;
		default :
			printf("\nINVALID CHOICE ");
			
	}
}
}
