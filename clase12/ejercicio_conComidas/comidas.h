#include <stdio.h>
#include <string.h>
#include <conio.h>

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

typedef struct
{
    int idComida;
    char descripcion[31];
    float precio;
} eComida;

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajoAlumno;
    int idComida;
    int idAlmuerzo;
    eFecha fecha;
    int estado;
} eAlmuerzo;


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

void mostrarUnaComida(eComida miComida);
void mostrarComidas(eComida listaComidas[], int tamComidas);
int buscarLibreAlmuerzos(eAlmuerzo listaAlmuerzos[], int tamAlmuerzos);
int altaAlmuerzo(eAlumno listaAlumnos[], int tamAlumnos, eComida listaComidas[], int tamComidas, eAlmuerzo listaAlmuerzos[], int tamAlmuerzos, int lastIdAl);
eAlmuerzo newAlmuerzo(int legajoAlumno, int idComida, eFecha fecha, int estado, int IdAlm);
