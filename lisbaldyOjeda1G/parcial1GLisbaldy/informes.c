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
    printf("10-Mostrar la recaudacion de una fecha en particular.\n");
    printf("11-Ingresar una localidad e informar el monto recaudado en alquileres a clientes de la misma.\n");
    printf("12-Elegir un juego e informar las fechas y nombres de los clientes que lo alquilaron.\n");
    printf("13-Informar la categoria de los juegos menos alquilada.\n");
    printf("14-Listar los telefonos de los clientes que alquilaron juegos en una determinada fecha.\n");
    printf("15-Mostrar el o los juegos mas alquilados por hombres.\n");
    printf("16-Salir\n\n");
    getInt(&option, "Ingrese opcion: ", "Opcion invalida. ", 1, 16);

    return option;
}

void mostrarJuegosCatMesa(eJuego listaJuegos[], int tamJuegos, eCategoria listaCategorias[], int tamCategorias)
{
    int categoria=1;

    for(int i=0; i<tamJuegos; i++)
    {
        if(listaJuegos[i].idCategoria == categoria)
        {
            imprimirJuego(listaJuegos[i], listaCategorias, tamCategorias);
        }
    }

    printf("\n");
    system("pause");
}

void MostrarAlquilerClienteSelec(eCliente listaClientes[], int tamClientes, eAlquiler listaAlquileres[], int tamAlquiler, eLocalidad listaLocalidades[], int tamLocalidades, eJuego listaJuegos[], int tamJuegos)
{
    int idCliente;
    int flag=0;

    imprimirClientes(listaClientes, tamClientes, listaLocalidades, tamLocalidades);

    getInt(&idCliente, "Seleccione el ID del cliente: ", "Error. Seleccione entre 100 y 999. ", 100, 999);

    for(int i=0; i<tamAlquiler; i++)
    {
        if(idCliente == listaAlquileres[i].codigoCliente)
        {
            imprimirAlquiler(listaAlquileres[i], listaJuegos, tamJuegos, listaClientes, tamClientes);
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

void juegosNoAlquilados(eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres, eCategoria listaCategorias[], int tamCategorias)
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
            imprimirJuego(listaJuegos[i], listaCategorias, tamCategorias);
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

void listarElJuegoPreferidoEnUnaLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, eCliente listaClientes[], int tamClientes, eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eCategoria listaCategorias[], int tamCategorias)
{
    int localidad;
    int cantImpresa=0;
    int cantidadJuegoPreferido[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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
        }
    }

    for(int i=0; i<tamJuegos; i++)
    {
        if(cantidadJuegoPreferido[i] == mayor)
        {
            imprimirJuego(listaJuegos[i], listaCategorias, tamCategorias);
        }
    }

    system("pause");
}

void listarJuegosAlquiladosPorMujeres(eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes, eAlquiler listaAlquileres[], int tamAlquileres, eCategoria listaCategorias[], int tamCategorias)
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
                            imprimirJuego(listaJuegos[k], listaCategorias, tamCategorias);
                        }
                    }
                }
            }
        }
    }
    system("pause");
}

void listarLosClientesQueAlquilaronUnDeterminadoJuego(eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades, eCategoria listaCategorias[], int tamCategorias)
{
    int juego;

    imprimirJuegos(listaJuegos, tamJuegos, listaCategorias, tamCategorias);
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

void mostrarLaRecaudacionDeUnaFechaEnParticular(eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos)
{
    eFecha fecha;
    float recaudacion=0;

    getInt(&fecha.dia, "Seleccione dia: ", "Error. ", 1, 31);
    getInt(&fecha.mes, "Seleccione mes: ", "Error. ", 1, 12);
    getInt(&fecha.anio, "Seleccione anio: ", "Error. ", 2000, 2019);

    for(int i=0; i<tamAlquileres; i++)
    {
        if(compararFechas(fecha, listaAlquileres[i].fecha) == 1)
        {
            for(int j=0; j<tamJuegos; j++)
            {
                if(listaAlquileres[i].codigoJuego == listaJuegos[j].codigo)
                {
                    recaudacion += listaJuegos[j].importe;
                }
            }
        }
    }

    printf("El importe recaudado en dicha fecha es: %.2f\n", recaudacion);
    system("pause");
}

int compararFechas(eFecha fecha1, eFecha fecha2)
{
    int coinciden = 0;

    if(fecha1.dia == fecha2.dia)
    {
        if(fecha1.mes == fecha2.mes)
        {
            if(fecha1.anio == fecha2.anio)
            {
                coinciden = 1;
            }
        }
    }

    return coinciden;
}

void montoRecaudadoPorLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres, eCliente listaClientes[], int tamClientes)
{
    int localidad;
    float importeRecaudado = 0;

    imprimirLocalidades(listaLocalidades, tamLocalidades);
    getInt(&localidad, "Seleccione el ID de la localidad: ", "ERROR! ", 1, 5);

    for(int i=0; i<tamLocalidades; i++)
    {
        if(localidad == listaLocalidades[i].id)
        {
            for(int k=0; k<tamClientes; k++)
            {
                if(listaLocalidades[i].id == listaClientes[k].idLocalidad)
                {
                    for(int j=0; j<tamAlquileres; j++)
                    {
                        if(listaClientes[k].codigo == listaAlquileres[j].codigoCliente)
                        {
                            for(int h=0; h<tamJuegos; h++)
                            {
                                if(listaAlquileres[j].codigoJuego == listaJuegos[h].codigo)
                                {
                                    importeRecaudado += listaJuegos[h].importe;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("\nEl importe recaudado por esa localidad es: %.2f\n\n", importeRecaudado);
    system("pause");
}

void fechaYNombreClientesAlquilaronJuego(eLocalidad listaLocalidades[], int tamLocalidades, eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres, eCliente listaClientes[], int tamClientes, eCategoria listaCategorias[], int tamCategorias)
{
    int juego;

    imprimirJuegos(listaJuegos, tamJuegos, listaCategorias, tamCategorias);
    getInt(&juego, "Selecciona el ID de un juego: ", "ERROR! ", 100, 110);

    for(int i=0; i<tamJuegos; i++)
    {
        if(juego == listaJuegos[i].codigo)
        {
            for(int j=0; j<tamAlquileres; j++)
            {
                if(listaJuegos[i].codigo == listaAlquileres[j].codigoJuego)
                {
                    for(int k=0; k<tamClientes; k++)
                    {
                        if(listaAlquileres[j].codigoCliente == listaClientes[k].codigo)
                        {
                            printf("\nLa fecha es: %d/%d/%d, y el nombre del cliente es: %s\n\n", listaAlquileres[j].fecha.dia,listaAlquileres[j].fecha.mes, listaAlquileres[j].fecha.anio, listaClientes[k].nombre);
                        }
                    }
                }
            }
        }
    }
    system("pause");
}

void categoriaMenosAlquilada(eLocalidad listaLocalidades[], int tamLocalidades, eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres, eCliente listaClientes[], int tamClientes, eCategoria listaCategorias[], int tamCategorias)
{
    int alquilerCategorias[5] = {0, 0, 0, 0, 0};
    int menor = 0;

    for(int i=0; i<tamCategorias; i++)
    {
        for(int j=0; j<tamJuegos; j++)
        {
            if(listaCategorias[i].idCategoria == listaJuegos[j].idCategoria)
            {
                for(int k=0; k<tamAlquileres; k++)
                {
                    if(listaJuegos[j].codigo == listaAlquileres[k].codigoJuego)
                    {
                        alquilerCategorias[i]++;
                    }
                }
            }
        }
    }

    for(int i=0; i<tamCategorias-1; i++)
    {
        if(menor > alquilerCategorias[i])
        {
            menor = alquilerCategorias[i];
        }
    }

    for(int i=0; i<tamCategorias-1; i++)
    {
        if(alquilerCategorias[i] == menor)
        {
            imprimirCategoria(listaCategorias[i]);
        }
    }
    system("pause");
}

void telefClientesAlquilaronJuegosFechaDeterm(eLocalidad listaLocalidades[], int tamLocalidades, eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres, eCliente listaClientes[], int tamClientes, eCategoria listaCategorias[], int tamCategorias)
{
    eFecha fecha;

    getInt(&fecha.dia, "Seleccione dia: ", "Error. ", 1, 31);
    getInt(&fecha.mes, "Seleccione mes: ", "Error. ", 1, 12);
    getInt(&fecha.anio, "Seleccione anio: ", "Error. ", 2000, 2019);

    for(int i=0; i<tamAlquileres; i++)
    {
        if( compararFechas(fecha, listaAlquileres[i].fecha) )
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

void juegosMasAlquiladosHombres(eLocalidad listaLocalidades[], int tamLocalidades, eJuego listaJuegos[], int tamJuegos, eAlquiler listaAlquileres[], int tamAlquileres, eCliente listaClientes[], int tamClientes, eCategoria listaCategorias[], int tamCategorias)
{
    int juegoMasAlquilado[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int mayor = 0;

    for(int i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].sexo == 'm')
        {
            for(int j=0; j<tamAlquileres; j++)
            {
                if(listaClientes[i].codigo == listaAlquileres[j].codigoCliente)
                {
                    for(int k=0; k<tamJuegos; k++)
                    {
                        if(listaAlquileres[j].codigoJuego == listaJuegos[k].codigo)
                        {
                            juegoMasAlquilado[k]++;
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<tamJuegos; i++)
    {
        if(mayor < juegoMasAlquilado[i])
        {
            mayor = juegoMasAlquilado[i];
        }
    }

    for(int i=0; i<tamJuegos; i++)
    {
        if(juegoMasAlquilado[i] == mayor)
        {
            imprimirJuego(listaJuegos[i], listaCategorias, tamCategorias);
        }
    }

    system("pause");
}
