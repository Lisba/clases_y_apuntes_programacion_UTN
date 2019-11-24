#ifndef DOMINIO_H
#define DOMINIO_H

typedef struct
{
    int id;
    char dominio[7];
    int anio;
    char tipo;
}eDominio;

#endif // DOMINIO_H

#include "LinkedList.h"

int menu(void);

eDominio* dominio_new(void);
eDominio* dominio_newParametros(char* idStr, char* dominioStr, char* anioStr);

void dominio_delete(eDominio* this);

int dominio_setId(eDominio* this, int id);
int dominio_getId(eDominio* this, int* id);

int dominio_setDominio(eDominio* this, char* dominio);
int dominio_getDominio(eDominio* this, char* dominio);

int dominio_setAnio(eDominio* this, int anio);
int dominio_getAnio(eDominio* this, int* anio);

int dominio_setTipo(eDominio* this, char tipo);
int dominio_getTipo(eDominio* this, char* tipo);

int printDominio(eDominio* this);
int printDominios(LinkedList* this);

int validateDominio(eDominio* this);

int ordenarPorId(void* dom1, void* dom2);
void* clasificarCampoTipo(void* pElement);
int filtrarCampoTipo(void* pElement, char character);
