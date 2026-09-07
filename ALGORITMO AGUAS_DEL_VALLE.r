ALGORITMO AGUAS_DEL_VALLE
ENTRADA: categoria, pago: caracter, consumo: real
SALIDA: importeFinal, totalIva, totalSinIva, totalpagar: real
VAR. AUX:
CONSTANTES: CARGOH = 1200
            CARGOHMIN = 45
            CARGOHMAX = 70
            CARGOC = 3000
            CARGOCMIN = 60
            CARGOCMAX = 95
            CARGOI = 7500
            CONSMOI= 130
            FONDOAMBIENTAL = 0.02
            IVA = 0.21
            DESCEFECT = 0.04
            RECARGOTARJ = 0.015
            MINIMOH = 20
            MINIMOC = 50

A0. Inicializar
    importeFinal <- 0
    totalIva <- 0
    totalSinIva <- 0
A1. LEER(categoria, pago, consumo)
A2. ProcesarLiquidacion
A3. ESCRIBIR(importeFinal, totalIva,totalSinIva)
A4. FIN_ALGORITMO


A2. ProcesarLiquidacion
    MIENTRAS(categoria <> 'F')
        SEGUN (categoria)
            'H': SI(consumo <= MINIMOH) ENTONCES
                    precio <- CARGOH + (consumo * CARGOHMIN )
                SINO 
                    precio <- CARGOH + (consumo - MINIMOH) * CARGOHMAX + MINIMOH * CARGOHMIN
                FIN_SI
            'C': SI(consumo <= MINIMOC) ENTONCES
                    precio <- CARGOC + (consumo * CARGOCMIN)
                 SINO
                    precio <- CARGOC + (consumo - MINIMOC)*CARGOCMAX + MINIMOC * CARGOCMIN
                FIN_SI
            'I': precio <- (consumo * CONSMOI) + CARGOI
        FIN_SEGUN

        SI(consumo > 120)ENTONCES
            totalSinIva <- precio * (1 + FONDOAMBIENTAL)
        SINO
            totalSinIva <- precio
        FIN_SI

        totalIva <- totalSinIva * (1 + IVA)

        SEGUN(pago)
            'E': totalpagar <- totalIva * (1 - DESCEFECT)
            'T': totalpagar <- totalIva * (1 +  RECARGOTARJ)
            'D': totalpagar <- totalIva
        FIN_SEGUN
        LEER(categoria, pago, consumo)
    FIN_MIENTRAS
            

