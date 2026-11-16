#include <stdio.h>

struct Location {
    char id[5];
    int profit, fuel;
    float ratio;
};

int main() {

    int n, fuelLimit;
    int totalFuel = 0, totalProfit = 0;

    printf("Enter number of locations: ");
    scanf("%d", &n);

    struct Location l[n];

    // Take input
    for (int i = 0; i < n; i++){

        printf("\nEnter location ID: ");
        scanf("%s", l[i].id);

        printf("Enter profit: ");
        scanf("%d", &l[i].profit);

        printf("Enter fuel: ");
        scanf("%d", &l[i].fuel);
    }

    printf("\nEnter fuel limit: ");
    scanf("%d", &fuelLimit);

    // Calculate profit/fuel ratio
    for (int i = 0; i < n; i++) {
        l[i].ratio = (float)l[i].profit / l[i].fuel;
    }

    // Sort in descending order of ratio
    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (l[i].ratio < l[j].ratio) {

                struct Location temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }

    // Select locations
    printf("\nSelected Locations:\n");

    for (int i = 0; i < n; i++) {

        if (totalFuel + l[i].fuel <= fuelLimit) {

            printf("%s Profit=%d Fuel=%d\n",
                   l[i].id, l[i].profit, l[i].fuel);

            totalFuel += l[i].fuel;
            totalProfit += l[i].profit;
        }
    }

    printf("\nTotal Fuel = %d", totalFuel);
    printf("\nTotal Profit = %d", totalProfit);

    return 0;
}

