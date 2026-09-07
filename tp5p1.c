#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

//CARGAR EL ARREGLO
void cargarArreglo(int participantes[], int tama)
{
    int i;
    for (i = 0; i < tama; i++)
    {
        int puntaje1 = rand() % 10 + 1;
        int puntaje2 = rand() % 10 + 1;
        int puntaje3 = rand() % 10 + 1;
        
        participantes[i] = puntaje1 + puntaje2 + puntaje3;
    }
}


void mostrarArreglo(int participantes[], int tama)
{
    int i = 0;
    while (i < tama)
    {
        printf("PARTICIPANTE %d : %d pts\n", i + 1, participantes[i]);
        i++;
    }
}


int buscarEliminado(int participantes[], int tama, int salvado1, int salvado2, int salvado3)
{
    int min = 31; // Puntaje inicial más alto que el máximo posible (30)
    int indiceMin = -1; // -1 significa "aún no encontrado"

    // Recorremos el arreglo usando 'tama'
    for (int i = 0; i < tama; i++)
    {
        // 1. Verificamos que NO sea un salvado
        // Comparamos el índice (i) con el número de participante (salvadoX - 1)
        // Usamos '&&' (Y) para asegurarnos que no sea NINGUNO de los tres.
        if (i != (salvado1 - 1) && i != (salvado2 - 1) && i != (salvado3 - 1))
        {
            // 2. Si no es salvado, comparamos su puntaje
            if (participantes[i] < min)
            {
                // ¡Encontramos un nuevo mínimo!
                min = participantes[i];
                indiceMin = i; // Guardamos el índice
            }
        }
    }
    
    // Devolvemos el índice del participante con el menor puntaje
    return indiceMin;
}


// --- FUNCION PRINCIPAL ---
int main()
{
    int tama = 8;
    int participantes[tama];
    
    // Inicializamos el generador de números aleatorios (solo 1 vez)
    srand(time(NULL));

    // --- 1. Cargar Arreglo ---
    cargarArreglo(participantes, tama);

    // --- 2. Mostrar Arreglo ---
    printf("--- PUNTUACIONES TOTALES ---\n");
    mostrarArreglo(participantes, tama);
    printf("------------------------------\n\n");

    // --- 3. Elegir Participantes Salvados (con validación) ---
    int salvado1, salvado2, salvado3;

    printf("--- SELECCION DEL COACH ---\n");
    
    // --- Validacion Salvado 1 ---
    // Usamos un bucle do-while para repetir si el dato es incorrecto
    do {
        printf("Elija el primer participante para salvar (1-8): ");
        scanf("%d", &salvado1);
        
        // Condición de error (fuera de rango)
        if (salvado1 < 1 || salvado1 > 8) {
            printf("Error: El numero debe estar entre 1 y 8.\n");
        }
    } while (salvado1 < 1 || salvado1 > 8); // Repetimos si está fuera de rango


    // --- Validacion Salvado 2 ---
    do {
        printf("Elija el segundo participante para salvar (1-8): ");
        scanf("%d", &salvado2);

        // Condición de error (fuera de rango O repetido)
        if (salvado2 < 1 || salvado2 > 8) {
            printf("Error: El numero debe estar entre 1 y 8.\n");
        } else if (salvado2 == salvado1) {
            printf("Error: El participante %d ya fue salvado. Elija otro.\n", salvado1);
        }
    } while ((salvado2 < 1 || salvado2 > 8) || (salvado2 == salvado1));


    // --- Validacion Salvado 3 ---
    do {
        printf("Elija el tercer participante para salvar (1-8): ");
        scanf("%d", &salvado3);

        // Condición de error (fuera de rango O repetido con 1 O repetido con 2)
        if (salvado3 < 1 || salvado3 > 8) {
            printf("Error: El numero debe estar entre 1 y 8.\n");
        } else if (salvado3 == salvado1 || salvado3 == salvado2) {
            printf("Error: Ese participante ya fue salvado. Elija otro.\n");
        }
    } while ((salvado3 < 1 || salvado3 > 8) || (salvado3 == salvado1) || (salvado3 == salvado2));

    
    // --- 4. Mostrar Salvados ---
    printf("\n--- PARTICIPANTES SALVADOS ---\n");
    // Usamos (salvadoX - 1) para acceder al índice correcto en el arreglo
    printf("Participante %d: %d puntos.\n", salvado1, participantes[salvado1 - 1]);
    printf("Participante %d: %d puntos.\n", salvado2, participantes[salvado2 - 1]);
    printf("Participante %d: %d puntos.\n", salvado3, participantes[salvado3 - 1]);


    // --- 5. Buscar y Mostrar Eliminado ---
    int indiceEliminado = buscarEliminado(participantes, tama, salvado1, salvado2, salvado3);

    printf("\n--- RESULTADO DE LA ELIMINACION ---\n");
    if (indiceEliminado != -1) // Si se encontró un mínimo
    {
        // Sumamos 1 al índice para mostrar el número de participante correcto
        printf("El participante eliminado es el Nro %d, con %d puntos.\n", indiceEliminado + 1, participantes[indiceEliminado]);
    } else {
        // Esto solo pasaría si todos los no-salvados empatan con 31 (muy improbable)
        printf("No se encontro un eliminado.\n");
    }

    return 0;
}