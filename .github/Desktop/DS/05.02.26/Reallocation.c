#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a, i, n, extra;

    printf("Enter the size of array:\n");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    printf("Enter the marks of students:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("STUDENT MARKS:\n");
    for(i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }

    printf("\nEnter how many more students to add:\n");
    scanf("%d", &extra);

    a = (int *)realloc(a, (n + extra) * sizeof(int));

    printf("Enter marks of new students:\n");
    for(i = n; i < n + extra; i++){
        scanf("%d", &a[i]);
    }

    printf("UPDATED STUDENT MARKS:\n");
    for(i = 0; i < n + extra; i++){
        printf("%d\t", a[i]);
    }

    free(a);
    return 0;
}
