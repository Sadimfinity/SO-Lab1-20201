#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int i;
    for (i=1; i<argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("cannot open file\n");
            exit(1);
        }
        char *s = malloc(sizeof(fp));
        s = fgets(s, sizeof(*fp), fp);
        printf("%s", s);
        free(s);
    }
    return 0;
}
