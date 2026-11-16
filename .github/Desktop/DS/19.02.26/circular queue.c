#include<stdio.h>
#include<stdlib.h>
#define max
int front=-1,rear=-1,data,queue[10];
void enqueue(){
	if(rear==max-1){
		printf("Queue is full:");
	}
	printf("Enter the data to insert:");
	scanf("%d",&data);
	if(front==-1){
		front =rear-0;
	}else if(rear=max-1){
		rear=0;
	}else{
		rear++;
	}
	queue[rear]=data;
}
void dequeue(){
	if(front==-1){
		printf("queue is empty");
	}
	printf("Deleted element :%d\n",queue[front]);
	if(front==rear){
		front=rear=-1;
	}
	else{
		front++;
	}
}

void display(){
	int i;
	if(front==-1){
		printf("queue is empty\n");
	}
	printf("queue elements");
	if(front<=rear){
		for(i=front;i<=rear;i++)
		printf("%d",queue[i]);
	}
	else{
		for(i=0;i<=rear;i++)
		printf("%d",queue[i]);
	}
}

int main(){
	int choice,c;
	do{
		printf("MENU:\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("Exit\n");
		printf("Enter your choice: \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				Exit();
				break;
				
		}printf("\n Do you want to continue:\n");
	}while(c==1);
}
