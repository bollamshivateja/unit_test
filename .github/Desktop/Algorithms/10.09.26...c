#include <stdio.h>
#include <string.h>

struct Node {
    char ch;
    int freq;
    int left;
    int right;
};

void sort(struct Node a[], int n) {
    int i, j;
    struct Node temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j].freq > a[j + 1].freq) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void generateCodes(struct Node tree[], int root, char code[], int pos,
                   char codes[][20]) {

    if(tree[root].left == -1 && tree[root].right == -1) {
        code[pos] = '\0';
        strcpy(codes[root], code);
        return;
    }

    code[pos] = '0';
    generateCodes(tree, tree[root].left, code, pos + 1, codes);

    code[pos] = '1';
    generateCodes(tree, tree[root].right, code, pos + 1, codes);
}

int main() {

    int n = 5;

    struct Node tree[10] = {
        {'S', 50, -1, -1},
        {'R', 20, -1, -1},
        {'V', 15, -1, -1},
        {'M', 10, -1, -1},
        {'T', 5, -1, -1}
    };

    int count = n;
    int i;

    // Create Huffman tree
    while(count < 2 * n - 1) {

        sort(tree, count);

        int first = 0;
        int second = 1;

        tree[count].ch = '-';
        tree[count].freq = tree[first].freq + tree[second].freq;
        tree[count].left = first;
        tree[count].right = second;

        // Remove first two nodes
        for(i = 0; i < count - 2; i++) {
            tree[i] = tree[i + 2];
        }

        // Move new node to the end
        tree[count - 2] = tree[count];

        count--;
    }

    // Generate Huffman codes
    char codes[10][20];
    char code[20];

    generateCodes(tree, count - 1, code, 0, codes);

    printf("Huffman Codes:\n");

    for(i = 0; i < n; i++) {
        printf("%c = %s\n", tree[i].ch, codes[i]);
    }

    // Encode message
    char message[] = "SRVMT";
    char encoded[100] = "";
    int totalBits = 0;

    for(i = 0; i < strlen(message); i++) {

        for(int j = 0; j < n; j++) {

            if(message[i] == tree[j].ch) {
                strcat(encoded, codes[j]);
                totalBits += strlen(codes[j]);
                break;
            }
        }
    }

    printf("\nMessage: %s\n", message);
    printf("Encoded Message: %s\n", encoded);
    printf("Total number of bits: %d\n", totalBits);

    return 0;
}
