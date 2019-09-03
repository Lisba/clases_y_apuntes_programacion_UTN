#include <stdio.h>
#include <stdlib.h>

int getIntRango(int a, int b);

int main()
{
    int x = getIntRango(300, 600);

    printf("\nEl numero ingresado es: %d\n", x);
    return 0;
}

int getIntRango(int a, int b)
{
    int a;
    int b;
    int numero;

    do
    {
        printf("Ingrese un entero: ");
        scanf("%d", &numero);

    } while (numero < a || numero > b);

    return numero;
}
