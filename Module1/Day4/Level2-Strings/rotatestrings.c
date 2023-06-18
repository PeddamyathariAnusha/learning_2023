#include <stdio.h>
#include <string.h>

void rotateString(char str[], int k, char direction[]) {
    int len = strlen(str);
    if (strcmp(direction, "Left") == 0) {
        // Rotate left
        for (int i = 0; i < k; i++) {
            char temp = str[0];
            for (int j = 0; j < len - 1; j++) {
                str[j] = str[j + 1];
            }
            str[len - 1] = temp;
        }
    } else if (strcmp(direction, "Right") == 0) {
        // Rotate right
        for (int i = 0; i < k; i++) {
            char temp = str[len - 1];
            for (int j = len - 1; j > 0; j--) {
                str[j] = str[j - 1];
            }
            str[0] = temp;
        }
    }
}

int main() {
    char str[100];
    int k;
    char direction[10];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter the number of rotations: ");
    scanf("%d", &k);
    printf("Enter the direction (Left/Right): ");
    scanf("%s", direction);
    rotateString(str, k, direction);
    printf("Rotated string: %s\n", str);
    return 0;
}