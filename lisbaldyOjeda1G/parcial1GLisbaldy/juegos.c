#include "juegos.h"

int hardCodearJuegos(eJuego listaJuegos[], int tamJuegos, int* codigo)
{
    int i;
    int cantidadHardcodeada=0;

    char descripcion[][51]= {"UNO", "MONOPOLIO", "BLACK JACK", "POKER", "AJEDREZ", "DAMAS", "BILLAR", "METEGOL", "WIZARDGAME", "MAGICGAME"};
    float importe[]= {7.66, 10.99, 7.66, 12.55, 9.99, 7.99, 25.88, 19.40, 12.99, 10.80};
    int idCategoria[]={1, 1, 2, 2, 3, 3, 4, 4, 5, 5};

    for(i=0; i<tamJuegos; i++)
    {
        listaJuegos[i].codigo = *codigo;
        strcpy(listaJuegos[i].descripcion, descripcion[i]);
        listaJuegos[i].importe = importe[i];
        listaJuegos[i].idCategoria = idCategoria[i];
        listaJuegos[i].isEmpty = 0;

        *codigo += 1;
        cantidadHardcodeada++;
    }
    return cantidadHardcodeada;
}

int imprimirJuegos(eJuego listaJuegos[], int tamJuegos, eCategoria listaCategorias[], int tamCategorias)
{
    int cantidadImpresa=0;

    system("cls");
    printf("****** Lista de Juegos *******\n\n");
    printf(" CODIGO             DESCRIPCION            IMPORTE         IDCATEGORIA\n");

    for(int i=0; i<tamJuegos; i++)
    {
        if(listaJuegos[i].isEmpty==0)
        {
            imprimirJuego(listaJuegos[i], listaCategorias, tamCategorias);
            cantidadImpresa++;
        }
    }

    printf("\n");

    return cantidadImpresa;
}

int imprimirJuego(eJuego juego, eCategoria listaCategorias[], int tamCategorias)
{
    int able = 0;
    char descripcionCategoria[51];

    cargarDescCategoria(listaCategorias, tamCategorias, juego.idCategoria, descripcionCategoria);

    printf("%5d %27s %15.2f %19s\n", juego.codigo, juego.descripcion, juego.importe, descripcionCategoria);
    able = 1;

    return able;
}

int iniciarJuegos(eJuego listaJuegos[], int tamJuegos)
{
    int able = 0;

    for(int i=0; i<tamJuegos; i++)
    {
        listaJuegos[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 1;
    }

    return able;
}

int findFreePositionJuegos(eJuego listaJuegos[], int tamJuegos)
{
    int index = -1;

    for(int i=0; i<tamJuegos; i++)
    {
        if(listaJuegos[i].isEmpty == 1)
        {
            index = i; // Guardo en la variable i el valor de la primera posicion disponible encontrada.
            break; // Corto la ejecucion del bucle ya que de lo contrario la variable i tomará el valor de la ultima posicion disponible encontrada y deseo la primera posicion disponible.
        }
    }

    return index;
}

int altaJuego(eJuego listaJuegos[], int tamJuegos, int codigo, char descripcion[], float importe, int categoria)
{
    int able = 0;
    int index;

    index = findFreePositionJuegos(listaJuegos, tamJuegos); // Obtengo -1 si el array de estructuras está lleno o el índice de la primera posición disponible.

    if( index == -1 )
    {
        printf("\nNo hay mas espacio para agregar!\n");
        system("pause");
    }
    else
    {
        listaJuegos[index] = nuevoJuego(codigo, descripcion, importe, categoria); // Almaceno los datos del nuevo empleado en la primera posicion disponible del array de estructuras.
        printf("\nALTA EXITOSA\n\n");
        able = 1;
        system("pause");
    }

    return able;
}

eJuego nuevoJuego(int codigo, char descripcion[], float importe, int categoria)
{
    eJuego nuevoJuego;

    nuevoJuego.codigo = codigo;
    strcpy(nuevoJuego.descripcion, descripcion);
    nuevoJuego.importe = importe;
    nuevoJuego.idCategoria = categoria;
    nuevoJuego.isEmpty = 0;

    return nuevoJuego;
}

int cargarJuego(eJuego listaJuegos[], int tamJuegos, eCategoria listaCategorias[], int tamCategorias, int* lastId)
{
    int able = 0;
    char descripcion[51];
    float importe;
    int categoria;
    int cantImpresa=0;

    system("cls");

    printf("****** Alta de Juegos *******\n\n");

    cantImpresa += imprimirCategorias(listaCategorias, tamCategorias);
    getInt(&categoria, "Ingrese la categoria: ", "Error. ", 1, cantImpresa);
    getString(descripcion, "Ingrese el descripcion: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 50);
    getFloat(&importe, "Ingrese el importe: ", "Error, debe ingresar un numero flotante (0.00 - 100.00). ", 0, 100);

    able = altaJuego(listaJuegos, tamJuegos, *lastId, descripcion, importe, categoria); // Carga los datos solicitados al array de estructuras y devuelve true si fue capaz de hacerlo.
    *lastId += 1;

    return able;
}

int eliminarJuego(eJuego listaJuegos[], int tamJuegos, eCategoria listaCategorias[], int tamCategorias)
{
    int able = 0;
    char option;
    int idJuegoAEliminar;
    int flag=0;

    getInt(&idJuegoAEliminar, "Ingrese el Codigo del Juego a Eliminar (100 - 999): ", "Error. ", 100, 999);

    for(int i=0; i<tamJuegos; i++)
    {
        if(listaJuegos[i].codigo == idJuegoAEliminar && listaJuegos[i].isEmpty == 0)
        {
            printf(" CODIGO             DESCRIPCION            IMPORTE         IDCATEGORIA\n");
            imprimirJuego(listaJuegos[i], listaCategorias, tamCategorias);

            printf("\nEsta seguro de eliminar este juego? (s/n)");
            fflush(stdin);
            option = getche();

            if(option == 's')
            {
                listaJuegos[i].isEmpty = 1;
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
        printf("\nNo se encontro ningun juego con ese ID.\n\n");
        system("pause");
    }

    return able;
}

int buscarJuegoPorCodigo(eJuego listaJuegos[], int tamJuegos, int codigo)
{
    int index = -1;

    for(int i=0; i<tamJuegos; i++)
    {
        if(listaJuegos[i].codigo == codigo)
        {
            index = i;
            break; // Interrumpo la ejecucion del bucle para devolver el valor de la posicion del empleado encontrado.
        }
    }

    return index;
}

int modificarJuego(eJuego listaJuegos[], int tamJuegos, eCategoria listaCategorias[], int tamCategorias)
{
    int codigo;
    int option;
    int cantImpresa=0;
    int index;
    int able=0;

        system("cls");

        printf("****** Modificar Cliente *******\n\n");

        fflush(stdin);
        getInt(&codigo, "Ingrese el Codigo del Juego a Eliminar (100 - 999): ", "Error. ", 100, 999);

        index = buscarJuegoPorCodigo(listaJuegos, tamJuegos, codigo);

            if(index == -1 || listaJuegos[index].isEmpty == 0)
            {
                printf("\nNo se encontro ningun juego con ese codigo.\n\n");
                system("pause");
            }
            else
            {
                able = 1;

                printf("\n");
                printf(" CODIGO             DESCRIPCION            IMPORTE         IDCATEGORIA\n");
                imprimirJuego(listaJuegos[index], listaCategorias, tamCategorias);

                printf("\nQue desea modificar de este juego?\n");
                printf("\n1) Descripcion\n");
                printf("2) Importe\n");
                printf("3) Categoria\n");
                printf("4) Salir\n\n");
                getInt(&option, "Ingrese opcion: ", "Opcion invalida. ", 1, 4);

                switch(option)
                {
                case 1:
                    getString(listaJuegos[index].descripcion, "\nIngrese la nueva descripcion: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 50);
                    printf("\nDescripcion modificada!\n\n");
                    system("pause");
                    break;
                case 2:
                    getFloat(&listaJuegos[index].importe, "\nIngrese el nuevo importe (0.00 - 100.00): ", "Error. ", 0, 100);
                    printf("\nImporte modificado!\n\n");
                    system("pause");
                    break;
                case 3:
                    cantImpresa += imprimirCategorias(listaCategorias, tamCategorias);
                    getInt(&listaJuegos[index].idCategoria, "Ingrese la nueva categoria: ", "Error. ", 1, cantImpresa);
                    printf("\nCategoria modificada!\n\n");
                    system("pause");
                    break;
                case 4:
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

int cargarDescJuego(eJuego listaJuegos[], int tamJuegos, int idJuego, char descripcionJuego[])
{
    int able = 0;

    for(int i=0; i<tamJuegos; i++)
    {
        if(idJuego == listaJuegos[i].codigo && listaJuegos[i].isEmpty == 0)
        {
            strcpy(descripcionJuego, listaJuegos[i].descripcion);
            able = 1;
        }
    }

    return able;
}
