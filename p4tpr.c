#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAMA 50

int validarEntrada(int n);
void cargarArreglo(int n, int arreglo[]);
void mostrarArreglo(int n, int arreglo[]);
void arregloAsc(int n, int arreglo[]);
int numPares(int n, int arreglo[]);

int main(){
    int n;
    int arreglo[TAMA];
    int esValido, pares;
    printf("Ingrese la cantidad de terminos de la secuencia: ");
    scanf("%d", &n );

    esValido = validarEntrada(n);
    if(esValido == 0){
        printf("supero los intentos permitidos, ejecute nuevamente el programa\n");
    }
    cargarArreglo(n, arreglo);
    printf("Arreglo: ");
    mostrarArreglo(n, arreglo);
    printf("\n");
    printf("Arreglo ascendente: ");
    arregloAsc(n, arreglo);
    printf("\n");
    pares = numPares(n, arreglo);
    printf("Cantidad numero pares: %d", pares);
   
    return 0;
}

int validarEntrada(int n){
    int intentos = 3;
    while(intentos > 0){
        if(n<1){
            printf("Ingrese un numero valido: ");
            scanf("%d", &n);
            intentos--;
        }else{
            return 1;
        }
    }
    return 0;
}

void cargarArreglo(int n, int arreglo[]){
    for(int i=1; i<=n; i++){
        arreglo[i] = i*i;
    }
}

void mostrarArreglo(int n, int arreglo[]){
    for (int i=1; i<=n ; i++){
        printf(" %d", arreglo[i]);
    }
}

void arregloAsc(int n, int arreglo[]){
    for(int i=n; i>=1; i--){
        printf(" %d", arreglo[i]);
    }
}

int numPares(int n, int arreglo[]){
    int cantPares = 0;
    for(int i=1; i<=n; i++){
        if(i%2 == 0){
            cantPares++;
        }
    }
    return cantPares;
}
