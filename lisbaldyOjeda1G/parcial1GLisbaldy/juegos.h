#ifndef JUEGOS_H
#define JUEGOS_H

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

/** \brief Agrega estructuras de juegos pre-definidos al array de juegos.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Cantidad de juegos hardcodeados a agregar al array de juegos.
 * \param codigo int* Codigo ID disponible para asignar al juego.
 * \return int Retorna la cantidad de estructuras del array hardcodeadas.
 *
 */
int hardCodearJuegos(eJuego listaJuegos[], int tamJuegos, int* codigo);

/** \brief Imprime en pantalla los juegos del array de juegos.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \return int Retorna la cantidad de juegos que imprimió en pantalla.
 *
 */
int imprimirJuegos(eJuego listaJuegos[], int tamJuegos);

/** \brief Imprime en pantalla un juego del array de juegos.
 *
 * \param juego eJuego El juego a imprimir en pantalla.
 * \return void
 *
 */
void imprimirJuego(eJuego juego);

#endif // JUEGOS_H
