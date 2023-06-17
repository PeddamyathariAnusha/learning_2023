#include <stdio.h>

int main() {
    int array[100],n;
    int sumEven=0, sumOdd=0; 
    printf("Enter size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            sumEven += array[i];  
            
        } else {
            sumOdd += array[i];  
            
        }
    }

    printf("Sum of even elements: %d\n", sumEven);
    printf("Sum of odd elements: %d\n", sumOdd);

    return 0;
}