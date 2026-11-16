#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next ;
	
};
	struct node *top=NULL;
void push(int val){
	struct node *newnode =(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("STACK IS OVERFLOW ");
		return ;
	}else{
		newnode->data=val;
		newnode->next=top;
		top=newnode;
		printf("\nInserted element :%d\n",val);
		
		
}
}
void pop(int val){
	struct node *temp=top;
	printf("%d",top->data);
	top=top->next;
	free(temp);
}
void peek(){
	if(top==NULL){
		printf("Stack is empty :");
		
	}else{
		printf("Top Element :%d",top->data);
		
	}
}
void insert_begin(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);

    newnode->next = head;
    head = newnode;
}
void insert_end(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp;

    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

// insert position
void insert_position(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    int pos, i=1;

    printf("Enter data: ");
    scanf("%d",&newnode->data);
    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos == 1){
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    while(i < pos-1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if(temp == NULL){
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void display (){
	if(top==NULL){
		printf("Stack is empty ");
		return;
	}else{
		struct node *temp=top;
		printf("Stack Elements :");
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
int main(){
	int choice ,value,c,top,val;
	do{
		printf("MENU :\n");
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.PEEK\n");
		printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
		printf("4.DISPLAY\n");
		printf("5.Exit\n\n");
		printf("Enter your choice :\n");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("Enter the value to push :");
				scanf("%d",&val);
				push(val);
				break ;
			case 2 :
				printf("POP:\n");
				pop(val);
				break;
			case 3:
				peek();
				break;
			case 4:
			    insert_begin();
			    break;
            case 5:
			    insert_end();
			    break;
            case 6:
			    insert_position();
			    break;
			case 7:
				display();
				break ;
			case 8:
				printf("EXITING...");
				exit(0);
			default :
				printf("Invalid Choice...");
			break ;
				
		}
		printf("Do you wanna continue (0/1):");
		scanf("%d",&c);
		
		
	}while(c==1);
}
