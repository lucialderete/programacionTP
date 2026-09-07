ALGORTIMO CONTADOR_DIPTONGOS
ENTRADA: c: cadena de caracteres con MF = '.'
SALIDA: palabrasA, palabrasUI: entero, promLetras: real
VAR. AUX: ant: caracter, contCaract, contPalabras: entero

A1. Inicializar
    palabrasA <-- 0
    palabrasUI <-- 0
    promLetras <--0
    contCaract <-- 0
    ant <-- ' '
A2. LEER(c)
A2. procesarCaracter
A3. mostrarResultados
A4. FIN ALGORTIMO

A2. procesarCaracter
    MIENTRS(c<> MF)
        SI(c<> ' ')ENTONCES
            contCaract <- contCaract + 1
            SI(ant = ' ')ENTONCES
                contPalabras <- contPalabras + 1
            FIN SI
        FIN SI
    
        SI(ant = ' ' Y c='a')ENTONCES
            palabrasA <-- palabrasA +1
        FIN SI
        SI(ant = ' u' Y c='i')ENTONCES
            contadorUI <-- contadorUI + 1
        FIN SI
        ant <- c
        LEER(c)
    FIN MIENTRAS

    promLetras <-- (contCaract / contPalabras)

A3. mostrar_resultados
    ESCRIBIR(palabrasA, contadorUI, promLetras)


amanecio con ruido.

