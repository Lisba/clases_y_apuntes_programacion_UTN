#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"

typedef struct
{
    int codigo;
    char descripcion[51];
    float importe;
    int idCategoria;
} eJuego;

int hardCodearJuegos(eJuego listaJuegos[], int tamJuegos, int codigo);
void imprimirJuegos(eJuego listaJuegos[], int tamJuegos);
void imprimirJuego(eJuego juego);
