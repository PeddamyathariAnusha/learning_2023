#include <stdio.h>

int countSetBits(unsigned int n) {
    int count = 0;
    while (n != 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int totalSetBits(unsigned int arr[], int size) {
    int totalBits = 0;
    for (int i = 0; i < size; i++) {
        totalBits += countSetBits(arr[i]);
    }
    return totalBits;
}

int main() {
    unsigned int arr[3] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);

    int totalBits = totalSetBits(arr, size);

    printf("The total number of set bits in the given array is: %d\n", totalBits);

    return 0;
}
