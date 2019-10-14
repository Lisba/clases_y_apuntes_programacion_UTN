#include <stdio.h>
#include <stdlib.h>
#include "lisba_utn.h"

int main()
{
    char telefono[16];

    getPhone(telefono, "Ingrese su telefono: ", "Error. ", 8, 15);

    printf("%s", telefono);

    return 0;
}
