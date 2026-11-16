#include <stdio.h>

int main() {
    int i, j, n, m, a[10], b[10];


    printf("Enter the size of PY array: ");
    scanf("%d", &n);

    printf("Enter PY roll numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    
    printf("Enter the size of JAVA array: ");
    scanf("%d", &m);

    printf("Enter JAVA roll numbers:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &b[j]); 
    }


    printf("Students enrolled in both courses:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                printf("%d\n", a[i]);
            }
        }
    }

    return 0;
}

