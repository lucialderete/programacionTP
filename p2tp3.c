#include <stdio.h>
#include <ctype.h> // Para isalpha, isdigit

int main() {
    char c;
    int cantPalabras = 0;
    int longitudPalabra = 0;
    int palabraMax = 0;
    int palabraMin = 999999; // Inicializado con un valor muy grande
    int totalCaracteres = 0;
    int espacios = 0;
    int dentroDePalabra = 0; // 0 = no estamos en palabra, 1 = estamos en palabra
    float promedio, porcentaje;

    printf("Ingrese la secuencia de caracteres (finalice con un punto '.'): \n");

    // Primera lectura
    c = getchar();

    // Procesar mientras no se ingrese '.'
    while (c != '.') {
        // Validar que el caracter sea letra, número o espacio
        if (!(isalpha(c) || isdigit(c) || c == ' ')) {
            printf("Error: caracter no valido detectado: '%c'\n", c);
            return 1; // Termina el programa
        }

        totalCaracteres++; // Contar el carácter (menos el punto final)

        if (c == ' ') {
            espacios++;
            // Si veníamos formando una palabra, la cerramos
            if (dentroDePalabra == 1) {
                cantPalabras++;
                if (longitudPalabra > palabraMax) palabraMax = longitudPalabra;
                if (longitudPalabra < palabraMin) palabraMin = longitudPalabra;
                longitudPalabra = 0;
                dentroDePalabra = 0;
            }
        } else {
            // Parte de una palabra
            longitudPalabra++;
            dentroDePalabra = 1;
        }

        // Leer el siguiente caracter
        c = getchar();
    }

    // Si la secuencia termina justo después de una palabra
    if (dentroDePalabra == 1) {
        cantPalabras++;
        if (longitudPalabra > palabraMax) palabraMax = longitudPalabra;
        if (longitudPalabra < palabraMin) palabraMin = longitudPalabra;
    }

    // Control por si no se ingresaron palabras
    if (cantPalabras == 0) {
        printf("No se ingresaron palabras.\n");
        return 0;
    }

    // Calcular promedio y porcentaje
    promedio = (float)(totalCaracteres - espacios) / cantPalabras;
    porcentaje = (float)espacios * 100 / totalCaracteres;

    // Mostrar resultados
    printf("\nResultados:\n");
    printf("Cantidad de palabras: %d\n", cantPalabras);
    printf("Longitud de la palabra mas larga: %d\n", palabraMax);
    printf("Longitud de la palabra mas corta: %d\n", palabraMin);
    printf("Promedio de caracteres por palabra: %.2f\n", promedio);
    printf("Porcentaje de espacios sobre el total de caracteres: %.2f%%\n", porcentaje);

    return 0;
}
