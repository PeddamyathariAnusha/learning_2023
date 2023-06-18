#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    int flag = 0; // Initialize flag variable to false
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            flag = 1; // Element found, set flag to true
            printf("Element found at position %d\n", i + 1);
            break; // Break the loop as element is found
        }
    }
    if (flag == 0) {
        printf("Element not found\n");
    }
}

int main() {
    int arr[100];
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key element to search: ");
    scanf("%d", &key);
    linearSearch(arr, n, key);

    return 0;
}