#include <stdio.h>

struct Item {
    char id[5];
    float w, p, r;
};

int main() {
    struct Item a[10], t;
    int n, i, j;
    float cap, total = 0;

    printf("Number of Items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s %f %f", a[i].id, &a[i].w, &a[i].p);
        a[i].r = a[i].p / a[i].w;
    }

    printf("Knapsack Capacity: ");
    scanf("%f", &cap);

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i].r < a[j].r) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    printf("\nSelected Items:\n");

    for (i = 0; i < n; i++) {
        if (cap >= a[i].w) {
            cap -= a[i].w;
            total += a[i].p;
            printf("%s = %.0f kg, Profit = %.0f\n",
                   a[i].id, a[i].w, a[i].p);
        } else {
            total += a[i].r * cap;
            printf("%s = %.0f kg (fraction), Profit = %.0f\n",
                   a[i].id, cap, a[i].r * cap);
            break;
        }
    }

    printf("Maximum Profit = %.0f\n", total);

    return 0;
}
