#include "Consultas.h"

int menuConsultas()
{
    int opcion;

    system("cls");
    printf("****** CONSULTAS *******\n\n");
    printf("1-TODOS LOS VUELOS DE UN PILOTO SELECCIONADO.\n");
    printf("2-TODOS LOS PILOTOS QUE VOLARON A UN DESTINO ESPECIFICO.\n");
    printf("3-RECAUDACION POR CADA PILOTO.\n");
    printf("4-DESTINO MAS ELEGIDO.\n");
    printf("5-SALIR\n\n");
    getInt(&opcion, "Ingrese opcion: ", "Opcion invalida. ", 1, 5);
    return opcion;
}

void vuelosPilotoSeleccionado(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos)
{
    int piloto;

    imprimirPilotos(listaPilotos, tamPilotos);
    getInt(&piloto, "INGRESE EL ID DEL PILOTO: ", "ERROR. ", 100, 110);

    for(int i=0; i<tamPilotos; i++)
    {
        if(piloto == listaPilotos[i].idPiloto)
        {
            for(int j=0; j<tamVuelos; j++)
            {
                if(listaPilotos[i].idPiloto == listaVuelos[j].IdPiloto)
                {
                    imprimirVuelo(listaVuelos[j], listaPilotos, tamPilotos, listaDestinos, tamDestinos);
                }
            }

            break;
        }
    }
}

void pilotosVolaronDestinoEspecifico(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos)
{
    int destino;

    imprimirDestinos(listaDestinos, tamDestinos);
    getInt(&destino, "INGRESE EL ID DEL DESTINO: ", "ERROR. ", 100, 104);

    for(int i=0; i<tamDestinos; i++)
    {
        if(destino == listaDestinos[i].idDestino)
        {
            for(int j=0; j<tamVuelos; j++)
            {
                if(listaDestinos[i].idDestino == listaVuelos[j].idDestino)
                {
                    for(int k=0; k<tamPilotos; k++)
                    {
                        if(listaVuelos[j].IdPiloto == listaPilotos[k].idPiloto)
                        {
                            imprimirPiloto(listaPilotos[k]);
                        }
                    }
                }
            }

            break;
        }
    }
}

void recaudacionPorPiloto(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos)
{
    float recaudacionPilotos[tamPilotos];

    for(int i=0; i<tamPilotos; i++)
    {
        recaudacionPilotos[i] = 0;
    }

    for(int i=0; i<tamPilotos; i++)
    {
        for(int j=0; j<tamVuelos; j++)
        {
            if(listaPilotos[i].idPiloto == listaVuelos[j].IdPiloto)
            {
                for(int k=0; k<tamDestinos; k++)
                {
                    if(listaDestinos[k].idDestino == listaVuelos[j].idDestino)
                    {
                        recaudacionPilotos[i] += listaDestinos[k].precio;
                    }
                }
            }
        }
    }

    printf("\n");
    for(int i=0; i<tamPilotos; i++)
    {
        printf("El importe recaudado por el piloto: %s es: %.2f\n", listaPilotos[i].nombre, recaudacionPilotos[i]);
    }
    printf("\n");
}

void destinoMasElegido(eVuelo listaVuelos[], int tamVuelos, ePiloto listaPilotos[], int tamPilotos, eDestino listaDestinos[], int tamDestinos)
{
    int destino[tamDestinos];
    int mayor;

    for(int i=0; i<tamDestinos; i++)
    {
        destino[i] = 0;
    }

    for(int i=0; i<tamDestinos; i++)
    {
        for(int j=0; j<tamVuelos; j++)
        {
            if(listaDestinos[i].idDestino == listaVuelos[j].idDestino)
            {
                destino[i]++;
            }
        }
    }

    mayor = destino[0];

    for(int i=0; i<tamDestinos; i++)
    {
        if(destino[i] > mayor)
        {
            mayor = destino[i];
        }
    }

    for(int i=0; i<tamDestinos; i++)
    {
        if(destino[i] == mayor)
        {
            imprimirDestino(listaDestinos[i]);
        }
    }
}
