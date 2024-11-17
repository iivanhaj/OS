#include <stdio.h>
#define MAX_PARTITIONS 100
#define MAX_PROCESSES 100

void worstFit(int partitions[], int numPartitions, int processes[], int numProcesses) {
    int allocation[MAX_PROCESSES] = {-1};  // Initialize all to -1
    for (int i = 0; i < numProcesses; i++) {
        int worstIndex = -1;
        for (int j = 0; j < numPartitions; j++) {
            if (partitions[j] >= processes[i]) {
                if (worstIndex == -1 || partitions[j] > partitions[worstIndex]) {
                    worstIndex = j;
                }
            }
        }
        if (worstIndex != -1) {
            allocation[i] = worstIndex;
            partitions[worstIndex] -= processes[i];  // Update partition size
        }
    }
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d %s to Partition %d\n", i + 1, allocation[i] != -1 ? "allocated" : "not allocated", allocation[i] + 1);
    }
}

int main() {
    int partitions[MAX_PARTITIONS], processes[MAX_PROCESSES];
    int numPartitions, numProcesses;
    printf("Enter number of partitions and processes: ");
    scanf("%d %d", &numPartitions, &numProcesses);
    printf("Enter partition sizes: ");
    for (int i = 0; i < numPartitions; i++) scanf("%d", &partitions[i]);
    printf("Enter process sizes: ");
    for (int i = 0; i < numProcesses; i++) scanf("%d", &processes[i]);

    printf("\nWorst Fit Allocation:\n");
    worstFit(partitions, numPartitions, processes, numProcesses);
    return 0;
}
