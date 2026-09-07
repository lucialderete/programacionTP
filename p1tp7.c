#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100


typedef struct
{
    char nombre[MAX];
    char apellido[MAX];
    int edad;
}Director;

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct{
    int codigo;
    char titulo[MAX];
    Director director;
    Fecha estreno;
    float precioBase;
    int genero;
}Pelicula;

Pelicula cargarDatos();
void mostrarDatos(Pelicula p);
float calcularCosto(Pelicula p);


int main(){
    printf("REGISTRO PELICULA\n");
    Pelicula pelicula;
    float precioFinal = 0;
    pelicula = cargarDatos();
    precioFinal = calcularCosto(pelicula);
    mostrarDatos(pelicula);
    printf("Precio a final: $%.2f", precioFinal);

    return 0;
}

Pelicula cargarDatos(){
    Pelicula p;
    int opcion;
    char listaGeneros[6][20] = {
        "ACCION", "COMEDIA", "DRAMA", 
        "TERROR", "CIENCIA FICCION", "ROMANCE"
    };
    printf("Codigo pelicula: ");
    scanf("%d", &p.codigo);
    fflush(stdin);
    printf("Titulo: ");
    gets(p.titulo);
    fflush(stdin);
    printf("DATOS DEL DIRECTOR\n");
    printf("Nombre Director: ");
    gets(p.director.nombre);
    fflush(stdin);
    printf("Apellido Director: ");
    gets(p.director.apellido);
    fflush(stdin);
    printf("Edad del director: ");
    scanf("%d", &p.director.edad);
    fflush(stdin);
    printf("FECHA DE ESTRENO\n");
    printf("dd/mm/aaaa: ");
    scanf("%d/%d/%d", &p.estreno.dia, &p.estreno.mes, &p.estreno.anio);
    fflush(stdin);
    if(p.estreno.anio > 2025){
        printf("Ingrese una fecha valida");
        scanf("%d/%d/%d", &p.estreno.dia, &p.estreno.mes, &p.estreno.anio);
    }
    for(int i=0; i<6; i++){
        printf("%d %s\n", i+1, listaGeneros[i]);
    }
    printf("Genero: [1-6]\n");
    scanf("%d", &opcion);
    if(opcion<1 || opcion > 6){
        printf("Seleccione una opcion valida");
        printf("Genero: [1-6] ");
        scanf("%d", &opcion);
    }
    opcion = p.genero;
    return p;
}


void mostrarDatos(Pelicula p){
    printf("TITULO: %s\n", p.titulo);
    printf("--DATOS DEL DIRECTOR--\n");
    printf("NOMBRE: %s, ", p.director.nombre);
    printf(" APELLIDO: %s\n", p.director.apellido);
    printf("EDAD: %d\n", p.director.edad);
    printf("--DATOS DE LA PELICULA --\n");
    printf("FECHA DE ESTRENO: %d/%d/%d\n", p.estreno.dia, p.estreno.mes, p.estreno.anio);
    printf("GENERO: %d\n", p.genero );

}

float calcularCosto(Pelicula p){
    int anioEstreno = p.estreno.anio;
    int genero = p.genero;
    float precioBase = 1000;
    float precioFinal = 0;
    if(anioEstreno == 2025 && (genero == 1 || genero == 5)){
        precioFinal = ((precioBase * 50)/100) +  precioBase;
    }else if(anioEstreno == 2024 && (genero == 6)||(genero == 4)){
        precioFinal = ((precioBase * 25)/100) + precioBase;
    }else{
        precioFinal = precioBase;
    }
    return precioFinal;
}