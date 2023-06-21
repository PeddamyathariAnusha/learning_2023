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
        printf("Roll No: %d\n", arr[i].rollno);
        printf("Name: %s\n", arr[i].name);
        printf("Marks: %.2f\n", arr[i].marks);
        printf("\n");
    }
}

void deleteMember(struct Student **arr, int *size) {
    if (*size <= 0) {
        printf("Array is empty. No member to delete.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *size -= 1;
    *arr = (struct Student *)realloc(*arr, (*size) * sizeof(struct Student));
    printf("Member at the start has been deleted.\n");
}

int main() {
    const char *input = "1001 Aron 100.00\n1002 Bob 90.50\n1003 Charlie 95.75";
    int size = 3;
    struct Student *arr = (struct Student *)malloc(size * sizeof(struct Student));
    initializeArray(arr, size, input);
    displayArray(arr, size);
    deleteMember(&arr, &size);
    printf("\nAfter deleting a member at the start:\n");
    displayArray(arr, size);
    free(arr);
    return 0;
}