#include <stdio.h>

void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main() {
    int a[10], n, i;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);   // ? correct function call
    }
}

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int lowa[n1], higha[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        lowa[i] = a[low + i];

    for (j = 0; j < n2; j++)
        higha[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    // Merge the arrays
    while (i < n1 && j < n2) {
        if (lowa[i] <= higha[j]) {
            a[k] = lowa[i];
            i++;
        } else {
            a[k] = higha[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1) {
        a[k] = lowa[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = higha[j];
        j++;
        k++;
    }
}
