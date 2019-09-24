#include "Alumno.h"

int buscarLibre(eAlumno listadoDeAlumnos[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


int hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam, int lastId)
{
    int i;

    float promedio[]= {6.66, 4,7.66};
    char nombre[][25]= {"Juan","Maria josefina","Maria"};
    int carrera[]={1,2,1};

    for(i=0; i<3; i++)
    {
        listadoDeAlumnos[i].legajo = lastId;
        listadoDeAlumnos[i].promedio = promedio[i];
        strcpy(listadoDeAlumnos[i].nombre, nombre[i]);
        listadoDeAlumnos[i].idCarrera=carrera[i];
        listadoDeAlumnos[i].estado = OCUPADO;

        lastId++;
    }
    return lastId;
}

void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            mostrarUnAlumno(listadoDeAlumnos[i]);
        }

    }
}

int cargarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam, int lastId, eCarrera listaCarreras[], int tc)
{
    int i;
    int indice;
    int respuesta = 0;

    indice = buscarLibre(listadoDeAlumnos, tam);

    if(indice!=-1)
    {
        //hay lugar
        listadoDeAlumnos[indice] = cargarAlumno(listaCarreras,tc);
        listadoDeAlumnos[indice].legajo = lastId;
        respuesta = 1;
    }

    return respuesta;
}

void mostrarCarreras(eCarrera listaCarreras[],int cant)
{
   int i;

    for(i=0; i<cant; i++)
    {
        printf("%d--%s\n", listaCarreras[i].idCarrera, listaCarreras[i].nombre);

    }
}

eAlumno cargarAlumno(eCarrera listaCarreras[], int tam)
{
    eAlumno miAlumno;


    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", miAlumno.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &miAlumno.promedio);
    mostrarCarreras(listaCarreras, tam);
    printf("Ingrese carrera: ");
    scanf("%d", &miAlumno.idCarrera);




    miAlumno.estado = OCUPADO;

    return miAlumno;
}

void mostrarListadoAlumnosConCarrera(eAlumno listaAlumnos[], int ta, eCarrera listaCarreras[], int tc)
{
    int i;
    int j;
    for(i=0; i<ta; i++)
    {
        if(listaAlumnos[i].estado==OCUPADO)
        {
            printf("%d %s %f ", listaAlumnos[i].legajo,
                           listaAlumnos[i].nombre,
                           listaAlumnos[i].promedio);


        for(j=0; j<tc; j++)
        {
            if(listaAlumnos[i].idCarrera==listaCarreras[j].idCarrera)
            {
                printf("%s\n", listaCarreras[j].nombre);
                break;
            }
        }
        }

    }
}


void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%04d %25s %8.2f \n",miAlumno.legajo,miAlumno.nombre, miAlumno.promedio);
}

void sortStudentsByNameAndAverage(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)>0)
            {
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }

            else
            {
                if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)==0)
                {
                    if(listadoDeAlumnos[i].promedio>listadoDeAlumnos[j].promedio)
                    {
                        auxAlumno = listadoDeAlumnos[i];
                        listadoDeAlumnos[i] = listadoDeAlumnos[j];
                        listadoDeAlumnos[j] = auxAlumno;
                    }
                }
            }
        }

    }
}


int buscarAlumnoPorLegajo(eAlumno* listaDeAlumnos, int cant, int legajo)
{
    int i;
    int retorno = -1;


    if(listaDeAlumnos!=NULL && cant>0)
    {

        for(i=0; i<cant; i++)
        {
            if(listaDeAlumnos[i].legajo==legajo && listaDeAlumnos[i].estado==OCUPADO)
            {
                retorno = i;
                break;
            }
        }
    }


    return retorno;
}

int modificarAlumno(eAlumno listaDeAlumnos[], int cant, int legajo)
{
    int index;
    char nombre[30];
    int quePaso = -1;
    char respuesta;
    eAlumno aux;

    index = buscarAlumnoPorLegajo(listaDeAlumnos,cant, legajo);
    if(index!=-1)
    {
        aux = listaDeAlumnos[index];
        mostrarUnAlumno(aux);
        printf("Ingrese el nuevo nombre: ");
        fflush(stdin);
        gets(aux.nombre);
        printf("Esta seguro que desea modificar este alumno? :");
        respuesta = getche();
        if(respuesta=='s')
        {
            listaDeAlumnos[index] = aux;
            quePaso = 1;
        }
        else
        {
            quePaso = 0;
        }

    }
    return quePaso;
}
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tam)
{
    int legajo;
    int i;
    int flag = 0 ;
    char respuesta;

    int quePaso = -1;

    mostrarListadoAlumnos(listadoDeAlumnos,tam);

    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].legajo==legajo && listadoDeAlumnos[i].estado==OCUPADO)
        {
            mostrarUnAlumno(listadoDeAlumnos[i]);
            printf("Esta seguro que desea eliminar este alumno? :");
            respuesta = getche();
            if(respuesta=='s')
            {
                listadoDeAlumnos[i].estado = LIBRE;
                quePaso = 1;
            }
            else
            {
                quePaso = 0;
            }
            break;
        }

    }

    return quePaso;

}


