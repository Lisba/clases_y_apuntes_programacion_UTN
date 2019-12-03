#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"
#include "Piloto.h"
#include "Vuelo.h"
#include "Destino.h"

int menuConsultas();
void vuelosPilotoSeleccionado(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos);
void pilotosVolaronDestinoEspecifico(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos);
void recaudacionPorPiloto(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos);
void destinoMasElegido(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos);
