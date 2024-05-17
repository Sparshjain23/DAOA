#include <stdio.h>

void jobScheduling(int deadlines[], int profits[], int n) {
    int maxDeadline = 0, totalProfit = 0;
    int slots[100] = {0}; 

    for (int i = 0; i < n; i++) {
        if (deadlines[i] > maxDeadline) {
            maxDeadline = deadlines[i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = deadlines[i] - 1; j >= 0; j--) {
            if (!slots[j]) {
                slots[j] = 1; 
                totalProfit += profits[i];
                break;
            }
        }
    }

    printf("Total Profit: %d\n", totalProfit);
}

int main() {

    int deadlines[] = {4, 1, 1, 1};
    int profits[] = {20, 10, 40, 30};
    int n = sizeof(deadlines) / sizeof(deadlines[0]);

    jobScheduling(deadlines, profits, n);

    return 0;
}