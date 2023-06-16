#include <stdio.h>
int countSetBits(unsigned int num) {
    int count = 0;
    
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    
    return count;
}
int countTotalSetBits(unsigned int arr[], int size) {
    int totalBits = 0;
    
    for (int i = 0; i < size; i++) {
        totalBits += countSetBits(arr[i]);
    }
    
    return totalBits;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    unsigned int arr[size];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%x", &arr[i]);
    }
    
    int result = countTotalSetBits(arr, size);
    
    printf("Total number of set bits: %d\n", result);
    
    return 0;
}
