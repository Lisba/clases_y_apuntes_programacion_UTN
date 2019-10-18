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

/** \brief Imprime en pantalla las categorías del array de categorías.
 *
 * \param listaCategorias[] eCategoria Array de categorías.
 * \param tamCategorias int Tamaño del array de categorías.
 * \return int Retorna la cantidad de categorias que imprimió en pantalla.
 *
 */
int imprimirCategorias(eCategoria listaCategorias[], int tamCategorias);

/** \brief Imprime en pantalla una categoría del array de categorías.
 *
 * \param categoria eCategoria La categoría a imprimir.
 * \return void
 *
 */
void imprimirCategoria(eCategoria categoria);

/** \brief Agrega estructuras de categorías pre-definidas al array de categorías.
 *
 * \param listaCategorias[] eCategoria Array de categorías.
 * \param tamCategorias int Tamaño del array de categorías.
 * \return int Retorna la cantidad de estructuras del array hardcodeadas.
 *
 */
int hardCodearCategorias(eCategoria listaCategorias[], int tamCategorias);

#endif // CATEGORIA_H
