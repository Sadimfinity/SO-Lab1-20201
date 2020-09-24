#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    for (i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        // {
        //     printf("wcat: cannot open file\n");
        //     exit(1);
        // }
        // char ch;
        // while((ch = getc(fp)) != EOF){
        //     printf("%c", ch);

        // }
        if (fp == NULL)
        {
            printf("cannot open file\n");
            exit(1);
        }
        char *s;
        while((s = fgets(s, sizeof(*fp), fp)) != EOF){
            if (s == NULL)
                break;
            else
                printf("%s", s);
            free(s);
        }
    }
    return 0;
}
