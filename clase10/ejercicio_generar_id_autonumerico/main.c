#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "conio.h"
#include "libreria_autonumerico.h"

#define A 2

int main()
{
    eAlumno listaDeAlumnos[A];
    int i;

    int lastId=100;
    int value;
    int respuesta;
    int opcion;
    for(i=0; i<A; i++)
    {
        listaDeAlumnos[i].estado=LIBRE;
    }

//    hardCodearAlumnos(listaDeAlumnos,A);

    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Eliminar\n5.Modificar\n7.Salir");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            value = cargarListadoAlumnos(listaDeAlumnos, A, lastId);
            if(value == 1)
            {
                lastId++;
            }

            break;
        case 2:
            mostrarListadoAlumnos(listaDeAlumnos, A);
            break;
        case 3:
            sortStudentsByNameAndAverage(listaDeAlumnos, A);
            break;
        case 4:
            respuesta = eliminarAlumno(listaDeAlumnos, A);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno eliminado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }

            break;
        case 5:

            respuesta = modificarAlumno(listaDeAlumnos,A,102);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno modificado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }
            break;
        }
    }
    while(opcion!=7);

    return 0;
}
