#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Dominio.h"
#include "parser.h"
#include "lisba_utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListDominio LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListDominio)
{
    int able = 0;
    FILE* f = NULL;

    if( path != NULL && pArrayListDominio != NULL )
    {
        f = fopen(path, "r");

        if( f != NULL )
        {
            parser_DominioFromText(f, pArrayListDominio);
            fclose(f);
            able = 1;
        }
        else
        {
            printf("\nNO SE PUDO ABRIR EL ARCHIVO DE TEXTO.\n\n");
            system("pause");
        }
    }

    return able;
}

/** \brief Listar dominios
 *
 * \param path char*
 * \param pArrayListDominio LinkedList*
 * \return int
 *
 */
int controller_ListDominio(LinkedList* pArrayListDominio)
{
    int able = 0;

    if( printDominios(pArrayListDominio) )
    {
        able = 1;
    }

    return able;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListDominio LinkedList*
 * \return int
 *
 */
int controller_sortDominio(LinkedList* pArrayListDominio)
{
    int able = 0;
    int opcion;

    if(pArrayListDominio != NULL)
    {
        system("cls");
        printf("\nCOMO DESEA ORDENAR LA LISTA?\n\n");
        printf("1) ASCENDENTE\n");
        printf("2) DESCENDENTE\n");
        printf("3) SALIR\n\n");

        getInt(&opcion, "INGRESE OPCION: ", "ERROR. OPCION INVALIDA! ", 1, 3);

        switch(opcion)
        {
        case 1:
            printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
            if( ( ll_sort(pArrayListDominio, ordenarPorId, 1) ) == 0 )
            {
                printf("\nSE ORDENO CORRECTAMENTE!\n\n");
            }
            else
            {
                printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
            }
            break;

        case 2:
            printf("\nESPERE MIENTRAS SE ORDENA LA LINKEDLIST...\n");
            if( ( ll_sort(pArrayListDominio, ordenarPorId, 0) ) == 0 )
            {
                printf("\nSE ORDENO CORRECTAMENTE!\n\n");
            }
            else
            {
                printf("\nNO SE PUDO ORDENAR LA LINKEDLIST!\n\n");
            }
            break;

        case 3:
            printf("\nSE CANCELO LA OPERACION!\n\n");
            break;

        default:
            printf("OPCION INVALIDA!\n");
            break;
        }
    }

    return able;
}

/** \brief Guarda los datos de los dominios en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListDominio LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListDominio)
{
    int able = 0;
    int tam = 0;
    int contador = 0;
    int id;
    char dominio[7];
    int anio;
    char tipo;
    FILE* f = NULL;
    eDominio* dominioInstancia = NULL;

    if( path != NULL && pArrayListDominio != NULL )
    {
        tam = ll_len(pArrayListDominio);
        f = fopen(path, "w");

        if( f != NULL )
        {
            fprintf(f, "id,dominio,anio,tipo\n");
            for(int i=0; i<tam; i++)
            {
                dominioInstancia = (eDominio*) ll_get(pArrayListDominio, i);

                dominio_getId(dominioInstancia, &id);
                dominio_getDominio(dominioInstancia, dominio);
                dominio_getAnio(dominioInstancia, &anio);
                dominio_getTipo(dominioInstancia, &tipo);

                fprintf(f, "%d,%s,%d,%c\n", id, dominio, anio, tipo);
                contador++;
            }

            fclose(f);

            if( contador == tam )
            {
                able = 1;
            }

        }
        else
        {
            printf("\nOCURRIO UN ERROR!\n\n");
        }
    }

    return able;
}
