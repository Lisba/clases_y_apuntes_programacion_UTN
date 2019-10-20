#ifndef JUEGOS_H
#define JUEGOS_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"
#include "categoria.h"

typedef struct
{
    int codigo;
    char descripcion[51];
    float importe;
    int idCategoria;
    int isEmpty;
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

/** \brief Inicializa el array de Juegos agregando 1 al campo isEmpty de cada elemento del array.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int iniciarJuegos(eJuego listaJuegos[], int tamJuegos);

/** \brief Busca una posicion libre en el array de juegos.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \return int Retorna el índice de la primera posicion disponibble o -1 en caso de no haber.
 *
 */
int findFreePositionJuegos(eJuego listaJuegos[], int tamJuegos);

/** \brief Carga la estructura del nuevo juego en la primera posicion del array disponible.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \param codigo int Código ID disponible para el nuevo juego.
 * \param descripcion[] char Descripcion para el nuevo juego.
 * \param importe float Valor monetario del nuevo juego.
 * \param categoria int Categoria a la que pertenece el nuevo juego.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int altaJuego(eJuego listaJuegos[], int tamJuegos, int codigo, char descripcion[], float importe, int categoria);

/** \brief convierte datos del juego en una estructura de juego válida.
 *
 * \param codigo int Código ID disponible para el nuevo juego.
 * \param descripcion[] char Descripcion para el nuevo juego.
 * \param importe float Valor monetario del nuevo juego.
 * \param categoria int Categoria a la que pertenece el nuevo juego.
 * \return eJuego Retorna la instancia de la estructura válida con los datos cargados.
 *
 */
eJuego nuevoJuego(int codigo, char descripcion[], float importe, int categoria);

/** \brief Toma los datos de un nuevo juego y lo carga al array.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \param listaCategorias[] eCategoria Array de categorias.
 * \param tamCategorias int Tamaño del array de categorias.
 * \param lastId int* Código ID disponible para el nuevo juego.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int cargarJuego(eJuego listaJuegos[], int tamJuegos, eCategoria listaCategorias[], int tamCategorias, int* lastId);

/** \brief Realiza una baja lógica del juego.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int eliminarJuego(eJuego listaJuegos[], int tamJuegos);

/** \brief Busca un juego en el array por su codigo ID.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \param codigo int Código ID del juego a buscar.
 * \return int Devuelve el índice en el cual está el cliente dentro del array o -1 en caso de no encontrarlo.
 *
 */
int buscarJuegoPorCodigo(eJuego listaJuegos[], int tamJuegos, int codigo);

/** \brief Modifica los datos de un juego.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \param listaCategorias[] eCategoria Array de categorias.
 * \param tamCategorias int Tamaño del array de categorias.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int modificarJuego(eJuego listaJuegos[], int tamJuegos, eCategoria listaCategorias[], int tamCategorias);

#endif // JUEGOS_H
