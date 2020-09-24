#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL)
    {
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    size_t size = 10;
    char *line = malloc(sizeof(char)*size);
    line = (char *)argv[1];

    size_t result = getline(&line, &size, fp);
    printf("%s", result);
    return 0;
}
