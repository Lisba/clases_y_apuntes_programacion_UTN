#include "Destino.h"

int hardCodearDestinos(eDestino listaDestinos[], int tamDestinos)
{
    int i;
    int cantidadHardcodeada=0;

    int id[]= {100, 101, 102, 103};
    char descripcion[][20]= {"CANCUN", "MIAMI", "RIO", "DOMINICA"};
    float precio[]= {102.66, 109.99, 157.66, 128.55};

    for(i=0; i<tamDestinos; i++)
    {
        listaDestinos[i].idDestino = id[i];
        strcpy(listaDestinos[i].descripcion, descripcion[i]);
        listaDestinos[i].precio = precio[i];
        listaDestinos[i].isEmpty = 0;

        cantidadHardcodeada++;
    }
    return cantidadHardcodeada;
}

int imprimirDestino(eDestino destino)
{
    int able = 0;

    printf("%5d %27s %15.2f\n", destino.idDestino, destino.descripcion, destino.precio);
    able = 1;

    return able;
}

int imprimirDestinos(eDestino listaDestinos[], int tamDestinos)
{
    int cantidadImpresa=0;

    system("cls");
    printf("****** Lista de Destinos *******\n\n");
    printf(" CODIGO             DESCRIPCION            PRECIO\n");

    for(int i=0; i<tamDestinos; i++)
    {
        if(listaDestinos[i].isEmpty==0)
        {
            imprimirDestino(listaDestinos[i]);
            cantidadImpresa++;
        }
    }

    printf("\n");

    return cantidadImpresa;
}

int buscarDestinoPorCodigo(eDestino listaDestinos[], int tamDestinos, int codigo)
{
    int index = -1;

    for(int i=0; i<tamDestinos; i++)
    {
        if(listaDestinos[i].idDestino == codigo)
        {
            index = i;
            break; // Interrumpo la ejecucion del bucle para devolver el valor de la posicion del empleado encontrado.
        }
    }

    return index;
}

int cargarDescDestino(eDestino listaDestinos[], int tamDestinos, int idDestino, char descripcionDestino[])
{
    int able = 0;

    for(int i=0; i<tamDestinos; i++)
    {
        if(listaDestinos[i].idDestino == idDestino && listaDestinos[i].isEmpty == 0)
        {
            strcpy(descripcionDestino, listaDestinos[i].descripcion);
            able = 1;
        }
    }

    return able;
}

int iniciarDestinos(eDestino listaDestinos[], int tamDestinos)
{
    int able = 0;

    for(int i=0; i<tamDestinos; i++)
    {
        listaDestinos[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 1;
    }

    return able;
}
