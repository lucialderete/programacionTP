#include <stdio.h>
int main()
{
    int a, b;
    int *pa, *pb;

    printf("Ingrese el primer numero: ");
    scanf("%d", &a);

    printf("\n Ingrese el segundo numero: ");
    scanf("%d", &b);

    pa = &a;
    pb = &b;

    printf("\n MOSTRAR RESULTADOS: ");
    printf("\n El contenido de lo que apunta el puntero PA: %d", *pa);
    printf("\n El contenido de lo que apunta el puntero PB: %d", *pb);
    printf("\n Lo que contiene de dato el puntero: %p", pa);
    printf("\n Lo que contiene de dato el puntero PB: %p", pb);
    printf("\n La direccion de memoria de la variable a: %p", &a);
    printf("\n La direccion de memoria de la variable b: %p", &b);
    printf("\n Lo que contiene de dato la variable a: %d", a);
    printf("\n Lo que contiene de dato la variable b: %d", b);

    return 0;
}