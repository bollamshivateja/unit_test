#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int val){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL){
        printf("QUEUE OVERFLOW\n");
        return;
    }

    newnode->data = val;
    newnode->next = NULL;

    if(front == NULL){          // If queue is empty
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("\nInserted element: %d\n", val);
}

void dequeue(){
    if(front == NULL){
        printf("QUEUE UNDERFLOW\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted element: %d\n", front->data);

    front = front->next;

    if(front == NULL)   // If queue becomes empty
        rear = NULL;

    free(temp);
}

void peek(){
    if(front == NULL){
        printf("Queue is empty\n");
    } else {
        printf("Front Element: %d\n", front->data);
    }
}

void display(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("Queue Elements: ");

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, val, c;

    do{
        printf("\nMENU:\n");
        printf("1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d",&val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nEXITING...");
                exit(0);

            default:
                printf("\nInvalid Choice...");
        }

        printf("\nDo you wanna continue (0/1): ");
        scanf("%d",&c);

    } while(c == 1);

    return 0;
}
