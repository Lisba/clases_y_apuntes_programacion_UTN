#include "Piloto.h"

int hardCodearPilotos(ePiloto listaPilotos[], int tamPilotos)
{
    int i;
    int cantidadHardcodeada=0;

    int id[]= {100, 101, 102, 103};
    char nombre[][20]= {"LISBALDY", "YANINA", "FACUNDO", "JORGE"};

    for(i=0; i<tamPilotos; i++)
    {
        listaPilotos[i].idPiloto = id[i];
        strcpy(listaPilotos[i].nombre, nombre[i]);
        listaPilotos[i].isEmpty = 0;

        cantidadHardcodeada++;
    }
    return cantidadHardcodeada;
}

int imprimirPiloto(ePiloto Piloto)
{
    int able = 0;

    printf("%5d %27s\n", Piloto.idPiloto, Piloto.nombre);
    able = 1;

    return able;
}

int imprimirPilotos(ePiloto listaPilotos[], int tamPilotos)
{
    int cantidadImpresa=0;

    system("cls");
    printf("****** Lista de Pilotos *******\n\n");
    printf(" CODIGO             NOMBRE\n");

    for(int i=0; i<tamPilotos; i++)
    {
        if(listaPilotos[i].isEmpty == 0)
        {
            imprimirPiloto(listaPilotos[i]);
            cantidadImpresa++;
        }
    }

    printf("\n");

    return cantidadImpresa;
}

int buscarPilotoPorCodigo(ePiloto listaPilotos[], int tamPilotos, int codigo)
{
    int index = -1;

    for(int i=0; i<tamPilotos; i++)
    {
        if(listaPilotos[i].idPiloto == codigo)
        {
            index = i;
            break; // Interrumpo la ejecucion del bucle para devolver el valor de la posicion del empleado encontrado.
        }
    }

    return index;
}

int cargarDescPiloto(ePiloto listaPilotos[], int tamPilotos, int idPiloto, char descripcionPiloto[])
{
    int able = 0;

    for(int i=0; i<tamPilotos; i++)
    {
        if(listaPilotos[i].idPiloto == idPiloto && listaPilotos[i].isEmpty == 0)
        {
            strcpy(descripcionPiloto, listaPilotos[i].nombre);
            able = 1;
        }
    }

    return able;
}

int iniciarPilotos(ePiloto listaPilotos[], int tamPilotos)
{
    int able = 0;

    for(int i=0; i<tamPilotos; i++)
    {
        listaPilotos[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 1;
    }

    return able;
}
