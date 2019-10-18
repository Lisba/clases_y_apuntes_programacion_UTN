#include "categoria.h"

int hardCodearCategorias(eCategoria listaCategorias[], int tamCategorias)
{
    int i;
    int cantidadHardcodeada=0;

    int idCategoria[]={1, 2, 3, 4, 5};
    char descripcion[][51]= {"MESA", "AZAR", "ESTRATEGIA", "SALON", "MAGIA"};

    for(i=0; i<tamCategorias; i++)
    {
        listaCategorias[i].idCategoria = idCategoria[i];
        strcpy(listaCategorias[i].descripcion, descripcion[i]);
        cantidadHardcodeada++;
    }

    return cantidadHardcodeada;
}

int imprimirCategorias(eCategoria listaCategorias[], int tamCategorias)
{
    int cantidadImpresa=0;

    system("cls");
    printf("****** Lista de Categorias *******\n\n");

    for(int i=0; i<tamCategorias; i++)
    {
        imprimirCategoria(listaCategorias[i]);
        cantidadImpresa++;
    }

    printf("\n");
    system("pause");

    return cantidadImpresa;
}

void imprimirCategoria(eCategoria categoria)
{
    printf("%5d %27s\n", categoria.idCategoria, categoria.descripcion);

}
