#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#define A 5


int main()
{
    eAlumno listaDeAlumnos[A];
    int i;
    for(i=0; i<A; i++)
    {
        listaDeAlumnos[i].estado=0;
    }

   //cargarListadoAlumnos(listaDeAlumnos, A);
   hardCodearAlumnos(listaDeAlumnos,A);

   sortStudentsByNameAndAverage(listaDeAlumnos,A);
   mostrarListadoAlumnos(listaDeAlumnos, A);



    return 0;
}


