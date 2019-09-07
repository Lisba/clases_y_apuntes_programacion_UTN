#include <stdio.h>
#include <stdlib.h>

void showVectorInt(int vect[], int length);
int getMajVectInt(int vect[], int length);

int main()
{
    int numero[5];
    int mayor;

    for(int i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero[i]);
    }

    for(int i=0; i<5; i++)
    {
        if(i==0)
        {
            mayor = numero[0];

        }else if(mayor <= numero[i])
        {
            mayor = numero[i];
        }
    }

    for(int i=0; i<5; i++)
    {
        if(mayor == numero[i])
        {
            printf("%d ", i);
        }
    }

    printf("\n\nEl valor mas alto es: %d\n", mayor);
    showVectorInt(numero, 5);
    printf("\nThe higher number is: %d", getMajVectInt(numero, 5));

    return 0;
}

void showVectorInt(int vect[], int length)
{
    for(int i=0; i<length; i++)
    {
        printf("%d ", vect[i]);
    }
}

int getMajVectInt(int vect[], int length)
{
    int major;

    for(int i=0; i<length; i++)
    {
        if(i==0)
        {
            major = vect[0];

        }else if(major <= vect[i])
        {
            major = vect[i];
        }
    }

    return major;
}
