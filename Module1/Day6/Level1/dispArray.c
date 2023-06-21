#include <stdio.h>
struct Student {
    int rollNo;
    char name[20];
    float marks;
};
void displayArray(struct Student *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d %s %f", &arr[i].rollNo, arr[i].name, &arr[i].marks);
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    struct Student arr[size];
    displayArray(arr, size);
    for (int i = 0; i < size; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Roll No: %d\n", arr[i].rollNo);
        printf("Name: %s\n", arr[i].name);
        printf("Marks: %.2f\n", arr[i].marks);
    }
    
    return 0;
}