#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];
    int isEmpty;
} eCliente;

/** \brief Muestra un menu de opciones.
 *
 * \param void
 * \return int Devuelve la opcion seleccionada.
 *
 */
int subMenuClientes(void);

/** \brief Inicializa el array de clientes con estado vac�o.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tama�o del array de clientes.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int iniciarClientes(eCliente listaClientes[], int tamClientes);

/** \brief Toma los datos de un nuevo cliente y lo carga al nuevo array.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int tama�o del array de clientes.
 * \param lastId int* ultimo codigo cliente disponible.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int cargarCliente(eCliente listaClientes[], int tamClientes, int* lastId);

/** \brief convierte datos de cliente en una estructura de cliente v�lida.
 *
 * \param codigo int C�digo ID del cliente.
 * \param nombre[] char Nombre del cliente.
 * \param apellido[] char Apellido del cliente.
 * \param sexo char Sexo del cliente.
 * \param telefono char[] Telefono del cliente.
 * \param domicilio[] char Domicilio del cliente.
 * \return eCliente Retorna la instancia de la estructura v�lida con los datos cargados.
 *
 */
eCliente nuevoCliente(int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[]);

/** \brief Carga la estructura del nuevo cliente en la primera posicion del array disponible.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tama�o del array de clientes.
 * \param codigo int C�digo ID disponible para el nuevo cliente.
 * \param nombre[] char Nombre del cliente.
 * \param apellido[] char Apellido del cliente.
 * \param sexo char Sexo del cliente.
 * \param telefono char[] Telefono del cliente.
 * \param domicilio[] char Domicilio del cliente.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int altaCliente(eCliente listaClientes[], int tamClientes, int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[]);

/** \brief Realiza una baja l�gica del cliente.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tama�o del array de clientes.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int eliminarCliente(eCliente listaClientes[], int tamClientes);

/** \brief Busca la primera posicion libre disponible en el array.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tama�o del array de clientes.
 * \return int Retorna el �ndice de la primera posicion disponibble.
 *
 */
int findFreePositionClientes(eCliente listaClientes[], int tamClientes);

/** \brief Imprime en pantalla a un cliente.
 *
 * \param cliente eCliente El cliente a imprimir en pantalla.
 * \return void
 *
 */
void imprimirCliente(eCliente cliente);

/** \brief Imprime en pantalla los clientes del array de clientes.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tama�o del array de clientes.
 * \return int Retorna la cantidad de clientes que imprimi� en pantalla.
 *
 */
int imprimirClientes(eCliente listaClientes[], int tamClientes);

/** \brief Ordena los clientes de manera ascendente (1) o descendente (0).
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tama�o del array de clientes.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int ordenarClientes(eCliente listaClientes[], int tamClientes);

/** \brief Busca a un cliente del array por su codigo ID.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tama�o del array de clientes.
 * \param codigo int C�digo ID del cliente a buscar.
 * \return int Devuelve el �ndice en el cual est� el cliente dentro del array.
 *
 */
int buscarClientePorCodigo(eCliente listaClientes[], int tamClientes, int codigo);

/** \brief Modifica los datos de un cliente.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tama�o del array de clientes.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int modificarCliente(eCliente listaClientes[], int tamClientes);

/** \brief Agrega estructuras de clientes pre-definidos al array de clientes.
 *
 * \param listaclientes[] eCliente Array de clientes.
 * \param cantClientesHardcodear int Cantidad de clientes hardcodeados a agregar al array de clientes.
 * \param codigo int* Codigo ID disponible para asignar al cliente.
 * \return int Retorna la cantidad de estructuras del array hardcodeadas.
 *
 */
int hardCodearClientes(eCliente listaclientes[], int cantClientesHardcodear, int* codigo);

#endif // CLIENTES_H
