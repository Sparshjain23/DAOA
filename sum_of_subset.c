#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int arr[] = {2, 3, 7, 8, 10};
int n = 5, target = 11;
int subset[MAX_SIZE];
bool found = false;

void subsetSum(int index, int sum, int size) {
    if (sum == target) {
        found = true;
        printf("Subset Found: ");
        for (int i = 0; i < size; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    if (index == n || sum > target || found)
        return;
    subset[size] = arr[index];
    subsetSum(index + 1, sum + arr[index], size + 1);
    subsetSum(index + 1, sum, size);
}

int main() {
    subsetSum(0, 0, 0);
    if (!found)
        printf("No subset found with the given sum\n");
    return 0;
}
