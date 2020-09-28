#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    for (i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        int val;
        char *s = malloc(sizeof(char));
        while((val = getc(fp)) != EOF){
            *s = val;
            if (s == NULL)
                break;
            else
                printf("%s", s);
        }
    }
    return 0;
}
