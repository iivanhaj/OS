#include <stdio.h>
#include <stdlib.h>

void FCFS(int arr[], int n, int start) {
    int total_seek = 0, seek;
    printf("\nFCFS Disk Scheduling:\n");
    printf("Seek Sequence: ");
    int current = start;
    for (int i = 0; i < n; i++) {
        seek = abs(arr[i] - current);
        total_seek += seek;
        current = arr[i];
        printf("%d ", arr[i]);
    }
    printf("\nTotal Seek Time = %d\n", total_seek);
}

int main() {
    int arr[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 50;

    FCFS(arr, n, start);

    return 0;
}
