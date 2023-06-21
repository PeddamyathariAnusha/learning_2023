#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    float marks;
};

void initializeArray(struct Student *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%19s", arr[i].name);
        printf("Marks: ");
        scanf("%f", &(arr[i].marks));
        printf("\n");
    }
}

void searchStudentByName(struct Student *arr, int size, const char *name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            printf("Student found!\n");
            printf("Name: %s\n", arr[i].name);
            printf("Marks: %.2f\n", arr[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    struct Student arr[size];
    initializeArray(arr, size);
    char searchName[20];
    printf("Enter the name of the student to search: ");
    scanf("%19s", searchName);
    searchStudentByName(arr, size, searchName);
    return 0;
}