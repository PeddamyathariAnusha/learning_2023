#include <stdio.h>

int greatestno(int num1, int num2, int num3) {
    int greatest = num1;

    if (num2 > greatest) {
        greatest = num2;
    }

    if (num3 > greatest) {
        greatest = num3;
    }

    return greatest;
}

int main() {
    int num1, num2, num3;
    printf("Enter three number: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    int result = greatestno(num1, num2, num3);
    printf("The greatest number is: %d\n", result);

    return 0;
}
