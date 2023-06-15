#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;
    printf("Enter Number1: ");
    scanf("%f", &num1);
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter Number2: ");
    scanf("%f", &num2);

    // Performing based operators
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Addition of %f and %f is %.2f", num1,num2,result);
            break;
        case '-':
            result = num1 - num2;
             printf("subtraction of %f and %f is %.2f", num1,num2,result);
            break;
        case '*':
            result = num1 * num2;
             printf("Multiplication of %f and %f is %.2f", num1,num2,result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                 printf("Division of %f and %f is %.2f", num1,num2,result);
            } else {
                printf("Division by zero is not allowed.\n");
                return 1; 
            }
            break;
        default:
            printf("Invalid operator.\n");
            return 1; 
    }
    return 0;
}
