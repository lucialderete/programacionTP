ALGORITMO CONTROL DE CALIDAD
ENTRADA: codigoPieza: entero, peso: real, calidad: caracter
SALIDA: total: entero, piezasRechazadas, pesoPiezaAprobada: real
VAR. AUX: rechazadas: entero
CONSTANTES:
A0. Inicializar
A1. LEER(codigoPieza)
A3. ProcesarPieza
A4. ESCRIBIR(total, piezasRechazadas, pesoPiezaAprobada)
A5. FIN_ALGORITMO

A0. Inicializar
    total <- 0
    piezasRechazadas <- 0
    pesoPiezaAprobada <- 0
    rechazadas <- 0
    pesoAux <- 0

A3. ProcesarPieza
    MIENTRAS(codigoPieza <> 0)
        total <- total + 1
        LEER(peso, calidad)
        SEGUN (calidad)
            'R': rechazadas <- rechazadas + 1
                 piezasRechazadas <- (rechazadas / total)*100
            'A': SI(peso > pesoPiezaAprobada) ENTONCES
                    pesoPiezaAprobada <- peso
                 FIN_SI
        FIN_SEGUN
        LEER(codigoPieza)
    FIN_MIENTRAS