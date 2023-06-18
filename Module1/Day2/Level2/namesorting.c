#include <stdio.h>
#include <string.h>

void sortNames(char *names[], int size) {
    int i, j;
    char *temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

int main() {
    int size, i;

    printf("Enter the number of names: ");
    scanf("%d", &size);

    char *names[size];

    printf("Enter the names:\n");
    for (i = 0; i < size; i++) {
        char buffer[100];
        scanf("%s", buffer);
        names[i] = strdup(buffer);
    }
     sortNames(names, size);


    printf("\nNames in Alphabetical Order:\n");
    for (i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }

    // Free dynamically allocated memory
    for (i = 0; i < size; i++) {
        free(names[i]);
    }

    return 0;
}
