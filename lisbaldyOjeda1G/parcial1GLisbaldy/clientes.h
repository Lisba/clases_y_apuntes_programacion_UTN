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
    int idLocalidad;
    int isEmpty;
} eCliente;

typedef struct
{
    int id;
    char nombre[51];
    int isEmpty;
}eLocalidad;

#endif // CLIENTES_H

/** \brief Muestra un menu de opciones.
 *
 * \param void
 * \return int Devuelve la opcion seleccionada.
 *
 */
int subMenuClientes(void);

/** \brief Inicializa el array de clientes con estado vacío.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int iniciarClientes(eCliente listaClientes[], int tamClientes);

/** \brief Toma los datos de un nuevo cliente y lo carga al array.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \param lastId int* ultimo codigo cliente disponible.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int cargarCliente(eCliente listaClientes[], int tamClientes, int* lastId, eLocalidad listaLocalidades[], int tamLocalidades);

/** \brief convierte datos de cliente en una estructura de cliente válida.
 *
 * \param codigo int Código ID del cliente.
 * \param nombre[] char Nombre del cliente.
 * \param apellido[] char Apellido del cliente.
 * \param sexo char Sexo del cliente.
 * \param telefono char[] Telefono del cliente.
 * \param domicilio[] char Domicilio del cliente.
 * \return eCliente Retorna la instancia de la estructura válida con los datos cargados.
 *
 */
eCliente nuevoCliente(int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[], int idLocalidad);

/** \brief Carga la estructura del nuevo cliente en la primera posicion del array disponible.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tamaño del array de clientes.
 * \param codigo int Código ID disponible para el nuevo cliente.
 * \param nombre[] char Nombre del cliente.
 * \param apellido[] char Apellido del cliente.
 * \param sexo char Sexo del cliente.
 * \param telefono char[] Telefono del cliente.
 * \param domicilio[] char Domicilio del cliente.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int altaCliente(eCliente listaClientes[], int tamClientes, int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[], int idLocalidad);

/** \brief Realiza una baja lógica del cliente.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tamaño del array de clientes.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int eliminarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

/** \brief Busca la primera posicion libre disponible en el array.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tamaño del array de clientes.
 * \return int Retorna el índice de la primera posicion disponibble o -1 en caso de no haber.
 *
 */
int findFreePositionClientes(eCliente listaClientes[], int tamClientes);

/** \brief Imprime en pantalla a un cliente.
 *
 * \param cliente eCliente El cliente a imprimir en pantalla.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int imprimirCliente(eCliente cliente, eLocalidad listaLocalidades[], int tamLocalidades);

/** \brief Imprime en pantalla los clientes del array de clientes.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tamaño del array de clientes.
 * \return int Retorna la cantidad de clientes que imprimió en pantalla.
 *
 */
int imprimirClientes(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

/** \brief Ordena los clientes de manera ascendente (1) o descendente (0).
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tamaño del array de clientes.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int ordenarClientes(eCliente listaClientes[], int tamClientes);

/** \brief Busca un cliente en el array por su codigo ID.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tamaño del array de clientes.
 * \param codigo int Código ID del cliente a buscar.
 * \return int Devuelve el índice en el cual está el cliente dentro del array o -1 en caso de no encontrarlo.
 *
 */
int buscarClientePorCodigo(eCliente listaClientes[], int tamClientes, int codigo);

/** \brief Modifica los datos de un cliente.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int Tamaño del array de clientes.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int modificarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

/** \brief Agrega estructuras de clientes pre-definidos al array de clientes.
 *
 * \param listaclientes[] eCliente Array de clientes.
 * \param cantClientesHardcodear int Cantidad de clientes hardcodeados a agregar al array de clientes.
 * \param codigo int* Codigo ID disponible para asignar al cliente.
 * \return int Retorna la cantidad de estructuras del array hardcodeadas.
 *
 */
int hardCodearClientes(eCliente listaclientes[], int cantClientesHardcodear, int* codigo);
int hardCodearLocalidades(eLocalidad listaLocalidades[], int cantHardcodear);
void imprimirLocalidad(eLocalidad localidad);
int imprimirLocalidades(eLocalidad listaLocalidades[], int tamLocalidades);
int cargarNombreLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, int idLocalidad, char nombreLocalidad[]);
int cargarNombreApellidoCliente(eCliente listaClientes[], int tamClientes, int idCliente, char nombreCliente[], char apellidoCliente[]);
int iniciarLocalidades(eLocalidad listaLocalidades[], int tamLocalidades);
int catNameLastName(char name[], char lastName[], char nameLastName[]);

