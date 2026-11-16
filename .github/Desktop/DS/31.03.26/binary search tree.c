#include<stdio.h>
#include<stdlib.h>

struct node {
    int item;
    struct node *left,*right ;
};
//create
struct node *create(int val){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->item=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

// SEARCH FUNCTION (NEW)(BST)
struct node* search(struct node *root, int key){
    if(root == NULL)
        return NULL;
    if(root->item == key)
        return root;

    struct node *leftree = search(root->left, key);
    if(leftree != NULL)
        return leftree;

    return search(root->right, key);
}
//insert on left
struct node *insertleft(struct node *root ,int val){
    root->left = create(val);
    return root->left;
}
//insert on right
struct node *insertright(struct node *root ,int val){
    root->right = create(val);
    return root->right;
}
//in order
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d->",root->item);
    inorder(root->right);
}
//pre order
void preorder(struct node * root){
    if (root==NULL){
        return ;
    }
    printf("%d->",root->item);
    preorder(root->left);
    preorder(root->right);
}
//post order
void postorder(struct node *root){
    if (root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->item);
}
//main function
int main(){
    int val,ch,c,parent;
    struct node *root =NULL;
    struct node *temp;

    do{
        printf("\nMENU:");
        printf("\n1.Create");
        printf("\n2.Insert Left ");
        printf("\n3.Insert right ");
        printf("\n4.Inorder");
        printf("\n5.PreOrder");
        printf("\n6.PostOrder");
        printf("\nEnter your choice :");
        scanf("%d",&ch);

        switch (ch){
            case 1 :
                printf("\nEnter the value to create :");
                scanf("%d",&val);
                root=create (val);
                break;

            case 2:
                if (root ==NULL){
                    printf("Create Root ");
                    break;
                }
                printf("\nEnter parent node value:");
                scanf("%d",&parent);

                temp = search(root, parent);
                if(temp == NULL){
                    printf("Parent not found!");
                    break;
                }

                if(temp->left != NULL){
                    printf("Left already exists!");
                    break;
                }

                printf("\nEnter the value to insert:");
                scanf("%d",&val);
                insertleft(temp ,val);
                break ;

            case 3:
                if (root ==NULL){
                    printf("Create Root ");
                    break;
                }
                printf("\nEnter parent node value:");
                scanf("%d",&parent);

                temp = search(root, parent);
                if(temp == NULL){
                    printf("Parent not found!");
                    break;
                }

                if(temp->right != NULL){
                    printf("Right already exists!");
                    break;
                }

                printf("\nEnter the value to insert:");
                scanf("%d",&val);
                insertright(temp ,val);
                break;

            case 4 :
                inorder(root);
                break;

            case 5 :
                preorder(root);
                break;

            case 6:
                postorder(root);
                break;    

            default :
                printf("Invalid choice ");
                break;
        }

        printf("\nDo you wanna continue (0/1):");
        scanf("%d",&c);

    }while(c==1);

    return 0;
}
