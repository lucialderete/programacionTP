ALGORTIMO SECUENCIA
ENTRADA: c: caracter, MF='.'
SALIDA: totalab, total12, total: entero
VAR. AUX: anterior: caracter

A0.Inicializar
    totalab <- 0
    total12 <- 0
    total <- 0
    anterior <- ' '
A1.LEER(c)
A2.MIENTRAS(c <> MF)
        procesar_secuencia
    FIN_MIENTRAS
A3. mostrar_resultados
A4. FIN_ALGORITMO


procesar_secuencia
SI(anterior == 'a' Y c == 'b') ENTONCES
    totalab <- totalab + 1
FIN_SI
SI(anterior == '1' Y c == '2' ) ENTONCES
    total12 <- total12 +1
FIN_SI

SI(c <> ' ') ENTONCES
    total <- total + 1
FINSI

