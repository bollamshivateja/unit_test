#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value){
    if(top == MAX - 1){
        printf("Error: Stack overflow!\n");
        return;
    }
    stack[++top]=value;
}

void display(){
    int i;
    for(i =top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
    printf("\n");
}
int pop(){
    if(top==-1){
        printf("Error: Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
int main() {
    int choice,value;
    while(1) {
        printf("1. Push\n2. Display\n3. Pop\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to push:");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                printf("Elements in the stack:\n");
                display();
                break;
            case 3:
                value = pop();
                if (value != -1){
                    printf("Popped value: %d\n",value);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
