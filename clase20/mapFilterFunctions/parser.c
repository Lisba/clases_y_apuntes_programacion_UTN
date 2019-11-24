#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Dominio.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListDominio LinkedList*
 * \return int
 *
 */
int parser_DominioFromText(FILE* pFile , LinkedList* pArrayListDominio)
{
    char buffer[3][10];
    int cant;
    eDominio* dominio;
    int able = 0;

    if(pFile != NULL && pArrayListDominio != NULL)
    {
        while( !feof(pFile) )
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2]);
            if(cant < 3)
            {
                break;
            }
            else
            {
                dominio = dominio_newParametros(buffer[0], buffer[1], buffer[2]);
                dominio_setTipo(dominio, '0');

                if(dominio != NULL && validateDominio(dominio))
                {
                    ll_add(pArrayListDominio, dominio);
                    able = 1;
                }
            }
        }
    }

    return able;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListDominio LinkedList*
 * \return int
 *
 */
int parser_DominioFromBinary(FILE* pFile , LinkedList* pArrayListDominio)
{
    int able = 0;
    int cant = 0;
    eDominio* dominio;

    if(pFile != NULL && pArrayListDominio != NULL)
    {
        while( !feof(pFile) )
        {
            dominio = dominio_new();
            if( dominio == NULL )
            {
                break;
            }

            cant = fread(dominio, sizeof(eDominio), 1, pFile);

            dominio_setId(dominio, dominio->id);

            if( validateDominio(dominio) == 1 )
            {
                ll_add(pArrayListDominio, dominio);
                able = 1;
            }
            else
            {
                dominio_delete(dominio);
            }

            if(cant < 1)
            {
                if( !feof(pFile) )
                {
                    break;
                }
                else
                {
                    able = 0;
                    break;
                }
            }
        }
    }

    return able;
}
