#include <stdio.h>

int isVowel(char ch) {
    int isVowel = 0;

    switch (ch) {
        case 'a':
            isVowel = 1;
            break;
        case 'e':
            isVowel = 1;
            break;
        case 'i':
            isVowel = 1;
            break;
        case 'o':
            isVowel = 1;
            break;
        case 'u':
            isVowel = 1;
            break;
        case 'A':
            isVowel = 1;
            break;
        case 'E':
            isVowel = 1;
            break;
        case 'I':
            isVowel = 1;
            break;
        case 'O':
            isVowel = 1;
            break;
        case 'U':
            isVowel = 1;
            break;
        default:
            isVowel = 0;
            break;
    }

    return isVowel;
}

int main() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    int result = isVowel(ch);
    if (result == 1) {
        printf("Vowel\n");
    } else {
        printf("Not Vowel\n");
    }

    return 0;
}
