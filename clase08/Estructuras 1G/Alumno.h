#include <stdio.h>
typedef struct
{
    int legajo;
    char nombre[29];
    float promedio;
    int estado;
} eAlumno;

eAlumno cargarAlumno(void);
void mostrarUnAlumno(eAlumno);

void cargarListadoAlumnos(eAlumno[], int);
void mostrarListadoAlumnos(eAlumno[], int);
void hardCodearAlumnos(eAlumno[], int);
void sortStudentsByNameAndAverage(eAlumno[], int);
