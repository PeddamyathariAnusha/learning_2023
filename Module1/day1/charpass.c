#include <stdio.h>
#include <ctype.h>

int findCharType(char ch) {
    if (isalpha(ch)) {
        if (isupper(ch)) {
            printf("Uppercase Alphabet\n");
            return 1; // 'A' to 'Z'
        } else {
             printf("Lowercase Alphabet\n");
            return 2; // 'a' to 'z'
        }
    } else if (isdigit(ch)) {
        printf("Digit\n");
        return 3; // '0' to '9'
    } else if (isprint(ch)) {
        printf("Printable Symbol\n");
        return 4; // Any other printable symbol
    } else {
        printf("Non-printable Symbol\n");
        return 5; // Non-printable symbol
    }
}

int main() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    int result = findCharType(ch);

    return 0;
}
