#include "Input.h"

int getInt(char mensaje[], int min, int max)
{
    int numero;

    printf("%s", mensaje);
    scanf("%d", &numero);
    while(numero<min || numero>max)
    {
        printf("ERROR, %s", mensaje);
        scanf("%d", &numero);
    }
    return numero;
}
