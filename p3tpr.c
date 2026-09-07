#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMA 50

void cargarArregloManual(int arreglo[], int cantidad);
void cargarArregloAleatorio(int arreglo[], int cantidad);
int esPrimo(int n);
int mayorPrimo(int arreglo[], int cantidad);
int maxNumPares(int arreglo[], int cantidad);
//void ordenarDescendente(int arreglo[], int cantidad);
//void mostrarEnPantalla(int arreglo[], int cantidad);

int main()
{
    int arreglo[TAMA];
    int cantidad, opcion, primo, mayorP, n, maxPares;
    printf("\nIngrese la cantidad de elementos que tendra su arreglo: ");
    scanf("%d", &cantidad);
    srand(time(NULL));
    if (cantidad >= 1 && cantidad <= TAMA)
    {
        printf("\nComo desea cargar el arreglo?");
        printf("\n0= Manualmente \n1= Aleatoriamente.");
        scanf("%d", &opcion);
        if (opcion == 0)
        {
            printf("\nIngrese las %d componentes del arreglo", cantidad);
            cargarArregloManual(arreglo, cantidad);
        }
        else if (opcion == 1)
        {
            cargarArregloAleatorio(arreglo, cantidad);
        }
        else
        {
            printf("\nIngrese una opcion valida");
        }
    }
    else
    {
        printf("\nIngrese una cantidad valida");
        printf("\nIngrese la cantidad de elementos que tendra su arreglo: ");
        scanf("%d", &cantidad);
    }
    printf("\nArreglo: ");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%d ", arreglo[i]);
    }

    mayorP = mayorPrimo(arreglo, cantidad);

    maxPares = maxNumPares(arreglo, cantidad);
    printf("\nMaximos pares: %d", maxPares);
    //ordenarDescendente(arreglo, cantidad);
    return 0;
}

// FUNCIONES
void cargarArregloManual(int arreglo[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nIngrese la componente %d del arreglo: ", i + 1);
        scanf("%d", &arreglo[i]);
    }
}

void cargarArregloAleatorio(int arreglo[], int cantidad)
{
    printf("Arreglo cargando aleatoriamente: ");
    for (int i = 0; i < cantidad; i++)
    {
        arreglo[i] = rand() % 101;
    }
}

int esPrimo(int n)
{
    int esPrimo = 0;
    if (n <= 1)
    {
        esPrimo = 0;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                esPrimo = 0;
            }
            else
            {
                esPrimo = 1;
            }
        }
    }
    return esPrimo;
}

int mayorPrimo(int arreglo[], int cantidad)
{
    int mayor = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (esPrimo(arreglo[i]) == 1)
        {
            if (arreglo[i] > mayor)
            {
                mayor = arreglo[i];
            }
        }
    }
    return mayor;
}

int maxNumPares(int arreglo[], int cantidad)
{
    int anterior, max = 0;
    for(int i = 0; i<cantidad; i++){
        if((arreglo[i] %2 == 0) && (arreglo[i+1] %2 == 0)){
            max = max + 1;
        }else{
            max = 0;
        }
    }
    return max;
}
