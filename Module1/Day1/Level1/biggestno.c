#include<stdio.h>
// If else condition
int biggest(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}
// Ternary operator
int ternary(int num1, int num2) {
    int biggest = (num1 > num2) ? num1 : num2;
    return biggest;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int biggestIfElse = biggest(num1, num2);
    printf("The biggest number using if-else is: %d\n", biggestIfElse);

    int biggestTernary = ternary(num1, num2);
    printf("The biggest number using ternary operator is: %d\n", biggestTernary);

    return 0;
}
