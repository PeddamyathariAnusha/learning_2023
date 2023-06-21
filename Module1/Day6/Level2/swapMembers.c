#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void initializeArray(struct Student *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter details for student %d:\n", i + 1);
        scanf("%d %19s %f", &(arr[i].rollno), arr[i].name, &(arr[i].marks));
    }
}
void displayArray(struct Student *arr, int size) {
    printf("Students Info:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", arr[i].rollno);
        printf("Name: %s\n", arr[i].name);
        printf("Marks: %.2f\n", arr[i].marks);
    }
}
void swapMembers(struct Student *arr, int size, int index1, int index2) {
    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
        printf("Invalid indexes. Unable to swap members.\n");
        return;
    }
    struct Student temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    printf("Members at indexes %d and %d swapped successfully.\n", index1, index2);
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    struct Student *arr = (struct Student *)malloc(size * sizeof(struct Student));
    initializeArray(arr, size);
    displayArray(arr, size);
    int index1, index2;
    printf("Enter the indexes of the members to swap (0-%d): ", size - 1);
    scanf("%d %d", &index1, &index2);
    swapMembers(arr, size, index1, index2);
    printf("\nAfter swapping members:\n");
    displayArray(arr, size);
    free(arr);
    return 0;
}