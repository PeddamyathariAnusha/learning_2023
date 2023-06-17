#include <stdio.h>
int main() {
    int array[100];
    int length, evenSum = 0, oddSum = 0;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);

        if (i % 2 == 0) {
            evenSum += array[i]; 
        } else {
            oddSum += array[i]; 
        }
    }

    printf("Sum of even indexed elements: ");
    for (int i = 0; i < length; i += 2) {
        printf("%d ", array[i]);
        if (i != length - 2) {
            printf("+ ");
        }
    }
    printf("= %d\n", evenSum);
    printf("Sum of odd indexed elements: ");
    for (int i = 1; i < length; i += 2) {
        printf("%d ", array[i]);
        if (i != length - 1) {
            printf("+ ");
        }
    }
    printf("= %d\n", oddSum);
    return 0;
}