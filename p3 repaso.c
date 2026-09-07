#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define TAMA 100; //tamaño del arreglo

//funciones
int esPrimo(int num);
int numeroMayor(int arreglo[], int n);
int numPares(int arreglo[], int n);
int ordenar(int arreglo[], int n);
int mostrarArreglo(int arreglo[], int n);

int main(){
    int n, i, opcion, mayprim;
    int arreglo[TAMA];

    srand(time(NULL));

    printf("Ingrese el tamaño del arreglo");
    scanf("%d", &n);

    printf("Seleccione el modo de carga");
    printf("\n 1. Manual \n 2. Automatica aleatoria");
    scanf("%d", opcion);

    if(opcion == 1){
        for(i=0; i<n; i++){
            printf("\n ingrese el valor %d ", i+1);
            scanf("%d", &arreglo[i]);
        }
    }else{
        for(i=0; i < n; i++){
            arreglo[i] = rand() %100;
        }
    }

    printf("\n Arreglo: ");
    mostrarArreglo(arreglo, n);

    
    

    

    return 0;
}

//C.a. determinar si un numero es primo
int esPrimo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}


//C.b.

int numeroMayor(int arreglo[], int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(esPrimo(arreglo[i]) && arreglo[i] > max){
            max = arreglo[i];
        }
    }

    return max;
}

//C.c
