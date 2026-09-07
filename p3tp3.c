#include <stdio.h>

int main()
{
    int billeteMil, billeteDosmil, billeteDiezmil, billeteVeintemil, total;
    int cantidadRetiros = 0;
    int dineroRetirado = 0;
    int monto = 0;

    // cargar cajero
    printf("INGRESE LA CANTIADAD DE BILLETES DE $1000: \n");
    scanf("%d", &billeteMil);
    printf("INGRESE LA CANTIDAD DE BILLETES DE $2000: \n");
    scanf("%d", &billeteDosmil);
    printf("INGRESE LA CANTIDAD DE BILLETES DE $10000: \n");
    scanf("%d", &billeteDiezmil);
    printf("INGRESE LA CANTIDAD DE BILLETES DE $20000: \n");
    scanf("%d", &billeteVeintemil);

    total = billeteDiezmil + billeteDosmil + billeteMil + billeteVeintemil;
    if (total == 0)
    {
        printf("no hay dinero en el cajero");
    }
    printf("EL MONTO INICIAL DEL CAJERO ES $%d\n", total);

    while (total > monto || total > 0)
    {
        printf("INGRESE EL MONTO A RETIRAR: \n");
        scanf("%d", &monto);

        if (monto%1000 = 0)
        {
             
        }
        
    }

    if (monto)
        return 0;
}