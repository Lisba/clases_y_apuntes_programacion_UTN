#include <stdio.h>
#include <stdlib.h>
#define T 3

void mostrarUnAlumno(int, int, char, int,int,int, float);
void mostrarAlumnos(int[], int[], char[], int[],int[],int[], float[], int);
void ordenarAlumnos(int[], int[], char[], int[],int[],int[], float[], int, char[], char);

int main()
{
    int legajo[T]= {101,102,105};
    int edad[T]= {15,16,12};
    char sexo[T]= {'m','f','f'};
    int nota1[T]= {10,5,9};
    int nota2[T]= {7,4,6};
    int nota3[T]= {3,3,8};
    float promedio[T]= {6.66, 4.00, 7.66};

    mostrarAlumnos(legajo[T], edad[T], sexo[T], nota1[T], nota2[T], nota3[T], promedio[T], T)

    return 0;
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

void mostrarAlumnos(int legajo[], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int tam)
{
    int i;
    for(int i=0; i<tam; i++)
    {
        mostrarUnAlumno(legajo[i], edad[i], sexo[i], nota1[i], nota2[i], nota3[i], promedio[i]);
    }

}

void ordenarAlumnos(int legajo[], int edad[], char sexo[], int nota1[],int nota2[],int nota3[], float promedio[], int tam, char criterio[], char ascDes)
{
    int auxInt;
    char auxChar;
    float auxFloat;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(sexo[i] > sexo[j])
            {
                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxInt = edad[i];
                edad[i] = edad[j];
                edad[j] = auxInt;

                auxInt = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxInt;

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
                promedio[j] = auxFloat;

            }else if(sexo[i] == sexo[j] && legajo[i] > legajo[j])
            {
                                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxInt = edad[i];
                edad[i] = edad[j];
                edad[j] = auxInt;

                auxInt = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxInt;

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
                promedio[j] = auxFloat;
            }
        }
    }
}
