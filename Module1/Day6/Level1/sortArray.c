#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortArray(struct Student *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].marks < arr[j + 1].marks) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(struct Student *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\nRoll No: %d\nName: %s\nMarks: %.2f\n\n", i + 1, arr[i].rollno, arr[i].name, arr[i].marks);
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    struct Student arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &(arr[i].rollno));
        printf("Name: ");
        scanf("%s", arr[i].name);
        printf("Marks: ");
        scanf("%f", &(arr[i].marks));
        printf("\n");
    }

    sortArray(arr, size);
    printf("Sorted Array:\n");
    displayArray(arr, size);
    return 0;
}