#include "juegos.h"

int hardCodearJuegos(eJuego listaJuegos[], int tamJuegos, int codigo)
{
    int i;

    char descripcion[][51]= {"UNO", "MONOPOLIO", "BLACK JACK", "POKER", "AJEDREZ", "DAMAS", "BILLAR", "METEGOL", "WIZARDGAME", "MAGICGAME"};
    float importe[]= {7.66, 10.99, 7.66, 12.55, 9.99, 7.99, 25.88, 19.40, 12.99, 10.80};
    int idCategoria[]={1, 1, 2, 2, 3, 3, 4, 4, 5, 5};

    for(i=0; i<tamJuegos; i++)
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
