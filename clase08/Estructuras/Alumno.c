#include "Alumno.h"

eAlumno cargarAlumno(void)
{
    eAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", miAlumno.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &miAlumno.promedio);

    return miAlumno;
}
void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%d--%s--%f",miAlumno.legajo,miAlumno.nombre, miAlumno.promedio);

    miAlumno.legajo = 1000;
}
