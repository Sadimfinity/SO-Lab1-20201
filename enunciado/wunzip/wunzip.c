#include <stdio.h>
#include <stdlib.h>
#define INTLEN 4
#define ASCLEN 1

int main(int argc, char *argv[])
{
    FILE *fp;
    char character;
    int iterations;

    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    iterations = 0;
    while (argc-- > 0) {
        if ((fp = fopen(*argv++, "r")) == NULL)
            exit(1);
        while (fread(&iterations, INTLEN, 1, fp)) {
            fread(&character, ASCLEN, 1, fp);
            while (iterations-- > 0)
                printf("%c", character);
        }
        fclose(fp);
    }
}