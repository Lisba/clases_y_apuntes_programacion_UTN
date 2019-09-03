#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[10];
    char sexo;
    int nota;
    char respuesta;
    int contador=0;
    int maximo;
    int minimo;
    char nombreMaximo[10];
    char sexoMaximo;
    int acumuladorNotas=0;
    float promedio=0.00;

    do
    {
        fflush(stdin);
        printf("Ingrese el nombre del alumno: ");
        gets(nombre);

        fflush(stdin);
        printf("Ingrese el sexo del alumno: ");
        scanf("%c", &sexo);

        printf("Ingrese la nota del alumno: ");
        scanf("%d", &nota);

        contador++;

        acumuladorNotas += nota;

        if(contador == 1)
        {
            maximo = nota;
            minimo = nota;

        }else
        {
            if(nota > maximo)
            {
                maximo = nota;
                strcpy(nombreMaximo, nombre);
                sexoMaximo = sexo;
            }

            if(nota < minimo)
            {
                nota = minimo;
            }
        }

        printf("Desea seguir agregando datos? ingrese s/n: ");
        fflush(stdin);
        scanf("%c", &respuesta);

    }while(respuesta=='s');

    promedio = (float) acumuladorNotas / contador;

    printf("\nLos datos del alumno con mayor nota son: %s, %c, %d\n\n", nombre, sexo, nota);
    printf("El promedio total de notas ingresadas es %.2f.\n\n", promedio);

    system("pause");

    return 0;
}

/*
Tomar nombre, nota y sexo de alumnos indefinidos y:
Mostrar todos los datos del alumno con mayor nota.
El promedio total de notas.
Y el promedio de notas de las mujeres.*/
