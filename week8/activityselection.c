#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int index;
    int start;
    int finish;
};

// Sort activities by finish time
int compare(const void *a, const void *b) {
    return ((struct Activity*)a)->finish - ((struct Activity*)b)->finish;
}

int main() {
    struct Activity activities[] = {
        {1, 1, 2},
        {2, 3, 4},
        {3, 0, 6},
        {4, 5, 7},
        {5, 8, 9},
        {6, 5, 9}
    };

    int n = sizeof(activities) / sizeof(activities[0]);

    // Sort by finish time
    qsort(activities, n, sizeof(struct Activity), compare);

    // Always select the first activity
    int last = 0;
    printf("A%d\n", activities[last].index);

    // Check remaining activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[last].finish) {
            printf("A%d\n", activities[i].index);
            last = i;
        }
    }

    return 0;
    }
