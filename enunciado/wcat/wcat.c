#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("cannot open file\n");
        exit(1);
    }
    char* s;
    char buffer = fgets(s, NULL,fp);
    //int* b = argv[1];
    //const char *a = atoi(b);
    printf("%s", buffer);
    return 0;
}
