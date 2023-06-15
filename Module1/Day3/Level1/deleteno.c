#include <stdio.h>
#include<math.h>
int findLargest(int num) {
    int largest = 0;

    for (int i = 0; i < 4; i++) {
        int temp = num / (int)pow(10, i + 1) * (int)pow(10, i) + num % (int)pow(10, i);
        if (temp > largest) {
            largest = temp;
        }
    }

    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    int largest = findLargest(num);
    printf("Largest number by deleting single digit: %d\n", largest);
    return 0;
}