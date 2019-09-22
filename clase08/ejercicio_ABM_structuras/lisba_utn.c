#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lisba_utn.h"

/** \brief Solicita un número al usuario y devuelve dicho número.
 *
 * \param void No recibe parametros.
 * \return float El número ingresado por el usuario.
 *
 */
float getFloat(char message[])
{
    float number;
    int validation;

    do
    {
        fflush(stdin); // Limpieza del buffer de entrada ya que en caso de ingresar un caracter no válido quedará enter en memoria e iterará infinitamente.
        printf("\n======================\n");
        printf("%s", message);
        validation = scanf("%f", &number); //Validación para números, en caso de ingresar un caracter distinto a un número la variable validation valdrá 0.

        if(!validation) // Si la variable validation vale 0 se muestra el mensaje de error.
        {
            printf("\n%cERROR! DEBE INGRESAR UN N%cMERO.\n", 173, 233);
        }

    }while(!validation); // Si la variable validation es 0 se repite el ciclo hasta que validation sea distinta de 0, es decir, hasta ingresr un número.

    return number;
}

/** \brief
 *
 * \param input int* Direccion de memoria de la variable a guardar el entero.
 * \param message[] char Cadena de caracter a mostrar como mensaje.
 * \param eMessage[] char Cadena de caracteres a mostrar como mensaje de error.
 * \param lowLimit int entero mas bajo permitido.
 * \param higLimit int entero mas alto permitido.
 * \return int 0 o -1
 *
 */
int getInt(int* input, char message[], char eMessage[], int lowLimit, int higLimit)
{
    int response;
    int aux;
    int flag;

    do
    {
        fflush(stdin);
        printf("\n======================\n");
        printf("%s: ", message);
        response = scanf("%d", &aux); //Validación para enteros, en caso de ingresar un caracter distinto a un entero la variable response valdrá 0.

        if(!response || aux<lowLimit || aux>higLimit) // Si la variable response vale -1 ó aux es menor a lowLimit o mayor a higLimit se muestra el mensaje de error.
        {
            printf("%s\n", eMessage);
            flag = -1;
        }else
        {
            flag = 0;
        }

    }while(!flag); // Si la variable flag vale -1 se repite el ciclo hasta que flag sea distinta de -1, es decir, hasta ingresr un número válido.

    *input = aux;

    return response;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int ret;
    int num;
    while(reintentos>0)
    {
        printf(mensaje);
        if(scanf("%d",&num)==1)
        {
            if(num<=maximo && num>=minimo)
            break;
        }

        fflush(stdin); //EN LINUX UTILIZAR __fpurge(stdin)
        reintentos--;
        printf(mensajeError);
    }

    if(reintentos==0)
    {
        ret=-1;
    }
    else
    {
        ret=0;
        *pResultado = num;
    }

    return ret;
}

/** \brief Caclula la suma entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la suma de ambos números.
 *
 */
float add(float number1, float number2)
{
    float result;

    result = number1 + number2; // Cálculo de la suma de ambos números recibidos como parámetros.

    return result;
}

/** \brief Caclula la resta entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la resta de ambos números.
 *
 */
float subtract(float number1, float number2)
{
    float result;

    result = number1 - number2; // Cálculo de la resta del primer número menos el segundo número recibido como parámetro.

    return result;
}

/** \brief Caclula la división entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la división entre ambos números.
 *
 */
float divide(float number1, float number2)
{
    float result;

    if(number2 == 0)
    {
        result = 0.00;
    }else
    {
        result = number1 / number2; // Cálculo de la división entre ambos números recibidos como parámetros.
    }

    return result;
}

/** \brief Caclula la multiplicación entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la multiplicación entre ambos números.
 *
 */
float multiply(float number1, float number2)
{
    float result;

    result = number1 * number2; // Calculo del producto de ambos números recibidos como parámetros.

    return result;
}

/** \brief Caclula el factorial de un número.
 *
 * \param number float Operando a calcular.
 * \return long El factorial del número.
 *
 */
long int factorial(float number) //Recibe un flotante pero toma en cuenta solo la parte entera del número y calcula su factorial.
{
    long int result=1;
    int i;

    for(i=number; i>=1; i--) //Iteración para calcular el producto del número recibido como parámetro por cada uno de sus números naturales inferiores hasta 1 (en forma decreciente).
    {
        result *= i;
    }

    return result;
}

void pedirAlumno(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo[i]);

        printf("Ingrese la edad: ");
        scanf("%d", &edad[i]);

        printf("Ingrese el sexo: ");
        fflush(stdin);
        scanf("%c", &sexo[i]);

        printf("Ingrese la nota1: ");
        scanf("%d", &nota1[i]);

        printf("Ingrese la nota2: ");
        scanf("%d", &nota2[i]);

        promedio[i] = (float) (nota1[i] + nota2[i]) / 2;
    }
}

void mostrarUnAlumno(int legajo, int edad, char sexo, int nota1, int nota2, float promedio)
{
     printf("%d\t%d\t%c\t%d\t%d\t%.3f\n", legajo, edad, sexo, nota1, nota2, promedio);
}

void mostrarAlumnos(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{
    printf("\nleg:\tedad:\tsexo:\tn1:\tn2:\tpromedio:\n\n");
    for(int i=0; i<tam; i++)
    {
        mostrarUnAlumno(legajo[i], edad[i], sexo[i], nota1[i], nota2[i], promedio[i]);
    }

}

void ordenarAlumnos(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{

    int auxInt;
    char auxChar;
    float auxFloat;
    int swap = 0;

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(sexo[i] > sexo[j])
            {
                swap = 1;

            } else if (sexo[i] == sexo[j] && legajo[i] > legajo[j])
            {
                swap = 1;
            }

            if (swap == 1)
            {

                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxInt = edad[i];
                edad[i] = edad[j];
                edad[j] = auxInt;

                auxChar = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxChar;

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;

                auxInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxInt;

                auxFloat = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxFloat;

                swap = 0;
            }
        }
    }
}

/** \brief
 *
 * \param nombreApellido[] char Vector donde se guardará el nombre y apellido.
 * \return void No retorna ya que recibe la variable por referencia (modifica la original).
 *
 */
void getNombreApellido(char nombreApellido[])
{
    char nombre[23];
    char apellido[11];
    char aux[50];

    do
    {
        printf("Ingrese nombre: ");
        gets(aux);

        if(strlen(aux) > 10)
        {
            printf("ERROR. Ingrese un nombre de 10 caracteres o menos: ");
            gets(aux);
        }
    } while (strlen(aux) > 10);

    strcpy(nombre, aux);

    do
    {
        printf("Ingrese apellido: ");
        gets(aux);

        if(strlen(aux) > 10)
        {
            printf("ERROR! Ingrese un apellido de 10 caracteres o menos: ");
            gets(aux);
        }
    } while (strlen(aux) > 10);

    strcpy(apellido, aux);

    strcpy(nombreApellido, nombre);
    strcat(nombreApellido, ", ");
    strcat(nombreApellido, apellido);
}
