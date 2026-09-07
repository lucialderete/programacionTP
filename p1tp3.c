#include <stdio.h>
#include <stdlib.h>

int esPrimo(int n) {
    // Devuelve 1 si n es primo, 0 si no
    if (n < 2) return 0;          // 0 y 1 no son primos
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int numero, temp, digito;
    int cantidadDigitos = 0;
    int cantidadPrimos = 0;
    int sumaPrimos = 0;
    int sumaImpares = 0;

    // Ingreso del número
    printf("Ingrese un numero entero entre 10 y 999999: ");
    scanf("%d", &numero);

    // Validar rango
    if (numero < 10 || numero > 999999) {
        printf("Numero fuera de rango.\n");
        return 1;
    }

    temp = numero; // Guardar una copia para procesar

    // Procesar dígitos
    while (temp > 0) {
        digito = temp % 10;
        cantidadDigitos++;

        if (esPrimo(digito)) {
            cantidadPrimos++;
            sumaPrimos += digito;
        }

        if (digito % 2 != 0) {
            sumaImpares += digito;
        }

        temp /= 10;
    }

    // Mostrar resultados
    printf("\nNumero ingresado: %d\n", numero);
    printf("Cantidad de digitos: %d\n", cantidadDigitos);
    printf("Cantidad de digitos primos: %d\n", cantidadPrimos);
    printf("Suma de digitos primos: %d\n", sumaPrimos);
    printf("Suma de digitos impares: %d\n", sumaImpares);

    return 0;
}
