#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char character;
    char characterAux;
    char characterFirst = 1;
    int sumChar = 1;

    for (int i = 1; i < argc; i++)
    {

        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }
        else
        {   
            //la funcion fgetc nos sirve para obtener el siguiente caracter y avanzar en la posicion de la secuencia leida.
            character = fgetc(fp);

            while (character != EOF)
            {
                if (character == characterAux)
                {

                    sumChar = sumChar + 1;
                }
                else
                {
                    if (characterFirst != 1)
                    {
                        //Aqui utilizamos la funcion fwrite para escribir datos en la matriz que apunta a la variable sumChar, tambien se te utiliza stdout como puntero para la secuencia del archivo.
                        fwrite(&sumChar, 1, sizeof(sumChar), stdout);
                        printf("%c", characterAux);
                    }

                    sumChar = 1;
                }

                characterAux = character;
                character = fgetc(fp);
                characterFirst = 2;
            }

            fclose(fp);
        }
    }
    fwrite(&sumChar, 1, sizeof(sumChar), stdout);
    printf("%c", characterAux);
    exit(0);
}