#include <stdio.h>

int comparebox(int boxA[], int boxB[], int size) {
    int i, j, match;
    for (i = 0; i < size; i++) {
        match = 0;
        for (j = 0; j < size; j++) {
            if (boxA[i] == boxB[j]) {
                match = 1;
                break;
            }
        }
        if (!match) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int size, i;

    printf("Enter the size of the boxes: ");
    scanf("%d", &size);

    int boxA[size], boxB[size];

    printf("Enter the items of box A: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &boxA[i]);
    }

    printf("Enter the items of box B: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &boxB[i]);
    }

    int result = comparebox(boxA, boxB, size);

    printf("Result: %d\n", result);

    return 0;
}
