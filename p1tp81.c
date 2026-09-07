#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
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
void mayusc(char texto[]){
    int i=0;
    while(texto[i] != '\n'){
        texto[i] = toupper(texto[i]);
        i++;
    }
}
float calcularPromedioEspectadores(Pelicula p);
void mostrarPeliculas(Pelicula *pelic, int cant);
void listarPorGenero(Pelicula *pelic, int cant, char genero[]);
void mostrarSalasGrandes(Pelicula *pelic, int cant);
int contarPeliculasImax(Pelicula *pelic, int cant);
void mostrarSalasLlenas(Pelicula *pelic, int cant);
void liberarMemoria(Pelicula *pelic, int cant);

int main(){
    int cant;
    int exp, salasgrandes;
    char genero[MAX];
    float prom;
    printf("--BIENVENIDO CINE LA BUTACA--\n");
    printf("Ingrese la cantidad de peliculas que se proyectataran: ");
    scanf("%d", &cant);
    Pelicula *pelic = (Pelicula *)malloc(cant * sizeof(Pelicula));
    cargarPeliculas(pelic, cant);
    cargarEspectadores(pelic, cant);
    mostrarPeliculas(pelic, cant);

    printf("--BUSCAR POR GENERO--\n");
    fflush(stdin);
    printf("Ingrese el genero que desea buscar: ");
    fgets(genero, MAX, stdin);
    mayusc(genero);
    listarPorGenero(pelic, cant, genero);
    mostrarSalasGrandes(pelic, cant);
    salasgrandes = contarPeliculasImax(pelic, cant);
    printf("--CANTIDAD DE PELICULAS CON SALAS GRANDES: %d\n", salasgrandes);
    mostrarSalasLlenas(pelic, cant);
    liberarMemoria(pelic, cant);


    
    
    return 0;
}

void cargarPeliculas(Pelicula *pelic, int cant){
    for(int i=0; i<cant; i++){
        fflush(stdin);
        printf("Ingrese el titulo de la pelicula %d: ", i+1);
        fgets(pelic[i].titulo, MAX, stdin);
        mayusc(pelic[i].titulo);

        fflush(stdin);
        printf("Ingrese el genero de la pelicula %d: ", i+1);
        fgets(pelic[i].genero, MAX, stdin);
        mayusc(pelic[i].genero);

        fflush(stdin);
        printf("Ingrese la cantidad de funciones de %d ", i+1);
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
        mayusc(pelic[i].sala.pantalla);

        pelic[i].espectadores = (int *)malloc(pelic[i].totalFunciones * sizeof(int));

    }
}

void cargarEspectadores(Pelicula *pelic, int cant){
    for(int i=0; i<cant; i++){
        printf("ESPECTADORES PELICULA %d: \n", i+1);
        for(int j=0; j<pelic[i].totalFunciones;j++){
           do
           {
            printf("Ingrese la cantiad de espectadores de la funcion %d ", j+1);
            scanf("%d", &pelic[i].espectadores[j]);
            if(pelic[i].espectadores[j] > pelic[i].sala.capacidad){
                printf("error supera la capacidad de la sala %d\n", pelic[i].sala.capacidad);
            }
           } while (pelic[i].espectadores[j] > pelic[i].sala.capacidad);
           
        }
    }

}


void listarPorGenero(Pelicula *pelic, int cant, char genero[]){
    printf("PELICULAS DEL GENERO: %s", genero);
    for(int i=0; i<cant; i++){
        if(strcmp(pelic[i].genero, genero) == 0){
            printf("%s", pelic[i].titulo);
        }

    }
}

void mostrarPeliculas(Pelicula *pelic, int cant){
    for(int i=0; i < cant; i++){
        printf("--PELICULAS A PROYECTAR--\n");
        printf("PELICULA %d:\n", i+1);
        printf("TITULO: %s\n", pelic[i].titulo);
        printf("GENERO: %s\n", pelic[i].genero);
        printf("CANTIDAD DE FUNCIONES: %d\n", pelic[i].totalFunciones);
        for(int j=0; j<pelic[i].totalFunciones; j++){
            printf("TOTAL ESPECTADORES FUNCION %d: %d\n", j+1, pelic[i].espectadores[j]);
        }
        printf("NUMERO DE SALA: %d\n", pelic[i].sala.numSala);
        printf("CAPACIDAD DE ESPECTADORES: %d\n", pelic[i].sala.capacidad);
        printf("TIPO PANTALLA: %s\n", pelic[i].sala.pantalla);
        float promedio = calcularPromedioEspectadores(pelic[i]);
        printf("PROMEDIO ESPECTADORES: %.2f\n", promedio );
    }
}

float calcularPromedioEspectadores(Pelicula p){
    float prom;
    float suma =0;
    for(int i=0; i<p.totalFunciones; i++){
        suma += p.espectadores[i];
    }
    prom = suma / p.totalFunciones;

    return prom;
}

void mostrarSalasGrandes(Pelicula *pelic, int cant){
    printf("--PELICULAS CON SALA MAYOR A 200--\n");
    for(int i=0; i<cant; i++){
        if(pelic[i].sala.capacidad > 200){
            printf("%s\n", pelic[i].titulo);
        }
    }
}

int contarPeliculasImax(Pelicula *pelic, int cant){
    int suma=0;
    for(int i=0; i<cant; i++){
        if(strcmp(pelic[i].sala.pantalla, "IMAX\n") == 0){
            suma++;
        }
    }
    return suma;
}

void mostrarSalasLlenas(Pelicula *pelic, int cant){
    printf("--PELICULAS CON SALA LLENA--\n");
    for(int i=0; i<cant; i++){
        for(int j=0; j<pelic[i].totalFunciones; j++){
            if(pelic[i].espectadores[j] == pelic[i].sala.capacidad){
                printf("%s", pelic[i].titulo);
            }
        }
    }
}

void liberarMemoria(Pelicula *pelic, int cant){
    for(int i=0; i<cant; i++){
        free(pelic[i].espectadores);
    }
    free(pelic);
}