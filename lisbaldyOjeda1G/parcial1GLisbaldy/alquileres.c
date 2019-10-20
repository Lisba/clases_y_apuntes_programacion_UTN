#include "alquileres.h"

int subMenuAlquileres()
{
    int opcion;

    system("cls");
    printf("****** ABM Alquileres *******\n\n");
    printf("1-Alta alquiler\n");
    printf("2-Listar Alquileres\n");
    printf("3-Salir\n\n");
    getInt(&opcion, "Ingrese opcion: ", "Opcion invalida. ", 1, 3);

    return opcion;
}

int iniciarAlquileres(eAlquiler listaAlquileres[], int tamAlquileres)
{
    int able = 0;

    for(int i=0; i<tamAlquileres; i++)
    {
        listaAlquileres[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 1;
    }

    return able;
}

int findFreePositionAlquileres(eAlquiler listaAlquileres[], int tamAlquileres)
{
    int index = -1;

    for(int i=0; i<tamAlquileres; i++)
    {
        if(listaAlquileres[i].isEmpty == 1)
        {
            index = i; // Guardo en la variable i el valor de la primera posicion disponible encontrada.
            break; // Corto la ejecucion del bucle ya que de lo contrario la variable i tomará el valor de la ultima posicion disponible encontrada y deseo la primera posicion disponible.
        }
    }

    return index;
}

int altaAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, int codigo, int codigoJuego, int codigoCliente, eFecha fecha)
{
    int able = 0;
    int index;

    index = findFreePositionAlquileres(listaAlquileres, tamAlquileres); // Obtengo -1 si el arraya de estructuras esta lleno o el indice de la primera posicion disponible.

    if( index == -1 )
    {
        printf("\nNo hay mas espacio para agregar.\n");
        system("pause");
    }
    else
    {
        listaAlquileres[index] = nuevoAlquiler(codigo, codigoJuego, codigoCliente, fecha); // Almaceno los datos del nuevo empleado en la primera posicion disponible del array de estructuras.
        printf("\nALTA EXITOSA\n\n");
        able = 1;
        system("pause");
    }

    return able;
}

eAlquiler nuevoAlquiler(int codigo, int codigoJuego, int codigoCliente, eFecha fecha)
{
    eAlquiler nuevAlquiler;

    nuevAlquiler.codigoAlquiler = codigo;
    nuevAlquiler.codigoJuego = codigoJuego;
    nuevAlquiler.codigoCliente = codigoCliente;
    nuevAlquiler.fecha = fecha;
    nuevAlquiler.isEmpty = 0;

    return nuevAlquiler;
}

int cargarAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes, int* codigoAlquiler)
{
    int able = 0;
    int codigoJuego;
    int codigoCliente;
    int maximoJuegos=99;
    int maximoClientes=99;
    eFecha fecha;

    system("cls");

    printf("****** Alta de Alquiler *******\n\n");

    maximoJuegos += imprimirJuegos(listaJuegos, tamJuegos);
    getInt(&codigoJuego, "Ingrese el codigo del juego seleccionado: ", "Error. ", 100, maximoJuegos);
    maximoClientes += imprimirClientes(listaClientes, tamClientes);
    getInt(&codigoCliente, "Ingrese el codigo del cliente seleccionado: ", "Error. ", 100, maximoClientes);

    getInt(&fecha.dia, "Ingrese el dia: ", "Error. ", 1, 31);
    getInt(&fecha.mes, "Ingrese el mes: ", "Error. ", 1, 12);
    getInt(&fecha.anio, "Ingrese el anio: ", "Error. ", 2000, 2019);

    able = altaAlquiler(listaAlquileres, tamAlquileres, *codigoAlquiler, codigoJuego, codigoCliente, fecha); // Carga los datos solicitados al array de estructuras y devuelve true si fue capaz de hacerlo.
    *codigoAlquiler += 1;

    return able;
}

int imprimirAlquileres(eAlquiler listaAlquileres[], int tamAlquileres)
{
    int cantImpresa = 0;

    system("cls");
    printf("****** Lista de aLQUILERES *******\n\n");
    printf(" CODIGO    CODIGO JUEGO    CODIGO CLIENTE    FECHA\n");

    for(int i=0; i<tamAlquileres; i++)
    {
        if(listaAlquileres[i].isEmpty == 0)
        {
            imprimirAlquiler(listaAlquileres[i]);
            cantImpresa++;
        }
    }
    printf("\n");
    system("pause");

    return cantImpresa;
}

void imprimirAlquiler(eAlquiler alquiler)
{
    printf("%5d %13d %15d %9d/%d/%d\n", alquiler.codigoAlquiler, alquiler.codigoJuego, alquiler.codigoCliente, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);
}

int buscarAlquilerPorCodigo(eAlquiler listaAlquileres[], int tamAlquileres, int codigo)
{
    int index = -1;

    for(int i=0; i<tamAlquileres; i++)
    {
        if(listaAlquileres[i].codigoAlquiler == codigo)
        {
            index = i;
            break; // Interrumpo la ejecucion del bucle para devolver el valor de la posicion del empleado encontrado.
        }
    }

    return index;
}

int eliminarAlquiler(eAlquiler listaAlquileres[], int tamAlquileres)
{
    int able = 0;
    char option;
    int idAlquilerAEliminar;
    int indice;

    getInt(&idAlquilerAEliminar, "Ingrese el Codigo del Alquiler a Eliminar (100 - 999): ", "Error. ", 100, 999);

    indice = buscarAlquilerPorCodigo(listaAlquileres, tamAlquileres, idAlquilerAEliminar);

    if(indice == -1 || listaAlquileres[indice].isEmpty == 1)
    {
        printf("\nNo se encontro alquiler con ese ID.\n\n");
        system("pause");
    }
    else
    {
        printf(" CODIGO    CODIGO JUEGO    CODIGO CLIENTE    FECHA\n");
        imprimirAlquiler(listaAlquileres[indice]);

        printf("\nEsta seguro de eliminar este Alquiler? (s/n)");
        fflush(stdin);
        option = getche();

        if(option == 's')
        {
            listaAlquileres[indice].isEmpty = 1;
            printf("\n\nBAJA EXITOSA!\n\n");
            able = 1;
            system("pause");
        }
    }

    return able;
}

int modificarAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes)
{
    int codigo;
    int option;
    int cantImpresa;
    int index;
    eFecha fecha;
    int able=0;

        system("cls");

        printf("****** Modificar Cliente *******\n\n");

        fflush(stdin);
        getInt(&codigo, "Ingrese el Codigo del Alquiler a Modificar (100 - 999): ", "Error. ", 100, 999);

        index = buscarAlquilerPorCodigo(listaAlquileres, tamAlquileres, codigo);

            if(index == -1 || listaAlquileres[index].isEmpty == 1)
            {
                printf("\nNo se encontro ningun Alquiler con ese codigo.\n\n");
                system("pause");
            }
            else
            {
                able = 1;

                printf("\n");
                printf(" CODIGO    CODIGO JUEGO    CODIGO CLIENTE    FECHA\n");
                imprimirAlquiler(listaAlquileres[index]);

                printf("\nQue desea modificar de este Alquiler?\n");
                printf("\n1) Codigo Juego\n");
                printf("2) Codigo Cliente\n");
                printf("3) Fecha\n");
                printf("4) Salir\n\n");
                getInt(&option, "Ingrese opcion: ", "Opcion invalida. ", 1, 4);

                switch(option)
                {
                case 1:
                    cantImpresa=99;
                    cantImpresa += imprimirJuegos(listaJuegos, tamJuegos);
                    getInt(&listaAlquileres[index].codigoJuego, "\nIngrese el nuevo codigo: ", "Error. ", 100, cantImpresa);
                    printf("\nCodigo Juego modificado!\n\n");
                    system("pause");
                    break;
                case 2:
                    cantImpresa=99;
                    cantImpresa += imprimirClientes(listaClientes, tamClientes);
                    getInt(&listaAlquileres[index].codigoCliente, "\nIngrese el nuevo codigo de cliente: ", "Error. ", 100, cantImpresa);
                    printf("\nCodigo Cliente modificado!\n\n");
                    system("pause");
                    break;
                case 3:
                    getInt(&fecha.dia, "Ingrese el dia: ", "Error. ", 1, 31);
                    getInt(&fecha.mes, "Ingrese el mes: ", "Error. ", 1, 12);
                    getInt(&fecha.anio, "Ingrese el anio: ", "Error. ", 2000, 2019);
                    listaAlquileres[index].fecha = fecha;
                    printf("\nFecha modificada!\n\n");
                    system("pause");
                    break;
                case 4:
                    printf("\nSe ha cancelado la modificacion!\n\n");
                    system("pause");
                    break;
                default:
                    printf("\nOpcion no valida!\n\n");
                    break;
                }
            }

    return able;
}

int hardCodearAlquileres(eAlquiler listaAlquileres[], int tamAlquileres, int* codigo)
{
    int i;
    int cantidadHardcodeada=0;

    int codigoJuego[]= {104, 105, 105, 108, 109};
    int codigoCliente[]= {100, 103, 100, 102, 102};
    eFecha fecha[]={{10,4,2010}, {12,9,2017}, {24,12,2016}, {31,4,2010}, {18,5,2016}};

    for(i=0; i<tamAlquileres; i++)
    {
        listaAlquileres[i].codigoAlquiler = *codigo;
        listaAlquileres[i].codigoJuego = codigoJuego[i];
        listaAlquileres[i].codigoCliente = codigoCliente[i];
        listaAlquileres[i].fecha = fecha[i];
        listaAlquileres[i].isEmpty = 0;

        *codigo += 1;
        cantidadHardcodeada++;
    }
    return cantidadHardcodeada;
}
