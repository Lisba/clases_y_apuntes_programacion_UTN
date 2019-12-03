#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"
#include "Piloto.h"
#include "Vuelo.h"
#include "Destino.h"
#include "Consultas.h"

#define TAMVUELOS 10
#define TAMPILOTOS 4
#define TAMDESTINOS 4

int main()
{

    int codigoVuelos = 100;
    char salir = 'n';

    eVuelo arrayVuelos[TAMVUELOS];
    ePiloto arrayPilotos[TAMPILOTOS];
    eDestino arrayDestinos[TAMDESTINOS];

    iniciarVuelos(arrayVuelos, TAMVUELOS);
    iniciarPilotos(arrayPilotos, TAMPILOTOS);
    iniciarDestinos(arrayDestinos, TAMDESTINOS);
    hardCodearVuelos(arrayVuelos, 6, &codigoVuelos);
    hardCodearPilotos(arrayPilotos, TAMPILOTOS);
    hardCodearDestinos(arrayDestinos, TAMDESTINOS);

    do
    {
        switch( menuVuelos() )
        {
        case 1:
            cargarVuelo(arrayVuelos, TAMVUELOS, &codigoVuelos, arrayPilotos, TAMPILOTOS, arrayDestinos, TAMDESTINOS);
            break;
        case 2:
            eliminarVuelo(arrayVuelos, TAMVUELOS, arrayPilotos, TAMPILOTOS, arrayDestinos, TAMDESTINOS);
            break;
        case 3:
            modificarEstadoVuelo(arrayVuelos, TAMVUELOS, arrayPilotos, TAMPILOTOS, arrayDestinos, TAMDESTINOS);
            break;
        case 4:
            imprimirVuelos(arrayVuelos, TAMVUELOS, arrayPilotos, TAMPILOTOS, arrayDestinos, TAMDESTINOS);
            system("pause");
            break;
        case 5:
            switch( menuConsultas() )
            {
            case 1:
                vuelosPilotoSeleccionado(arrayVuelos, TAMVUELOS, arrayPilotos, TAMPILOTOS, arrayDestinos, TAMDESTINOS);
                break;
            case 2:
                pilotosVolaronDestinoEspecifico(arrayVuelos, TAMVUELOS, arrayPilotos, TAMPILOTOS, arrayDestinos, TAMDESTINOS);
                break;
            case 3:
                recaudacionPorPiloto(arrayVuelos, TAMVUELOS, arrayPilotos, TAMPILOTOS, arrayDestinos, TAMDESTINOS);
                break;
            case 4:
                destinoMasElegido(arrayVuelos, TAMVUELOS, arrayPilotos, TAMPILOTOS, arrayDestinos, TAMDESTINOS);
                break;
            case 5:
                printf("\nSALIENDO DEL MENU CONSULTAS!\n\n");
                system("pause");
                break;
            default:
                printf("\nOpcion Invalida!\n\n");
            }
            system("pause");
            break;
        case 6:
            printf("Confirma salir? (s/n):");
            fflush(stdin);
            salir = getche();
            break;
        default:
            printf("\nOpcion Invalida!\n\n");
        }
    }while(salir != 's');

    return 0;
}
