#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "alquileres.h"
#include "clientes.h"
#include "juegos.h"

#define TAMCLIENTES 10
#define TAMALQUILERES 10
#define TAMJUEGOS 5

int main()
{
    int codigoCliente = 100;
    int codigoJuego = 100;
    int codigoAlquiler = 100;
    int respuestaAlta;
    int respuestaAltaAlquiler;
    int codigoParaEliminar;
    int option;
    int orden;
    int codigoJuegoAlquiler;
    int codigoClienteAlquiler;
    char salirSubmenuClientes = 'n';
    char salirSubmenuAlquileres = 'n';
    char salir = 'n';

    eCliente arrayClientes[TAMCLIENTES];
    eAlquiler arrayAlquileres[TAMALQUILERES];
    eJuego arrayJuegos[TAMJUEGOS];

    iniciarClientes(arrayClientes, TAMCLIENTES);
    iniciarAlquileres(arrayAlquileres, TAMALQUILERES);
    hardCodearJuegos(arrayJuegos, TAMJUEGOS, codigoJuego);

    do
    {
        printf("************ABM************\n\n");
        printf("1) CLIENTES\n");
        printf("2) ALQUILERES\n");
        printf("3) SALIR\n");
        printf("INGRESE OPCION: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            do
            {
                switch(subMenuClientes())
                {
                case 1:
                    respuestaAlta = cargarCliente(arrayClientes, TAMCLIENTES, codigoCliente);
                    if(respuestaAlta)
                    {
                        codigoCliente++;
                    }
                    break;
                case 2:
                    modificarCliente(arrayClientes, TAMCLIENTES);
                    break;
                case 3:
                    getInt(&codigoParaEliminar, "Ingrese el Codigo del Cliente a Eliminar: ", "Error. ", 100, 999);
                    eliminarCliente(arrayClientes, TAMCLIENTES, codigoParaEliminar);
                    break;
                case 4:
                    printf("Ascendente(0) o Descendente(1)?: ");
                    scanf("%d", &orden);
                    ordenarClientes(arrayClientes, TAMCLIENTES, orden);
                    imprimirClientes(arrayClientes, TAMCLIENTES);
                    break;
                case 5:
                    printf("Confirma salir? (s/n):");
                    fflush(stdin);
                    salirSubmenuClientes = getche();
                    break;
                default:
                    printf("\nOpcion Invalida!\n\n");
                }
                system("pause");

            }while(salirSubmenuClientes == 'n');
            break;

        case 2:
            do
            {
                switch(subMenuAlquileres())
                {
                case 1:
                    imprimirJuegos(arrayJuegos, TAMJUEGOS);
                    getInt(&codigoJuegoAlquiler, "Ingrese el codigo del juego seleccionado: ", "Error. ", 100, 999);
                    imprimirClientes(arrayClientes, TAMCLIENTES);
                    getInt(&codigoClienteAlquiler, "Ingrese el codigo del cliente seleccionado: ", "Error. ", 100, 999);
                    respuestaAltaAlquiler = cargarAlquiler(arrayAlquileres, TAMALQUILERES, codigoAlquiler, codigoJuegoAlquiler, codigoClienteAlquiler);

                    if(respuestaAltaAlquiler)
                    {
                        codigoAlquiler++;
                    }
                    break;
                case 2:
                    imprimirAlquileres(arrayAlquileres, TAMALQUILERES);
                    break;
                case 3:
                    printf("Confirma salir?:");
                    fflush(stdin);
                    salirSubmenuAlquileres = getche();
                    break;
                default:
                    printf("\nOpcion Invalida!\n\n");
                }
                system("pause");

            }while(salirSubmenuAlquileres == 'n');
            break;

        case 3:
            printf("Confirma salir? (s/n):");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}
