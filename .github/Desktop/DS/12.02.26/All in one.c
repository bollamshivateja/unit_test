#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

// function declarations
void create_list();
void display();
void insert_begin();
void insert_end();
void insert_position();
void delete_begin();
void delete_end();
void delete_position();

int main(){
    int choice;

    while(1){
        printf("\n..... LINKED LIST MENU .....\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: create_list(); break;
            case 2: insert_begin(); break;
            case 3: insert_end(); break;
            case 4: insert_position(); break;
            case 5: delete_begin(); break;
            case 6: delete_end(); break;
            case 7: delete_position(); break;
            case 8: display(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

// create list
void create_list(){
    struct node *newnode, *temp;
    int choice = 1;

    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = temp = newnode;
        }else{
            temp->next = newnode;
            temp = newnode;
        }

        printf("Add more? (0/1): ");
        scanf("%d",&choice);
    }
}

// display
void display(){
    struct node *temp = head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// insert beginning
void insert_begin(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);

    newnode->next = head;
    head = newnode;
}

// insert end
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

// delete beginning
void delete_begin(){
    struct node *temp;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// delete end
void delete_end(){
    struct node *temp, *prev;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL){
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// delete position
void delete_position(){
    struct node *temp, *nextnode;
    int pos, i=1;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d",&pos);

    if(pos == 1){
        temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    temp = head;
    while(i < pos-1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if(temp == NULL || temp->next == NULL){
        printf("Invalid position\n");
        return;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    printf("Deleted element: %d\n", nextnode->data);
    free(nextnode);
}
