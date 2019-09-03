#include "Operaciones.h"

int calcularFactorial(int numero)
{
    int factorial;

    if(numero == 1)
    {
        factorial = 1;
    }
    else
    {
        factorial = numero * calcularFactorial(numero-1);
    }


    return factorial;
}
