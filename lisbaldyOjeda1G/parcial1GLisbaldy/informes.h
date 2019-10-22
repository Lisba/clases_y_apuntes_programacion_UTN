#ifndef INFORMES_H
#define INFORMES_H

#include <stdio.h>
#include <stdlib.h>
#include "alquileres.h"
#include "clientes.h"
#include "juegos.h"
#include "categoria.h"

/** \brief Muestra un submenu de opciones para mostrar informes.
 *
 * \return int Devuelve la opcion seleccionada.
 *
 */
int subMenuInformes();

/** \brief Muestra los juegos con categoria mesa.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \return void
 *
 */
void mostrarJuegosCatMesa(eJuego listaJuegos[], int tamJuegos);

/** \brief Muestra los alquileres del cliente seleccionado.
 *
 * \param listaCliente[] eCliente Array de clientes.
 * \param tamCliente int Tamaño del array de clientes.
 * \param listaAlquiler[] eAlquiler Array de alquileres.
 * \param tamAlquiler int Tamaño del array de alquileres.
 * \return void
 *
 */
void MostrarAlquilerClienteSelec(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquiler, eLocalidad listaLocalidades[], int tamLocalidades);

/** \brief Muestra el valor de los importes pagados por el cliente seleccionado.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamCliente int Tamaño del array de clientes.
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquiler int Tamaño del array de alquileres.
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \return float Retorna el importe pagado por el cliente.
 *
 */
float ImportesPagadosPorCliente(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eLocalidad listaLocalidades[], int tamLocalidades);

/** \brief Muestra la lista de clientes que no alquilaron nada.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamCliente int Tamaño del array de clientes.
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array de alquileres.
 * \return void
 *
 */
void clientesNoAlquilaron(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquileres, eLocalidad listaLocalidades[], int tamLocalidades);

/** \brief Muestra una lista de los juegos que no fueron alquilados.
 *
 * \param listaJuegos[] eJuego Array de juegos.
 * \param tamJuegos int Tamaño del array de juegos.
 * \param listaAlquileres[] eAlquiler Array de alquileres.
 * \param tamAlquileres int Tamaño del array de alquileres.
 * \return void
 *
 */
void juegosNoAlquilados(eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres);

void listarLosClientesDeUnaDeterimnadaLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, eCliente listaClientes[], int tamClientes);
void listarElJuegoPreferidoEnUnaLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, eCliente listaClientes[], int tamClientes, eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos);
void listarJuegosAlquiladosPorMujeres(eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes, eAlquiler listaAlquileres[], int tamAlquileres);
void listarLosClientesQueAlquilaronUnDeterminadoJuego(eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);
void mostrarLaRecaudacionDeUnaFechaEnParticular(eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos);
int compararFechas(eFecha fecha1, eFecha fecha2);


#endif // INFORMES_H
