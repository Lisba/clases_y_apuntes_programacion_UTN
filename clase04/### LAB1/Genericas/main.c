#include <stdio.h>
#include <stdlib.h>
#include "INPUTS.h"
int main()
{
    int edad = 7;
    int nota;

    getInt(&edad, "Ingrese su edad: ", 10, 50);
    printf("Ud tiene: %d años", edad);

    getInt(&nota, "Ingrese una nota: ", 1, 10);
    printf("Ud se saco un: %d", nota);

    return 0;
}

