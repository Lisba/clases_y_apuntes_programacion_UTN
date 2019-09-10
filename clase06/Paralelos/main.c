#include <stdio.h>
#include <stdlib.h>
#define T 3
#define NOTAS 3

void cargarAlumnos(int[], int[], char[], int[],int[],int[], float[], int);
void mostrarAlumnos(int[], int[], char[], int[],int[],int[], float[], int);
void mostrarAlumnosBySex(int[], int[], char[], int[],int[],int[], float[], int, char);
void mostrarUnAlumno(int, int, char, int,int,int, float);
void mostrarAlumnoByLegajo(int[], int[], char[], int[],int[],int[], float[], int, int);
int main()
{
    int legajo[T]= {101,102,105};
    int edad[T]= {15,16,12};
    char sexo[T]= {'m','f','f'};
    int nota1[T]= {10,5,9};
    int nota2[T]= {7,4,6};
    int nota3[T]= {3,3,8};
    float promedio[T]= {6.66, 4,7.66};
    int opcion;
    char sex;
    int leg;

    do
    {
        printf("1.Cargar datos\n");
        printf("2.Mostrar datos\n");
        printf("3.Mostrar por sexo\n");
        printf("4.Buscar por legajo\n");
        printf("7.Salir\n");
        printf("Elija una opcion:");
        scanf("%d", & opcion);
        switch(opcion)
        {
            case 1:
                cargarAlumnos(legajo, edad, sexo, nota1,nota2,nota3,promedio,T);
                break;
            case 2:
                mostrarAlumnos(legajo, edad, sexo, nota1,nota2,nota3,promedio,T);
                break;
            case 3:

                printf("Ingrese sexo: ");
                fflush(stdin);
                scanf("%c", &sex);

                mostrarAlumnosBySex(legajo, edad, sexo, nota1,nota2,nota3,promedio,T, sex);
                break;
            case 4:
                printf("Ingrese el legajo a buscar: ");
                scanf("%d", &leg);
                 mostrarAlumnoByLegajo(legajo, edad, sexo, nota1,nota2,nota3,promedio,T, leg);
        }
        system("pause");
        system("cls");
    }
    while(opcion!=7);


    return 0;
}
void cargarAlumnos(int legajo[], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo[i]);


        printf("Ingrese edad: ");
        scanf("%d", &edad[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo[i]);

        printf("Ingrese Nota 1: ");
        scanf("%d", &nota1[i]);

        printf("Ingrese nota 2: ");
        scanf("%d", &nota2[i]);

        printf("Ingrese nota 3: ");
        scanf("%d", &nota3[i]);

        promedio[i] = (float)(nota1[i]+nota2[i]+nota3[i])/NOTAS;

    }
}

void mostrarAlumnos(int legajo[], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        mostrarUnAlumno(legajo[i],edad[i],sexo[i],nota1[i],nota2[i],
                   nota3[i],
                   promedio[i]);
    }

}
void mostrarAlumnosBySex(int legajo[], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int cant, char sex)
{
    int i;
    for(i=0; i<T; i++)
    {
        if(sex==sexo[i])
        {
           mostrarUnAlumno(legajo[i],edad[i],sexo[i],nota1[i],nota2[i],
                   nota3[i],
                   promedio[i]);
        }
    }

}
void mostrarUnAlumno(int legajo, int edad, char sexo, int nota1,int nota2,int nota3, float promedio)
{
     printf("%d\t%d\t%c\t%d\t%d\t%d\t%f\n",
                   legajo,
                   edad,
                   sexo,
                   nota1,
                   nota2,
                   nota3,
                   promedio);
}

void mostrarAlumnoByLegajo(int legajo[], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int cant,int leg)
{
    int i;
    int flag=0;
    for(i=0; i<cant; i++)
    {
        if(legajo[i]==leg)
        {
           mostrarUnAlumno(legajo[i],edad[i],sexo[i],nota1[i],nota2[i],
                   nota3[i],
                   promedio[i]);
                   flag = 1;
                   break;
        }

    }
    if(flag==0)
    {
        printf("Legajo inexistente");
    }

}
