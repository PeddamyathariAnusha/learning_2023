#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[20];
    float marks;
};

typedef struct Student Student;

void initStudent(Student*, int, char*, float);
void displayStudent(Student*);
void displayArray(Student*, int);
void initArray(Student*, int);

int main() {
    int size = 1;
    Student arr[size];
    initArray(arr, size);
    displayArray(arr, size);
    return 0;
}

void initStudent(Student* ptr, int id, char* nptr, float score) {
    ptr->rollNo = id;
    ptr->marks = score;
    strcpy(ptr->name, nptr);
}

void displayStudent(Student* ptr) {
    printf("%d %s %.2f\n", ptr->rollNo, ptr->name, ptr->marks);
}

void displayArray(Student* ptr, int size) {
    printf("Displaying\n");
    for (int i = 0; i < size; i++) {
        displayStudent(&ptr[i]);
    }
}

void initArray(Student* ptr, int size) {
    int id;
    char n[20];
    float score;
    printf("Scanning: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &id);
        scanf("%s", n);
        scanf("%f", &score);
        initStudent(&ptr[i], id, n, score);
    }
}