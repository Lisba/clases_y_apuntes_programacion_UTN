#ifndef VUELO_H
#define VUELO_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"
#include "Piloto.h"
#include "Destino.h"

typedef struct
{
    int idVuelo;
    int idDestino;
    int IdPiloto;
    int partida;
    int llegada;
    char estadoVuelo[20];
    int isEmpty;
}eVuelo;

#endif // VUELO_H

int menuVuelos();
int iniciarVuelos(eVuelo listaVuelos[], int tamVuelos);
int findFreePositionVuelos(eVuelo listaVuelos[], int tamVuelos);
int altaVuelos(eVuelo listaVuelos[], int tamVuelos, int idVuelo, int idDestino, int idPiloto, int partida, int llegada, char estadoVuelo[]);
eVuelo nuevoVuelo(int idVuelo, int idDestino, int idPiloto, int partida, int llegada, char estadoVuelo[]);
int cargarVuelo(eVuelo listaVuelos[], int tamVuelos, int* lastId, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos);
int buscarVueloPorCodigo(eVuelo listaVuelos[], int tamVuelos, int codigo);
int eliminarVuelo(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos);
int imprimirVuelo(eVuelo Vuelo, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos);
int imprimirVuelos(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos);
int hardCodearVuelos(eVuelo listaVuelos[], int tamVuelos, int* lastId);
int modificarEstadoVuelo(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos);
