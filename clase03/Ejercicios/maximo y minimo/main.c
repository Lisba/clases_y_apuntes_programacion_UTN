#include <stdio.h>
#include <stdlib.h>

int getMax (int a, int b, int c);

int main()
{
    int a;
    int b;
    int c;

    printf("Ingrese primer valor: ");
    scanf("%d", &a);

    printf("Ingrese segundo valor: ");
    scanf("%d", &b);

    printf("Ingrese tercer valor: ");
    scanf("%d", &c);

    printf("\nThe Max Number is: %d\n", getMax (a, b, c));

    return 0;
}

int getMax (int a, int b, int c)
{
    int max = a;

    if (a < b)
    {
        max = b;

    } else if (a < c)
    {
        max = c;
    }

    return max;
}
