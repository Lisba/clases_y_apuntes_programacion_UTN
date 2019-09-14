#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarVectorChar(char vec[], int tam);

int main()
{
    char nombre[20]= "Juan pablo";
    char x[20];
    char auxCad[100];

   // printf("Ingrese un nombre: ");
    fflush(stdin);
   // gets(auxCad);

    while( strlen(auxCad) > 19 ){
        printf("Error. Ingrese un nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
   // strcpy( nombre, auxCad);
    char cad1[20] = "Hola";

    char cad2[20] = "Mundo";

    char cad3[39];

   //printf("%d\n", stricmp(cad2, cad1));

   strlwr(cad2);

   strcat(cad1, cad2);

printf("%s\n", cad2);



  // printf("Ingrese su nombre: ");
  // gets(x);

  //  printf("%s\n", nombre);
//mostrarVectorChar(x, 20);


    return 0;
}


void mostrarVectorChar(char vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        printf("%c ", vec[i]);
    }
    printf("\n\n");
}
