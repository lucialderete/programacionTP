#include <stdio.h>

int main()
{
    float ph1, ph2, ph3, phPromedio, maximo, minimo;
    int muestra, rango, alerta;

    printf("\nIngrese el primer valor: ");
    scanf("%f", &ph1);
    printf("\nIngrese el segundo valor: ");
    scanf("%f", &ph2);
    printf("\nIngrese el tercer valor; ");
    scanf("%f", &ph3);

    if ((ph1 < 0) || (ph1 > 14))
    {
        printf("\nEl valor del pH 1 debe estar entre 0 y 14");
    }
    else if ((ph2 < 0) || (ph2 > 14))
    {
        printf("\nEl valor del pH 1 debe estar entre 0 y 14");
    }
    else if ((ph3 < 0) || (ph3 > 14))
    {
        printf("\nEl valor del pH 1 debe estar entre 0 y 14");
    }
    else
    {
        printf("\nIngrese el tipo de muestra: (1: agua potable, 2: suelo agricola, 3: alimento acido");
        scanf("%d", &muestra);

        phPromedio = (ph1 + ph2 + ph3) / 3;
        printf("\nREPORTE: ");
        printf("\npH promedio: %.2f", phPromedio);

        

        switch (muestra)
        {
        case 1:
            minimo = 6.5;
            maximo = 8.5;
            break;
        case 2:
            minimo = 5.5;
            maximo = 7.5;
            break;
        case 3:
            minimo = 4.0;
            maximo = 7.0;
            break;
        default:
            printf("\nIngrese un numero valido");
            break;
        }
        printf("\nRango: %.2f, %.2f", minimo, maximo);
        printf("\nEstado: ");
        if (phPromedio < minimo)
        {
            printf("\nPor debajo del rango");
            if((minimo - phPromedio) > 1.0){
                printf("\nalerta prioritaria");
            }
            
        }else if(phPromedio > maximo){
            printf("\npor encima del rango");
            if((maximo - phPromedio) > 1.0){
                printf("\nalerta prioritari");
            }
        }else{
            printf("\ndentro del rango");
            if(((phPromedio - minimo) < 0.2) || ((maximo - phPromedio) < 0.2)){
                printf("\ncerca del limite");
            }
        }
    }

    return 0;
}