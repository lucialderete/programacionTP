#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define MAX 100

// estructuras
typedef struct
{
    int dni;
    int antig;
    char rol[MAX];
    char lenguaje[MAX];
} Desarrollador;

typedef struct
{
    int cod;
    char estado[MAX];
    float costo;
    int cantDesarrolladores;
    Desarrollador *asignado;
} Proyecto;

// declaracion de modulos
void mostrarDesarrolladoresPorEstado(Proyecto *proy, int cant, char estado[]);
void mostrarDesarrolladorMenor(Proyecto *proy, int cant);
void proyectosFinalizadosBackYJava(Proyecto *proy, int cant);
void mostrarProyectoMayorDesarrolladores(Proyecto *proy, int cant, char lenguaje[]);
float calcularCostoPromedioAntiguedad(Proyecto *proy, int cant, int antiguedadMinima);
void liberarMemoria(Proyecto *proy, int cant);

int main()
{
    printf("--REALLOC SOFT--\n");
    int cant = 5, antiguedadMinima = 5;
    char estado[MAX];
    char lenguaje[MAX];

    Proyecto *proy = (Proyecto *)malloc(cant * sizeof(Proyecto));

    // precarga de datos
    proy[0] = (Proyecto){
        200, "DISENIO", 3000, 3, (Desarrollador *)malloc(3 * sizeof(Desarrollador))};

    proy[0].asignado[0] = (Desarrollador){44919342, 6, "FRONTEND", "JAVASCRIPT"};
    proy[0].asignado[1] = (Desarrollador){44919343, 2, "FRONTEND", "JAVASCRIPT"};
    proy[0].asignado[2] = (Desarrollador){44919346, 1, "FRONTEND", "PYTHON"};

    proy[1] = (Proyecto){
        250, "FINALIZADO", 5000, 2, (Desarrollador *)malloc(2 * sizeof(Desarrollador))};
    proy[1].asignado[0] = (Desarrollador){
        44827651, 7, "LIDER", "C"};
    proy[1].asignado[1] = (Desarrollador){
        44392472, 8, "BACKEND", "JAVA"};

    proy[2] = (Proyecto){
        625, "ANALISIS", 2500, 4, (Desarrollador *)malloc(4 * sizeof(Desarrollador))};
    proy[2].asignado[0] = (Desarrollador){
        77213861, 1, "DBA", "JAVA"};
    proy[2].asignado[1] = (Desarrollador){
        66292675, 9, "BACKEND", "JAVA"};
    proy[2].asignado[2] = (Desarrollador){
        991272351, 5, "BACKEND", "JAVA"};
    proy[2].asignado[3] = (Desarrollador){
        38843284, 2, "BACKEND", "JAVA"};

    proy[3] = (Proyecto){
        625, "CODIFICACION", 2500, 4, (Desarrollador *)malloc(4 * sizeof(Desarrollador))};
    proy[3].asignado[0] = (Desarrollador){
        77213861, 1, "LIDER", "JAVA"};
    proy[3].asignado[1] = (Desarrollador){
        66292675, 9, "LIDER", "PYTHON"};
    proy[3].asignado[2] = (Desarrollador){
        991272351, 5, "FRONTEND", "JAVASCRIPT"};
    proy[3].asignado[3] = (Desarrollador){
        38843284, 2, "QA", "JAVA"};

    proy[4] = (Proyecto){
        625, "ANALISIS", 2500, 4, (Desarrollador *)malloc(4 * sizeof(Desarrollador))};
    proy[4].asignado[0] = (Desarrollador){
        77213861, 1, "LIDER", "JAVA"};
    proy[4].asignado[1] = (Desarrollador){
        66292675, 9, "DBA", "PYTHON"};
    proy[4].asignado[2] = (Desarrollador){
        991272351, 5, "QA", "C"};
    proy[4].asignado[3] = (Desarrollador){
        38843284, 2, "FRONTEND", "JAVA"};

    //-----
    fflush(stdin);
    printf("ingrese el estado del proyecto que desea buscar: ");
    fgets(estado, MAX, stdin);

    fflush(stdin);
    printf("ingrese el lenguaje que desea buscar: ");
    fgets(lenguaje, MAX, stdin);

    mostrarDesarrolladoresPorEstado(proy, cant, estado);
    mostrarDesarrolladorMenor(proy, cant);
    proyectosFinalizadosBackYJava(proy, cant);
    mostrarProyectoMayorDesarrolladores(proy, cant, lenguaje);
    float promedio = calcularCostoPromedioAntiguedad(proy, cant, antiguedadMinima);
    printf("El costo total promedio de todos los proyectos gestionados por al menos un desarrolador es: %.2f", promedio);

    liberarMemoria(proy, cant);

    return 0;
}

// desarrollo de los modulos

void mostrarDesarrolladoresPorEstado(Proyecto *proy, int cant, char estado[])
{
    printf("--CODIGO DE PROYECTOS DE ESTADO %s", estado);
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(proy[i].estado, estado) == 0)
        {
            printf("%d\n", proy[i].cod);
        }
    }
}

void mostrarDesarrolladorMenor(Proyecto *proy, int cant)
{
    int antiguedad = 100;
    int posI = -1, posJ = -1;
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j < proy[i].cantDesarrolladores; j++)
        {
            if (proy[i].asignado[j].antig < antiguedad)
            {
                antiguedad = proy[i].asignado[j].antig;
                posI = i;
                posJ = j;
            }
        }
    }

    if (posI != -1)
    {
        printf("---DESARROLLADOR CON MENOR ANTIGUEDAD: ---\n");
        printf("DNI: %d, ROL: %s\n, ANTG: %d", proy[posI].asignado[posJ].dni, proy[posI].asignado[posJ].rol, proy[posI].asignado[posJ].antig);
    }
}

void proyectosFinalizadosBackYJava(Proyecto *proy, int cant)
{
    printf("PROYECTOS FINALIZADOS CON DESARROLLADORES BACKEND EN LENGUAJE JAVA: \n");
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(proy[i].estado, "FINALIZADO\n") == 0)
        {
            for (int j = 0; j < proy[i].cantDesarrolladores; j++)
            {
                if(strcmp(proy[i].asignado[j].rol, "BACKEND\n")==0){
                    if(strcmp(proy[i].asignado[j].lenguaje, "JAVA\n")==0){
                        printf("PROYECTO %d \n", proy[i].cantDesarrolladores);
                    }
                }
            }
        }
    }
}

void mostrarProyectoMayorDesarrolladores(Proyecto *proy, int cant, char lenguaje[])
{
    int cantidadDesarrolladores = 0, cont = 0, indiceMax = -1;
    for (int i = 0; i < cant; i++)
    {
        cant = 0;
        for (int j = 0; j < proy[i].cantDesarrolladores; j++)
        {
            if (strcmp(proy[i].asignado[j].lenguaje, lenguaje) == 0)
            {
                cont++;
            }
        }
        if (cant > cantidadDesarrolladores)
        {
            cantidadDesarrolladores = cant;
            indiceMax = i;
        }
    }
    if (indiceMax != -1 && cantidadDesarrolladores > 0)
    {
        printf("PROYECTO CON MAS DESARROLLADORES DE %s: %s", lenguaje, proy[indiceMax].cod);
    }
    else
    {
        printf("NO se encontraron proyectos con desarrolladores que usen %s", lenguaje);
    }
}

float calcularCostoPromedioAntiguedad(Proyecto *proy, int cant, int antiguedadMinima)
{
    float suma = 0, promedio = 0, contador = 0;
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j < proy[i].cantDesarrolladores; j++)
        {
            if (proy[i].asignado[j].antig > 5)
            {
                suma += proy[i].costo;
            }
        }
        contador++;
    }
    if (contador != 0)
    {
        promedio = suma / contador;
    }
    return promedio;
}

void liberarMemoria(Proyecto *proy, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        free(proy[i].asignado);
    }
    free(proy);
}