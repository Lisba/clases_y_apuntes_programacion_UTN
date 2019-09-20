#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library_struct.h"
#define T 2

void menu(void)
{
    ePerson listaDePersonas[T];
    char option;

    do
    {

        printf("1) ALTA\n");
        printf("2) MODIFICAR\n");
        printf("3) BAJA\n");
        printf("4) MOSTRAR\n");
        printf("5) ORDENAR\n");
        printf("6) SALIR\n");

        fflush(stdin);
        printf("\nQUE DESEA HACER?: ");
        scanf("%c", &option);

        system("cls");

        switch(option)
        {
        case '1':
            addPersonsList(listaDePersonas, T);
            break;
        case '2':
            modifyPerson(listaDePersonas, T);
            break;
        case '3':
            erasePerson(listaDePersonas, T);
            break;
        case '4':
            showPersonList(listaDePersonas, T);
            break;
        case '5':
            sortPeopleByLastName(listaDePersonas, T);
            system("cls");
            printf("\n\nSE ORDENO LA AGENDA POR APELLIDO\n\n");
            system("pause");
            system("cls");
            break;
        }

    } while (option != '6');

}

ePerson addPerson (void)
{
    ePerson onePerson;

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s", onePerson.name);
    printf("Ingrese el apellido: ");
    fflush(stdin);
    scanf("%s", onePerson.lastName);
    printf("Ingrese el legajo: ");
    scanf("%d", &onePerson.file);

    printf("\n");

    onePerson.state = 1;

    return onePerson;
}

void addPersonsList(ePerson personList[], int lenght)
{
    for(int i=0; i<lenght; i++)
    {
        personList[i] = addPerson();
    }

    system("cls");

}

void showOnePerson(ePerson onePerson)
{
    printf("%2d %10s %10s\n", onePerson.file, onePerson.lastName, onePerson.name);
}

void showPersonList(ePerson personList[], int length)
{
    for(int i=0; i<length; i++)
    {
        if(personList[i].state != 0)
        {
            showOnePerson(personList[i]);
        }
    }

    system("pause");
    system("cls");
}

void sortPeopleByLastName(ePerson personList[], int lengh)
{
    ePerson aux;

    for(int i=0; i<lengh-1; i++)
    {
        for(int j=i+1; j<lengh; j++)
        {
            if( strcmp(personList[i].lastName, personList[j].lastName) > 0 )
            {
                aux = personList[i];
                personList[i] = personList[j];
                personList[j] = aux;

            }
        }
    }
}

void erasePerson(ePerson personList[], int length)
{
    int file;

    printf("Ingrese el legajo: ");
    scanf("%d", &file);

    for (int i=0; i<length; i++)
    {
        if(personList[i].file == file)
        {
            personList[i].state = 0;
        }

    }

    system("cls");

}

void modifyPerson (ePerson personList[], int length)
{
    int file;

    printf("INGRESE EL LEGAJO: ");
    scanf("%d", &file);

    for(int i=0; i<length; i++)
    {
        if(personList[i].file == file)
        {
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            fgets(personList[i].name, 20, stdin);
            printf("Ingrese el nuevo apellido: ");
            fflush(stdin);
            fgets(personList[i].lastName, 20, stdin);
        }

    }

    printf("\nEL LEGAJO NO EXISTE!!\n\n");

    system("pause");
    system("cls");
}
