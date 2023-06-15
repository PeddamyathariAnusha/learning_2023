// To set,clear and toggle 8 bit number
#include <stdio.h>

unsigned char setBit(unsigned char num, int pos) {
    unsigned char mask = 1 << pos;
    return num | mask;
}
unsigned char clearBit(unsigned char num, int pos) {
    unsigned char mask = ~(1 << pos);
    return num & mask;
}
unsigned char toggleBit(unsigned char num, int pos) {
    unsigned char mask = 1 << pos;
    return num ^ mask;
}

int main() {
    unsigned char num;
    int bitPosition;
    printf("Enter the initial value (in hexadecimal): ");
    scanf("%hhx", &num);
    num = setBit(num, 2);
    printf("Value after setting bit %d: 0x%02X\n", bitPosition, num);
    num = clearBit(num, 3);
    printf("Value after clearing bit %d: 0x%02X\n", bitPosition, num);
    num = toggleBit(num, 4);
    printf("Value after toggling bit %d: 0x%02X\n", bitPosition, num);
    return 0;
}

