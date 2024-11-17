#include <stdio.h>
#include <stdlib.h>

void CSCAN(int arr[], int n, int start, int end) {
    int total_seek = 0, seek;
    int current = start;
    printf("\nC-SCAN Disk Scheduling:\n");
    printf("Seek Sequence: ");
    
    for (int i = 0; i < n; i++) {
        if (arr[i] >= start) {
            seek = abs(arr[i] - current);
            total_seek += seek;
            current = arr[i];
            printf("%d ", arr[i]);
        }
    }
    total_seek += abs(current - end);
    current = end;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < start) {
            seek = abs(arr[i] - current);
            total_seek += seek;
            current = arr[i];
            printf("%d ", arr[i]);
        }
    }
    printf("\nTotal Seek Time = %d\n", total_seek);
}

int main() {
    int arr[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 50, end = 200;

    CSCAN(arr, n, start, end);

    return 0;
}
