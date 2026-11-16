#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;

void create(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
    }else{
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void display(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void insert_begin(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);

    newnode->prev=NULL;
    newnode->next=head;

    if(head!=NULL)
        head->prev=newnode;

    head=newnode;
}

void insert_end(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);

    newnode->next=NULL;

    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;
        return;
    }

    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newnode;
    newnode->prev=temp;
}

void insert_position(){
    int pos,i=1;
    struct node *newnode,*temp=head;

    printf("Enter position: ");
    scanf("%d",&pos);

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);

    if(pos==1){
        newnode->prev=NULL;
        newnode->next=head;
        if(head!=NULL)
            head->prev=newnode;
        head=newnode;
        return;
    }

    while(i<pos-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }

    if(temp==NULL){
        printf("Invalid position\n");
        return;
    }

    newnode->next=temp->next;
    newnode->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=newnode;

    temp->next=newnode;
}

void delete_begin(){
    struct node *temp;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    temp=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    free(temp);
}

void delete_end(){
    struct node *temp=head;

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }

    while(temp->next!=NULL)
        temp=temp->next;

    temp->prev->next=NULL;
    free(temp);
}

void delete_position(){
    int pos,i=1;
    struct node *temp=head;

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos==1){
        head=temp->next;
        if(head!=NULL)
            head->prev=NULL;
        free(temp);
        return;
    }

    while(i<pos && temp!=NULL){
        temp=temp->next;
        i++;
    }

    if(temp==NULL){
        printf("Invalid position\n");
        return;
    }

    if(temp->next!=NULL)
        temp->next->prev=temp->prev;

    if(temp->prev!=NULL)
        temp->prev->next=temp->next;

    free(temp);
}

int main(){
    int choice;

    do{
        printf("\n1.Create");
        printf("\n2.Insert at begin");
        printf("\n3.Insert at end");
        printf("\n4.Insert at position");
        printf("\n5.Delete at begin");
        printf("\n6.Delete at end");
        printf("\n7.Delete at position");
        printf("\n8.Display");
        printf("\n9.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: create(); break;
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

    }while(1);

    return 0;
}
