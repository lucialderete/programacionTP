#include <stdio.h>
#include <ctype.h>

int main()
{
    int dia, mes, anio, bisiesto, dias;
    printf("Ingrese el dia:");
    scanf("%d", &dia);
    fflush(stdin);
    printf("\nIngrese el mes: ");
    scanf("%d", &mes);
    fflush(stdin);
    printf("\nIngrese el anio: ");
    scanf("%d", &anio);
    fflush(stdin);

    if (anio >= 1)
    {
        if (mes >= 1 && mes <= 12)
        {
            if (anio % 400 == 0)
            {
                bisiesto = 0;
            }
            else
            {
                bisiesto = 1;
            }

            switch (mes)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                dias = 31;
                break;
            case 2:
                if (bisiesto == 0)
                {
                    dias = 29;
                }
                else
                {
                    dias = 28;
                }

            default:
                dias = 30;
                break;
            }
            if (dia < 1 || dia > dias)
            {
                printf("dia del mes invalido\n");
            }
            else
            {
                printf("fecha valida\n");
            }
            printf("FECHA: %d/%d/%d \n", dia, mes, anio);

            if(bisiesto == 0){
                printf("Anio bisiesto: SI\n");
            }else{
                printf("anio bisiesto: NO \n");
            }
            
            if (mes >= 1 && mes <= 3)
            {
                printf("Trimestre: T1\n");
            }
            else if (mes >= 4 && mes <= 6)
            {
                printf("Trimestre: T1\n");
            }
            else if (mes >= 7 && mes <= 9)
            {
                printf("Trimestre: T3\n");
            }
            else if (mes >= 10 && mes <= 12)
            {
                printf("Trimestre: T4 \n");
            }
            
            

            if ((mes >= 6 && dia >= 21) || (mes <= 9 && dia <= 21))
            {
                printf("INVIERNO: Si");
            }
            else
            {
                printf("invierno: NO");
            }
            
        }
        else
        {
            printf("FECHA INVALIDA: mes fuera de rango\n");
        }
    }

    else
    {
        printf("FECHA INVALIDA. \n el anio debe ser mayor a 1\n");
    }

    return 0;
}
