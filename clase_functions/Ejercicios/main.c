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
    int max;

    if (a > b && a > c)
    {
        max = a;

    } else if (b > a && b > c)
    {
        max = b;

    } else if (c > a && c > b)
    {
        max = c;
    }

    return max;
}
