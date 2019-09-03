#include "INPUTS.h"





int getInt(int* valor, char mensaje[], int min, int max)
{
    int retorno = 0;

    printf("%s", mensaje);
    scanf("%d", valor);

    while(*valor<min || *valor>max)
    {
        printf("Error, %s\a\a", mensaje);
        scanf("%d", valor);
    }

    return retorno;
}
