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
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int iniciarClientes(eCliente listaClientes[], int tamClientes)
{
    int able = -1;

    for(int i=0; i<tamClientes; i++)
    {
        listaClientes[i].isEmpty = 1; // Asigna 1 al campo isEmpty de todas las posiciones del array para inicializarlo.
        able = 0;
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
            break; // Corto la ejecucion del bucle ya que de lo contrario la variable i tomará el valor de la ultima posicion disponible encontrada y deseo la primera posicion disponible.
        }
    }

    return index;
}

int altaCliente(eCliente listaClientes[], int tamClientes, int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[])
{
    int able = 0;
    int index;

    index = findFreePositionClientes(listaClientes, tamClientes); // Obtengo -1 si el arraya de estructuras esta lleno o el indice de la primera posicion disponible.

    if( index == -1 )
    {
        printf("\nNo hay mas espacio para agregar.\n");
    }
    else
    {
        listaClientes[index] = nuevoCliente(codigo, nombre, apellido, sexo, telefono, domicilio); // Almaceno los datos del nuevo empleado en la primera posicion disponible del array de estructuras.
        printf("\nALTA EXITOSA\n\n");
        able = 1;
    }

    return able;
}

eCliente nuevoCliente(int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio[])
{
    eCliente nuevoCliente;

    nuevoCliente.codigo = codigo;
    strcpy(nuevoCliente.nombre, nombre);
    strcpy(nuevoCliente.apellido, apellido);
    nuevoCliente.sexo = sexo;
    strcpy(nuevoCliente.telefono, telefono);
    strcpy(nuevoCliente.domicilio, domicilio);
    nuevoCliente.isEmpty = 0;

    return nuevoCliente;
}

int cargarCliente(eCliente listaClientes[], int tamClientes, int lastId)
{
    int able = 0;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];

    system("cls");

    printf("****** Alta de Cliente *******\n\n");

    getString(nombre, "Ingrese el nombre: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
    getString(apellido, "Ingrese el apellido: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
    getChar(&sexo, "Ingrese el sexo: ", "Error. ", 'f', 'm');
    getPhone(telefono, "Ingrese el telefono: ", "Error, debe ingresar al menos 8 numeros. ", 7, 15);
    getString(domicilio, "Ingrese el domicilio: ", "Error. ", 1, 51);

    able = altaCliente(listaClientes, tamClientes, lastId, nombre, apellido, sexo, telefono, domicilio); // Carga los datos solicitados al array de estructuras y devuelve true si fue capaz de hacerlo.

    return able;
}

int eliminarCliente(eCliente listaClientes[], int tamClientes, int codigo)
{
    int able = -1;
    char option;
    int flag=0;

    for(int i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].codigo == codigo && listaClientes[i].isEmpty == 0)
        {
            printf(" CODIGO    NOMBRE    APELLIDO      SEXO     TELEFONO      DOMICILIO\n");
            imprimirCliente(listaClientes[i]);

            printf("\nEsta seguro de eliminar a este empleado? (s/n)");
            fflush(stdin);
            option = getch();

            if(option == 's')
            {
                listaClientes[i].isEmpty = 1;
                printf("\n\nBAJA EXITOSA!\n\n");
                able = 0;
            }
            flag = 1; // flag para indicar que se encontro un usuario con dicho ID independientemente de si se remueve o no.
            break;
        }
    }

    if( able == -1 && flag == 0)
    {
        printf("\nNo se encontro ningun cliente con ese ID.\n\n");
    }

    return able;
}

void imprimirClientes(eCliente listaClientes[], int tamClientes)
{
    system("cls");
    printf("****** Lista de Empleados *******\n\n");
    printf(" CODIGO    NOMBRE    APELLIDO      SEXO     TELEFONO      DOMICILIO\n");

    for(int i=0; i<tamClientes; i++)
    {
        if(listaClientes[i].isEmpty == 0)
        {
            imprimirCliente(listaClientes[i]);
        }
    }
    system("pause");
}

void imprimirCliente(eCliente cliente)
{
    printf("%5d %11s %11s %7c %16s %14s\n", cliente.codigo, cliente.nombre, cliente.apellido, cliente.sexo, cliente.telefono, cliente.domicilio);

}

int ordenarClientes(eCliente listaClientes[], int tamClientes, int orden)
{
    int able = 0;

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

int modificarCliente(eCliente listaClientes[], int tamClientes)
{
    int codigo;
    int option;
    char telefono[21];
    int index;
    int able=0;

        system("cls");

        printf("****** Modificar Cliente *******\n\n");

        fflush(stdin);
        getInt(&codigo, "Ingrese el Codigo del Cliente a modificar: ", "Error, ingrese un Codigo entre 100 y 999. ", 100, 999);

        index = buscarClientePorCodigo(listaClientes, tamClientes, codigo);

            if(index == -1)
            {
                printf("\nNo se encontro ningun cliente con ese codigo.\n\n");
            }
            else
            {
                able = 1;

                printf("\n");
                printf(" CODIGO    NOMBRE    APELLIDO      SEXO     TELEFONO      DOMICILIO\n");
                imprimirCliente(listaClientes[index]);

                printf("\nQue desea modificar de este cliente?\n");
                printf("\n1) Nombre\n");
                printf("2) Domicilio\n");
                printf("3) Telefono\n");
                printf("4) Salir\n\n");

                printf("Seleccione una opcion: ");
                scanf("%d", &option);


                switch(option)
                {
                case 1:
                    getString(listaClientes[index].nombre, "\nIngrese el nuevo nombre: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
                    printf("\nNombre modificado!\n\n");
                    break;
                case 2:
                    getString(listaClientes[index].domicilio, "\nIngrese el nuevo domicilio: ", "Error, debe contener entre 2 y 50 caracteres. ", 2, 51);
                    printf("\nApellido modificado!\n\n");
                    break;
                case 3:
                    getPhone(telefono, "Ingrese el nuevo telefono: ", "Error. ", 7, 15);
                    printf("\nTelefono modificado!\n\n");
                    strcpy(listaClientes[index].telefono, telefono);
                    break;
                case 4:
                    printf("\nSe ha cancelado la modificacion!\n\n");
                    break;
                default:
                    printf("\nOpcion no valida!\n\n");
                    break;
                }
            }

    return able;
}

int hardCodearClientes(eCliente listaclientes[], int cantClientesHardcodear, int codigo)
{
    int i;

    char nombre[][51] = {"Lisbaldy", "Jesus", "Keimarly", "Daniela"};
    char apellido[][51] = {"Ojeda", "Leon", "Cisneros", "Sanchez"};
    char sexo[] = {'m', 'm', 'f', 'f'};
    char telefono[][21] = {"15-3030-7105", "15-4293-4856", "15-8473-9456", "15-7845-9036"};
    char domicilio[][51] = {"Palermo CABA", "Avellaneda", "Tigre", "Olivos"};
    int isEmpty[] = {0, 0, 0, 0};

    for(i=0; i<cantClientesHardcodear; i++)
    {
        listaclientes[i].codigo = codigo;
        strcpy(listaclientes[i].nombre, nombre[i]);
        strcpy(listaclientes[i].apellido, apellido[i]);
        listaclientes[i].sexo = sexo[i];
        strcpy(listaclientes[i].telefono, telefono[i]);
        strcpy(listaclientes[i].domicilio, domicilio[i]);
        listaclientes[i].isEmpty = isEmpty[i];

        codigo++;
    }
    return codigo;
}
