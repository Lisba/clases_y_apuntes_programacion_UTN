#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dominio.h"
#include "LinkedList.h"
#include "lisba_utn.h"

int menu(void)
{
    int opcion;

    system("cls");
    printf("****** ABM Empleados *******\n\n");
    printf("1-Cargar los datos de los empleados desde el archivo datos.csv (modo texto).\n");
    printf("2-Listar empleados.\n");
    printf("3-Ordenar empleados.\n");
    printf("4-Cargar campos tipo segun vehiculo.\n");
    printf("5-Guardar archivos separados segun tipo.\n");
    printf("6-Guardar los datos de los empleados con tipo en un archivo llamado datosConTipo.csv (modo texto).\n");
    printf("7-Salir.\n\n");
    getInt(&opcion, "Ingrese opcion: ", "Opcion invalida. ", 1, 7);

    return opcion;
}

eDominio* dominio_new(void)
{
    eDominio* this = (eDominio*) malloc(sizeof(eDominio));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->dominio, " ");
        this->anio = 0;
        this->tipo = ' ';
    }

    return this;
}

eDominio* dominio_newParametros(char* idStr, char* dominioStr, char* anioStr)
{
    eDominio* this;

        if(idStr != NULL && dominioStr != NULL && anioStr != NULL)
        {
            this = dominio_new();

            if(this != NULL)
            {
                if( !dominio_setId(this, atoi(idStr)) || !dominio_setDominio(this, dominioStr) || !dominio_setAnio(this, atoi(anioStr)) )
                {
                        dominio_delete(this);
                        this = NULL;
                }
            }
        }

    return this;
}

void dominio_delete(eDominio* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int dominio_setId(eDominio* this, int id)
{
    int able = 0;
    static int maxId = -1;

    if(this != NULL)
    {
        if(id < 0)
        {
            maxId++;
            this->id = maxId;
        }
        else
        {
            this->id = id;
            maxId = id;
        }

        able = 1;
    }

    return able;
}

int dominio_getId(eDominio* this, int* id)
{
    int able = 0;

    if(this != NULL && id > 0)
    {
        *id = this->id;
        able = 1;
    }

    return able;
}

int dominio_setDominio(eDominio* this, char* dominio)
{
    int able = 0;

    if(this != NULL && (dominio != NULL && strlen(dominio)>1))
    {
        strcpy(this->dominio, dominio);
        able = 1;
    }

    return able;
}

int dominio_getDominio(eDominio* this, char* dominio)
{
    int able = 0;

    if(this != NULL && dominio != NULL)
    {
        strcpy(dominio, this->dominio);
        able = 1;
    }

    return able;
}

int dominio_setAnio(eDominio* this, int anio)
{
    int able = 0;

    if(this != NULL && anio > 0)
    {
        this->anio = anio;
        able = 1;
    }

    return able;
}

int dominio_getAnio(eDominio* this, int* anio)
{
    int able = 0;

    if(this != NULL && anio > 0)
    {
        *anio = this->anio;
        able = 1;
    }

    return able;
}

int dominio_setTipo(eDominio* this, char tipo)
{
    int able = 0;

    if(this != NULL && tipo != ' ')
    {
        this->tipo = tipo;
        able = 1;
    }

    return able;
}

int dominio_getTipo(eDominio* this, char* tipo)
{
    int able = 0;

    if(this != NULL && tipo > 0)
    {
        *tipo = this->tipo;
        able = 1;
    }

    return able;
}

int printDominio(eDominio* this)
{
    int able = 0;

    printf("%d %18s %9d %12c\n", this->id, this->dominio, this->anio, this->tipo);
    able = 1;

    return able;
}

int printDominios(LinkedList* this)
{
    int able = 0;
    int tam;

    if( this != NULL )
    {
        tam = ll_len(this);
        system("cls");
        printf("ID             DOMINIO      ANIO    TIPO\n");

        for(int i=0; i<tam; i++)
        {
            printDominio(((eDominio*) ll_get(this, i)));
            able = 1;
        }
    }

    return able;
}

int validateDominio(eDominio* this)
{
    int isUsed = 0;
    int id;
    char dominio[7];
    int anio;
    char tipo;

    if(this != NULL)
    {
        dominio_getId(this, &id);
        dominio_getDominio(this, dominio);
        dominio_getAnio(this, &anio);
        dominio_getTipo(this, &tipo);

        if(id > 0 && anio > 0 &&  strlen(dominio) > 0 && tipo != ' ')
        {
            isUsed = 1;
        }
    }

    return isUsed;
}

int ordenarPorId(void* dom1, void* dom2)
{
    int value;

    eDominio* dominio1 = (eDominio*) dom1;
    eDominio* dominio2 = (eDominio*) dom2;

    if( dominio1->id > dominio2->id )
    {
        value = 1;
    }
    else if( (*dominio1).id < (*dominio2).id )
    {
        value = -1;
    }
    else
    {
        value = 0;
    }

    return value;
}

void* clasificarCampoTipo(void* pElement)
{
    eDominio* pElement1 = (eDominio*) pElement;

    if(pElement != NULL)
    {
        if(pElement1->dominio[0] >= '0' && pElement1->dominio[0] <= '9')
        {
            dominio_setTipo(pElement1, 'M');
        }
        else
        {
            dominio_setTipo(pElement1, 'A');
        }
    }

    return pElement1;
}

int filtrarCampoTipo(void* pElement, char character)
{
    int value = -1;

    eDominio* pElement1 = (eDominio*) pElement;

    if(pElement1->tipo == character)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    return value;
}
