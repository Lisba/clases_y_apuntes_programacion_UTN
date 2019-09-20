#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNombreApellido(char[]);

int main()
{
    char nombreApellido[23];

    getNombreApellido(nombreApellido);

    printf("\nEl nombre cargado es: %s", nombreApellido);

    return 0;
}

void getNombreApellido(char nombreApellido[])
{
    char nombre[23];
    char apellido[11];
    char aux[50];

    do
    {
        printf("Ingrese nombre: ");
        gets(aux);

        if(strlen(aux) > 10)
        {
            printf("ERROR. Ingrese un nombre de 10 caracteres o menos: ");
            gets(aux);
        }
    } while (strlen(aux) > 10);

    strcpy(nombre, aux);

    do
    {
        printf("Ingrese apellido: ");
        gets(aux);

        if(strlen(aux) > 10)
        {
            printf("ERROR! Ingrese un apellido de 10 caracteres o menos: ");
            gets(aux);
        }
    } while (strlen(aux) > 10);

    strcpy(apellido, aux);

    strcpy(nombreApellido, nombre);
    strcat(nombreApellido, ", ");
    strcat(nombreApellido, apellido);
}
