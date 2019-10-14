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

/** \brief Inicializa el array de clientes con estado vacio.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \return int devuelve un estado si pudo o no efectuar la operacion.
 *
 */
int iniciarClientes(eCliente listaClientes[], int tamClientes);

/** \brief Toma los datos de un nuevo cliente y lo carga al nuevo array.
 *
 * \param listaClientes[] eCliente Array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \param lastId int ultimo codigo cliente disponible.
 * \return int devuelve un estado si pudo o no efectuar la operacion.
 *
 */
int cargarCliente(eCliente listaClientes[], int tamClientes, int lastId);

/** \brief convierte datos de cliente en una estructura de cliente valida.
 *
 * \param codigo int codigo del cliente.
 * \param nombre[] char nombre del cliente.
 * \param apellido[] char apellido del cliente.
 * \param sexo char sexo del cliente.
 * \param telefono char[] telefono del cliente.
 * \param domicilio[] char domicilio del cliente.
 * \return eCliente returna la instancia de la estructura valida con los datos cargados.
 *
 */
eCliente nuevoCliente(int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[]);

/** \brief Carga la estructura del nuevo cliente en la primera posicion del array disponible.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \param codigo int codigo disponible del cliente.
 * \param nombre[] char nombre del cliente.
 * \param apellido[] char apellido del cliente.
 * \param sexo char sexo del cliente.
 * \param telefono char[] telefono del cliente.
 * \param domicilio[] char domicilio del cliente.
 * \return int retorna un estado si pudo o no efectuar la operacion.
 *
 */
int altaCliente(eCliente listaClientes[], int tamClientes, int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[]);

/** \brief Realiza una baja logica del cliente.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \param codigo int codigo del cliente a eliminar.
 * \return int retorna un valor si pudo o no eliminar al cliente.
 *
 */
int eliminarCliente(eCliente listaClientes[], int tamClientes, int codigo);

/** \brief Busca la primera posicion libre disponible.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \return int retorna la primera posicion disponibble.
 *
 */
int findFreePositionClientes(eCliente listaClientes[], int tamClientes);

/** \brief Imprime en pantalla a un cliente.
 *
 * \param cliente eCliente un cliente a imprimir en pantalla.
 * \return void
 *
 */
void imprimirCliente(eCliente cliente);

/** \brief Imprime en pantalla los clientes del array de clientes.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \return void
 *
 */
void imprimirClientes(eCliente listaClientes[], int tamClientes);

/** \brief Ordena los clientes de manera ascendente o descendente.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tammaño del array de clientes.
 * \param orden int 1 o 0 para indicar el modo de ordenamiento.
 * \return int retorna un estado si pudo o no realizar la operacion.
 *
 */
int ordenarClientes(eCliente listaClientes[], int tamClientes, int orden);

/** \brief Busca a un cliente del array por su codigo.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \param codigo int codigo del cliente a buscar.
 * \return int devuelve el indice en el cual esta el cliente.
 *
 */
int buscarClientePorCodigo(eCliente listaClientes[], int tamClientes, int codigo);

/** \brief Modifica los datos de un cliente.
 *
 * \param listaClientes[] eCliente array de clientes.
 * \param tamClientes int tamaño del array de clientes.
 * \return int retorna un estado si pudo o no realizar la operacion.
 *
 */
int modificarCliente(eCliente listaClientes[], int tamClientes);

/** \brief Agrega datos de clientes pre-definidos al array de clientes.
 *
 * \param listaclientes[] eCliente Array de clientes.
 * \param cantClientesHardcodear int Cantidad de clientes a hardcodear.
 * \param codigo int Codigo de cliente disponible.
 * \return int retorna el ultimo codigo disponible para dar continuidad al codigo de cliente.
 *
 */
int hardCodearClientes(eCliente listaclientes[], int cantClientesHardcodear, int codigo);
