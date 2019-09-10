#include <stdio.h>
#include <stdlib.h>
#define TAM 3
#define NOTAS 3

int main()
{
    int legajo[TAM]={101,102,103};
    int edad[TAM]={22,21,19};
    char sexo[TAM]={'f','m','f'};
    int n1[TAM]={10,8,7};
    int n2[TAM]={9,8,7};
    int n3[TAM]={6,8,9};
    float promedio[TAM];

    for(int i=0; i<TAM; i++)
    {
//        printf("Ingrese el legajo: ");
//        scanf("%d", &legajo[i]);
//        printf("Ingrese edad: ");
//        scanf("%d", &edad[i]);
//        fflush(stdin);
//        printf("Ingrese sexo: ");
//        scanf("%c", &sexo[i]);
//        printf("Ingrese nota 1: ");
//        scanf("%d", &n1[i]);
//        printf("Ingrese nota 2: ");
//        scanf("%d", &n2[i]);
//        printf("Ingrese nota 3: ");
//        scanf("%d", &n3[i]);

        printf("\n");

        promedio[i] = (float) (n1[i] + n2[i] + n3[i]) / NOTAS;
    }

    system("pause");
    system("cls");

    for(int i=0; i<TAM; i++)
    {
        printf("%d \t%d \t%c \t%d \t%d \t%d \t%.2f\n", legajo[i], edad[i], sexo[i], n1[i], n2[i], n3[i], promedio[i]);
    }

    return 0;
}
