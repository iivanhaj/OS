#include <stdio.h>
#include <limits.h>

void lru(int pages[], int n, int capacity) {
    int frame[capacity], time[capacity], faults = 0, t = 0;
    for (int i = 0; i < capacity; i++) frame[i] = -1, time[i] = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) found = j;
        }
        if (found == -1) {
            int lru_idx = 0;
            for (int j = 1; j < capacity; j++) {
                if (time[j] < time[lru_idx]) lru_idx = j;
            }
            frame[lru_idx] = pages[i];
            faults++;
            time[lru_idx] = ++t;
        } else {
            time[found] = ++t;
        }
    }

    printf("LRU Page Faults: %d\n", faults);
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

    lru(pages, n, capacity);
    return 0;
}
