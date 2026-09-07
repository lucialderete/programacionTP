#include <stdio.h>
#include <ctype.h>
int main(){
    char frase[100], *p_frase;
    int contador =0;
    int *p_contador = &contador;

    puts("Ingrese una cadena en minuscula: ");
    gets(frase);

    p_frase = frase;

    while(*p_frase != '\0' && *p_frase != '\n')
    {
        if(*p_frase != 'a' && *p_frase != 'e' && *p_frase != 'i' && *p_frase != 'o' && *p_frase != 'u'){
            *p_frase = toupper(*p_frase);
            (*p_contador) ++;
        }
        
        p_frase++;

    }
    printf("\n La frase modificada: %c", p_frase);
    printf("\n Cantidad de consontantes: %d", p_contador);

    return 0;
}