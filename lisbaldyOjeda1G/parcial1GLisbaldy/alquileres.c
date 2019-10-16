#include "alquileres.h"

int subMenuAlquileres()
{
    int opcion;

    system("cls");
    printf("****** ABM Alquileres *******\n\n");
    printf("1-Alta alquiler\n");
    printf("2-Listar Alquileres\n");
    printf("3-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int iniciarAlquileres(eAlquiler listaAlquileres[], int tamAlquileres)
{
    int able = -1;

    for(int i=0; i<tamAlquileres; i++)
    {
        listaAlquileres[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 0;
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
    }
    else
    {
        listaAlquileres[index] = nuevoAlquiler(codigo, codigoJuego, codigoCliente, fecha); // Almaceno los datos del nuevo empleado en la primera posicion disponible del array de estructuras.
        printf("\nALTA EXITOSA\n\n");
        able = 1;
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

int cargarAlquiler(eAlquiler listaAlquileres[], int tamAlquileres, eJuego listaJuegos[], int tamJuegos, eCliente listaClientes[], int tamClientes, int codigoAlquiler)
{
    int able = 0;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;

    system("cls");

    printf("****** Alta de Alquiler *******\n\n");

    imprimirJuegos(listaJuegos, tamJuegos);
    getInt(&codigoJuego, "Ingrese el codigo del juego seleccionado: ", "Error. ", 100, 999);
    imprimirClientes(listaClientes, tamClientes);
    getInt(&codigoCliente, "Ingrese el codigo del cliente seleccionado: ", "Error. ", 100, 999);

    getInt(&fecha.dia, "Ingrese el dia: ", "Error. ", 1, 31);
    getInt(&fecha.mes, "Ingrese el mes: ", "Error. ", 1, 12);
    getInt(&fecha.anio, "Ingrese el anio: ", "Error. ", 2000, 3000);

    able = altaAlquiler(listaAlquileres, tamAlquileres, codigoAlquiler, codigoJuego, codigoCliente, fecha); // Carga los datos solicitados al array de estructuras y devuelve true si fue capaz de hacerlo.

    return able;
}

void imprimirAlquileres(eAlquiler listaAlquileres[], int tamAlquileres)
{
    system("cls");
    printf("****** Lista de aLQUILERES *******\n\n");
    printf(" CODIGO    CODIGO JUEGO    CODIGO CLIENTE    FECHA\n");

    for(int i=0; i<tamAlquileres; i++)
    {
        if(listaAlquileres[i].isEmpty == 0)
        {
            imprimirAlquiler(listaAlquileres[i]);
        }
    }
    system("pause");
}

void imprimirAlquiler(eAlquiler alquiler)
{
    printf("%5d %13d %15d %9d/%d/%d\n", alquiler.codigoAlquiler, alquiler.codigoJuego, alquiler.codigoCliente, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);

}
