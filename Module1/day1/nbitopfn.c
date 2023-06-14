#include <stdio.h>

int bit_operations(int num, int oper_type, int pos) {
    switch (oper_type) {
        case 1:
            num |= (0x3 << pos); // Set 2 bits from nth bit position
            break;
        case 2:
            num &= ~(0x7 << pos); // Clear 3 bits from nth bit position
            break;
        case 3:
            num ^= (1 << 31); // Toggle MSB (Most Significant Bit)
            break;
        default:
            printf("Error: Invalid operation type.\n");
            return -1; 
    }

    return num;
}

int main() {
    int number, operation, position;
    printf("Enter an integer (32 bits): ");
    scanf("%d", &number);
    printf("Enter the operation type (1, 2, 3): ");
    scanf("%d", &operation);
    printf("Enter the position (0-31): ");
    scanf("%d", &position);
    int result = bit_operations(number, operation, position);

    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}
