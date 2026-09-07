#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Definimos constantes para que sea facil leer
#define DESC 0.15
#define CUOTA3 0.10
#define CUOTA6 0.25
#define CUOTA12 0.60
#define DESCPERFUM 0.05
#define RECARGOBEB 0.05

// 1. FUNCION MONTO ITEM CORREGIDA
float monto_item(int categoria, int cantidad, float precioUnidad)
{
    float precioTotal = 0; // OJO: Usar float, no int
    int aux, sobrante;

    // Calculo base por si acaso
    float precioBase = cantidad * precioUnidad;

    switch (categoria)
    {
    case 1: // 3x2
        aux = cantidad / 3;
        int a_pagar = cantidad - aux;
        precioTotal = a_pagar * precioUnidad;
        break;
    case 2: // 2da al 50%
        aux = cantidad / 2;
        sobrante = cantidad % 2;
        precioTotal = (aux * 1.5 * precioUnidad) + (sobrante * precioUnidad);
        break;
    case 3: // Perfumeria
        precioTotal = precioBase * (1 - DESCPERFUM);
        break;
    case 4: // Bebidas s/alcohol
        precioTotal = precioBase;
        break;
    case 5: // Bebidas c/alcohol
        precioTotal = precioBase * (1 + RECARGOBEB);
        break;
    default:
        precioTotal = 0;
        break;
    }
    
    return precioTotal; // OJO: Muy importante devolver el valor
}

// 2. FUNCION MOSTRAR ITEM (Estaba bien)
void mostrarItem(int categoria, int cantidad, float precioUnidad, float precioCantidad)
{
    printf("\n--- Resumen del Item ---");
    printf("\nCATEGORIA: %d ", categoria);
    printf("\nCANTIDAD: %d", cantidad);
    printf("\nPRECIO UNITARIO: $%.2f", precioUnidad);
    printf("\nTOTAL ITEM: $%.2f\n", precioCantidad);
}

// 3. FUNCION MEDIO DE PAGO CORREGIDA
float totalMedioPago(char medio, int cuotas, float total)
{
    float totalFinal = total;

    switch (medio)
    {
    case 'E':
    case 'T':
        totalFinal = total * (1 - DESC);
        break;
    case 'D': // Debito suele ser precio de lista
        totalFinal = total;
        break;
    case 'C':
        // Las cuotas ya vienen por parametro o se piden aqui (el enunciado pedia pedirlas fuera, 
        // pero tu logica de pedirlas dentro es valida si ajustamos el parametro)
        
        switch (cuotas)
        {
        case 1: // 1 cuota es 0% interes normalmente
             totalFinal = total; 
             break;
        case 3:
            totalFinal = total * (1 + CUOTA3);
            break;
        case 6:
            totalFinal = total * (1 + CUOTA6);
            break;
        case 12:
            totalFinal = total * (1 + CUOTA12);
            break;
        default:
            printf("\nCuotas no validas, se cobra precio de lista.");
            break;
        }
        break; // Faltaba este break del case 'C'
    default:
        printf("\nMedio de pago desconocido.");
        break;
    }
    return totalFinal; // OJO: Devolver el valor
}

// 4. FUNCION VALIDACION CORREGIDA
int validacion(int categoria, int cantidad, float precioUnidad)
{
    // Si queremos cerrar el ticket con categoria 0, no es un "error", 
    // pero validacion debe decir que paremos.
    if (categoria == 0) return 0;

    if (categoria < 1 || categoria > 5)
    {
        printf("\nError: Categoria invalida\n");
        return 0; // OJO: Devuelve 0 (Falso) para indicar error
    }
    if (cantidad <= 0) // Cantidad 0 o negativa es error
    {
        printf("Error: Cantidad invalida\n");
        return 0;
    }
    if (precioUnidad <= 0)
    {
        printf("Error: Precio invalido\n");
        return 0;
    }
    
    return 1; // OJO: Devuelve 1 (Verdadero) si todo está bien
}

void mostrarMenu()
{
    printf("\n---- CATEGORIAS ----\n");
    printf("1. Alimentos (3x2)\n2. Limpieza (2da 50%%)\n3. Perfumeria (5%% off)\n4. Bebidas s/alcohol\n5. Bebidas c/alcohol (+5%%)\n0. CERRAR TICKET\n");
}

// 5. MAIN ORGANIZADO (EL FLUJO PRINCIPAL)
int main()
{
    int categoria, cantidad, cuotas = 0;
    char medio;
    float precioUnidad;
    
    // Variables acumuladoras
    float subtotalCompra = 0;
    float precioItem = 0;
    float totalFinalPagar = 0;
    
    int continuar = 1; // Bandera para el bucle

    printf("=== CAJA REGISTRADORA ===\n");

    // BUCLE PRINCIPAL: Mientras continuar sea 1 (Verdadero)
    while (continuar == 1) 
    {
        mostrarMenu();

        printf("\nIngrese categoria (0 para terminar): ");
        scanf("%d", &categoria);

        // Si pone 0, salimos antes de pedir lo demas
        if (categoria == 0) {
            continuar = 0;
        } 
        else {
            printf("Ingrese cantidad: ");
            scanf("%d", &cantidad);

            printf("Ingrese precio por unidad: ");
            scanf("%f", &precioUnidad);

            // 1. VALIDAMOS
            if (validacion(categoria, cantidad, precioUnidad) == 1) 
            {
                // 2. CALCULAMOS MONTO ITEM
                precioItem = monto_item(categoria, cantidad, precioUnidad);
                
                // 3. MOSTRAMOS ITEM
                mostrarItem(categoria, cantidad, precioUnidad, precioItem);
                
                // 4. ACUMULAMOS AL SUBTOTAL
                subtotalCompra += precioItem;
            } 
            else 
            {
                // Si validacion dio 0 (error), cerramos el ticket segun enunciado
                // O podriamos solo avisar y seguir (depende de tu profesor).
                // El enunciado dice: "retorna 0 para que se cierre el ticket"
                printf("Dato incorrecto. Cerrando ticket...\n");
                continuar = 0; 
            }
        }
    }

    // FUERA DEL BUCLE (CIERRE DE TICKET)
    if (subtotalCompra > 0) 
    {
        printf("\n\n=== CIERRE DE TICKET ===");
        printf("\nSubtotal acumulado: $%.2f", subtotalCompra);
        
        printf("\nIngrese medio de pago (E, T, D, C): ");
        scanf(" %c", &medio);
        medio = toupper(medio); // OJO: Asi se usa toupper

        if (medio == 'C') {
            printf("Ingrese cuotas (1, 3, 6, 12): ");
            scanf("%d", &cuotas);
        }

        // 5. CALCULO FINAL CON MEDIO DE PAGO
        totalFinalPagar = totalMedioPago(medio, cuotas, subtotalCompra);

        printf("\n-------------------------");
        printf("\nMONTO FINAL A PAGAR: $%.2f", totalFinalPagar);
        printf("\n-------------------------\n");
    }
    else {
        printf("\nNo hubo venta.\n");
    }

    return 0;
}