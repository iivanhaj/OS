#include <stdio.h>

void fifo(int pages[], int n, int capacity) {
    int frame[capacity], front = 0, faults = 0;
    for (int i = 0; i < capacity; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) found = 1;
        }
        if (!found) {
            frame[front] = pages[i];
            front = (front + 1) % capacity;
            faults++;
        }
    }

    printf("FIFO Page Faults: %d\n", faults);
}

int main() {
    int n, capacity;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter pages: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter frame capacity: ");
    scanf("%d", &capacity);

    fifo(pages, n, capacity);
    return 0;
}
