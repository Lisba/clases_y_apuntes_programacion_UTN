#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;
    int isEmpty;
} eAlquiler;

int subMenuAlquileres();
int iniciarAlquileres(eAlquiler listaAlquileres[], int tamAlquileres);
int findFreePositionAlquileres(eAlquiler listaAlquileres[], int tamAlquileres);
int altaAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, int codigo, int codigoJuego, int codigoCliente, eFecha fecha);
eAlquiler nuevoAlquiler(int codigo, int codigoJuego, int codigoCliente, eFecha fecha);
int cargarAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, int codigoAlquiler, int codigoJuego, int codigoCliente);
void imprimirAlquileres(eAlquiler listaAlquileres[], int tamAlquileres);
void imprimirAlquiler(eAlquiler alquiler);
