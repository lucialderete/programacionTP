#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX 50

typedef struct
{
    int numSala;
    int capacidad;
    char pantalla[MAX];
}Sala;

typedef struct{
    char titulo[MAX];
    char genero[MAX];
    int totalFunciones;
    int *espectadores;
    Sala sala;
}Pelicula;

void cargarPeliculas(Pelicula *pelic, int cant);
void cargarEspectadores(Pelicula *pelic, int cant);

int main(){
    int cant;
    int exp;
    printf("--BIENVENIDO CINE LA BUTACA--\n");
    printf("Ingrese la cantidad de peliculas que se proyectataran: ");
    scanf("%d", &cant);
    Pelicula *pelic = (Pelicula *)malloc(cant * sizeof(Pelicula));
    cargarPeliculas(pelic, cant);
    cargarEspectadores(pelic, cant);

    return 0;
}

void cargarPeliculas(Pelicula *pelic, int cant){
    for(int i=0; i<cant; i++){
        fflush(stdin);
        printf("Ingrese el titulo de la pelicula %d: ", i+1);
        fgets(pelic[i].titulo, MAX, stdin);

        fflush(stdin);
        printf("Ingrese el genero de la pelicula %d: ", i+1);
        fgets(pelic[i].genero, MAX, stdin);

        fflush(stdin);
        printf("Ingrese la cantidad de funciones de %d", i+1);
        scanf("%d", &pelic[i].totalFunciones);

        fflush(stdin);
        printf("Ingrese el numero de sala: ");
        scanf("%d", &pelic[i].sala.numSala);

        fflush(stdin);
        printf("Ingrese la capacidad de espectadores por sala: ");
        scanf("%d", &pelic[i].sala.capacidad);

        fflush(stdin);
        printf("Ingrese el tipo de pantalla: ");
        fgets(pelic[i].sala.pantalla, MAX, stdin);

        pelic[i].espectadores = (int *)malloc(pelic[i].totalFunciones * sizeof(int));

    }
}

void cargarEspectadores(Pelicula *pelic, int cant){
    for(int i=0; i<cant; i++){
        printf("ESPECTADORES PELICULA %d: \n", i+1);
        for(int j=0; j<pelic[i].totalFunciones;j++){
           do
           {
            printf("Ingrese la cantiad de espectadores de la funcion %d", j+1);
            scanf("%d", &pelic[i].espectadores[j]);
            if(pelic[i].espectadores[j] > pelic[i].espectadores[j]){
                printf("error supera la capacidad de la sala %d\n", pelic[i].sala.capacidad);
            }
           } while (pelic[i].espectadores[j] > pelic[i].sala.capacidad);
           
        }
    }

}