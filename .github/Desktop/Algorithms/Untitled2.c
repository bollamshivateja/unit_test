#include <stdio.h>

// Recursive Binary Search
int recursiveBinarySearch(int a[], int low, int high, int key) {
    int mid;

    if (low > high) {
        return -1;
    }

    mid = (low + high) / 2;

    if (a[mid] == key) {
        return mid;
    }
    else if (key < a[mid]) {
        return recursiveBinarySearch(a, low, mid - 1, key);
    }
    else {
        return recursiveBinarySearch(a, mid + 1, high, key);
    }
}

int main() {
    int a[10], i, n, mid, key;
    int found = 0, index;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("ELEMENTS:");
    for (i = 0; i < n; i++) {
        printf("\na[%d] = %d", i, a[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    // -------------------------------
    // Iterative Binary Search
    // -------------------------------

    int low = 0, high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            found = 1;
            index = mid;
            break;
        }
        else if (key < a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (found == 1) {
        printf("\n\nIterative Binary Search:");
        printf("\nElement Found %d at index %d", key, index);
    }
    else {
        printf("\n\nIterative Binary Search:");
        printf("\nElement Not Found");
    }

    // -------------------------------
    // Recursive Binary Search
    // -------------------------------

    index = recursiveBinarySearch(a, 0, n - 1, key);

    if (index != -1) {
        printf("\n\nRecursive Binary Search:");
        printf("\nElement Found %d at index %d", key, index);
    }
    else {
        printf("\n\nRecursive Binary Search:");
        printf("\nElement Not Found");
    }

    return 0;
}
