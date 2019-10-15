#include "informes.h"

int subMenuInformes()
{
    int option;

    system("cls");

    printf("************INFORMES************\n\n");
    printf("1-Mostrar Juegos de Categoria Mesa.\n");
    printf("2-Mostrar los Alquileres efectuados por algun Cliente seleccionado.\n");
    printf("3-Mostrar el total de todos los importes pagados por el Cliente seleccionado.\n");
    printf("4-Listar los Clientes que no Alquilaron Juegos.\n");
    printf("5-Listar los Juegos que no fueron Alquilados.\n");
    printf("6-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &option);

    return option;
}

void mostrarJuegosCatMesa(eJuego listaJuegos[], int tamJuegos)
{
    int categoria=1;

    for(int i=0; i<tamJuegos; i++)
    {
        if(listaJuegos[i].idCategoria == categoria)
        {
            imprimirJuego(listaJuegos[i]);
        }
    }

    system("pause");
}

void MostrarAlquilerClienteSelec(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquiler)
{
    int idCliente;
    int flag=0;

    imprimirClientes(listaClientes, tamCliente);

    getInt(&idCliente, "Seleccione el ID del cliente: ", "Error. Seleccione entre 100 y 999. ", 100, 999);

    for(int i=0; i<tamAlquiler; i++)
    {
        if(idCliente == listaAlquileres[i].codigoCliente)
        {
            imprimirAlquiler(listaAlquileres[i]);
            flag=1;
        }
    }

    if(!flag)
    {
        printf("\nEl cliente no tiene ningun alquiler!\n\n");
    }

    system("pause");
}

float ImportesPagadosPorCliente(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos)
{
    int idCliente;
    float importeTotal=0.00;

    imprimirClientes(listaClientes, tamCliente);

    getInt(&idCliente, "Seleccione el ID del cliente: ", "Error. Seleccione entre 100 y 999. ", 100, 999);

    for(int i=0; i<tamAlquileres; i++)
    {
        if(idCliente == listaAlquileres[i].codigoCliente)
        {
            for(int j=0; j<tamJuegos; j++)
            {
                if(listaAlquileres[i].codigoJuego == listaJuegos[j].codigo)
                {
                    importeTotal += listaJuegos[j].importe;
                }
            }
        }
    }

    printf("El Cliente ha pagado un importe total de: %.2f\n", importeTotal);

    system("pause");

    return importeTotal;
}

void clientesNoAlquilaron(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquileres)
{
    int contador=0;

    for(int i=0; i<tamCliente; i++)
    {
        contador=0;

        for(int j=0; j<tamAlquileres; j++)
        {
            if(listaClientes[i].codigo == listaAlquileres[j].codigoCliente && listaClientes[i].isEmpty == 0)
            {
                contador++;
            }
        }

        if(contador == 0 && listaClientes[i].isEmpty == 0)
        {
            imprimirCliente(listaClientes[i]);
        }
    }

    system("pause");
}

void juegosNoAlquilados(eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres)
{
    int contador=0;

    for(int i=0; i<tamJuegos; i++)
    {
        contador=0;

        for(int j=0; j<tamAlquileres; j++)
        {
            if(listaJuegos[i].codigo == listaAlquileres[j].codigoJuego)
            {
                contador++;
            }
        }

        if(contador == 0)
        {
            imprimirJuego(listaJuegos[i]);
        }
    }

    system("pause");
}
