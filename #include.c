#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//estructuras
typedef struct{
    char nombre[MAX];
    int edad;
    float peso;
    float costo;
}Mascotas;

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fechas;


typedef struct{
    char veterinario[MAX];
    char especialidad[MAX];
    Fechas fecha;
    int cantMascotas;
    Mascotas *mascota;
}Consultas;


//modulos
void cargarMascotas(Consultas *consulta, int cant);
void listarMascotas(Consultas *consulta, int cant);
void mostrarCirugia(Consultas *cosulta, int cant);
float pesoPromedio(Consultas *consulta, int cant, char espIngresada[]);
void librerarMemoria(Consultas *consulta, int cant);

//funcion principal

int main(){
    int cant=5;
    char espIngresada[MAX];
    float promedio=0;

    Consultas *consulta = (Consultas *)malloc(cant * sizeof(Consultas));

    printf("--CLINICA VETERINARIA--");
    cargarMascotas(consulta, cant);
    listarMascotas(consulta, cant);
    mostrarCirugia(consulta, cant);

    fflush(stdin);
    printf("Ingrese una especialidad para calcular el promedio del peso de las mascotas: ");
    gets(espIngresada);
    promedio = pesoPromedio(consulta, cant, espIngresada);
    printf("El peso promedio del area %s es: %.2f\n", espIngresada, promedio);
    


    return 0;
}