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
    int isEmpty;
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
 * \param codigo int* Ultimo Codigo ID para categoria.
 * \return int Retorna la cantidad de estructuras del array hardcodeadas.
 *
 */
int hardCodearCategorias(eCategoria listaCategorias[], int tamCategorias, int* codigo);

/** \brief Inicializa el array de categorias agregando 1 al campo isEmpty de cada elemento del array.
 *
 * \param listaCategorias[] eCategoria Array de categorias.
 * \param tamCategorias int Tamaño del array de categorias.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int iniciarCategorias(eCategoria listaCategorias[], int tamCategorias);

/** \brief Busca una posicion libre en el array de juegos.
 *
 * \param listaCategorias[] eCategoria Array de categorias.
 * \param tamCategorias int Tamaño del array de categorias.
 * \return int Retorna el índice de la primera posicion disponibble o -1 en caso de no haber.
 *
 */
int findFreePositionCategorias(eCategoria listaCategorias[], int tamCategorias);

/** \brief Carga la estructura de la nueva categoria en la primera posicion del array disponible.
 *
 * \param listaCategorias[] eCategoria Array de categoria.
 * \param tamCategorias int Tamaño del array de categoria.
 * \param codigo int Código ID disponible para la nueva categoria.
 * \param descripcion[] char Descripcion de la nueva categoria.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int altaCategoria(eCategoria listaCategorias[], int tamCategorias, int codigo, char descripcion[]);

/** \brief Convierte datos de la categoria en una estructura de juego válida.
 *
 * \param codigo int Codigo ID para la nueva categoria.
 * \param descripcion[] char Descripcion para la nueva categoria.
 * \return eCategoria Retorna la instancia de la estructura válida con los datos cargados.
 *
 */
eCategoria nuevaCategoria(int codigo, char descripcion[]);

/** \brief Toma los datos de una nueva categoria y la carga al array.
 *
 * \param listaCategorias[] eCategoria Array de categorias.
 * \param tamCategorias int Tamaño del array de categorias.
 * \param lastId int* Código ID disponible para el nuevo juego.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int cargarCategoria(eCategoria listaCategorias[], int tamCategorias, int* lastId);

/** \brief Realiza una baja lógica de la categoria.
 *
 * \param listaCategorias[] eCategoria Array de categoria.
 * \param tamCategorias int Tamaño del array de categoria.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int eliminarCategoria(eCategoria listaCategorias[], int tamCategorias);

/** \brief Busca una categoria en el array por su codigo ID.
 *
 * \param listaCategorias[] eCategoria Array de categorias.
 * \param tamCategorias int Tamaño del array de categorias.
 * \param codigo int Código ID de la categoria a buscar.
 * \return int Devuelve el índice en el cual está el cliente dentro del array o -1 en caso de no encontrarlo.
 *
 */
int buscarCategoriaPorCodigo(eCategoria listaCategorias[], int tamCategorias, int codigo);

/** \brief Modifica los datos de una categoría.
 *
 * \param listaCategorias[] eCategoria Array de categorías.
 * \param tamCategorias int Tamaño del array de categorías.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int modificarCategoria(eCategoria listaCategorias[], int tamCategorias);

int cargarDescCategoria(eCategoria listaCategorias[], int tamCategorias, int idCategoria, char descripcionCategoria[]);

#endif // CATEGORIA_H
