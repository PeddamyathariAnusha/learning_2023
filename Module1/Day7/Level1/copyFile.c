#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fin, *fout;
    fin = fopen("read.txt", "r");
    fout = fopen("write.txt", "w");
    if (fin == NULL)
    {
        printf("Unable to open the source file.\n");
        return 1;
    }
    if (fout == NULL)
    {
        printf("Unable to create the destination file.\n");
        fclose(fin);
        return 1;
    }
    size_t maxlen = 50;
    char *ptr = (char *)malloc(maxlen * sizeof(char));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(fin);
        fclose(fout);
        return 1;
    }
    while (fgets(ptr, maxlen, fin) != NULL)
    {
        fputs(ptr, fout);
    }
    free(ptr);
    fclose(fin);
    fclose(fout);
    printf("File copied successfully.\n");
    return 0;
}