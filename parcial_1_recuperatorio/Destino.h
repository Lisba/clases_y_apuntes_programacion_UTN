#ifndef DESTINO_H
#define DESTINO_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"

typedef struct
{
    int idDestino;
    char descripcion[20];
    float precio;
    int isEmpty;
}eDestino;

#endif // DESTINO_H

int hardCodearDestinos(eDestino listaDestinos[], int tamDestinos);
int imprimirDestino(eDestino destino);
int imprimirDestinos(eDestino listaDestinos[], int tamDestinos);
int buscarDestinoPorCodigo(eDestino listaDestinos[], int tamDestinos, int codigo);
int cargarDescDestino(eDestino listaDestinos[], int tamDestinos, int idDestino, char descripcionDestino[]);
int iniciarDestinos(eDestino listaDestinos[], int tamDestinos);

