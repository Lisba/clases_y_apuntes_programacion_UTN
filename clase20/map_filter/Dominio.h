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

int dominio_setId(eDominio* this, int id);
int dominio_getId(eDominio* this, int id);

int dominio_setDominio(eDominio* this, char* dominio);
int dominio_getDominio(eDominio* this, char* dominio);

int printDominio(eDominio* this);
int printDominios(LinkedList* this);

int validateDominio(eDominio* this);
