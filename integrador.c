#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct{
    char hora[10];
    char lugar[50];
}Encuentro;

typedef struct{
    char nombre[50];
    char dni[10];
    int edad;
}Voluntario;

typedef struct{
    char nombreAct[50];
    char area[50];
    char responsable[50];
    Encuentro encuentro;
    int cantVoluntarios;
    Voluntario *voluntario;
}Actividad;

void mostrarAct(Actividad*actividades, int cantAct){
    int i;
    printf("Actividades propuestas: \n");
    for(i=0; i<cantAct;i++){
        printf("actividad: %s\n", actividades[i].nombreAct);
        printf("area: %s\n", actividades[i].area);
        printf("responsable a cargo: %s\n", actividades[i].responsable);
        printf("hora y lugar: %s -  %s\n", actividades[i].encuentro.hora, actividades[i].encuentro.lugar);
        printf("cantidad de voluntarios anotados: %d\n\n", actividades[i].cantVoluntarios);
    }
}

void listadoVoluntarios(Actividad *actividades, int cantAct){
    int i, j;
    printf("voluntarios anotados por actividad: uwu\n");
    for(i=0; i<cantAct;i++){
        printf("actividad: %s\n", actividades[i].nombreAct);
        for(j=0;j<actividades[i].cantVoluntarios;j++){
            printf("nombre del voluntariE: %s\nDNI: %s\nedad: %d\n\n", 
                actividades[i].voluntario[j].nombre,
                actividades[i].voluntario[j].dni,
                actividades[i].voluntario[j].edad);
        }
    }
}

int main(){
    int cantAct = 3;
    Actividad *actividades= (Actividad *)malloc(cantAct*sizeof(Actividad));
    //actividad 1
    actividades[0]=(Actividad){
        "restauracion de doc historicos","conservacion",
        "Ana herrera",{"10:00", "Sala de restauracion"},
        3, 
        (Voluntario *)malloc(3 * sizeof(Voluntario))};
    //voluntarios de 1
    actividades[0].voluntario[0]=(Voluntario){
        "lucas martinez", "12345678", 21};
    actividades[0].voluntario[1]=(Voluntario){
        "maria lopez","98765432", 24
        };
    actividades[0].voluntario[2]=(Voluntario){
        "julian gomez" , "11223344", 23
    };

    //actividad 2
    actividades[1]=(Actividad){
        "limpieza de do artefactos arqueologicos", "arqueologia",
        "roberto sanchez", {"12:00","deposito"}, 2, (Voluntario * )malloc(2*sizeof(Voluntario))
    };
    //voluntarios act2
    actividades[1].voluntario[0]=(Voluntario){
        "sofia ramirez", "55667788", 26
    };
    actividades[1].voluntario[1]=(Voluntario){
        "pedro fernandez", "66778899", 22
    };

    //actividad 3
    actividades[2]=(Actividad){
        "visitas guiadas", "historia", "elena morales",
        {"14:00", "museo principal"}, 5, (Voluntario *)malloc(5*sizeof(Voluntario))
    };
    //voluntarios act3
    actividades[2].voluntario[0]=(Voluntario){
        "camila rodriguez", "77889900", 36
    };
    actividades[2].voluntario[1]=(Voluntario){
        "jorge mendoza", "44556677", 21
    };
    actividades[2].voluntario[2]=(Voluntario){
        "carla hernandez", "00998877", 18
    };
    actividades[2].voluntario[3]=(Voluntario){
        "luis ortiz", "11223344", 23
    };
    actividades[2].voluntario[4]=(Voluntario){
        "paula mendoza", "123456787", 28
    };

    //mostrar los datos xd
    mostrarAct(actividades, cantAct);
    listadoVoluntarios(actividades, cantAct);
    for (int i = 0; i < cantAct; i++) {
        free(actividades[i].voluntario);
    }
    free(actividades);

    return 0;
}