#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {
    int i,j,n,capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort by profit/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float totalProfit = 0;
    int totalWeight = 0;

    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalWeight += capacity;
            totalProfit += items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    printf("Total Weight = %d kg\n", totalWeight);
    printf("Maximum Profit = %.0f\n", totalProfit);

    return 0;
}
