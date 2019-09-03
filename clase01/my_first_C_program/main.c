#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contadorGral=0;
    int contadorPositivos=0;
    int contadorNegativos=0;

    while(contadorGral<10)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        contadorGral++;
        if(numero>0)
        {
            contadorPositivos++;

        } else if(numero<0)
        {
            contadorNegativos++;
        }
    }

    printf("\nLa cantidad de positivos ingresados es %d y la cantidad de negativos ingresados es %d.\n", contadorPositivos, contadorNegativos);

    return 0;
}
