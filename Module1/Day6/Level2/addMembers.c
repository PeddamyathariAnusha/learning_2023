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
    }
}

void addMember(struct Student **arr, int *size) {
    *size += 1;
    *arr = (struct Student *)realloc(*arr, (*size) * sizeof(struct Student));
    printf("Enter details for the new student:\n");
    printf("Roll No: ");
    scanf("%d", &((*arr)[*size - 1].rollno));
    printf("Name: ");
    scanf("%19s", (*arr)[*size - 1].name);
    printf("Marks: ");
    scanf("%f", &((*arr)[*size - 1].marks));
   }

int main() {
    const char *input = "1001 Aron 100.00";
    int size = 1;
    struct Student *arr = (struct Student *)malloc(size * sizeof(struct Student));
    initializeArray(arr, size, input);
    displayArray(arr, size);
    addMember(&arr, &size);
    printf("\nAfter adding a new member:\n");
    displayArray(arr, size);
    free(arr);
    return 0;
}