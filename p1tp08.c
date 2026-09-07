#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct
{
    int numSala;
    int totalEspectadores;
    char pantalla[MAX];
} Sala;

typedef struct
{
    char titulo[MAX];
    char genero[MAX];
    int cantFunciones;
    int *espectadores;
    Sala sala;
} Pelicula;

void cargarPeliculas(Pelicula *pelis, int cant);
void cargarEspectadores(Pelicula *pelis, int cant);
void mostrarPeliculas(Pelicula *pelis, int cant);
void listarPorGenero(Pelicula *pelis, int cant);
float calcularPromedioEspectadores(Pelicula p);
void mostrarSalasGrandes(Pelicula *pelis, int cant);
int contarPeliculasIMAX(Pelicula *pelis, int cant);
void mostrarPeliculasSalaLlena(Pelicula *pelis, int cant);
void liberarMemoria(Pelicula *pelis, int cant);

int main()
{
    int cant, contadorImax = 0;
    printf("Ingrese la cantidad de peliculas: ");
    scanf("%d", &cant);

    Pelicula *pelis = (Pelicula *)malloc(cant * sizeof(Pelicula));
    cargarPeliculas(pelis, cant);
    cargarEspectadores(pelis, cant);
    listarPorGenero(pelis, cant);
    mostrarSalasGrandes(pelis, cant);
    contadorImax = contarPeliculasIMAX(pelis, cant);
    printf("Cantidad de peliculas proyectadas en pantallas IMAX: %d\n", contadorImax);
    mostrarPeliculasSalaLlena(pelis, cant);
    liberarMemoria(pelis, cant);
    return 0;
}

void cargarPeliculas(Pelicula *pelis, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf("---CARGA PELICULA %d --- \n", i + 1);
        fflush(stdin);
        printf("Titulo Pelicula: ");
        gets(pelis[i].titulo);
        fflush(stdin);

        printf("Genero: ");
        gets(pelis[i].genero);
        fflush(stdin);

        printf("Numero de sala: ");
        scanf("%d", &pelis[i].sala.numSala);
        fflush(stdin);

        printf("Capacidad sala: ");
        scanf("%d", &pelis[i].sala.totalEspectadores);
        fflush(stdin);

        printf("Tipo de pantalla: ");
        gets(pelis[i].sala.pantalla);
        fflush(stdin);

        printf("Cantidad de funciones: ");
        scanf("%d", &pelis[i].cantFunciones);
        fflush(stdin);

        pelis[i].espectadores = (int *)malloc(pelis[i].cantFunciones * sizeof(int));
    }
}

void cargarEspectadores(Pelicula *pelis, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        int cantTotal = (pelis[i].cantFunciones) * (pelis[i].sala.totalEspectadores);

        for (int j = 0; j < pelis[i].cantFunciones; j++)
        {
            int valido = 0;
            {
                do
                {
                    printf("Cantidad de espectadores de la funcion %d:  ", j + 1);
                    scanf("%d", &pelis[i].espectadores[j]);
                    if (pelis[i].espectadores[j] > cantTotal)
                    {
                        printf("Error: Supera la capacidad de la sala (%d). Reingrese.\n", pelis[i].sala.totalEspectadores);
                    }
                    else if (pelis[i].espectadores[j] < 0)
                    {
                        printf("Error: No puede haber espectadores negativos.\n");
                    }
                    else
                    {
                        valido = 1;
                    }

                } while (valido == 0);
            }
        }
    }
}

void listarPorGenero(Pelicula *pelis, int cant)
{
    char genero[MAX];
    printf("Ingrese un genero para listar: ");
    gets(genero);
    fflush(stdin);
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(pelis[i].genero, genero) == 0)
        {
            printf("Peliculas del genero %s\n", genero);
            printf("%d_ %s\n", i + 1, pelis[i].genero);
        }
    }
}

void mostrarSalasGrandes(Pelicula *pelis, int cant)
{
    int butacas = 200;
    for (int i = 0; i < cant; i++)
    {
        if (pelis[i].sala.totalEspectadores > butacas)
        {
            printf("Pelicula proyectada en sala grande: ");
            printf("%s \n", pelis[i].titulo);
        }
    }
}

int contarPeliculasIMAX(Pelicula *pelis, int cant)
{
    int contador = 0;
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(pelis[i].sala.pantalla, "IMAX") == 0)
        {
            contador++;
        }
    }
    return contador;
}

void mostrarPeliculasSalaLlena(Pelicula *pelis, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        if (pelis[i].espectadores == pelis[i].sala.totalEspectadores)
        {
            printf("Peliculas con sala llena: %s \n", pelis[i].titulo);
        }
    }
}

void liberarMemoria(Pelicula *pelis, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        free(pelis[i].espectadores);
    }
    free(pelis);
}
