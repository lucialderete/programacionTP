#include <stdio.h>
#include <time.h>
#include <stdin.h>
#include <ctype.h>

void listarHuespedes(Huesped huespedes[], int cantHuesped);

typedef struct{
    int dia;
    int mes;
    int anio;

}Fecha;

typedef struct{
    char usuario;
    char ctrs;
}DatosCuenta;

typedef struct{
    char apellido;
    char nombre;
    int dni;
    Fecha fechaNac;
    int telefono;
    DatosCuenta datos;
    int reservaVigente ;
}Huesped;



struct Huesped huespedes[3]{
    {'Alderete', 'Lucia', 44919342, {07, 07, 2003}, 3815154871, {'itsluald', 'unodostres'}, 0},
    {'Guerrero', 'Cynthia', 45823521, {30, 01, 2004}, 381653823, {'guesam', 'ctrs234'}, 0},
    {'Betura', 'Camila', 45723083, {11, 06, 2004}, 381632874, {'cambetura', '123ctrs'}, 0}

};



int main(){
    printf("---BIENVENIDO A HOTEL MANAGER---");
    listarHuespedes(huespedes[], cantHuepedes);

    return 0;
}

void listarHuespedes(Huesped huespedes[], int cantHuespedes){

}