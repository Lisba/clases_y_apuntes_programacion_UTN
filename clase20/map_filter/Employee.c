#include "Employee.h"
#include "LinkedList.h"

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

int dominio_setTipo(eDominio* this, int tipo)
{
    int able = 0;

    if(this != NULL && tipo > 0)
    {
        this->tipo = tipo;
        able = 1;
    }

    return able;
}

int dominio_getTipo(eDominio* this, int* tipo)
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

int printDominios(LinkedList* pArrayListDominio)
{
    int able = 0;
    int tam;

    if( pArrayListDominio != NULL )
    {
        tam = ll_len(pArrayListDominio);
        system("cls");
        printf("ID             DOMINIO      ANIO    TIPO\n");

        for(int i=0; i<tam; i++)
        {
            printDominio(((eDominio*) ll_get(pArrayListDominio, i)));
            able = 1;
        }
    }

    return able;
}

int validateDominio(eDominio* this)
{
    int isUsed = 0;
    int id;
    char dominio[128];
    int anio;
    char tipo;

    if(this != NULL)
    {
        dominio_getId(this, &id);
        dominio_getAnio(this, &anio;
        dominio_gettipo(this, &tipo);
        dominio_getdominio(this, dominio);

        if(id > 0 && anio > 0 &&  dominio != NULL && tipo > 0)
        {
            isUsed = 1;
        }
    }

    return isUsed;
}
