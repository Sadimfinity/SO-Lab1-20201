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
    char *s = malloc(sizeof(char)*10000000);
    s = fgets(s, 100000,fp);
    printf("%s", s);
    return 0;
}
