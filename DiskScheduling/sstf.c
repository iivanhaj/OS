#include <stdio.h>
#include <stdlib.h>

void SSTF(int arr[], int n, int start) {
    int total_seek = 0, seek, temp;
    int visited[100] = {0};
    int current = start, min_seek, min_index;
    printf("\nSSTF Disk Scheduling:\n");
    printf("Seek Sequence: ");
    for (int i = 0; i < n; i++) {
        min_seek = 9999;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                seek = abs(arr[j] - current);
                if (seek < min_seek) {
                    min_seek = seek;
                    min_index = j;
                }
            }
        }
        visited[min_index] = 1;
        total_seek += min_seek;
        current = arr[min_index];
        printf("%d ", arr[min_index]);
    }
    printf("\nTotal Seek Time = %d\n", total_seek);
}

int main() {
    int arr[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 50;

    SSTF(arr, n, start);

    return 0;
}
