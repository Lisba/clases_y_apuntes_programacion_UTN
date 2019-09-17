#include <stdio.h>
typedef struct
{
    int legajo;
    char nombre[29];
    float promedio;
} eAlumno;

eAlumno cargarAlumno(void);
void mostrarUnAlumno(eAlumno);
