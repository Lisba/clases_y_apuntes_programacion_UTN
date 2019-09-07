#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero[5];
    int suma=0;

    for(int i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero[i]);
    }

    for(int i=0; i<5; i++)
    {
        suma += numero[i];
    }

    for(int i=0; i<5; i++)
    {
        printf("\nEl valor de numero%d es: %d",i , numero[i]);
    }
        printf("\n\nEl resultado total de la suma de numero es: %d\n", suma);

    return 0;
}
