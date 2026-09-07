ALGORITMO PALABRAS
ENTRADA: c: caracter, MF = '.'
SALIDA: vocales, consontantes, palabras: entero
        esletra: booleno
VAR. AUX: anterior: caracter
A0. Inicializar
    vocales <- 0
    consontantes <-0
    palabras<- 0
    esletra <- 0
    anterior <- ' '
A1. LEER(c)
A2. procesar_caracter
A3. mostrar_resultados
A4. FIN_ALGORITMO

A2. procesar_caracter
   
    MIENTRAS(c <> MF) ENTONCES
        SI(c = 'a' o c='e' o c = 'i' o c = 'o' o c='u') ENTONCES
            vocales <- vocales + 1
        SINO 
            consontantes <- consontantes + 1
        FIN_SI

        
        SI(c<>' ' Y anterior = ' ' )ENTONCES
            palabras <- palabras + 1
            
        FIN_SI

        anterior <- c
        LEER(c)
    FIN_MIENTRAS
     
A3. mostrar_resultados
    
    ESCRIBIR(vocales)
    ESCRIBIR(consontantes)
    ESCRIBIR(palabras)

