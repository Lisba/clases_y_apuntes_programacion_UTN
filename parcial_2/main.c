#include <stdio.h>
#include <stdlib.h>
#include "Cachorros.h"
#include "Controller.h"
#include "lisba_utn.h"
#include "LinkedList.h"

int main()
{
    LinkedList* listaCachorros = NULL;
    LinkedList* listaCachorrosMenores45Dias = NULL;
    LinkedList* listaMachos = NULL;
    LinkedList* ListaCallejeros = NULL;
    char respuesta = 'n';
    char NombreArchivo[30];
    int sortOption;

    do
    {
        switch( menu() )
        {
        case 1:
            listaCachorros = ll_newLinkedList();
            if( listaCachorros != NULL )
            {
                getString(NombreArchivo, "\nINGRESE EL NOMBRE DEL ARCHIVO A ABRIR: ", "ERROR! MAXIMO 29 CARACTERES! ", 1, 29);
                if( controller_loadFromText(NombreArchivo, listaCachorros) )
                {
                    printf("\nDATOS CARGADOS CORRECTAMENTE!\n\n");
                }
                else
                {
                    printf("\nNO SE PUDO CARGAR EL ARCHIVO!\n\n");
                }
            }
            else
            {
                printf("\n\nNO SE PUDO CARGAR EL ARCHIVO YA QUE LA LISTA ES NULL!\n\n");
            }
            system("pause");
            break;
        case 2:
            if( !ll_isEmpty(listaCachorros) )
            {
                controller_ListCachorros(listaCachorros);
            }
            else
            {
                printf("\nNO SE PUDO MOSTRAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 3:
            if( !ll_isEmpty(listaCachorros) )
            {
                listaCachorrosMenores45Dias = ll_filter(listaCachorros, filtrarMenores45);

                controller_ListCachorros(listaCachorrosMenores45Dias);

                if( controller_saveAsText("45dias.csv", listaCachorrosMenores45Dias) )
                   {
                        printf("ARCHIVO DE CACHORROS MENORES A 45 DIAS GUARDADO!\n\n");
                   }
                else
                {
                    printf("NO SE PUDO GUARDAR EL ARCHIVO DE CACHORROS MENORES A 45 DIAS!\n\n");
                }
            }
            else
            {
                printf("\nNO SE PUDO GENERAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 4:
            if( !ll_isEmpty(listaCachorros) )
            {
                listaMachos = ll_filter(listaCachorros, filtrarMachos);

                controller_ListCachorros(listaMachos);

                if( controller_saveAsText("machos.csv", listaMachos) )
                   {
                        printf("ARCHIVO DE CACHORROS MACHOS GUARDADO!\n\n");
                   }
                else
                {
                    printf("NO SE PUDO GUARDAR EL ARCHIVO DE CACHORROS MACHOS!\n\n");
                }
            }
            else
            {
                printf("\nNO SE PUDO GENERAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 5:
            if( !ll_isEmpty(listaCachorros) )
            {
                ListaCallejeros = ll_filter(listaCachorros, filtrarCallejeros);

                controller_ListCachorros(ListaCallejeros);

                if( controller_saveAsText("callejeros.csv", ListaCallejeros) )
                   {
                        printf("ARCHIVO DE CACHORROS CALLEJEROS GUARDADO!\n\n");
                   }
                else
                {
                    printf("NO SE PUDO GUARDAR EL ARCHIVO DE CACHORROS CALLEJEROS!\n\n");
                }
            }
            else
            {
                printf("\nNO SE PUDO GENERAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 6:
            if( !ll_isEmpty(listaCachorros) )
            {
                getInt(&sortOption, "ASCENDENTE (1) O DESCENDENTE (0)?: ", "ERROR! ", 0, 1);
                if(sortOption)
                {
                    ll_sort(listaCachorros, ordenarListaPorId, 1);
                }
                else
                {
                    ll_sort(listaCachorros, ordenarListaPorId , 0);
                }
                printf("\nLA LISTA HA SIDO ORDENADA!\n\n");
            }
            else
            {
                printf("\nNO SE PUDO ORDENAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 7:
            getChar(&respuesta, "\nSEGURO QUE DESEA SALIR? (s/n): ", "\nOPCION INVALIDA! \n", 'n', 's');
            break;
        default:
            printf("\nOPCION INVALIDA!!!\n\n");
            break;
        }

    }while(respuesta != 's');

    return 0;
}
