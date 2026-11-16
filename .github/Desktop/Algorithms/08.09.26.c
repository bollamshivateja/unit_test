#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(char ch, int freq)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Sort nodes in ascending order of frequency
void sort(struct Node *arr[], int n)
{
    int i, j;
    struct Node *temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]->freq > arr[j+1]->freq)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

char code[256][20];

// Traverse tree (Left=0, Right=1)
void generateCodes(struct Node *root, char str[], int top)
{
    if(root->left)
    {
        str[top]='0';
        generateCodes(root->left,str,top+1);
    }

    if(root->right)
    {
        str[top]='1';
        generateCodes(root->right,str,top+1);
    }

    if(root->left==NULL && root->right==NULL)
    {
        str[top]='\0';
        strcpy(code[(int)root->ch],str);
        printf("%c : %s\n",root->ch,str);
    }
}

int main()
{
    int n,i,size;
    char message[100];

    printf("Enter number of characters: ");
    scanf("%d",&n);

    struct Node *arr[100];

    for(i=0;i<n;i++)
    {
        char c;
        int f;

        printf("Character: ");
        scanf(" %c",&c);

        printf("Frequency: ");
        scanf("%d",&f);

        arr[i]=createNode(c,f);
    }

    printf("Enter message: ");
    scanf("%s",message);

    size=n;

    // Build Huffman Tree
    while(size>1)
    {
        sort(arr,size);

        printf("\nSorted Frequencies: ");
        for(i=0;i<size;i++)
            printf("%d ",arr[i]->freq);

        struct Node *left=arr[0];
        struct Node *right=arr[1];

        printf("\nCombine %d + %d = %d\n",
               left->freq,right->freq,left->freq+right->freq);

        struct Node *newNode=createNode('#',left->freq+right->freq);
        newNode->left=left;
        newNode->right=right;

        arr[0]=newNode;

        for(i=1;i<size-1;i++)
            arr[i]=arr[i+1];

        size--;
    }

    printf("\nHuffman Codes:\n");
    char str[20];
    generateCodes(arr[0],str,0);

    printf("\nEncoded Message: ");
    int bits=0;

    for(i=0;message[i]!='\0';i++)
    {
        printf("%s",code[(int)message[i]]);
        bits += strlen(code[(int)message[i]]);
    }

    printf("\nTotal Bits = %d\n",bits);

    return 0;
}
