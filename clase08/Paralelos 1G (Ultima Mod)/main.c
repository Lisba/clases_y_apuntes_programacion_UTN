#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3
#define NOTAS 3

void cargarAlumnos(int[], char[][25], int[], char[], int[],int[],int[], float[], int);
void mostrarAlumnos(int[], char[][25],int[], char[], int[],int[],int[], float[], int);
void mostrarAlumnosBySex(int[], int[], char[], int[],int[],int[], float[], int, char);
void mostrarUnAlumno(int,char[], int, char, int,int,int, float);
void mostrarAlumnoByLegajo(int[], int[], char[], int[],int[],int[], float[], int, int);
void ordenarAlumnosByNombre(int[], char[][25], int[], char[], int[],int[],int[], float[], int);
int main()
{
    int legajo[T]= {101,102,105};
    int edad[T]= {15,16,12};
    char sexo[T]= {'m','f','f'};
    int nota1[T]= {10,5,9};
    int nota2[T]= {7,4,6};
    int nota3[T]= {3,3,8};
    float promedio[T]= {6.66, 4,7.66};
    char nombre[T][25]= {"Juan","Maria","Maria"};
    int opcion;
    char sex;
    int leg;

    do
    {
        printf("1.Cargar datos\n");
        printf("2.Mostrar datos\n");
        printf("3.Mostrar por sexo\n");
        printf("4.Buscar por legajo\n");
        printf("5.Ordenar\n");
        printf("7.Salir\n");
        printf("Elija una opcion:");
        scanf("%d", & opcion);
        switch(opcion)
        {
        case 1:
            cargarAlumnos(legajo,nombre, edad, sexo, nota1,nota2,nota3,promedio,T);
            break;
        case 2:
            mostrarAlumnos(legajo,nombre, edad, sexo, nota1,nota2,nota3,promedio,T);
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
            break;
        case 5:
            ordenarAlumnosByNombre(legajo,nombre, edad, sexo, nota1,nota2,nota3,promedio,T);
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=7);


    return 0;
}

void ordenarAlumnosByNombre(int legajo[], char nombre[][25], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int cant)
{
    int i;
    int j;
    //legajo[], char nombre[][25],
    // int edad[], char sexo[], int nota1[],
    //int nota2[],int nota3[], float promedio[]
    int auxInt;
    char auxChar;
    char auxString[25];
    float auxFloat;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(nombre[i],nombre[j])<0)
            {
                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                strcpy(auxString,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxString);

                auxInt = edad[i];
                edad[i] = edad[j];
                edad[j] = auxInt;

                auxChar = sexo[i];
                sexo[i] =sexo[j];
                sexo[j] = auxChar;

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;


                auxInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxInt;


                auxInt = nota3[i];
                nota3[i] = nota3[j];
                nota3[j] = auxInt;

                auxFloat = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxFloat  ;


            }
            else
            {
                if(strcmp(nombre[i],nombre[j])==0)
                {
                    if(legajo[i]<legajo[j])
                    {
                        auxInt = legajo[i];
                        legajo[i] = legajo[j];
                        legajo[j] = auxInt;

                        auxInt = edad[i];
                        edad[i] = edad[j];
                        edad[j] = auxInt;

                        auxChar = sexo[i];
                        sexo[i] =sexo[j];
                        sexo[j] = auxChar;

                        auxInt = nota1[i];
                        nota1[i] = nota1[j];
                        nota1[j] = auxInt;


                        auxInt = nota2[i];
                        nota2[i] = nota2[j];
                        nota2[j] = auxInt;


                        auxInt = nota3[i];
                        nota3[i] = nota3[j];
                        nota3[j] = auxInt;

                        auxFloat = promedio[i];
                        promedio[i] = promedio[j];
                        promedio[j] = auxFloat  ;
                    }
                }
            }
        }
    }

}
void cargarAlumnos(int legajo[], char nombre[][25], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int cant)
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

        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", nombre[i]);

        promedio[i] = (float)(nota1[i]+nota2[i]+nota3[i])/NOTAS;

    }
}

void mostrarAlumnos(int legajo[], char nombre[][25], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        mostrarUnAlumno(legajo[i],nombre[i],edad[i],sexo[i],nota1[i],nota2[i],
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
            /*  mostrarUnAlumno(legajo[i],edad[i],sexo[i],nota1[i],nota2[i],
                      nota3[i],
                      promedio[i]);*/
        }
    }

}
void mostrarUnAlumno(int legajo,char nombre[], int edad, char sexo, int nota1,int nota2,int nota3, float promedio)
{
    printf("%d\t%d\t%c\t%d\t%d\t%d\t%f\t%s\n",
           legajo,
           edad,
           sexo,
           nota1,
           nota2,
           nota3,
           promedio, nombre);
}

void mostrarAlumnoByLegajo(int legajo[], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int cant,int leg)
{
    int i;
    int flag=0;
    for(i=0; i<cant; i++)
    {
        if(legajo[i]==leg)
        {
            /* mostrarUnAlumno(legajo[i],edad[i],sexo[i],nota1[i],nota2[i],
                     nota3[i],
                     promedio[i]);
                     flag = 1;
                     break;*/
        }

    }
    if(flag==0)
    {
        printf("Legajo inexistente");
    }

}
