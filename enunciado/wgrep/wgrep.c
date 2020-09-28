#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    char *hilera = argv[1];
    if (argc == 2)
    {
        char limteMax[100];
        while ( fgets(limteMax, 100, stdin) ){
            if (strstr(limteMax, hilera) != NULL)
            {
                printf("%s", limteMax);
            }
        }
    }
    if (argc > 2)
    {
        for (int i = 2; i < argc; i++)
        {
            char *hilera2 = NULL;
            size_t len = 0;
            ssize_t read;
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                printf("wgrep: cannot open file\n");
                return 1;
                
            }
            while ((read = getline(&hilera2, &len, fp)) != -1)
            {
                if (strstr(hilera2, hilera) != NULL)
                {
                    printf("%s", hilera2);
                }
            }
            fclose(fp);
        }
    }

    return 0;
}