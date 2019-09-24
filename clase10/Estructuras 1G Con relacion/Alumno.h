#include <stdio.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1



typedef struct
{
    int idCarrera;
    char nombre[30];
    int duracion;
    int cantidadDeMaterias;
}eCarrera;

typedef struct
{
    int legajo;
    char nombre[29];
    float promedio;
    int idCarrera;
    int estado;
} eAlumno;


void mostrarCarreras(eCarrera[],int);
eAlumno cargarAlumno(eCarrera[],int);
void mostrarUnAlumno(eAlumno);
int buscarLibre(eAlumno*, int);
int cargarListadoAlumnos(eAlumno[], int, int, eCarrera[], int);
void mostrarListadoAlumnos(eAlumno[], int);
void mostrarListadoAlumnosConCarrera(eAlumno[], int, eCarrera[], int);
int hardCodearAlumnos(eAlumno[], int, int);
void sortStudentsByNameAndAverage(eAlumno[], int);
int eliminarAlumno(eAlumno[], int);

int modificarAlumno(eAlumno[], int, int);
int buscarAlumnoPorLegajo(eAlumno[], int, int);
