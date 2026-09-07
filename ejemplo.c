#include <stdio.h>
float calcularCuotas(int antiguedad, float sueldo, float prestamo, int cuotas);

int main(){
    
    int numEmpleados, cuotas, antiguedad, i;
    float sueldo, prestamo;

    int aplica = 0;
    int noaplica = 0;
    float valorcuota = 0;
    float totalinvertido = 0;
    float porcentajeNoApto = 0;

    printf("Ingrese la cantidad de empleados: ");
    scanf("%d", &numEmpleados);
    
    for (i = 0; i < numEmpleados; i++)
    {
        printf(" \nIngrese la antiguedad: ");
        scanf("%d", &antiguedad);
        
        printf(" \nIngrese el sueldo  neto: ");
        scanf("%f", &sueldo);

        printf(" \nIngrese el monto solicitado: ");
        scanf("%f", &prestamo);

        printf(" \nIngrese la cantidad de cuotas: ");
        scanf("%d", &cuotas);

        if (antiguedad < 4 || sueldo >  950000)
        {
            printf(" \nNo es posible realizar el prestamo \n");
            noaplica ++;

        }else{
            valorcuota = calcularCuotas(antiguedad, sueldo, prestamo, cuotas);
            if (valorcuota > 0)
            {
                printf(" \nEL valor de la cuota a abonar es de %.2f \n", valorcuota);
                aplica ++;
                totalinvertido += prestamo;

            }else{
                printf(" \nno aplica para solicitar el prestamo \n");
                noaplica ++;
            }
        }
        
    }
    porcentajeNoApto = (noaplica * 100)/ numEmpleados;

    printf(" \nCantidad de empleados aptos para el prestamo: %d", aplica);
    printf(" \nCantidad de empleados no aptos para el prestamo: %d", noaplica);
    printf(" \nTotal invertido :  %.2f", totalinvertido);
    printf(" \nEl porcentaje de personas no aptas:  %.2f", porcentajeNoApto);

    return 0;
}

    float calcularCuotas(int antiguedad, float sueldo, float prestamo, int cuotas){
        float interes, valorcuota;
        switch (cuotas)
        {
        case 12:
            interes = 0.34;
            break;
        case 24: 
            interes = 0.48;
            break;
        case 48: 
            interes = 0.68;
            break;
        default: 
            printf("Cantidad de cuotas no válida.\n");
            return 0;
        }
        valorcuota = (prestamo + (prestamo * interes) ) / cuotas;

        return valorcuota;
    }
