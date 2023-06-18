#include <stdio.h>

void decimalToBinary(int num) {
    int binary[32];
    int index = 0;
    while (num > 0) {
        binary[index] = num % 2;
        num /= 2;
        index++;
    }
    printf("Binary value: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

void decimalToOctal(int num) {
    int octal[32];
    int index = 0;
    while (num > 0) {
        octal[index] = num % 8;
        num /= 8;
        index++;
    }
    printf("Octal value: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", octal[i]);
    }
    printf("\n");
}

void decimalToHexadecimal(int num) {
    char hex[32];
    int index = 0;
    while (num > 0) {
        int rem = num % 16;
        if (rem < 10) {
            hex[index] = rem + '0';
        } else {
            hex[index] = rem + 'A' - 10;
        }
        num /= 16;
        index++;
    }
    printf("Hexadecimal Value: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    decimalToBinary(num);
    decimalToOctal(num);
    decimalToHexadecimal(num);
    return 0;
}






