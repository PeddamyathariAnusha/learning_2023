#include <stdio.h>
#include <math.h>

long long binaryToDecimal(char binary[]) {
    int length = 0;
    while (binary[length] != '\0') {
        length++;
    }

    long long decimal = 0;
    int base = 2;

    for (int i = length - 1; i >= 0; i--) {
        decimal += (binary[i] - '0') * pow(base, length - 1 - i);
    }

    return decimal;
}

long long octalToDecimal(char octal[]) {
    int length = 0;
    while (octal[length] != '\0') {
        length++;
    }

    long long decimal = 0;
    int base = 8;

    for (int i = length - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * pow(base, length - 1 - i);
    }

    return decimal;
}

long long hexadecimalToDecimal(char hexadecimal[]) {
    int length = 0;
    while (hexadecimal[length] != '\0') {
        length++;
    }

    long long decimal = 0;
    int base = 16;

    for (int i = length - 1; i >= 0; i--) {
        int digit;
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            digit = hexadecimal[i] - '0';
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            digit = hexadecimal[i] - 'A' + 10;
        } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            digit = hexadecimal[i] - 'a' + 10;
        }
        decimal += digit * pow(base, length - 1 - i);
    }

    return decimal;
}

int main() {
    char binary[32];
    char octal[32];
    char hexadecimal[32];

    printf("Enter a binary,octal and hexadecimal number: ");
    scanf("%s %s %s", binary,octal, hexadecimal);
    long long decimalBinary = binaryToDecimal(binary);
    long long decimalOctal = octalToDecimal(octal);
    long long decimalHexadecimal = hexadecimalToDecimal(hexadecimal);

    printf("Decimal from binary: %lld\n", decimalBinary);
    printf("Decimal from octal: %lld\n", decimalOctal);
    printf("Decimal from hexadecimal: %lld\n", decimalHexadecimal);

    return 0;
}