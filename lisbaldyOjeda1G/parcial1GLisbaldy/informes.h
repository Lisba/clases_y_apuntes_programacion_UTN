#ifndef INFORMES_H
#define INFORMES_H

#include <stdio.h>
#include <stdlib.h>
#include "alquileres.h"
#include "clientes.h"
#include "juegos.h"
#include "categoria.h"

int subMenuInformes();
void mostrarJuegosCatMesa(eJuego listaJuegos[], int tamJuegos);
void MostrarAlquilerClienteSelec(eCliente listaCliente[], int tamCliente, eAlquiler listaAlquiler[], int tamAlquiler);
float ImportesPagadosPorCliente(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquiler, eJuego listaJuegos[], int tamJuegos);
void clientesNoAlquilaron(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquileres);
void juegosNoAlquilados(eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres);

#endif // INFORMES_H
