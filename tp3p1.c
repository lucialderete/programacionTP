#include <stdio.h>

int main()
{
    int num;
    int cantPrimos = 0, sumaPrimos = 0, sumImpares = 0, cantidad=0;
    int aux, dig, div=0, i ;

    printf("Ingrese un numero entero entere 10 y 999999: ");
    scanf("%d", &num);

    if ((num < 10) || (num > 999999))
    {
        printf("\nEl numero no es valido. ingrese otro");
        scanf("%d", &num);
    }
    else
    {

        aux = num;
        while (aux > 0)
        {
            dig = aux % 10;
            cantidad ++;
            if (dig % 2 != 0)
            {
                sumImpares += dig;
            }
            for (i = 1; i < dig; i++)
            {
                if (dig % i == 0)
                {
                    div += 1;
                }
            }
            if (i == 2)
            {
                cantPrimos += 1;
                sumaPrimos += dig;
            }
            aux = aux / 10;
        }
    }
    printf("\nEl numero ingresado es: %d", num);
    printf("\nCantidad de digitos: %d", cantidad);
    printf("\nCantidad de digitos primos: %d", cantPrimos);
    printf("\nSuma de digitos primos: %d", sumaPrimos);
    printf("\nSuma de impares: %d", sumImpares);
    return 0;
}