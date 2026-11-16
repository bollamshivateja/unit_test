#include <stdio.h>

struct Meeting {
    char id[5];
    int start;
    int finish;
};

int main() {
    struct Meeting m[8] = {
        {"M1", 1, 2},
        {"M2", 3, 4},
        {"M3", 0, 6},
        {"M4", 5, 7},
        {"M5", 8, 9},
        {"M6", 5, 9},
        {"M7", 8, 11},
        {"M8", 12, 14}
    };

    int i, j;
    struct Meeting temp;

    // Sort meetings by finish time
    for (i = 0; i < 8 - 1; i++) {
        for (j = 0; j < 8 - i - 1; j++) {
            if (m[j].finish > m[j + 1].finish) {
                temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }

    printf("Selected Meetings:\n");

    int count = 0;
    int lastFinish = -1;

    for (i = 0; i < 8; i++) {
        if (m[i].start >= lastFinish) {
            printf("%s  %d  %d\n",
                   m[i].id, m[i].start, m[i].finish);

            lastFinish = m[i].finish;
            count++;
        }
    }

    printf("\nTotal meetings scheduled: %d\n", count);

    return 0;
}
