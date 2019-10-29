#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[30];
    float salario;
}eEmpleado;

void escribirBinaro(char* path);
void leerBinario(char* path);

int main()
{
    escribirBinaro("miArchivo.dat");
    leerBinario("miArchivo.dat");

    return 0;
}

void escribirBinaro(char* path)
{
    FILE* miArchivo;
    int len = 2;
    eEmpleado miEmpleado[2] = {{200, "Mario", 2000}, {100, "Pepe", 1000}};

    miArchivo = fopen(path, "wb");

    if(miArchivo != NULL)
    {
        fwrite(&len, sizeof(int), 1, miArchivo);

        for(int i=0; i<2; i++)
        {
            fwrite(miEmpleado+i, sizeof(eEmpleado), 1, miArchivo);
        }

        fclose(miArchivo);
    }
}

void leerBinario(char* path)
{
    eEmpleado miEmpleado[2];
    FILE* miArchivo;
    int len;

    miArchivo = fopen(path, "rb");
    fread(&len, sizeof(int), 1, miArchivo);
    printf("%d\n\n", len);

    if(miArchivo != NULL)
    {
        fread(miEmpleado, sizeof(eEmpleado), len, miArchivo);
        fclose(miArchivo);
    }

    for(int i=0; i<len; i++)
    {
        printf("%d %s %.2f\n", miEmpleado[i].legajo, miEmpleado[i].nombre, miEmpleado[i].salario);
    }
}
