#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define TAMA 50

void cargarPalabra(char palabra[]);
void convertirPalabra(int longitud, char guiones[]);
void compararPalabras(char guiones[], char palabra[], int longitud);

int main()
{
    char palabra[TAMA], guiones[TAMA];
    char letras;
    int longitud;
    cargarPalabra(palabra);
    longitud = strlen(palabra);
    convertirPalabra(longitud, guiones);
    compararPalabras(guiones, palabra, longitud);
    return 0;
}

void cargarPalabra(char palabra[])
{
    printf("\nIngrese la palabra: ");
    scanf("%s", palabra);
    fflush(stdin);
}

void convertirPalabra(int longitud, char guiones[])
{
    for (int i = 0; i < longitud; i++)
    {
        guiones[i] = '_';
    }
    guiones[longitud] = '\0';
}

void compararPalabras(char guiones[], char palabra[], int longitud)
{
    int intentos = 3;
    int ganaste = 0;
    char letra;
    int aciertos;

    while (intentos > 0 && ganaste == 0)
    {
        printf("\nPalabra: ");
        for (int i = 0; i < longitud; i++)
        {
            printf("%c ", guiones[i]);
        }
        printf("Intentos disponibles: %d", intentos);
        printf("\nIngrese una letra: ");
        scanf(" %c", &letra);
        aciertos = 0;
        for(int i=0; i<longitud; i++){
            if(palabra[i] == letra){
                guiones[i] = letra;
                aciertos = 1;
            }

        }
        if(aciertos == 0){
            intentos--;
            printf("\nLa letra %c no esta en la palabra :c", letra);
        }else{
            if(strcmp(palabra, guiones)==0){
                ganaste = 1;
            }
        }
    }
    if(ganaste == 1){
        printf("\nGanaste, la palabra es: %s: ", palabra);

    }else{
        printf("\nPerdistee, la palabra era: %s ", palabra);
    }
}
