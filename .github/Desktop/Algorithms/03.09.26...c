#include <stdio.h>
#include <string.h>

struct Appointment {
    char id[5];
    int deadline, priority;
};

int main() {
    struct Appointment a[20], temp;
    char slot[20][5] = {""};
    int n, i, j, maxDeadline, total = 0;

    printf("Number of Appointments: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s %d %d",
              a[i].id,
              &a[i].deadline,
              &a[i].priority);
    }

    // Find maximum deadline
    maxDeadline = a[0].deadline;
    for (i = 1; i < n; i++) {
        if (a[i].deadline > maxDeadline)
            maxDeadline = a[i].deadline;
    }

    // Sort by priority in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i].priority < a[j].priority) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Schedule appointments
    for (i = 0; i < n; i++) {
        for (j = a[i].deadline - 1; j >= 0; j--) {
            if (strcmp(slot[j], "") == 0) {
                strcpy(slot[j], a[i].id);
                total += a[i].priority;
                break;
            }
        }
    }

    printf("\nScheduled Appointments:\n");

    for (i = 0; i < maxDeadline; i++)
        if (strcmp(slot[i], "") != 0)
            printf("Slot %d: %s\n", i + 1, slot[i]);

    printf("\nMaximum Priority Score = %d\n", total);

    return 0;
}
