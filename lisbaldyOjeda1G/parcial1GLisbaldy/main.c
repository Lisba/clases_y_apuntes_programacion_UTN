#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lisba_utn.h"
#include "alquileres.h"
#include "clientes.h"
#include "juegos.h"
#include "categoria.h"
#include "informes.h"

#define TAMCLIENTES 10
#define TAMALQUILERES 10
#define TAMJUEGOS 10
#define TAMCATEGORIAS 5

int main()
{
    int codigoCliente = 100;
    int codigoJuego = 100;
    int codigoAlquiler = 100;
    int option;
    char salirSubmenuClientes = 'n';
    char salirSubmenuAlquileres = 'n';
    char salirSubmenuInformes = 'n';
    char salir = 'n';

    eCliente arrayClientes[TAMCLIENTES];
    eAlquiler arrayAlquileres[TAMALQUILERES];
    eJuego arrayJuegos[TAMJUEGOS];
    eCategoria arrayCategorias[TAMCATEGORIAS];

    iniciarClientes(arrayClientes, TAMCLIENTES);
    iniciarAlquileres(arrayAlquileres, TAMALQUILERES);
    hardCodearClientes(arrayClientes, 4, &codigoCliente);
    hardCodearJuegos(arrayJuegos, 10, &codigoJuego);
    hardCodearCategorias(arrayCategorias, TAMCATEGORIAS);

    do
    {
        system("cls");
        printf("************ABM************\n\n");
        printf("1) CLIENTES\n");
        printf("2) ALQUILERES\n");
        printf("3) INFORMES\n");
        printf("4) SALIR\n\n");
        getInt(&option, "Ingrese opcion: ", "Opcion invalida. ", 1, 4);
        switch(option)
        {
        case 1:
            do
            {
                switch(subMenuClientes())
                {
                    case 1:
                        cargarCliente(arrayClientes, TAMCLIENTES, &codigoCliente);
                        break;
                    case 2:
                        modificarCliente(arrayClientes, TAMCLIENTES);
                        break;
                    case 3:
                        eliminarCliente(arrayClientes, TAMCLIENTES);
                        break;
                    case 4:
                        ordenarClientes(arrayClientes, TAMCLIENTES);
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
            }while(salirSubmenuClientes == 'n');
            break;
        case 2:
            do
            {
                switch(subMenuAlquileres())
                {
                    case 1:
                        cargarAlquiler(arrayAlquileres, TAMALQUILERES, arrayJuegos, TAMJUEGOS, arrayClientes, TAMCLIENTES, &codigoAlquiler);
                        break;
                    case 2:
                        imprimirAlquileres(arrayAlquileres, TAMALQUILERES);
                        break;
                    case 3:
                        printf("Confirma salir? (s/n): ");
                        fflush(stdin);
                        salirSubmenuAlquileres = getche();
                        break;
                    default:
                        printf("\nOpcion Invalida!\n\n");
                }
            }while(salirSubmenuAlquileres != 's');
            break;
        case 3:
            do
            {
                switch(subMenuInformes())
                {
                    case 1:
                        mostrarJuegosCatMesa(arrayJuegos, TAMJUEGOS);
                        break;
                    case 2:
                        MostrarAlquilerClienteSelec(arrayClientes, TAMCLIENTES, arrayAlquileres, TAMALQUILERES);
                        break;
                    case 3:
                        ImportesPagadosPorCliente(arrayClientes, TAMCLIENTES, arrayAlquileres, TAMALQUILERES, arrayJuegos, TAMJUEGOS);
                        break;
                    case 4:
                        clientesNoAlquilaron(arrayClientes, TAMCLIENTES, arrayAlquileres, TAMALQUILERES);
                        break;
                    case 5:
                        juegosNoAlquilados(arrayJuegos, TAMJUEGOS, arrayAlquileres, TAMALQUILERES);
                        break;
                    case 6:
                        printf("Confirma salir? (s/n):");
                        fflush(stdin);
                        salirSubmenuInformes = getche();
                        break;
                    default:
                        printf("\nOpcion Invalida!\n\n");
                }
            } while (salirSubmenuInformes != 's');
            break;
        case 4:
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
