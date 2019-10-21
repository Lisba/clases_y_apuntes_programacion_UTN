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
    printf("6-Listar los clientes de una determinada localidad\n");
    printf("7-Listar el juego preferido en una localidad\n");
    printf("8-Listar los juegos alquilados por mujeres\n");
    printf("9-Listar los clientes que alquilaron un determinado juego.\n");
    printf("10-Salir\n\n");
    getInt(&option, "Ingrese opcion: ", "Opcion invalida. ", 1, 10);

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

    printf("\n");
    system("pause");
}

void MostrarAlquilerClienteSelec(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquiler, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int idCliente;
    int flag=0;

    imprimirClientes(listaClientes, tamCliente, listaLocalidades, tamLocalidades);

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

float ImportesPagadosPorCliente(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int idCliente;
    float importeTotal=0.00;

    imprimirClientes(listaClientes, tamCliente, listaLocalidades, tamLocalidades);

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

    printf("\nEl Cliente ha pagado un importe total de: %.2f\n\n", importeTotal);

    system("pause");

    return importeTotal;
}

void clientesNoAlquilaron(eCliente listaClientes[], int tamCliente, eAlquiler listaAlquileres[], int tamAlquileres, eLocalidad listaLocalidades[], int tamLocalidades)
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
            imprimirCliente(listaClientes[i], listaLocalidades, tamLocalidades);
        }
    }

    printf("\n");
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

    printf("\n");
    system("pause");
}

void listarLosClientesDeUnaDeterimnadaLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, eCliente listaClientes[], int tamClientes)
{
    int localidad;
    int cantImpresa=0;

    cantImpresa = imprimirLocalidades(listaLocalidades, tamLocalidades);
    getInt(&localidad, "Seleccione la localidad por ID: ", "Error. ", 1, cantImpresa);

    for(int i=0; i<tamClientes; i++)
    {
        if(localidad == listaClientes[i].idLocalidad)
        {
            imprimirCliente(listaClientes[i], listaLocalidades, tamLocalidades);
            system("pause");
        }
    }
}

void listarElJuegoPreferidoEnUnaLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, eCliente listaClientes[], int tamClientes, eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos)
{
    int localidad;
    int cantImpresa=0;
    int cantidadJuegoPreferido[tamJuegos];
    int mayor=0;


    cantImpresa = imprimirLocalidades(listaLocalidades, tamLocalidades);
    getInt(&localidad, "Seleccione el Id de la localidad: ", "Error. ", 1, cantImpresa);

    for(int i=0; i<tamJuegos; i++)
    {
        for(int j=0; j<tamAlquileres; j++)
        {
            if(listaAlquileres[j].codigoJuego == listaJuegos[i].codigo)
            {
                for(int k=0; k<tamClientes; k++)
                {
                    if(listaAlquileres[j].codigoCliente == listaClientes[k].codigo)
                    {
                        if(listaClientes[k].idLocalidad == localidad)
                        {
                            cantidadJuegoPreferido[i]++;
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i<tamJuegos; i++)
    {
        if(mayor < cantidadJuegoPreferido[i])
        {
            mayor = cantidadJuegoPreferido[i];
            imprimirJuego(listaJuegos[i]);
            system("pause");
        }
    }
}

void listarJuegosAlquiladosPorMujeres(eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes, eAlquiler listaAlquileres[], int tamAlquileres)
{
    for(int i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].sexo == 'f')
        {
            for(int j=0; j<tamAlquileres; j++)
            {
                if(listaClientes[i].codigo == listaAlquileres[j].codigoCliente)
                {
                    for(int k=0; k<tamJuegos; k++)
                    {
                        if(listaAlquileres[j].codigoJuego == listaJuegos[k].codigo)
                        {
                            imprimirJuego(listaJuegos[k]);
                        }
                    }
                }
            }
        }
    }
    system("pause");
}

void listarLosClientesQueAlquilaronUnDeterminadoJuego(eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int juego;
    int cantImpresa=99;

    cantImpresa = imprimirJuegos(listaJuegos, tamJuegos);
    getInt(&juego ,"Seleccione el ID del Juego: ", "Error. ", 100, 110);

    for(int i=0; i<tamAlquileres; i++)
    {
        if(listaAlquileres[i].codigoJuego == juego)
        {
            for(int j=0; j<tamClientes; j++)
            {
                if(listaAlquileres[i].codigoCliente == listaClientes[j].codigo)
                {
                    imprimirCliente(listaClientes[j], listaLocalidades, tamLocalidades);
                }
            }
        }
    }
    system("pause");
}
