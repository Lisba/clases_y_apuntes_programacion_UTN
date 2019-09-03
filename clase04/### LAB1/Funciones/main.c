#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
#include "Input.h"





void funcion(int*);


int main()
{
    int numero = 100;
   funcion(&numero);
    printf("Numero en el main: %d", numero);
    return 0;
}

void funcion(int* numero)
{
    //*numero = 5;
    int n;
    printf("Ingrese numero: ");
    scanf("%d", numero);

}

