#include <stdio.h>
#include <ctype.h>

#define CARGO_H 1200
#define LIMITEH 20
#define HMIN 45
#define HMAX 70
#define CARGO_C 3000
#define LIMITEC 50
#define CMIN 60
#define CMAX 95
#define CARGO_I 7500
#define CARGOI 130
#define IVA 0.21
#define FA 0.02
#define DESCEFEC 0.04
#define RECARGTARJ 0.015
#define LIMITE 120

int main()
{
    char categoria, metodo;
    float consumo, totalPagar, totalSinIva, totalIva;
    printf("Ingrese la categoria de sus servicio (H=hogar, C=comercio, I=industria, F=finalizar):");
    scanf(" %c", &categoria);
    fflush(stdin);
    printf("\nIngrese el metodo de pago (E=efectivo, T=Tarjeta, D=debito automatico: ");
    scanf(" %c", &metodo);
    fflush(stdin);
    printf("\nIngrese el consumo en m3: ");
    scanf("%f", &consumo);
    fflush(stdin);

    if (categoria != 'F')
    {

        switch (categoria)
        {
        case 'H':
            if (consumo > LIMITEH)
            {
                totalSinIva = CARGO_H + (consumo - LIMITEH) * HMAX + LIMITEH * HMIN;
            }
            else
            {
                totalSinIva = CARGO_H + (consumo * HMIN);
            }
            break;

        case 'C':
            if (consumo > LIMITEC)
            {
                totalSinIva = CARGO_C + (consumo - LIMITEC) * CMAX + LIMITEC * CMIN;
            }
            else
            {
                totalSinIva = CARGO_C + (consumo * CMIN);
            }
            break;
        case 'I':
            totalSinIva = CARGO_I + consumo * CARGOI;
            break;

        default:
            break;
        }

        if (consumo > LIMITE)
        {
            totalSinIva = totalSinIva * (1 + FA);
        }

        totalIva = totalSinIva * (1 + IVA);

        switch (metodo)
        {
        case 'E':
            totalPagar = totalIva * (1 - DESCEFEC);
            break;
        case 'T':
            totalPagar = totalIva * (1 + RECARGTARJ);
            break;
        case 'D':
            totalPagar = totalIva;
            break;

        default:
            break;
        }

        printf("SUBTOTAL (sin IVA): $ %.2f \n", totalSinIva);
        printf("SUBTOTAL (con IVA): $ %.2f \n", totalIva);
        printf("TOTAL A PAGAR: $ %.2f \n", totalPagar);
    }

    return 0;
}