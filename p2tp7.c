#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define TAMA 50
#define MAX 15

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct {
    char apellido[TAMA];
    char nombre[TAMA];
    int dni;
}Persona;

typedef struct{
    char nombreTaller[TAMA];
    Persona profesor;
    Fecha fechaInicio;
    Fecha fechaFin;
    float costoInscripcion;
    int cantAlumnos;
    int diniLista[MAX];
}Taller;

Taller cargarTaller();

void mostrarTaller (Taller t);
int fechaValida(Taller t);

int main(){
    srand(time(NULL));
    Taller taller;
    printf("Bienvenido al taller: \n");
    taller = cargarTaller();
    mostrarTaller(taller);
    return 0;
}

Taller cargarTaller(){
    Taller t;
    printf("--CARGAR TALLER--\n");
    printf("Ingrese el nombre del taller: ");
    gets(t.nombreTaller);
    fflush(stdin);
    printf("Ingrese el nombre del profesor: ");
    gets(t.profesor.nombre);
    fflush(stdin);
    printf("Ingrese el apellido del profesor: ");
    gets(t.profesor.apellido);
    fflush(stdin);
    printf("Ingrese el dni del profesor: ");
    scanf("%d", &t.profesor.dni);
    fflush(stdin);
    printf("Ingrese la fecha de inicio del curso: (dd/mm/aaaa) ");
    scanf("%d/%d/%d ", &t.fechaInicio.dia, &t.fechaInicio.mes, &t.fechaInicio.anio);
    fflush(stdin);
    printf("Ingrese la fecha de finalizacion del curso: (dd/mm/aaaa) ");
    scanf("%d/%d/%d", &t.fechaFin.dia, &t.fechaFin.mes, &t.fechaFin.anio);
    fflush(stdin);
    printf("Ingrese el costo del taller: ");
    scanf(" %f", &t.costoInscripcion);
    fflush(stdin);
    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &t.cantAlumnos);
    fflush(stdin);

    for(int i=0; i<t.cantAlumnos; i++){
        t.diniLista[i] = rand() % 20000000;
    }

    return t;
}

int fechaValida(Taller t){
    int diaInicio = t.fechaInicio.dia;
    int mesInicio = t.fechaInicio.mes;
    int anioInicio = t.fechaInicio.anio;
    int diaFin = t.fechaFin.dia;
    int mesFin = t.fechaFin.mes;
    int anioFin = t.fechaFin.anio;

    if(anioInicio > 2025){
        printf("Anio no valido\n");
        if(anioFin < anioInicio){
            printf("Las fechas ingresadas no son validas \n");
        }
    }

    switch (mesInicio)
    {
    case 1 :
    case 3:
    case 5:
    case 7:
    case 8:
    case 9:
    case 12:
        if(diaInicio > 31){
            printf("dia fuera de rango \n");
        }
        break;
        
    case 4:
    case 6:
    case 10:
    case 11:
        if(diaInicio > 30){
            printf("Dia fuera de rango \n");
        }
        break;
    case 2: 
        if(diaInicio > 28){
            printf("Dia fuera de rango \n");
        }
    default:
        break;
    }




    return ;
}


void mostrarTaller(Taller t){
    printf("NOMBRE DEL TALLER: %s\n", t.nombreTaller);
    printf("DATOS DEL PROFESOR: \n");
    printf("APELLIDO: %s, NOMBRE: %s, DNI: %d \n", t.profesor.apellido, t.profesor.nombre, t.profesor.dni);
    printf("FECHA INICIO DEL CURSO: %d/%d/%d\n", t.fechaInicio.dia, t.fechaInicio.mes, t.fechaInicio.anio);
    printf("FECHA DE FIN DEL CURSO: %d/%d/%d\n", t.fechaFin.dia, t.fechaFin.mes, t.fechaFin.anio);
    printf("PRECIO DEL CURSO: %.2f\n", t.costoInscripcion);
    printf("CANTIDAD DE ALUMNOS: %d\n", t.cantAlumnos);
    printf("DNI ALUMNOS: ");
    for(int i=0; i<t.cantAlumnos; i++){
        printf("%d ", t.diniLista[i]);
    }
    
}

