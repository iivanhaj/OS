#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

// Function to calculate the Need matrix
void calculateNeed(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allot[MAX_PROCESSES][MAX_RESOURCES], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allot[i][j];
}

// Function to check if the system is in a safe state and find the safe sequence
bool isSafe(int processes[], int avail[], int max[][MAX_RESOURCES], int allot[][MAX_RESOURCES], int n, int m) {
    int need[MAX_PROCESSES][MAX_RESOURCES], work[MAX_RESOURCES], finish[MAX_PROCESSES] = {0}, safeSeq[MAX_PROCESSES];
    calculateNeed(need, max, allot, n, m);

    // Initialize work with available resources
    for (int i = 0; i < m; i++) work[i] = avail[i];

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[p][j] > work[j]) break;

                // If process p can be finished
                if (j == m) {
                    for (int k = 0; k < m; k++) work[k] += allot[p][k];  // Add allocated resources back to work
                    safeSeq[count++] = processes[p];  // Add process to safe sequence
                    finish[p] = 1;  // Mark process as finished
                    found = true;
                }
            }
        }
        if (!found) return false;  // No process could be finished, system is not safe
    }

    // Print the safe sequence
    printf("Safe sequence: ");
    for (int i = 0; i < n; i++) printf("%d ", safeSeq[i]);
    printf("\n");
    return true;
}

int main() {
    int processes[MAX_PROCESSES];
    int n, m;

    // Input number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int max[MAX_PROCESSES][MAX_RESOURCES], allot[MAX_PROCESSES][MAX_RESOURCES], avail[MAX_RESOURCES];

    // Input max matrix
    printf("Enter the max matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter max resources for process %d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter allocated resources for process %d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    // Input available resources
    printf("Enter the available resources: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Initialize processes array
    for (int i = 0; i < n; i++) {
        processes[i] = i;
    }

    // Check if the system is in a safe state
    if (!isSafe(processes, avail, max, allot, n, m)) {
        printf("System is not in a safe state.\n");
    }

    return 0;
}
