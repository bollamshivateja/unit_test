#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
    int number;
};

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and profit of each item:\n");

    for (i = 0; i < n; i++) {
        items[i].number = i + 1;
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort according to profit/weight ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float totalProfit = 0;
    int totalWeight = 0;

    printf("\nSelected Items:\n");

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {
            // Take complete item
            capacity -= items[i].weight;
            totalWeight += items[i].weight;
            totalProfit += items[i].profit;

            printf("I%d = %d kg, Profit = %d\n",
                   items[i].number,
                   items[i].weight,
                   items[i].profit);
        }
        else if (capacity > 0) {
            // Take fraction of item
            float fraction = (float)capacity / items[i].weight;
            float profit = items[i].profit * fraction;

            totalWeight += capacity;
            totalProfit += profit;

            printf("I%d = %d kg (fraction), Profit = %.0f\n",
                   items[i].number,
                   capacity,
                   profit);

            capacity = 0;
            break;
        }
    }

    printf("Total Weight = %d kg\n", totalWeight);
    printf("Maximum Profit = %.0f\n", totalProfit);

    return 0;
}
