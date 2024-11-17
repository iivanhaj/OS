#include <stdio.h>
#define MAX_PARTITIONS 100
#define MAX_PROCESSES 100

void firstFit(int partitions[], int numPartitions, int processes[], int numProcesses) {
    int allocation[MAX_PROCESSES] = {-1};  // Initialize all to -1
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numPartitions; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j;
                partitions[j] -= processes[i];  // Update partition size
                break;
            }
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

    printf("\nFirst Fit Allocation:\n");
    firstFit(partitions, numPartitions, processes, numProcesses);
    return 0;
}
