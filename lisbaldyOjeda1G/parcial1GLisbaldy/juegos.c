#include "juegos.h"

int hardCodearJuegos(eJuego listaJuegos[], int tamJuegos, int codigo)
{
    int i;

    char descripcion[][51]= {"Need For Speed", "Mortal Kombat", "Flight Simulator X", "Digital Combat Simulator", "Call Of Dutty"};
    float importe[]= {10.66, 4.99, 7.66, 8.55, 9.99};
    int idCategoria[]={1, 2, 3, 3, 2};

    for(i=0; i<5; i++)
    {
        listaJuegos[i].codigo = codigo;
        strcpy(listaJuegos[i].descripcion, descripcion[i]);
        listaJuegos[i].importe = importe[i];
        listaJuegos[i].idCategoria=idCategoria[i];

        codigo++;
    }
    return codigo;
}

void imprimirJuegos(eJuego listaJuegos[], int tamJuegos)
{
    system("cls");
    printf("****** Lista de Juegos *******\n\n");
    printf(" CODIGO             DESCRIPCION            IMPORTE         IDCATEGORIA\n");

    for(int i=0; i<tamJuegos; i++)
    {
        imprimirJuego(listaJuegos[i]);
    }
    system("pause");
}

void imprimirJuego(eJuego juego)
{
    printf("%5d %27s %15.2f %14d\n", juego.codigo, juego.descripcion, juego.importe, juego.idCategoria);

}
