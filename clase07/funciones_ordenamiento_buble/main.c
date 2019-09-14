#include <stdio.h>
#include <stdlib.h>
#define T 8
#define NOTAS 2

void pedirAlumno(int[], int[], char[], int[], int[], float[], int);
void mostrarUnAlumno(int, int, char, int, int, float);
void mostrarAlumnos(int[], int[], char[], int[], int[], float[], int);
void ordenarAlumnos(int[], int[], char[], int[], int[], float[], int);

int main()
{
    int legajo[T]= {101, 102, 105, 100, 103, 104};
    int edad[T]= {27, 18, 19, 20, 25, 26};
    char sexo[T]= {'m', 'f', 'f', 'm', 'f', 'm'};
    int nota1[T]= {10, 5, 9, 8, 7, 6};
    int nota2[T]= {7, 4, 6, 8, 9, 7};
    float promedio[T] = {8.5, 4.5, 7.5, 8, 8, 6.5};

    mostrarAlumnos(legajo, edad, sexo, nota1, nota2, promedio, T);
    ordenarAlumnos(legajo, edad, sexo, nota1, nota2, promedio, T);
    mostrarAlumnos(legajo, edad, sexo, nota1, nota2, promedio, T);
    pedirAlumno(legajo, edad, sexo, nota1, nota2, promedio, 2);
    ordenarAlumnos(legajo, edad, sexo, nota1, nota2, promedio, T);
    mostrarAlumnos(legajo, edad, sexo, nota1, nota2, promedio, T);

    return 0;
}

void pedirAlumno(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo[i]);

        printf("Ingrese la edad: ");
        scanf("%d", &edad[i]);

        printf("Ingrese el sexo: ");
        fflush(stdin);
        scanf("%c", &sexo[i]);

        printf("Ingrese la nota1: ");
        scanf("%d", &nota1[i]);

        printf("Ingrese la nota2: ");
        scanf("%d", &nota2[i]);

        promedio[i] = (float) (nota1[i] + nota2[i]) / NOTAS;
    }
}

void mostrarUnAlumno(int legajo, int edad, char sexo, int nota1, int nota2, float promedio)
{
     printf("%d\t%d\t%c\t%d\t%d\t%.3f\n", legajo, edad, sexo, nota1, nota2, promedio);
}

void mostrarAlumnos(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{
    printf("\nleg:\tedad:\tsexo:\tn1:\tn2:\tpromedio:\n\n");
    for(int i=0; i<tam; i++)
    {
        mostrarUnAlumno(legajo[i], edad[i], sexo[i], nota1[i], nota2[i], promedio[i]);
    }

}

void ordenarAlumnos(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{

    int auxInt;
    char auxChar;
    float auxFloat;
    int swap = 0;

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(sexo[i] > sexo[j])
            {
                swap = 1;

            } else if (sexo[i] == sexo[j] && legajo[i] > legajo[j])
            {
                swap = 1;
            }

            if (swap == 1)
            {

                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxInt = edad[i];
                edad[i] = edad[j];
                edad[j] = auxInt;

                auxChar = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxChar;

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;

                auxInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxInt;

                auxFloat = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxFloat;

                swap = 0;
            }
        }
    }
}
