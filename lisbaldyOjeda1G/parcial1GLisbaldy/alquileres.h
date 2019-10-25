#ifndef ALQUILERES_H
#define ALQUILERES_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"
#include "juegos.h"
#include "clientes.h"

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

/** \brief Muestra un menu de opciones.
 *
 * \return int Devuelve la opción seleccionada.
 *
 */
int subMenuAlquileres();

/** \brief Inicializa el array de alquileres asignando a cada campo de isEmpty 1 (true).
 *
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int iniciarAlquileres(eAlquiler listaAlquileres[], int tamAlquileres);

/** \brief Busca la primera posicion disponible en el array de alquileres.
 *
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array.
 * \return int Retorna el índice de la primera posicion disponibble o -1 en caso de no haber.
 *
 */
int findFreePositionAlquileres(eAlquiler listaAlquileres[], int tamAlquileres);

/** \brief Carga la estructura del nuevo alquiler en la primera posicion libre del array.
 *
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array.
 * \param codigo int Codigo ID disponible para el nuevo alquiler.
 * \param codigoJuego int Codigo ID del juego alquilado.
 * \param codigoCliente int Codigo ID del cliente  que alquila.
 * \param fecha eFecha Fecha del alquiler.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int altaAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, int codigo, int codigoJuego, int codigoCliente, eFecha fecha);

/** \brief Convierte los datos del alquiler en una estructura alquiler válida.
 *
 * \param codigo int Codigo ID del alquiler.
 * \param codigoJuego int Codigo ID del juego.
 * \param codigoCliente int Codigo ID del cliente.
 * \param fecha eFecha Fecha del aquiler.
 * \return eAlquiler Returna la estructura alquiler con los datos recibidos por parámetro.
 *
 */
eAlquiler nuevoAlquiler(int codigo, int codigoJuego, int codigoCliente, eFecha fecha);

/** \brief Solicita los datos del alquiler y los carga como una estructura en el array de estructura.
 *
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array de alquileres.
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tamaño del array de clientes.
 * \param codigoAlquiler int* Codigo ID disponible para el nuevo alquiler.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 ***************************************************************************************************************/
int cargarAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes, int* codigoAlquiler, eLocalidad listaLocalidades[], int tamLocalidades, eCategoria listaCategorias[], int tamCategorias);

/** \brief Imprime el array de alquileres en pantalla.
 *
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array.
 * \return int Retorna la cantidad de alquileres que imprimió en pantalla.
 *
 *****************************************************************************************************/
int imprimirAlquileres(eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes);

/** \brief Imprime un elemento (estructura) del array de alquileres.
 *
 * \param alquiler eAlquiler Alquiler a imprimir.
 * \return void
 *
 **********************************************************************************/
int imprimirAlquiler(eAlquiler alquiler, eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes);

/** \brief Busca a un alquiler del array por su codigo ID.
 *
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array de alquileres.
 * \param codigo int Codigo ID del alquiler a buscar.
 * \return int Retorna el ID del alquiler o -1 en caso de no encontrarlo.
 *
 */
int buscarAlquilerPorCodigo(eAlquiler listaAlquileres[], int tamAlquileres, int codigo);

/** \brief Realiza una baja lógica de alquiler.
 *
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array de alquileres.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 *****************************************************************************************************/
int eliminarAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes);

/** \brief Modifica los datos de un alquiler existente.
 *
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array de alquileres.
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tamaño del array de clientes.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int modificarAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades, eCategoria listaCategorias[], int tamCategorias);

/** \brief Agrega estructuras de alquileres pre-definidos al array de clientes.
 *
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array de alquileres.
 * \param codigo int* Codigo ID disponible para asignar al cliente.
 * \return int Retorna la cantidad de alquileres hardcodeados agregados al array de alquileres.
 *
 */
int hardCodearAlquileres(eAlquiler listaAlquileres[], int tamAlquileres, int* codigo);

#endif // ALQUILERES_H
