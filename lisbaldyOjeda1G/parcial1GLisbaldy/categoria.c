#include "categoria.h"

int hardCodearCategorias(eCategoria listaCategorias[], int tamCategorias, int* codigo)
{
    int i;
    int cantidadHardcodeada=0;

    int idCategoria[]={1,2,3,4,5};
    char descripcion[][51]= {"MESA", "AZAR", "ESTRATEGIA", "SALON", "MAGIA"};

    for(i=0; i<tamCategorias; i++)
    {
        listaCategorias[i].idCategoria = idCategoria[i];
        strcpy(listaCategorias[i].descripcion, descripcion[i]);
        listaCategorias[i].isEmpty = 0;

        *codigo += 1;
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
        if(listaCategorias[i].isEmpty == 0)
        {
            imprimirCategoria(listaCategorias[i]);
            cantidadImpresa++;
        }
    }

    printf("\n");
    system("pause");

    return cantidadImpresa;
}

void imprimirCategoria(eCategoria categoria)
{
    printf("%5d %27s\n", categoria.idCategoria, categoria.descripcion);
}

int iniciarCategorias(eCategoria listaCategorias[], int tamCategorias)
{
    int able = 0;

    for(int i=0; i<tamCategorias; i++)
    {
        listaCategorias[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 1;
    }

    return able;
}

int findFreePositionCategorias(eCategoria listaCategorias[], int tamCategorias)
{
    int index = -1;

    for(int i=0; i<tamCategorias; i++)
    {
        if(listaCategorias[i].isEmpty == 1)
        {
            index = i; // Guardo en la variable i el valor de la primera posicion disponible encontrada.
            break; // Corto la ejecucion del bucle ya que de lo contrario la variable i tomará el valor de la ultima posicion disponible encontrada y deseo la primera posicion disponible.
        }
    }

    return index;
}

int altaCategoria(eCategoria listaCategorias[], int tamCategorias, int codigo, char descripcion[])
{
    int able = 0;
    int index;

    index = findFreePositionCategorias(listaCategorias, tamCategorias); // Obtengo -1 si el array de estructuras está lleno o el índice de la primera posición disponible.

    if( index == -1 )
    {
        printf("\nNo hay mas espacio para agregar!\n");
        system("pause");
    }
    else
    {
        listaCategorias[index] = nuevaCategoria(codigo, descripcion); // Almaceno los datos del nuevo empleado en la primera posicion disponible del array de estructuras.
        printf("\nALTA EXITOSA\n\n");
        able = 1;
        system("pause");
    }

    return able;
}

eCategoria nuevaCategoria(int codigo, char descripcion[])
{
    eCategoria nuevaCategoria;

    nuevaCategoria.idCategoria = codigo;
    strcpy(nuevaCategoria.descripcion, descripcion);
    nuevaCategoria.isEmpty = 0;

    return nuevaCategoria;
}

int cargarCategoria(eCategoria listaCategorias[], int tamCategorias, int* lastId)
{
    int able = 0;
    char descripcion[51];

    system("cls");

    printf("****** Alta de Categorias *******\n\n");

    getString(descripcion, "Ingrese el descripcion: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 50);

    able = altaCategoria(listaCategorias, tamCategorias, *lastId, descripcion); // Carga los datos solicitados al array de estructuras y devuelve true si fue capaz de hacerlo.
    *lastId += 1;

    return able;
}

int eliminarCategoria(eCategoria listaCategorias[], int tamCategorias)
{
    int able = 0;
    char option;
    int idCategoriaAEliminar;
    int flag=0;

    getInt(&idCategoriaAEliminar, "Ingrese el Codigo de la categoria a Eliminar (100 - 999): ", "Error. ", 100, 999);

    for(int i=0; i<tamCategorias; i++)
    {
        if(listaCategorias[i].idCategoria == idCategoriaAEliminar && listaCategorias[i].isEmpty == 0)
        {
            imprimirCategoria(listaCategorias[i]);

            printf("\nEsta seguro de eliminar esta Categoria? (s/n)");
            fflush(stdin);
            option = getche();

            if(option == 's')
            {
                listaCategorias[i].isEmpty = 1;
                printf("\n\nBAJA EXITOSA!\n\n");
                able = 1;
                system("pause");
            }
            flag = 1; // flag para indicar que se encontró un usuario con dicho ID independientemente de si se remueve o no.
            break;
        }
    }

    if( able == 0 && flag == 0)
    {
        printf("\nNo se encontro ninguna Categoria con ese ID.\n\n");
        system("pause");
    }

    return able;
}

int buscarCategoriaPorCodigo(eCategoria listaCategorias[], int tamCategorias, int codigo)
{
    int index = -1;

    for(int i=0; i<tamCategorias; i++)
    {
        if(listaCategorias[i].idCategoria == codigo)
        {
            index = i;
            break; // Interrumpo la ejecucion del bucle para devolver el valor de la posicion del empleado encontrado.
        }
    }

    return index;
}

int modificarCategoria(eCategoria listaCategorias[], int tamCategorias)
{
    int codigo;
    int option;
    int index;
    int able=0;

        system("cls");

        printf("****** Modificar Cliente *******\n\n");

        fflush(stdin);
        getInt(&codigo, "Ingrese el Codigo de la Categoria a Eliminar (100 - 999): ", "Error. ", 100, 999);

        index = buscarCategoriaPorCodigo(listaCategorias, tamCategorias, codigo);

            if(index == -1 || listaCategorias[index].isEmpty == 0)
            {
                printf("\nNo se encontro ninguna Categoria con ese codigo.\n\n");
                system("pause");
            }
            else
            {
                able = 1;

                printf("\n");
                imprimirCategoria(listaCategorias[index]);

                printf("\nQue desea modificar de esta Categoria?\n");
                printf("\n1) Descripcion\n");
                printf("2) Salir\n\n");
                getInt(&option, "Ingrese opcion: ", "Opcion invalida. ", 1, 4);

                switch(option)
                {
                case 1:
                    getString(listaCategorias[index].descripcion, "\nIngrese la nueva descripcion: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 50);
                    printf("\nDescripcion modificada!\n\n");
                    system("pause");
                    break;
                case 2:
                    printf("\nSe ha cancelado la modificacion!\n\n");
                    system("pause");
                    break;
                default:
                    printf("\nOpcion no valida!\n\n");
                    break;
                }
            }

    return able;
}

int cargarDescCategoria(eCategoria listaCategorias[], int tamCategorias, int idCategoria, char descripcionCategoria[])
{
    int able = 0;

    for(int i=0; i<tamCategorias; i++)
    {
        if(listaCategorias[i].idCategoria == idCategoria && listaCategorias[i].isEmpty == 0)
        {
            strcpy(descripcionCategoria, listaCategorias[i].descripcion);
            able = 1;
        }
    }

    return able;
}
