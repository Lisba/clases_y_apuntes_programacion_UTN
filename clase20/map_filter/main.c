#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList* ll_map(LinkedList* this, void* (*pFunc)(void* pElement) );

int main()
{



    return 0;
}

LinkedList* ll_map(LinkedList* this, void*(*pFunc)(void* pElement) )
{
    int tam;
    LinkedList* newLinkedList = NULL;
    void* element;

    if(this != NULL)
    {
        tam = ll_len(this);
        newLinkedList = ll_newLinkedList();

        for(int i=0; i<tam; i++)
        {
            element = ll_get(this, i);
            ll_add(newLinkedList, pFunc(element) );
        }
    }

    return newLinkedList;
}
