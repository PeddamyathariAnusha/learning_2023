#include <stdio.h>

int stringToInt(char* str) {
    int res = 0;
    int i = 0;
    if (str[0] == '-') {
        i = 1;
    }
    while (str[i] != '\0') {
        int ival = str[i] - '0';
        res = res * 10 + ival;
        i++;
    }
    if (str[0] == '-') {
        res = -res;
    }
    return res;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int num = stringToInt(str);
    printf("Integer value: %d\n", num);

    return 0;
}