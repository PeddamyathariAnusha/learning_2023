#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student *arr, int size, const char *input) {
    int i = 0;
    while (sscanf(input, "%d %19s %f", &(arr[i].rollno), arr[i].name, &(arr[i].marks)) == 3) {
        input = strchr(input, '\n');
        if (input == NULL)
            break;
        input++;
        i++;
    }
}

void displayArray(struct Student *arr, int size) {
    printf("Students Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", arr[i].rollno);
        printf("Name: %s\n", arr[i].name);
        printf("Marks: %.2f\n", arr[i].marks);
        printf("\n");
    }
}

void rotateArray(struct Student *arr, int size, int k) {
    k = k % size;
    if (k == 0)
        return;
    struct Student *tempArr = (struct Student *)malloc(k * sizeof(struct Student));
    for (int i = 0; i < k; i++) {
        tempArr[i] = arr[i];
    }
    for (int i = k; i < size; i++) {
        arr[i - k] = arr[i];
    }
    for (int i = 0; i < k; i++) {
        arr[size - k + i] = tempArr[i];
    }
    free(tempArr); 
}

int main() {
    const char *input = "1001 Aron 100.00\n1002 Bob 90.50\n1003 Charlie 95.75";
    int size = 3;
    struct Student *arr = (struct Student *)malloc(size * sizeof(struct Student));
    initializeArray(arr, size, input);
    displayArray(arr, size);
    int k;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);
    rotateArray(arr, size, k);
    printf("\nAfter rotating array by %d positions:\n", k);
    displayArray(arr, size);
    free(arr);
    return 0;
}