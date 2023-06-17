#include <stdio.h>

int main() {
    int array[100];
    int n;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\nReversed array: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }

    return 0;
}