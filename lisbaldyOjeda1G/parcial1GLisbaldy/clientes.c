#include "clientes.h"

int subMenuClientes()
{
    int opcion;

    system("cls");
    printf("****** ABM Clientes *******\n\n");
    printf("1-Alta cliente\n");
    printf("2-Modificar cliente\n");
    printf("3-Baja cliente\n");
    printf("4-Listar clientes\n");
    printf("5-Salir\n\n");
    getInt(&opcion, "Ingrese opcion: ", "Opcion invalida. ", 1, 5);
    return opcion;
}

int iniciarClientes(eCliente listaClientes[], int tamClientes)
{
    int able = 0;

    for(int i=0; i<tamClientes; i++)
    {
        listaClientes[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 1;
    }

    return able;
}

int findFreePositionClientes(eCliente listaClientes[], int tamClientes)
{
    int index = -1;

    for(int i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].isEmpty == 1)
        {
            index = i; // Guardo en la variable i el valor de la primera posicion disponible encontrada.
            break; // Corto la ejecucion del bucle ya que de lo contrario la variable i tomar� el valor de la ultima posicion disponible encontrada y deseo la primera posicion disponible.
        }
    }

    return index;
}

int altaCliente(eCliente listaClientes[], int tamClientes, int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[], int idLocalidad)
{
    int able = 0;
    int index;

    index = findFreePositionClientes(listaClientes, tamClientes); // Obtengo -1 si el arraya de estructuras esta lleno o el indice de la primera posicion disponible.

    if( index == -1 )
    {
        printf("\nNo hay mas espacio para agregar.\n");
        system("pause");
    }
    else
    {
        listaClientes[index] = nuevoCliente(codigo, nombre, apellido, sexo, telefono, domicilio, idLocalidad); // Almaceno los datos del nuevo empleado en la primera posicion disponible del array de estructuras.
        printf("\nALTA EXITOSA\n\n");
        able = 1;
        system("pause");
    }

    return able;
}

eCliente nuevoCliente(int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[], int idLocalidad)
{
    eCliente nuevoCliente;

    nuevoCliente.codigo = codigo;
    strcpy(nuevoCliente.nombre, nombre);
    strcpy(nuevoCliente.apellido, apellido);
    nuevoCliente.sexo = sexo;
    strcpy(nuevoCliente.telefono, telefono);
    strcpy(nuevoCliente.domicilio, domicilio);
    nuevoCliente.idLocalidad = idLocalidad;
    nuevoCliente.isEmpty = 0;

    return nuevoCliente;
}

int cargarCliente(eCliente listaClientes[], int tamClientes, int* lastId, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int able = 0;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];
    int idLocalidad;
    int cantLocalidadesImpresas=0;

    system("cls");

    printf("****** Alta de Cliente *******\n\n");


    getString(nombre, "Ingrese el nombre: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 50);
    getString(apellido, "Ingrese el apellido: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 50);
    do
    {
        getChar(&sexo, "Ingrese el sexo (f/m): ", "Error. ", 'f', 'm');
        if(sexo != 'f' && sexo != 'm')
        {
            printf("Error. ");
        }
    }while(sexo != 'f' && sexo != 'm');
    getPhone(telefono, "Ingrese el telefono: ", "Error, debe ingresar al menos 8 numeros. ", 7, 20);
    cantLocalidadesImpresas += imprimirLocalidades(listaLocalidades, tamLocalidades);
    getInt(&idLocalidad, "Seleccione el ID de la localidad: ", "Error. ", 1, cantLocalidadesImpresas);
    getString(domicilio, "Ingrese el domicilio: ", "Error. ", 1, 50);

    able = altaCliente(listaClientes, tamClientes, *lastId, nombre, apellido, sexo, telefono, domicilio, idLocalidad); // Carga los datos solicitados al array de estructuras y devuelve true si fue capaz de hacerlo.
    *lastId += 1;

    return able;
}

int buscarClientePorCodigo(eCliente listaClientes[], int tamClientes, int codigo)
{
    int index = -1;

    for(int i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].codigo == codigo)
        {
            index = i;
            break; // Interrumpo la ejecucion del bucle para devolver el valor de la posicion del empleado encontrado.
        }
    }

    return index;
}

int eliminarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int able = 0;
    char option;
    int idClienteAEliminar;
    int flag=0;

    imprimirClientes(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
    getInt(&idClienteAEliminar, "Ingrese el Codigo del Cliente a Eliminar (100 - 999): ", "Error. ", 100, 999);

    for(int i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].codigo == idClienteAEliminar && listaClientes[i].isEmpty == 0)
        {
            printf("\nCODIGO     NOMBRE      APELLIDO   SEXO    TELEFONO            DOMICILIO         LOCALIDAD\n");
            imprimirCliente(listaClientes[i], listaLocalidades, tamLocalidades);

            printf("\nEsta seguro de eliminar a este cliente? (s/n): ");
            fflush(stdin);
            option = getche();

            if(option == 's')
            {
                listaClientes[i].isEmpty = 1;
                printf("\n\nBAJA EXITOSA!\n\n");
                able = 1;
                system("pause");
            }
            flag = 1; // flag para indicar que se encontr� un usuario con dicho ID independientemente de si se remueve o no.
            break;
        }
    }

    if( able == 0 && flag == 0)
    {
        printf("\nNo se encontro ningun cliente con ese ID.\n\n");
        system("pause");
    }

    return able;
}

int imprimirClientes(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int cantidadImpresa=0;
    system("cls");
    printf("****** Lista de Empleados *******\n\n");
    printf("CODIGO     NOMBRE      APELLIDO   SEXO    TELEFONO            DOMICILIO         LOCALIDAD\n");

    for(int i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].isEmpty == 0)
        {
            imprimirCliente(listaClientes[i], listaLocalidades, tamLocalidades);
            cantidadImpresa++;
        }
    }
    printf("\n");

    return cantidadImpresa;
}

int imprimirCliente(eCliente cliente, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int able = 0;
    char nombreLocalidad[51];

    cargarNombreLocalidad(listaLocalidades, tamLocalidades, cliente.idLocalidad, nombreLocalidad);

    printf("%4d %13s %13s %3c %15s %20s %14s\n", cliente.codigo, cliente.nombre, cliente.apellido, cliente.sexo, cliente.telefono, cliente.domicilio, nombreLocalidad);
    able = 1;

    return able;
}

int ordenarClientes(eCliente listaClientes[], int tamClientes)
{
    int able = 0;
    int orden;

    getInt(&orden, "Descendente(0) o Ascendente(1)?: ", "Error. ", 0, 1);

    eCliente aux;

    switch(orden)
    {
        case 0:
            for(int i=0; i<tamClientes-1; i++)
            {
                for(int j=i+1; j<tamClientes; j++)
                {
                    if(strcmp(listaClientes[i].apellido, listaClientes[j].apellido)>0)
                    {
                        aux = listaClientes[i];
                        listaClientes[i] = listaClientes[j];
                        listaClientes[j] = aux;
                    }
                    else
                    {
                        if(strcmp(listaClientes[i].apellido, listaClientes[j].apellido)==0)
                        {
                            if(strcmp(listaClientes[i].nombre, listaClientes[j].nombre)>0)
                            {
                                aux = listaClientes[i];
                                listaClientes[i] = listaClientes[j];
                                listaClientes[j] = aux;
                            }
                        }
                    }
                }
            }
            able = 1;
            break;
        case 1:
            for(int i=0; i<tamClientes-1; i++)
            {
                for(int j=i+1; j<tamClientes; j++)
                {
                    if(strcmp(listaClientes[i].apellido, listaClientes[j].apellido)<0)
                    {
                        aux = listaClientes[i];
                        listaClientes[i] = listaClientes[j];
                        listaClientes[j] = aux;
                    }
                    else
                    {
                        if(strcmp(listaClientes[i].apellido, listaClientes[j].apellido)==0)
                        {
                            if(strcmp(listaClientes[i].nombre, listaClientes[j].nombre)<0)
                            {
                                aux = listaClientes[i];
                                listaClientes[i] = listaClientes[j];
                                listaClientes[j] = aux;
                            }
                        }
                    }
                }
            }
            able = 1;
            break;
    }
    return able;
}

int modificarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int codigo;
    int option;
    int index;
    int able=0;

        system("cls");

        printf("****** Modificar Cliente *******\n\n");

        imprimirClientes(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
        fflush(stdin);
        getInt(&codigo, "Ingrese el Codigo del Cliente a Modificar (100 - 999): ", "Error. ", 100, 999);

        index = buscarClientePorCodigo(listaClientes, tamClientes, codigo);

            if(index == -1 || listaClientes[index].isEmpty == 1)
            {
                printf("\nNo se encontro ningun cliente con ese Codigo.\n\n");
                system("pause");
            }
            else
            {
                able = 1;

                printf("\n");
                printf("CODIGO     NOMBRE      APELLIDO   SEXO    TELEFONO            DOMICILIO         LOCALIDAD\n");
                imprimirCliente(listaClientes[index], listaLocalidades, tamLocalidades);

                printf("\nQue desea modificar de este cliente?\n");
                printf("\n1) Nombre\n");
                printf("2) Domicilio\n");
                printf("3) Telefono\n");
                printf("4) Salir\n\n");
                getInt(&option, "Ingrese opcion: ", "Opcion invalida. ", 1, 4);

                switch(option)
                {
                case 1:
                    getString(listaClientes[index].nombre, "\nIngrese el nuevo nombre: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
                    printf("\nNombre modificado!\n\n");
                    system("pause");
                    break;
                case 2:
                    getString(listaClientes[index].domicilio, "\nIngrese el nuevo domicilio: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
                    printf("\nDomicilio modificado!\n\n");
                    system("pause");
                    break;
                case 3:
                    getPhone(listaClientes[index].telefono, "\nIngrese el nuevo telefono: ", "Error. ", 7, 15);
                    printf("\nTelefono modificado!\n\n");
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

int hardCodearClientes(eCliente listaclientes[], int cantClientesHardcodear, int* codigo)
{
    int i;
    int cantidadHardcodeada=0;

    char nombre[][51] = {"Lisbaldy", "Jesus", "Keimarly", "Daniela"};
    char apellido[][51] = {"Ojeda", "Leon", "Cisneros", "Sanchez"};
    char sexo[] = {'m', 'm', 'f', 'f'};
    char telefono[][21] = {"15-3030-7105", "15-4293-4856", "15-8473-9456", "15-7845-9036"};
    char domicilio[][51] = {"Santos Dumont 100", "Avellaneda 300", "Av maipu 500", "Puerto de Frutos"};
    int idLocalidad[] = {1, 2, 3, 4};
    int isEmpty[] = {0, 0, 0, 0};

    for(i=0; i<cantClientesHardcodear; i++)
    {
        listaclientes[i].codigo = *codigo;
        strcpy(listaclientes[i].nombre, nombre[i]);
        strcpy(listaclientes[i].apellido, apellido[i]);
        listaclientes[i].sexo = sexo[i];
        strcpy(listaclientes[i].telefono, telefono[i]);
        strcpy(listaclientes[i].domicilio, domicilio[i]);
        listaclientes[i].idLocalidad = idLocalidad[i];
        listaclientes[i].isEmpty = isEmpty[i];

        *codigo += 1;
        cantidadHardcodeada++;
    }
    return cantidadHardcodeada;
}

int hardCodearLocalidades(eLocalidad listaLocalidades[], int cantHardcodear)
{
    int cantHardcodeada = 0;
    int id[] = {1, 2, 3, 4, 5};
    char nombre[][51] = {"Moron", "Lanus", "Florida", "Tigre", "Avellaneda"};

    for(int i=0; i<cantHardcodear; i++)
    {
        listaLocalidades[i].id = id[i];
        strcpy(listaLocalidades[i].nombre, nombre[i]);
        listaLocalidades[i].isEmpty = 0;

        cantHardcodeada++;
    }
    return cantHardcodeada;
}

void imprimirLocalidad(eLocalidad localidad)
{
    printf("%5d %11s\n", localidad.id, localidad.nombre);
}

int imprimirLocalidades(eLocalidad listaLocalidades[], int tamLocalidades)
{
    int cantidadImpresa=0;
    system("cls");
    printf("****** Lista de Localidades *******\n\n");
    printf(" CODIGO    NOMBRE\n");

    for(int i=0; i<tamLocalidades; i++)
    {
        imprimirLocalidad(listaLocalidades[i]);
        cantidadImpresa++;
    }
    printf("\n");

    return cantidadImpresa;
}

int cargarNombreLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, int idLocalidad, char nombreLocalidad[])
{
    int able = 0;

    for(int i=0; i<tamLocalidades; i++)
    {
        if(listaLocalidades[i].id == idLocalidad && listaLocalidades[i].isEmpty == 0)
        {
            strcpy(nombreLocalidad, listaLocalidades[i].nombre);
            able = 1;
        }
    }

    return able;
}

int iniciarLocalidades(eLocalidad listaLocalidades[], int tamLocalidades)
{
    int able = 0;

    for(int i=0; i<tamLocalidades; i++)
    {
        if(listaLocalidades[i].isEmpty != 1)
        {
            listaLocalidades[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
            able = 1;
        }
    }

    return able;
}

int cargarNombreApellidoCliente(eCliente listaClientes[], int tamClientes, int idCliente, char nombreCliente[], char apellidoCliente[])
{
    int able = 0;

    for(int i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].codigo == idCliente && listaClientes[i].isEmpty == 0)
        {
            strcpy(nombreCliente, listaClientes[i].nombre);
            strcpy(apellidoCliente, listaClientes[i].apellido);
            able = 1;
        }
    }

    return able;
}

int catNameLastName(char name[], char lastName[], char nameLastName[])
{
    int able = 0;

    if(strlen(name) < 51)
    {
        strcpy(nameLastName, name);
    }

    if(strlen(lastName) < 51)
    {
        strcat(nameLastName, " ");
        strcat(nameLastName, lastName);
        able = 1;
    }

    return able;
}
