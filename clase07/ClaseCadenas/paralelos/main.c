#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarAlumnos( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio);
void ordAlumnosLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);


int main()
{
    int legajos[TAM] = {923, 432, 567, 179, 876};
    int edades[TAM] =  {21, 23, 20, 21, 30};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    int notasp1[TAM] = {2, 4, 7, 8, 5};
    int notasp2[TAM] = {4, 10, 9, 4, 2};
    float promedios[TAM] = { 3, 7, 8, 6, 3.5};

    /* for(int i = 0; i < TAM; i++){

         printf("Ingrese legajo: ");
         scanf("%d", &legajos[i]);

         printf("Ingrese edad: ");
         scanf("%d", &edades[i]);

         printf("Ingrese sexo: ");
         fflush(stdin);
         scanf("%c", &sexos[i]);

         printf("Ingrese Nota Primer Parcial: ");
         scanf("%d", &notasp1[i]);

         printf("Ingrese Nota Segundo Parcial: ");
         scanf("%d", &notasp2[i]);

         promedios[i] = (float) (notasp1[i] + notasp2[i]) / 2;
     }*/

    mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

    ordAlumnosSexLeg(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

    mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

    return 0;
}

void mostrarAlumnos( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam)
{

    printf(" Legajo  Edad  Sexo  Nota1  Nota2  Promedio\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarAlumno( leg[i], age[i], sex[i], n1[i], n2[i], prom[i]);
    }
    printf("\n\n");
}

void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio)
{

    printf("   %d     %d    %c     %d    %d     %.2f\n", leg, age, sexo, nota1, nota2, promedio);

}

void ordAlumnosLeg( int leg[],
                    int age[],
                    char sex[],
                    int n1[],
                    int n2[],
                    float prom[],
                    int tam)
{
    int auxInt;
    float auxFloat;
    char auxChar;

    for( int i=0; i< tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if( sex[i] > sex[j])
            {

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = n1[i];
                n1[i] = n1[j];
                n1[j] = auxInt;

                auxInt = n2[i];
                n2[i] = n2[j];
                n2[j] = auxInt;

                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;
            }
        }
    }
}


void ordAlumnosSexLeg( int leg[],
                       int age[],
                       char sex[],
                       int n1[],
                       int n2[],
                       float prom[],
                       int tam)
{
    int auxInt;
    float auxFloat;
    char auxChar;
    int swap = 0;

    for( int i=0; i< tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if( sex[i] > sex[j])
            {
                swap = 1;
            }
             else if( sex[i] == sex[j] && leg[i] > leg[j]){
                swap = 1;
             }

             if( swap ){

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = n1[i];
                n1[i] = n1[j];
                n1[j] = auxInt;

                auxInt = n2[i];
                n2[i] = n2[j];
                n2[j] = auxInt;

                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;

             }

             swap = 0;


        }
    }
}



