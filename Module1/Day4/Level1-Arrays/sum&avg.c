#include <stdio.h>

int main() {
    int array[100];
    int len, i;
    float sum = 0, average=0;

    printf("Enter size of the array: ");
    scanf("%d", &len);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i <= len; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0 ; i <= len ; i++)
    {
        sum = sum + array[i] ;
        average = sum / len;
    }
    printf("Sum: %.1f\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
