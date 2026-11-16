#include<stdio.h>
#include<stdlib.h>
#define MAX 10      //macro
int stack[MAX];
int top=-1;

void push(int value){
	if(top==max-1){
		printf("Error stack overflow!\n");
		return;
	}
	stack[++top]=value;
}
void display();
{
	for(i=top;i>=0;i--){
		printf("%d\t",stack[i]);
	}
}

int pop(){
	if(top==-1){
		printf("Error:Stack underflow\n");
	}
	return stack[top--];
}
int main(){
	int choice,value;
	while(1){
		printf("1.push\n2.dispaly\n3.pop\n4.exit\n");
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Ener value to push");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
				printf("Enter elements in the stack");
				display();
				break;
			case 3:
				value=pop();
				if(value!=-1){
					printf("Popped  value:%d\n",value);
				}
				break;
			case 4:
				exit(0);
				default:
					printf("invalid choice!\n");
				}
			}
		return 0;
				
		}
	}
}
