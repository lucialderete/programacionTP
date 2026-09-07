#include <stdio.h>

int main(){
    int billetesMil, billetesDosMil, billetesDiezMil, billetesVeintMil;
    int retiro=0, total;
    int aux=0;
    int totalRetiros=0, totalEntregado=0;

    printf("Ingrese la cantidad de billetes de MIL que tiene el cajero: ");
    scanf("%d", &billetesMil);
    printf("\nIngrese la cantidad de billetes de DOS MIL que tiene el cajero: ");
    scanf("%d", &billetesDosMil);
    printf("\nIngrese la cantidad de billetes de DIEZ MIL que tiene el cajero: ");
    scanf("%d", &billetesDiezMil);
    printf("\nIngrese la cantidad de billetes de VEINTE MIL que tiene el cajero: ");
    scanf("%d", &billetesVeintMil);



    printf("\n------------------------");

    printf("\nIngrese la cantidad de dinero que desea retirar: ");
    scanf("%d", &retiro);

    total = (billetesMil * 1000) + (billetesDosMil * 2000) + (billetesDiezMil * 10000) + (billetesVeintMil * 20000);


    if(retiro % 1000 == 0){
        while (retiro <= total)
        {
            if(retiro <= (billetesMil * 1000)){
                retiro = ()
            }
        }
        


    }else{
        printf("\nERROR");
        printf("\nEl monto a retirar debe ser multiplo de mil");
        scanf("%d", &retiro);
    }

    return 0;
}