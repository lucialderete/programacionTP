#include <stdio.h>
#include <stdlib.h>

int main() {
    float ph1, ph2, ph3, promedio;
    float min, max;  
    int tipoMuestra;

    // Mostrar opciones de tipo de muestra
    printf("Seleccione el tipo de muestra:\n");
    printf("1. Agua potable (6.5 - 8.5)\n");
    printf("2. Suelo agricola (5.5 - 7.5)\n");
    printf("3. Alimento acido (4.0 - 7.0)\n");
    printf("Opcion: ");
    scanf("%d", &tipoMuestra);

    // Asignar rango según el tipo elegido
    switch(tipoMuestra) {
        case 1:
            min = 6.5;
            max = 8.5;
            break;
        case 2:
            min = 5.5;
            max = 7.5;
            break;
        case 3:
            min = 4.0;
            max = 7.0;
            break;
        default:
            printf("Opcion invalida.\n");
            return 1;
    }

    // Ingreso de lecturas de pH
    printf("Ingrese las tres lecturas de pH separadas por espacio: ");
    scanf("%f %f %f", &ph1, &ph2, &ph3);

    // Validar que cada pH esté en el rango [0, 14]
    if (ph1 < 0 || ph1 > 14 || ph2 < 0 || ph2 > 14 || ph3 < 0 || ph3 > 14) {
        printf("Error: Al menos una lectura esta fuera del rango valido (0-14).\n");
        printf("No se continuara con la evaluacion.\n");
        return 1;
    }

    // Calcular promedio
    promedio = (ph1 + ph2 + ph3) / 3.0;

    // Mostrar pH promedio
    printf("\nPH promedio: %.2f\n", promedio);

    // Comparar promedio con el rango
    if (promedio < min) {
        printf("El pH promedio esta por DEBAJO del rango recomendado.\n");

        // Alerta prioritaria
        if ((min - promedio) > 1.0) {
            printf("Alerta prioritaria\n");
        }

    } else if (promedio > max) {
        printf("El pH promedio esta por ENCIMA del rango recomendado.\n");

        // Alerta prioritaria
        if ((promedio - max) > 1.0) {
            printf("Alerta prioritaria\n");
        }

    } else {
        printf("El pH promedio esta DENTRO del rango recomendado.\n");

        // Cerca del límite
        if ((promedio - min) < 0.2 || (max - promedio) < 0.2) {
            printf("Cerca del limite\n");
        }
    }

    return 0;
}
