/*
------------------------------------------------------------
TP6 - Punto 1: Estructuras en C

Este programa introduce el uso de estructuras (struct) para
organizar información compleja en C. A partir del registro
de una película, se busca trabajar con estructuras anidadas
(Fecha, Persona, Pelicula) y comprender cómo acceder a sus
miembros mediante el operador punto (.)

El objetivo de esta base es servir como guía inicial para
completar las funciones del programa. Los estudiantes deberán:
 - Implementar la carga completa de los datos de una película.
 - Mostrar la información registrada de forma legible.
 - Calcular el costo final de la película según ciertas condiciones.
 - Verificar si el género ingresado coincide con el de la película.

El código se entrega parcialmente comentado para orientar
la comprensión y favorecer la práctica autónoma.
------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

// Definición de estructuras
// Estructura para guardar una fecha (día, mes, año)
typedef struct
{
    // completar...
    int dia;
    int mes;
    int anio;
} Fecha;

// Estructura para guardar los datos del director
typedef struct
{
    char nombre[50];
    char apellido[50];
    int edad;
} Persona;

// Estructura principal: Película
typedef struct
{
    int codigo;
    char titulo[50];
    Persona director;
    Fecha fechaEstreno;
    float precioBase;
    int genero;
} Pelicula;

// Arreglo de géneros disponibles
char genero[6][20] = {
    "Accion", //0
    "Comedia", //1
    "Drama", //2
    "Terror", //3
    "Ciencia ficcion", //4
    "Romance"}; //5

// Prototipos de funciones
Pelicula cargarDatos();
void mostrarDatos(Pelicula p);
float calcularCosto(Pelicula p);
int verificarPorGenero(Pelicula p, int generoSeleccionado);

int main()
{
    Pelicula miPelicula;
    float costoFinal;
    int generoBusq;
    int resultadoVerificacion;

    miPelicula = cargarDatos();
    mostrarDatos(miPelicula);

    costoFinal= calcularCosto(miPelicula);
    printf("el costo final es: $%.2f \n", costoFinal);
    //verficar genero
    printf("Ingrese un numero para buscar una pelicula (0-5)");
    scanf("%d \n", &generoBusq);
    fflush(stdin);

    resultadoVerificacion = verificarPorGenero(miPelicula, generoBusq);
    if(resultadoVerificacion == 1){
        printf("La pelicula es del genero %s \n", genero[generoBusq]);
    }else{
        printf("La pelicula no es del genero %s \n", genero[generoBusq]);
    }
    return 0;
}

// ------------------------------------
// Función para cargar datos
// ------------------------------------
Pelicula cargarDatos()
{
    Pelicula p;
    int esValido = 0;
    // ⚙️ Completar la carga de los datos paso a paso:
    // código, título, director, fecha, precio base y género.
    // Recordar: para acceder a los miembros de una estructura, se usa el operador punto (.)
    int i;
    printf("Ingrese el codigo de la pelicula: ");
    scanf("%d", &p.codigo);
    fflush(stdin);
    

    // Continuar...
    printf("ingrese el titulo de la pelicula: ");
    fgets(p.titulo, 100, stdin);
    p.titulo[strcspn(p.titulo, "\n")] =0;

    printf("datos del director: \n");
    printf("Nombre del Director: ");
    fgets(p.director.nombre, 50, stdin);
    p.director.nombre[strcspn(p.director.nombre, "\n")] =0;
    
    printf("Apellido del director: ");
    fgets(p.director.apellido, 50, stdin);
    p.director.apellido[strcspn(p.director.apellido, "\n")] =0;

    printf("edad del director: ");
    scanf("%d", &p.director.edad);
    fflush(stdin);

   

    printf("fecha estrno (dd mm aaaa): ");
    scanf("%d %d %d", &p.fechaEstreno.dia, &p.fechaEstreno.mes, &p.fechaEstreno.anio);
    fflush(stdin);
    if(p.fechaEstreno.anio > 2025){
        printf("fecha invalida \n");
      }

    
    printf("Ingrese el Precio Base: ");
    scanf("%f", &p.precioBase);
    fflush(stdin);
    

    printf("generos disponibles \n");
    for(i=0; i<6; i++){
        printf("%d: %s\n" , i, genero[i]);
    }
    esValido = 0;
    do{
        printf("seleccione el genero de la pelicula (0-5)");
        scanf("%d", &p.genero);
        fflush(stdin);
        if (p.genero >= 0 && p.genero <= 5) {
            esValido = 1;
        } else {
            printf("indice invalido debe ser entre 0 y 5\n");
        }
    } while (esValido == 0);
    
    return p;
}

// ------------------------------------
// Función para mostrar los datos
// ------------------------------------
void mostrarDatos(Pelicula p)
{
    printf("\n--- DATOS DE LA PELÍCULA ---\n");
    printf("Código: %d\n", p.codigo);
    printf("Titulo: %s\n", p.titulo);
    printf("Director: %s %s\n", p.director.nombre, p.director.apellido);
    printf("edad del director: %d \n", p.director.edad);
    printf("fecha estreno pelicula: %02d/%02d/%d \n", p.fechaEstreno.dia, p.fechaEstreno.mes, p.fechaEstreno.anio );
    printf("Precio base: $%0.2f \n", p.precioBase);
    printf("genero: %s\n", genero[p.genero]);
}

// ------------------------------------
// Función para calcular el costo final
// ------------------------------------
float calcularCosto(Pelicula p)
{
    float costoFinal;
    float recargo = 0.50;
    float recargo2 = 0.25;


    if(p.fechaEstreno.anio == 2025 && (p.genero == 0 || p.genero == 4)){
        costoFinal = p.precioBase * (1+ recargo);
    }else if(p.fechaEstreno.anio == 2024 && (p.genero == 5 || p.genero == 3)){
        costoFinal = p.precioBase * (1 + recargo2);
    }else{
        costoFinal = p.precioBase;
    }

    return costoFinal;
}



// ------------------------------------
// Función para verificar coincidencia de género
// ------------------------------------
int verificarPorGenero(Pelicula p, int generoSeleccionado)
{
    if (p.genero == generoSeleccionado)
    {
        return 1;
    }else{
        return 0;
    }
    
}