#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encodeString(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] + 5;  // Add 5 to each character
    }
}

void decodeString(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] - 5;  // Subtract 5 from each character
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    encodeString(str);
    printf("Encoded string: %s\n", str);

    decodeString(str);
    printf("Decoded string: %s\n", str);

    return 0;
}
