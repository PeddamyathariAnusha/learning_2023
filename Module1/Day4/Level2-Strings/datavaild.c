#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
bool isValidEmail(char email[]) {
    int length = strlen(email);
    int atIndex = -1;
    int dotIndex = -1;
    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            atIndex = i;
        } else if (email[i] == '.') {
            dotIndex = i;
        }
    }
    // Check if '@' and '.' are present and in valid positions
    if (atIndex == -1 || dotIndex == -1 || atIndex > dotIndex || atIndex == 0 || dotIndex == length - 1) {
        return false;
    }
    // Check for username
    for (int i = 0; i < atIndex; i++) {
        if (!isalnum(email[i]) && email[i] != '.') {
            return false;
        }
    }
    // Check domain name and extension
    for (int i = atIndex + 1; i < dotIndex; i++) {
        if (!isalpha(email[i]) || !islower(email[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char email[100];
    printf("Enter an email address: ");
    scanf("%s", email);
    if (isValidEmail(email)) {
        printf("Valid email address\n");
    } else {
        printf("Invalid email address\n");
    }
    return 0;
}