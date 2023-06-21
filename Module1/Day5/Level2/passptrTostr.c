#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};
struct Person* modifyPerson(struct Person* person) {
    printf("Enter new name and age of the person: ");
    scanf("%s %d", person->name, &person->age);
    return person;
}
typedef struct Person person;
int main() {
    struct Person person;
    printf("Enter name and age of the person: ");
    scanf("%s %d", person.name, &person.age);
    struct Person* modifiedPerson = modifyPerson(&person);
    printf("Modified Person Details:\n");
    printf("Name: %s\n", modifiedPerson->name);
    printf("Age: %d\n", modifiedPerson->age);
    return 0;
}