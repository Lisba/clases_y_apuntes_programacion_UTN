#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "lisba_utn.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char dominio[7];
    int anio;
    char tipo;
}eDominio;

int dominio_setId(eDominio* this, int id);
int dominio_getId(eDominio* this, int id);

int dominio_setDominio(eDominio* this, char* dominio);
int dominio_getDominio(eDominio* this, char* dominio);

int printDominio(eDominio* this);
int printDominios(LinkedList* pArrayListDominio);

int validateDominio(eDominio* this);

#endif // employee_H_INCLUDED
