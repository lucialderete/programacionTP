ALGORITMO CARACTERES
ENTRADA: c, letra: caracter, MF = '.'
SALIDA: totalCaracteres, totalVocales, totalLetra, cantPalabras, cantPalabraEspec: entero

VAR. AUX.: anterior: caracter
CONSTANTES: 

A0. Inicializar
A1. LEER(letra, c)
A2. ProcesarFrase
A3. ESCRIBIR(totalCaracteres, totalVocales, totalLetra, cantPalabras, cantPalabraEspec)
A4. FIN ALGORITMO

A0. Inicializar
    totalCaracteres <- 0
    totalVocales <- 0
    totalLetra <- 0
    cantPalabras <- 0
    cantPalabraEspec <- 0
    anterior <- ' '


A2. ProcesarFrase
    MIENTRAS (c <> MF)
    totalCaracteres <- totalCaracteres + 1
    SI(c == 'a' ∨ c=='e' ∨ c == 'i' ∨ c == 'o' ∨ c== 'u' 
       ∨ c == 'A' ∨ c=='E' ∨ c == 'I' ∨ c == 'O' ∨ c== 'U') ENTONCES
        totalVocales <- totalVocales + 1
    FIN SI
    SI( c == letra) ENTONCES
        totalLetra <- totalLetra + 1
    FIN SI
    
    SI(anterior = ' ' ∧  c<> ' ') ENTONCES
        cantPalabras <- cantPalabras + 1
        SI(c = letra) ENTONCES
            cantPalabraEspec <- cantPalabraEspec + 1
        FIN SI
    FIN SI

    anterior <- c
    LEER(c)

    FIN MIENTRAS

