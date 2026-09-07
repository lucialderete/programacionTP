#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct{
    char apellido[50];
    char nombre[50];
    char dni[20];
}Pasajero;

typedef struct{
    int numVuelo;
    char origen[50];
    char destino[50];
    Fecha fecha;
    float costo;
    int cantAsientos;
    Pasajero *pasajeros;
}Vuelos;

void vuelosLista(Vuelos *vuelo, int cantVuelos){
    printf("---AEROLINEAS ARGENTINAS TUCUMAN_CORDOBA---\n");
    printf("Vuelos programados para diciembre:\n");
    for (int i = 0; i < cantVuelos; i++)
    {
        if(strcmp(vuelo[i].origen, "tucuman")==0 && 
            strcmp(vuelo[i].destino, "cordoba")==0){

            printf("Numero de vuelo: %d\n", vuelo[i].numVuelo);
            printf("Origen: %s\n", vuelo[i].origen);
            printf("Destino: %s\n", vuelo[i].destino);
            printf("Fecha del vuelo: %d / %d / %d\n", 
                vuelo[i].fecha.dia, 
                vuelo[i].fecha.mes, 
                vuelo[i].fecha.anio);
            printf("Precio del vuelo: %.2f\n", vuelo[i].costo);
            printf("Cantidad de asientos: %d\n\n", vuelo[i].cantAsientos);
            }
    }
}
void vuelosDescuento (Vuelos *vuelo, int cantVuelos){
    int descuento = 5800;
    printf("pasajeros con descuentos --- \n");
    for(int i=0; i<cantVuelos; i++){
        if(vuelo[i].costo > descuento){
            vuelo[i].costo = vuelo[i].costo * 0.95;
            for(int j=0; j<cantVuelos;j++){
                printf("apellido y nombre: %s, %s\n",
                vuelo[i].pasajeros[j].apellido,
                vuelo[i].pasajeros[j].nombre);
                printf("dni del descuentado: %s\n", 
                vuelo[i].pasajeros[j].dni);
            }
        }
    }
}
int main(){
    int cantVuelos = 3;
    Vuelos *vuelo = (Vuelos *)malloc(cantVuelos *sizeof(Vuelos));
    //primer vuelo
    vuelo[0]=(Vuelos){
        123, "tucuman", "cordoba", {12, 11, 2025}, 6000, 3,
        (Pasajero *)malloc(3 *sizeof(Pasajero))
    };

    vuelo[0].pasajeros[0]=(Pasajero){
        "alderete", "lucia", "44919342"
    };
    vuelo[0].pasajeros[1]=(Pasajero){
        "perez", "ana", "11223344"
    };
    vuelo[0].pasajeros[2]=(Pasajero){
        "herrera", "sofia", "12345678"
    };

    //vuelo 2
    vuelo[1]=(Vuelos){
        456, "santa fe", "buenos aires", {15, 12, 2025}, 5000,
        4, (Pasajero *)malloc(4 * sizeof(Pasajero))
    };
    vuelo[1].pasajeros[0]=(Pasajero){
        "martinez", "lucas", "99888777"
    };
    vuelo[1].pasajeros[1]=(Pasajero){
        "diaz", "tomas", "99888777"
    };
    vuelo[1].pasajeros[2]=(Pasajero){
        "ramierez", "sofia", "99888777"
    };
    vuelo[1].pasajeros[3]=(Pasajero){
        "fernandez", "pedro", "99888777"
    };

    //vuelo 3
    vuelo[2]=(Vuelos){
        567, "tucuman", "cordoba", {26, 12, 2025}, 7000,
        2, (Pasajero *)malloc( 2 * sizeof(Pasajero))
    };

    vuelo[2].pasajeros[0]=(Pasajero){
        "garcia", "laura", "33998165"
    };
    vuelo[2].pasajeros[1]=(Pasajero){
        "navarro", "luis", "33998195"
    };

    vuelosLista(vuelo, cantVuelos);
    vuelosDescuento(vuelo, cantVuelos);


    for(int i=0; i<cantVuelos; i++){
        free(vuelo[i].pasajeros);
    }
    free(vuelo);

    return 0;
}