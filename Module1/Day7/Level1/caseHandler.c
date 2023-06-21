#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyFile(FILE *source, FILE *destination, int caseOption) {
    char ch;
    
    while ((ch = fgetc(source)) != EOF) {
        if (caseOption == 1)
            ch = toupper(ch);
        else if (caseOption == 2)
            ch = tolower(ch);
        else if (caseOption == 3) {
            if (isalpha(ch)) {
                if (islower(ch))
                    ch = toupper(ch);
                else
                    ch = tolower(ch);
            }
        }
        
        fputc(ch, destination);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s -s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
    
    int caseOption = 0;
    
    if (argv[1][0] == '-') {
        switch (argv[1][1]) {
            case 'u':
                caseOption = 1;
                break;
            case 'l':
                caseOption = 2;
                break;
            case 's':
                caseOption = 3;
                break;
            default:
                printf("Invalid option: %s\n", argv[1]);
                return 1;
        }
    }
    
    FILE *source = fopen(argv[2], "r");
    if (source == NULL) {
        printf("Error opening source file: %s\n", argv[2]);
        return 1;
    }
    
    FILE *destination = fopen(argv[3], "w");
    if (destination == NULL) {
        printf("Error opening destination file: %s\n", argv[3]);
        return 1;
    }
    
    copyFile(source, destination, caseOption);
    
    printf("File copied successfully.\n");
    
    fclose(source);
    fclose(destination);
    
    return 0;
}
