ALGORITMO 2
ENTRADA: c: caracter, MF='.'
SALIDA: fraseIngresada, fraseSalida: cadena de caracteres, cant_doble: entero
VAR. AUX.: anterior, espacio: caracter, tieneDoble: bool

A0. Inicializar
A1. ProcesarFrase
A2. MostrarResultados
A3. FIN_ALGORITMO

A0. Inicializar
    anterior <-  ' '
    cant_doble <- 0
    tieneDoble <- 0

A1. ProcesarFrase
    LEER(c)
    MIENTRAS (c <> MF)
        SI(c = ' ') ENTONCES
            ESCRIBIR('#')
        SINO  
            ESCRIBIR(c)
        FIN_SI

        SI( anterior = c) ENTONCES
            tieneDoble <- 1
        FIN_SI

        SI(tieneDoble = 1) ENTONCES
            cant_doble <- cant_doble + 1
        anterior <- c
        LEER(c)
    FIN_MIENTRAS

A2. MostrarResultados
    ESCRIBIR(cant_doble)