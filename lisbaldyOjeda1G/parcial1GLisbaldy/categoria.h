#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"

typedef struct
{
    int idCategoria;
    char descripcion[51];
} eCategoria;

/** \brief Imprime en pantalla las categor�as del array de categor�as.
 *
 * \param listaCategorias[] eCategoria Array de categor�as.
 * \param tamCategorias int Tama�o del array de categor�as.
 * \return int Retorna la cantidad de categorias que imprimi� en pantalla.
 *
 */
int imprimirCategorias(eCategoria listaCategorias[], int tamCategorias);

/** \brief Imprime en pantalla una categor�a del array de categor�as.
 *
 * \param categoria eCategoria La categor�a a imprimir.
 * \return void
 *
 */
void imprimirCategoria(eCategoria categoria);

/** \brief Agrega estructuras de categor�as pre-definidas al array de categor�as.
 *
 * \param listaCategorias[] eCategoria Array de categor�as.
 * \param tamCategorias int Tama�o del array de categor�as.
 * \return int Retorna la cantidad de estructuras del array hardcodeadas.
 *
 */
int hardCodearCategorias(eCategoria listaCategorias[], int tamCategorias);

#endif // CATEGORIA_H
