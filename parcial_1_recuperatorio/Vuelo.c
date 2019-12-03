#include "Vuelo.h"

int menuVuelos()
{
    int opcion;

    system("cls");
    printf("****** ABM Vuelos *******\n\n");
    printf("1-Alta Vuelo\n");
    printf("2-Baja Vuelo\n");
    printf("3-Modificar Vuelo\n");
    printf("4-Listar Vuelos\n");
    printf("5-Consultas\n");
    printf("6-Salir\n\n");
    getInt(&opcion, "Ingrese opcion: ", "Opcion invalida. ", 1, 6);
    return opcion;
}

int iniciarVuelos(eVuelo listaVuelos[], int tamVuelos)
{
    int able = 0;

    for(int i=0; i<tamVuelos; i++)
    {
        listaVuelos[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 1;
    }

    return able;
}

int findFreePositionVuelos(eVuelo listaVuelos[], int tamVuelos)
{
    int index = -1;

    for(int i=0; i<tamVuelos; i++)
    {
        if(listaVuelos[i].isEmpty == 1)
        {
            index = i; // Guardo en la variable i el valor de la primera posicion disponible encontrada.
            break; // Corto la ejecucion del bucle ya que de lo contrario la variable i tomará el valor de la ultima posicion disponible encontrada y deseo la primera posicion disponible.
        }
    }

    return index;
}

int altaVuelos(eVuelo listaVuelos[], int tamVuelos, int idVuelo, int idDestino, int idPiloto, int partida, int llegada, char estadoVuelo[])
{
    int able = 0;
    int index;

    index = findFreePositionVuelos(listaVuelos, tamVuelos); // Obtengo -1 si el arraya de estructuras esta lleno o el indice de la primera posicion disponible.

    if( index == -1 )
    {
        printf("\nNo hay mas espacio para agregar.\n");
        system("pause");
    }
    else
    {
        listaVuelos[index] = nuevoVuelo(idVuelo, idDestino, idPiloto, partida, llegada, estadoVuelo); // Almaceno los datos del nuevo vuelo en la primera posicion disponible del array de estructuras.
        printf("\nALTA EXITOSA\n\n");
        able = 1;
        system("pause");
    }

    return able;
}

eVuelo nuevoVuelo(int idVuelo, int idDestino, int idPiloto, int partida, int llegada, char estadoVuelo[])
{
    eVuelo nuevoVuelo;

    nuevoVuelo.idVuelo = idVuelo;
    nuevoVuelo.idDestino = idDestino;
    nuevoVuelo.IdPiloto = idPiloto;
    nuevoVuelo.partida = partida;
    nuevoVuelo.llegada = llegada;
    strcpy(nuevoVuelo.estadoVuelo, estadoVuelo);
    nuevoVuelo.isEmpty = 0;

    return nuevoVuelo;
}

int cargarVuelo(eVuelo listaVuelos[], int tamVuelos, int* lastId, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos)
{
    int able = 0;
    int idDestino;
    int idPiloto;
    int partida;
    int llegada;
    char estadoVuelo[20];

    system("cls");

    printf("****** Alta de Vuelos *******\n\n");

    imprimirDestinos(listaDestinos, tamDestinos);
    getInt(&idDestino, "Seleccione el ID del destino: ", "Error. ", 100, 103);

    imprimirPilotos(listaPilotos, tamPilotos);
    getInt(&idPiloto, "Seleccione el ID del piloto: ", "Error. ", 100, 103);

    getInt(&partida, "Ingrese la hora de partida: ", "Error. ", 1, 24);
    getInt(&llegada, "Ingrese la hora de llegada: ", "Error. ", 1, 24);
    getString(estadoVuelo, "Ingrese el estado del vuelo: ", "Error. ", 1, 10);

    able = altaVuelos(listaVuelos, tamVuelos, *lastId, idDestino, idPiloto, partida, llegada, estadoVuelo); // Carga los datos solicitados al array de estructuras y devuelve true si fue capaz de hacerlo.
    *lastId += 1;

    return able;
}

int buscarVueloPorCodigo(eVuelo listaVuelos[], int tamVuelos, int codigo)
{
    int index = -1;

    for(int i=0; i<tamVuelos; i++)
    {
        if(listaVuelos[i].idVuelo == codigo)
        {
            index = i;
            break; // Interrumpo la ejecucion del bucle para devolver el valor de la posicion del empleado encontrado.
        }
    }

    return index;
}

int eliminarVuelo(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos)
{
    int able = 0;
    char option;
    int idVueloAEliminar;
    int flag=0;

    imprimirVuelos(listaVuelos, tamVuelos, listaPilotos, tamPilotos, listaDestinos, tamDestinos);
    getInt(&idVueloAEliminar, "Ingrese el Codigo del Vuelo a Eliminar (100 - 999): ", "Error. ", 100, 999);

    for(int i=0; i<tamVuelos; i++)
    {
        if(listaVuelos[i].idVuelo == idVueloAEliminar && listaVuelos[i].isEmpty == 0)
        {
            printf("\nCODIGO     NOMBRE_PILOTO      DESTINO   PARTIDA    LLEGADA            ESTADO_VUELO\n");
            imprimirVuelo(listaVuelos[i], listaPilotos, tamPilotos, listaDestinos, tamDestinos);

            printf("\nEsta seguro de eliminar a este Vuelo? (s/n): ");
            fflush(stdin);
            option = getche();

            if(option == 's')
            {
                listaVuelos[i].isEmpty = 1;
                printf("\n\nBAJA EXITOSA!\n\n");
                able = 1;
                system("pause");
            }
            flag = 1; // flag para indicar que se encontró un usuario con dicho ID independientemente de si se remueve o no.
            break;
        }
    }

    if( able == 0 && flag == 0)
    {
        printf("\nNo se encontro ningun Vuelo con ese ID.\n\n");
        system("pause");
    }

    return able;
}

int imprimirVuelo(eVuelo Vuelo, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos)
{
    int able = 0;
    char nombrePiloto[20];
    char descripcionDestino[20];

    cargarDescPiloto(listaPilotos, tamPilotos, Vuelo.IdPiloto, nombrePiloto);
    cargarDescDestino(listaDestinos, tamDestinos, Vuelo.idDestino, descripcionDestino);

    printf("%4d %15s %15s %7d %9d %25s\n", Vuelo.idVuelo, nombrePiloto, descripcionDestino, Vuelo.partida, Vuelo.llegada, Vuelo.estadoVuelo);
    able = 1;

    return able;
}

int imprimirVuelos(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos)
{
    int cantidadImpresa=0;
    system("cls");
    printf("****** Lista de Vuelos *******\n\n");
    printf("\nCODIGO     NOMBRE_PILOTO      DESTINO   PARTIDA    LLEGADA            ESTADO_VUELO\n");

    for(int i=0; i<tamVuelos; i++)
    {
        if(listaVuelos[i].isEmpty == 0)
        {
            imprimirVuelo(listaVuelos[i], listaPilotos, tamPilotos, listaDestinos, tamDestinos);
            cantidadImpresa++;
        }
    }
    printf("\n");

    return cantidadImpresa;
}

int hardCodearVuelos(eVuelo listaVuelos[], int tamVuelos, int* lastId)
{
    int i;
    int cantidadHardcodeada=0;

    int idDestino[]= {100, 101, 102, 103, 101, 100};
    int idPiloto[]= {100, 103, 101, 102, 102, 100};
    int partida[]= {12, 9, 7, 10, 13, 8};
    int llegada[]= {22, 17, 20, 18, 21, 19};
    char estadoVuelo[][20]= {"ACTIVO", "SUSPENDIDO", "DEMORADO", "CANCELADO", "ACTIVO", "DEMORADO"};

    for(i=0; i<tamVuelos; i++)
    {
        listaVuelos[i].idVuelo = *lastId;
        listaVuelos[i].idDestino = idDestino[i];
        listaVuelos[i].IdPiloto = idPiloto[i];
        listaVuelos[i].partida = partida[i];
        listaVuelos[i].llegada = llegada[i];
        strcpy(listaVuelos[i].estadoVuelo, estadoVuelo[i]);
        listaVuelos[i].isEmpty = 0;

        *lastId += 1;
        cantidadHardcodeada++;
    }
    return cantidadHardcodeada;
}

int modificarEstadoVuelo(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos)
{
    int codigo;
    int option;
    int index;
    int able=0;

        system("cls");

        printf("****** Modificar Estado de Vuelo *******\n\n");

        imprimirVuelos(listaVuelos, tamVuelos, listaPilotos, tamPilotos, listaDestinos, tamDestinos);
        fflush(stdin);
        getInt(&codigo, "Ingrese el Codigo del Vuelo a Modificar (100 - 999): ", "Error. ", 100, 999);

        index = buscarVueloPorCodigo(listaVuelos, tamVuelos, codigo);

            if(index == -1 || listaVuelos[index].isEmpty == 1)
            {
                printf("\nNo se encontro ningun Vuelo con ese Codigo.\n\n");
                system("pause");
            }
            else
            {
                able = 1;

                printf("\n");
                printf("CODIGO     NOMBRE      APELLIDO   SEXO    TELEFONO            DOMICILIO         LOCALIDAD\n");
                imprimirVuelo(listaVuelos[index], listaPilotos, tamPilotos, listaDestinos, tamDestinos);

                printf("\nDesea modificar de este Vuelo? (1)SI/(2)NO.\n");
                getInt(&option, "Ingrese opcion: ", "Opcion invalida. ", 1, 2);

                switch(option)
                {
                case 1:
                    getString(listaVuelos[index].estadoVuelo, "\nIngrese el nuevo estado: ", "Error. ", 1, 19);
                    printf("\nEstado modificado!\n\n");
                    system("pause");
                    break;
                case 2:
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
