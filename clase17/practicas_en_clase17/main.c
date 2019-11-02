#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[30];
    int modelo;
    float precio;
}eAuto;

int setIdAuto(eAuto* unAuto, int id);
int getIdAuto(eAuto* unAuto);
int getMarcaAuto(eAuto* unAuto, char* marca);
int setMarcaAuto(eAuto* unAuto, char* marca);
int setModeloAuto(eAuto* unAuto, int modelo);
int getModeloAuto(eAuto* unAuto);
int setPrecioAuto(eAuto* unAuto, float precio);
float getPrecioAuto(eAuto* unAuto);
eAuto* newAuto(void);
eAuto* newAutoParam(int id, char* marca, int modelo, float precio);
int mostrarTodos(eAuto** autos, int tam);
int guardarAutosBinario(eAuto** lista, int tam, char* path);

int main()
{
    eAuto** lista = (eAuto**) malloc(sizeof(eAuto*));
    eAuto* autoAux = NULL;
    FILE* f = NULL;
    eAuto** auxLista = NULL;

    char buffer[4][30];
    int tam = 0;
    int cant = 0;

    if(lista == NULL)
    {
        printf("No se pudo conseguir memoria.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    f = fopen("autos.csv", "r");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(f))
    {
        cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant < 4)
        {
            break;
        }
        else
        {
            autoAux = newAutoParam(atoi(buffer[0]), buffer[1], atoi(buffer[2]), atof(buffer[3]));
            if(autoAux != NULL)
            {
                *(lista + tam) = autoAux;
                tam++;

                auxLista = (eAuto**) realloc(lista, sizeof(eAuto*) * (tam+1));
                 if(auxLista != NULL)
                 {
                     lista = auxLista;
                 }
            }
        }
    }

    fclose(f);

    mostrarTodos(lista, tam);

    if( guardarAutosBinario(lista, tam, "autos.bin"))
    {
        printf("Autos guardados en archivo binario.\n");
        system("pause");
    }
    else
    {
        printf("No se pudieron guardar los autos.\n");
        system("pause");
    }

    int tam2 = 0;
    eAuto** lista2 = (eAuto**) malloc(sizeof(eAuto*));
    if(lista2 == NULL)
    {
        printf("No se pudo conseguir memoria.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    f = fopen("autos.bin", "rb");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    while(!feof(f))
    {
        autoAux = newAuto();
        if(autoAux == NULL)
        {
            break;
        }

        cant = fread(autoAux, sizeof(eAuto), 1, f);
        if(cant < 1)
        {
            break;
        }
        else
        {
            *(lista2 + tam2) = autoAux;
            tam2++;

            auxLista = (eAuto**) realloc(lista, sizeof(eAuto*) * (tam+1));
            if(auxLista != NULL)
            {
                lista2 = auxLista;
            }
        }
    }

    fclose(f);

    mostrarTodos(lista2, tam2);

    return 0;
}

int setIdAuto(eAuto* unAuto, int id)
{
    int able=0;

    if(unAuto != NULL && id >= 1000 && id <= 2000)
    {
        unAuto->id = id;
        able = 1;
    }

    return able;
}

int getIdAuto(eAuto* unAuto)
{
    int id = -1;

    if(unAuto != NULL)
    {
        id = unAuto->id;
    }

    return id;
}

int setMarcaAuto(eAuto* unAuto, char* marca)
{
    int able=0;

    if(unAuto != NULL && marca != NULL && strlen(marca)>= 30)
    {
        strcpy(unAuto->marca, marca);
        able = 1;
    }

    return able;
}

int getMarcaAuto(eAuto* unAuto, char* marca)
{
    int able=0;

    if(unAuto != NULL && marca != NULL)
    {
        strcpy(marca, unAuto->marca);
        able = 1;
    }

    return able;
}

int setModeloAuto(eAuto* unAuto, int modelo)
{
    int able=0;

    if(unAuto != NULL && modelo >= 1950 && modelo <= 2020)
    {
        unAuto->modelo = modelo;
        able = 1;
    }

    return able;
}

int getModeloAuto(eAuto* unAuto)
{
    int modelo=0;

    if(unAuto != NULL && modelo >= 1950 && modelo <= 2020)
    {
        modelo = unAuto->modelo;
        modelo = 1;
    }

    return modelo;
}

int setPrecioAuto(eAuto* unAuto, float precio)
{
    int able=0;

    if(unAuto != NULL && precio >= 60000 && precio <= 1000000)
    {
        unAuto->precio = precio;
        able = 1;
    }

    return able;
}

float getPrecioAuto(eAuto* unAuto)
{
    float precio = -1;

    if(unAuto != NULL)
    {
        precio = unAuto->precio;
    }

    return precio;
}

eAuto* newAuto(void)
{
    eAuto* unAuto;

    unAuto = (eAuto*) malloc(sizeof(eAuto));

    if(unAuto == NULL)
    {
        printf("No se pudo reservar memoria\n");
        exit(1);
    }

    unAuto->id = 0;
    strcpy(unAuto->marca, " ");
    unAuto->modelo = 0;
    (*unAuto).precio = 0;

    return unAuto;
}

eAuto* newAutoParam(int id, char* marca, int modelo, float precio)
{
    eAuto* myCar;

    myCar = newAuto();

    if(myCar != NULL)
    {
        if((setIdAuto(myCar, id)
            && getMarcaAuto(myCar, marca)
            && setModeloAuto(myCar, modelo)
            && setPrecioAuto(myCar, precio)) == 0)
        {
            free(myCar);
            myCar = NULL;
        }
    }

    return myCar;
}

int mostrarUnAuto(eAuto* myAuto)
{
    int able = 0;

    if(myAuto != NULL)
    {
        printf("%d %s %d %.2f", myAuto->id, myAuto->marca, (*myAuto).modelo, myAuto->precio);
        able = 1;
    }

    return able;
}

int mostrarTodos(eAuto** autos, int tam)
{
    int cantMostrada=0;

    if(autos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            mostrarUnAuto( *(autos+i) );
            cantMostrada++;
        }
    }

    return cantMostrada;
}

int guardarAutosBinario(eAuto** lista, int tam, char* path)
{
    int able = 0;
    FILE* f = NULL;

    if(lista != NULL && tam > 0 && path != NULL)
    {
        f = fopen(path, "wb");
        if(f == NULL)
        {
            printf("No se pudo conseguir memoria.\n");
            system("pause");
            return able;
        }

        for(int i=0; i<tam; i++)
        {
            fwrite( *(lista+i), sizeof(eAuto), 1, path);
        }

        fclose(f);

        able = 1;
    }

    return able;
}
