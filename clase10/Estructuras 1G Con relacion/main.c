#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#define A 5
/*
   int idCarrera;
    char nombre[30];
    int duracion;
    int cantidadDeMaterias;

*/
int main()
{
    eAlumno listaDeAlumnos[A];
    eCarrera listaDeCarreras[]={{1,"TUP",2,21},{2,"TUSI",1,15},{3,"TE",2,20}};



    int i;

    int lastId = 100;

    int respuesta;
    int opcion;
    int legajo;
    for(i=0; i<A; i++)
    {
        listaDeAlumnos[i].estado=LIBRE;
    }

   lastId=hardCodearAlumnos(listaDeAlumnos,A,lastId);

    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Eliminar\n5.Modificar\n7.Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            respuesta = cargarListadoAlumnos(listaDeAlumnos,A,lastId, listaDeCarreras, 3);
            if(respuesta == 1)
            {
                lastId++;
            }
            break;
        case 2:
            mostrarListadoAlumnosConCarrera(listaDeAlumnos, A, listaDeCarreras,3);
            printf("\n");
            break;
        case 3:
            sortStudentsByNameAndAverage(listaDeAlumnos,A);
            break;
        case 4:
            respuesta = eliminarAlumno(listaDeAlumnos,A);
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

            printf("Ingrese un legajo: ");
            scanf("%d", &legajo);
            respuesta = modificarAlumno(listaDeAlumnos,A,legajo);
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
        system("pause");

        system("cls");
    }
    while(opcion!=7);
    return 0;
}


