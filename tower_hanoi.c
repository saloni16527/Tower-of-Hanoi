#include <stdio.h>

long long moveCount = 0;

void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {
    if (n == 1) {
        printf("Move %lld: Disk 1 from %c to %c\n",
               ++moveCount, source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the largest disk to destination
    printf("Move %lld: Disk %d from %c to %c\n",
           ++moveCount, n, source, destination);

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main(void) {
    int n;

    printf("=== Tower of Hanoi ===\n");
    printf("Enter number of disks (1-20): ");

    if (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        printf("Invalid input. Enter a number from 1 to 20.\n");
        return 1;
    }

    moveCount = 0;

    printf("\nSteps to solve %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');

    printf("\nTotal moves: %lld\n", moveCount);
    printf("Minimum moves required: %lld\n", (1LL << n) - 1);

    return 0;
}