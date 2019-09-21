#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 3

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fecha;
    int isEmpty;

} eAlumno;


char menu(void);
void inicializarAlumno(eAlumno vec[], int tam);
void mostrarAlumnos(eAlumno vec[], int tam);
void altaAlumno (eAlumno vec[], int tam);
int buscarLibre (eAlumno vec[], int tam);
int buscarAlumno(int legajo; eAlumno vec[], int tam);
int bajaAlumno(eAlumno vec[], int tam);

int main()
{
    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumno(lista, TAM);

    do
    {
        switch(menu())
        {
        case '1':
            printf("ALTA ALUMNO\n\n");
            break;
        case '2':
            printf("BAJA ALUMNO\n\n");
            break;
        case '3':
            printf("MODIFICAR ALUMNO\n\n");
            break;
        case '4':
            mostrarAlumnos(lista, TAM);
            break;
        case '5':
            printf("ORDENAR ALUMNOS\n\n");
            break;
        case '6':
            printf("INFORMES ALUMNOS\n\n");
            break;
        case '7':
            printf("CONFIRMA SALIR?\n\n");
            fflush(stdin);
            salir = getche();
        default:
            printf("\nOPCION INVALIDA!\n\n");
        }
    } while (salir == 'n');

    return 0;
}

char menu(void)
{
    char option;

    system("cls");

    printf("1) ALTA ALUMNO\n");
    printf("2) BAJA ALUMNO\n");
    printf("3) MODIFICAR ALUMNO\n");
    printf("4) LISTAR ALUMNOS\n");
    printf("5) ORDENAR ALUMNOS\n");
    printf("6) INFORMES\n");
    printf("7) SALIR\n");
    printf("INGRESE OPCION: ");
    fflush(stdin);
    scanf("%c", &option);

    return option;
}

void inicializarAlumno(eAlumno vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    int flag = 0;
    system("cls");
    printf("Legajo Nombre Edad Sexo Nota1 Nota2 Promedio\n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
//            mostrarAlumno(vec[i]);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\nNO HAY ALUMNOS QUE MOSTRAR\n");
    }
}

void altaAlumno (eAlumno vec[], int tam);

int buscarLibre (eAlumno vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarAlumno(int legajo; eAlumno vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].legajo == legajo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaAlumno(eAlumno vec[], int tam)
{
    int todoOk=0;
    int indice;
    int esta;
    int legajo;
    int nombre;
    int edad;
    char sexo;
    int nota1;
    int nota2;

    indice = buscarLibre(vec, tam);

    if(indice != -1)
    {
        printf("No hay espacio");
    }else
    {
        esta = buscarAlumno(vec, tam);
        if(esta != -1)
        {
            printf("Ya existe");
//            Muestro el alumno
        }else
        {
            printf("Ingrese nombre: ");
            scanf("%s", nombre);
            printf("Ingrese Edad: ");
            scanf("%d", &edad);
            printf("Ingrese sexo: ");
            scanf("%c", &sexo);
//            nota1;
//            nota2;

//            vec[indice] = newAlumno(legajo, nombre, sexo, n1, n2);
        }
    }

    return todoOk;
}

int bajaAlumno(eAlumno vec[], int tam)
{
    int todoOk=0;
    int legajo;
    int indice;
    char confirma;

    printf("Ingrese Legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, vec, tam);

    if(indice == -1)
    {
        printf("El alumno no existe");
    }else
    {
        if(confirma == 's')
        {
//          mostrarAlumno(vec[indice]);
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa");
        }else
        {
            printf("La operacion ha sido cancelada");
        }
    }

    return todoOk;
}

int modificarAlumno(eAlumno vec[], int tam)
{
    int todoOk=0;
    int legajo;
    int indice;

    printf("Ingrese Legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, vec, tam);

    if(indice == -1)
    {
        printf("El alumno no existe");
    }else
    {
        int option;

        do
        {
            printf("1) Modificar nombre");
            printf("2) Modificar edad");
            printf("3) Modificar sexo");
            printf("4) Modificar nota 1");
            printf("5) Modificar nota 2");
            printf("Ingrese una opcion: ");
            scanf("%c", &option);

            switch(option)
            {
            case '1':

                break
            }
        }
    }

    return todoOk;
}
