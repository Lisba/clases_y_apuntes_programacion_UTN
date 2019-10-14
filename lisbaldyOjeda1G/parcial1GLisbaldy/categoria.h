#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lisba_utn.h"

typedef struct
{
    int idCategoria;
    char descripcion[51];
} eCategoria;

void imprimirCategorias(eCategoria listaCategorias[], int tamCategorias);
void imprimirCategoria(eCategoria categoria);
int hardCodearCategorias(eCategoria listaCategorias[], int tamCategorias);
