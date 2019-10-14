#include "categoria.h"

int hardCodearCategorias(eCategoria listaCategorias[], int tamCategorias)
{
    int i;

    int idCategoria[]={1, 2, 3, 4, 5};
    char descripcion[][51]= {"MESA", "AZAR", "ESTRATEGIA", "SALON", "MAGIA"};

    for(i=0; i<tamCategorias; i++)
    {
        listaCategorias[i].idCategoria = idCategoria[i];
        strcpy(listaCategorias[i].descripcion, descripcion[i]);
    }

    return tamCategorias;
}

void imprimirCategorias(eCategoria listaCategorias[], int tamCategorias)
{
    system("cls");
    printf("****** Lista de Categorias *******\n\n");

    for(int i=0; i<tamCategorias; i++)
    {
        imprimirCategoria(listaCategorias[i]);
    }
    system("pause");
}

void imprimirCategoria(eCategoria categoria)
{
    printf("%5d %27s\n", categoria.idCategoria, categoria.descripcion);

}
