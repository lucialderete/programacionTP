#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STR 100

// Estructuras
typedef struct {
    int numero;
    int capacidad;
    char tipoPantalla[MAX_STR]; // "2D", "3D", "IMAX", etc.
} Sala;

typedef struct {
    char titulo[MAX_STR];
    char genero[MAX_STR];
    int cantFunciones;
    int *espectadores; // arreglo dinámico: espectadores por función
    Sala sala;         // Sala anidada
} Pelicula;

// Prototipos
void cargarPeliculas(Pelicula *pelis, int cant);
void cargarEspectadores(Pelicula *pelis, int cant);
void mostrarPeliculas(Pelicula *pelis, int cant);
void listarPorGenero(Pelicula *pelis, int cant, char genero[]);
float calcularPromedioEspectadores(Pelicula p);
void mostrarSalasGrandes(Pelicula *pelis, int cant);
int contarPeliculasIMAX(Pelicula *pelis, int cant);
void mostrarPeliculasSalaLlena(Pelicula *pelis, int cant);
int equalsIgnoreCase(const char *a, const char *b);

// Implementación
int equalsIgnoreCase(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return 0;
        a++; b++;
    }
    return *a == '\0' && *b == '\0';
}

// Carga datos básicos y reserva memoria para espectadores
void cargarPeliculas(Pelicula *pelis, int cant) {
    // Para facilitar las pruebas: generamos datos simulados
    for (int i = 0; i < cant; i++) {
        snprintf(pelis[i].titulo, MAX_STR, "Pelicula %d", i+1);

        // Rotamos algunos géneros
        const char *generos[] = {"Accion", "Comedia", "Drama", "Terror", "IMAX"};
        strncpy(pelis[i].genero, generos[i % (sizeof(generos)/sizeof(generos[0]))], MAX_STR-1);
        pelis[i].genero[MAX_STR-1] = '\0';

        // Cantidad de funciones: entre 1 y 5
        pelis[i].cantFunciones = 1 + (i % 5);

        // Sala (simulada)
        pelis[i].sala.numero = 1 + i;
        // capacidad variada: algunos por encima de 200
        pelis[i].sala.capacidad = 80 + (i * 70); // 80, 150, 220, 290, ...
        // Tipo de pantalla: asignamos "IMAX" a los que tengan capacidad > 250
        if (pelis[i].sala.capacidad > 250) {
            strncpy(pelis[i].sala.tipoPantalla, "IMAX", MAX_STR-1);
        } else {
            // 2D, 3D según i
            if (i % 3 == 0) strncpy(pelis[i].sala.tipoPantalla, "2D", MAX_STR-1);
            else if (i % 3 == 1) strncpy(pelis[i].sala.tipoPantalla, "3D", MAX_STR-1);
            else strncpy(pelis[i].sala.tipoPantalla, "Digital", MAX_STR-1);
        }
        pelis[i].sala.tipoPantalla[MAX_STR-1] = '\0';

        // Reservamos memoria para el arreglo de espectadores por función
        pelis[i].espectadores = (int*) malloc(pelis[i].cantFunciones * sizeof(int));
        if (!pelis[i].espectadores) {
            fprintf(stderr, "Error de memoria al reservar espectadores para pelicula %d\n", i+1);
            // Liberar ya reservado antes de salir
            for (int j = 0; j < i; j++) free(pelis[j].espectadores);
            free(pelis);
            exit(EXIT_FAILURE);
        }
        // Inicializamos a 0
        for (int f = 0; f < pelis[i].cantFunciones; f++) pelis[i].espectadores[f] = 0;
    }
}

// Genera (aleatoriamente) espectadores por función, controlando la capacidad
void cargarEspectadores(Pelicula *pelis, int cant) {
    srand((unsigned int) time(NULL));
    for (int i = 0; i < cant; i++) {
        int cap = pelis[i].sala.capacidad;
        for (int f = 0; f < pelis[i].cantFunciones; f++) {
            // Generamos un número entre 0 y cap (inclusive)
            pelis[i].espectadores[f] = rand() % (cap + 1);
        }
    }
}

void mostrarPeliculas(Pelicula *pelis, int cant) {
    for (int i = 0; i < cant; i++) {
        printf("--- Pelicula %d ---\n", i+1);
        printf("Titulo: %s\n", pelis[i].titulo);
        printf("Genero: %s\n", pelis[i].genero);
        printf("Cantidad de funciones: %d\n", pelis[i].cantFunciones);
        printf("Sala: numero %d, capacidad %d, pantalla %s\n",
               pelis[i].sala.numero, pelis[i].sala.capacidad, pelis[i].sala.tipoPantalla);
        printf("Espectadores por funcion:\n");
        for (int f = 0; f < pelis[i].cantFunciones; f++) {
            printf("  Funcion %d: %d\n", f+1, pelis[i].espectadores[f]);
        }
        float prom = calcularPromedioEspectadores(pelis[i]);
        printf("Promedio espectadores por funcion: %.2f\n", prom);
        printf("\n");
    }
}

void listarPorGenero(Pelicula *pelis, int cant, char genero[]) {
    printf("Peliculas del genero '%s':\n", genero);
    int found = 0;
    for (int i = 0; i < cant; i++) {
        if (equalsIgnoreCase(pelis[i].genero, genero)) {
            printf(" - %s (Sala %d, Capacidad %d)\n", pelis[i].titulo, pelis[i].sala.numero, pelis[i].sala.capacidad);
            found = 1;
        }
    }
    if (!found) printf("(ninguna)\n");
}

float calcularPromedioEspectadores(Pelicula p) {
    if (p.cantFunciones == 0) return 0.0f;
    int suma = 0;
    for (int i = 0; i < p.cantFunciones; i++) suma += p.espectadores[i];
    return (float)suma / (float)p.cantFunciones;
}

void mostrarSalasGrandes(Pelicula *pelis, int cant) {
    printf("Peliculas en salas con capacidad > 200:\n");
    int found = 0;
    for (int i = 0; i < cant; i++) {
        if (pelis[i].sala.capacidad > 200) {
            printf(" - %s (Sala %d, Capacidad %d)\n", pelis[i].titulo, pelis[i].sala.numero, pelis[i].sala.capacidad);
            found = 1;
        }
    }
    if (!found) printf("(ninguna)\n");
}

int contarPeliculasIMAX(Pelicula *pelis, int cant) {
    int contador = 0;
    for (int i = 0; i < cant; i++) {
        if (equalsIgnoreCase(pelis[i].sala.tipoPantalla, "IMAX")) contador++;
    }
    return contador;
}

void mostrarPeliculasSalaLlena(Pelicula *pelis, int cant) {
    printf("Peliculas que tuvieron al menos una funcion con sala llena:\n");
    int found = 0;
    for (int i = 0; i < cant; i++) {
        for (int f = 0; f < pelis[i].cantFunciones; f++) {
            if (pelis[i].espectadores[f] == pelis[i].sala.capacidad) {
                printf(" - %s (Sala %d)\n", pelis[i].titulo, pelis[i].sala.numero);
                found = 1;
                break; // mostrar una sola vez por pelicula
            }
        }
    }
    if (!found) printf("(ninguna)\n");
}

int main() {
    int cant;
    printf("Cuantas peliculas desea cargar (ej: 3)? ");
    if (scanf("%d", &cant) != 1 || cant <= 0) {
        printf("Entrada invalida. Se usaran 3 peliculas por defecto.\n");
        cant = 3;
    }

    // Reservamos arreglo dinámico de Pelicula
    Pelicula *pelis = (Pelicula*) malloc(cant * sizeof(Pelicula));
    if (!pelis) {
        fprintf(stderr, "No se pudo reservar memoria para peliculas.\n");
        return EXIT_FAILURE;
    }

    // Cargar estructuras y reservar espectadores
    cargarPeliculas(pelis, cant);

    // Cargar (generar) espectadores
    cargarEspectadores(pelis, cant);

    // Informes solicitados
    mostrarPeliculas(pelis, cant);

    char generoBuscado[MAX_STR];
    printf("\nIngrese un genero para listar (ej: Comedia): ");
    scanf("%s", generoBuscado);
    listarPorGenero(pelis, cant, generoBuscado);

    mostrarSalasGrandes(pelis, cant);

    int nIMAX = contarPeliculasIMAX(pelis, cant);
    printf("Cantidad de peliculas en IMAX: %d\n", nIMAX);

    mostrarPeliculasSalaLlena(pelis, cant);

    // Liberar memoria dinámica
    for (int i = 0; i < cant; i++) {
        free(pelis[i].espectadores);
    }
    free(pelis);

    return 0;
}
