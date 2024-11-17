#include <stdio.h>
#include <limits.h>

void optimal(int pages[], int n, int capacity) {
    int frame[capacity], faults = 0;
    for (int i = 0; i < capacity; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) found = 1;
        }
        if (!found) {
            int replace_idx = -1, farthest = i;
            for (int j = 0; j < capacity; j++) {
                int next = i + 1;
                while (next < n && pages[next] != frame[j]) next++;
                if (next > farthest) {
                    replace_idx = j;
                    farthest = next;
                }
            }
            if (replace_idx == -1) replace_idx = 0;
            frame[replace_idx] = pages[i];
            faults++;
        }
    }

    printf("Optimal Page Faults: %d\n", faults);
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

    optimal(pages, n, capacity);
    return 0;
}
