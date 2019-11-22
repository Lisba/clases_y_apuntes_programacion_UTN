#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arrayP[4] = {NULL, NULL, NULL, NULL};
    int arrayInt[4] = {2,3,4,8};

    int bool = arrayP[1] == *(arrayP+1); //TRUE

    *(arrayP+1) = arrayInt+3; // == arrayP[1] = &arrayInt[3];

    printf("%d\n\n", **(arrayP+1) ); // 8

    printf("%p\n\n", *(arrayP+1) ); // 0060FEE8 esto es: &arrayInt[3]

    **(arrayP+1) = 5; // == arrayInt[3] = 5;

    printf("%d\n\n", *(arrayInt+3) ); // 5
    printf("%d\n\n", arrayInt[3] ); // 5

    printf("%d", bool); // 1
    return 0;
}
