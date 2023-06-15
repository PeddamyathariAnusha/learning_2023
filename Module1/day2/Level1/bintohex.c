#include <stdio.h>
void printExponent(double x) {
    unsigned long long *ptr = (unsigned long long*)&x;
    unsigned long long exponent = (*ptr >> 52) & 0x7FF;
    unsigned long long hexExponent = exponent - 1023;
    
    printf("Hexadecimal exponent: 0x%llx\n", hexExponent);
    
    // Convert exponent to binary
    unsigned long long binaryExponent = 0;
    int i;
    for (i = 10; i >= 0; i--) {
        binaryExponent = (binaryExponent << 1) | ((exponent >> i) & 1);
    }
    
    printf("Binary exponent: 0b");
    for (i = 10; i >= 0; i--) {
        printf("%llu", (binaryExponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);
    
    return 0;
}
