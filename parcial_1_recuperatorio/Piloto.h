#ifndef PILOTO_H
#define PILOTO_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"

typedef struct
{
    int idPiloto;
    char nombre[20];
    int isEmpty;
}ePiloto;

#endif // PILOTO_H

int hardCodearPilotos(ePiloto listaPilotos[], int tamPilotos);
int imprimirPiloto(ePiloto Piloto);
int imprimirPilotos(ePiloto listaPilotos[], int tamPilotos);
int buscarPilotoPorCodigo(ePiloto listaPilotos[], int tamPilotos, int codigo);
int cargarDescPiloto(ePiloto listaPilotos[], int tamPilotos, int idPiloto, char descripcionPiloto[]);
int iniciarPilotos(ePiloto listaPilotos[], int tamPilotos);
