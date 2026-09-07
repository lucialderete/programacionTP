#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarArreglo(int arreglo[], int tama);

void mostrarArreglo(int arreglo[], int tama);

int buscarEiminado(int arreglo[], int tama, int salvado1, int salvado2, int salvado3);

int main(){
    int tama = 9;
    int arreglo[tama];
    int salvado1, salvado2, salvado3, eliminado;
    srand(time(NULL));
    printf("--LA VOZ ARGENTINA--");
    printf("\nPUNTAJE DE LOS PARTICIPANTES: ");
    cargarArreglo(arreglo, tama);
    mostrarArreglo(arreglo, tama);
    printf("\n---PARTICIPANTES SALVADOS---");

    printf("\nIngrese el numero del primer participante salvado: ");
    scanf("%d", &salvado1);
    printf("\nIngrese el numero del segundo participante salvado: ");
    scanf("%d", &salvado2);
    printf("\nIngrese el numero del tercer participante salvado: ");
    scanf("%d", &salvado3);


    eliminado = buscarEiminado(arreglo, tama, salvado1, salvado2, salvado3);
    printf("\n--PARTICIPANTE ELIMINADO:  %d", eliminado);

    return 0;
}

void cargarArreglo(int arreglo[], int tama){
    for(int i=1; i<tama; i++){
        arreglo[i] = rand() % 11;
    }
}

void mostrarArreglo(int arreglo[], int tama){
    for(int i=1; i < tama; i++){
        printf("\nParticipante %d tiene: %d puntos", i, arreglo[i]);
    }
}

int buscarEiminado(int arreglo[], int tama, int salvado1, int salvado2, int salvado3){
    int puntMenor = 11;
    int idEliminado=0;
    int i=1;
    for(i; i<tama; i++){
        if((i != salvado1 && i != salvado2 && i != salvado3)){
            if(arreglo[i]<puntMenor){
                puntMenor= arreglo[i];
                idEliminado = i;
            }
        }
        
    }

    return idEliminado;
}