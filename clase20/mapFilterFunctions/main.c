#include <stdio.h>
#include <stdlib.h>
#include "Dominio.h"
#include "Controller.h"
#include "lisba_utn.h"

int main()
{
    LinkedList* listaDominios = ll_newLinkedList();
    LinkedList* listaDominiosConTipo = NULL;
    LinkedList* listaDominiosAuto = NULL;
    LinkedList* listaDominiosMoto = NULL;
    char respuesta = 'n';
    int datosCargadosConTipo = 0;
    char NombreArchivo[30];

    do
    {
        switch( menu() )
        {
        case 1:
            if( listaDominios != NULL )
            {
                getString(NombreArchivo, "\nINGRESE EL NOMBRE DEL ARCHIVO A ABRIR: ", "ERROR! MAXIMO 29 CARACTERES! ", 1, 29);
                if( controller_loadFromText(NombreArchivo, listaDominios) )
                {
                    printf("\nDATOS CARGADOS CORRECTAMENTE!\n\n");
                }
                else
                {
                    printf("\n\nNO SE PUDO CARGAR EL ARCHIVO!\n\n");
                }
            }
            else
            {
                printf("\n\nNO SE PUDO CARGAR EL ARCHIVO YA QUE LA LISTA ES NULL!\n\n");
            }
            system("pause");
            break;
        case 2:
            if( !ll_isEmpty(listaDominios) )
            {
                controller_ListDominio(listaDominios);
            }
            else
            {
                printf("\nNO SE PUDO MOSTRAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 3:
            if( !ll_isEmpty(listaDominios) )
            {
                controller_sortDominio(listaDominios);
            }
            else
            {
                printf("\nNO SE PUDO ORDENAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 4:
            if( !ll_isEmpty(listaDominios) )
            {
                listaDominiosConTipo = ll_map( listaDominios, clasificarCampoTipo );
                printf("\nDATOS MODIFICADOS CORRECTAMENTE!\n\n");
                datosCargadosConTipo = 1;
            }
            else
            {
                printf("\nNO SE PUDO MODIFICAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 5:
            if( !ll_isEmpty(listaDominiosConTipo) &&  datosCargadosConTipo)
            {
                listaDominiosMoto = ll_filter(listaDominiosConTipo, filtrarCampoTipo, 'M');
                listaDominiosAuto = ll_filter(listaDominiosConTipo, filtrarCampoTipo, 'A');
                printf("\nDATOS MODIFICADOS CORRECTAMENTE!\n\n");

                if( controller_saveAsText("moto.csv", listaDominiosMoto) )
                   {
                        printf("ARCHIVO DE MOTOS GUARDADO!\n\n");
                   }
                else
                {
                    printf("NO SE PUDO GUARDAR EL ARCHIVO DE MOTOS!\n\n");
                }

                if( controller_saveAsText("auto.csv", listaDominiosAuto) )
                   {
                       printf("ARCHIVO DE AUTOS GUARDADO!\n\n");
                   }
                   else
                   {
                       printf("NO SE PUDO GUARDAR EL ARCHIVO DE AUTOS!\n\n");
                   }
            }
            else
            {
                printf("\nNO HAY LISTA GENERADA CON TIPOS CARGADOS!\n\n");
            }
            system("pause");
            break;
        case 6:
            if( !ll_isEmpty(listaDominiosConTipo) && datosCargadosConTipo )
            {
                if( controller_saveAsText("datosConTipo.csv", listaDominiosConTipo) )
                {
                    printf("\nDATOS CARGADOS CORRECTAMENTE!\n\n");
                }
            }
            else
            {
                printf("\nNO SE PUDO GUARDAR EL ARCHIVO!\n\n");
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
