#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//estructuras
typedef struct
{
    char nombre[MAX];
    int edad;
    float avance;
}Participantes;

typedef struct{
    char nombreTaller[MAX];
    char nivel[MAX];
    char categoria[MAX];
    int cantParticipantes;
    Participantes *participante;
}Talleres;

//modulos
void listarParticipantesMayoresYTallerCompleto(Talleres *taller, int cant);
void listarTalleresIAavanzado(Talleres *taller, int cant);
float calcularEdadPomedioTallerEspecifico(Talleres *taller, int cant, char tallerIngresado[]);
void liberarMemoria(Talleres *taller, int cant);


//funcion principal
int main(){
    int cant= 6; //cantidad inicial
    char tallerIngresado[MAX];
    float edadProm=0;
    printf("---BIENVENIDO AL FESTIVAL DE CIENCIA Y TECNOLOGIA---\n");
    Talleres *taller = (Talleres *)malloc(cant * sizeof(Talleres));


    //cargar datos
    taller[0] = (Talleres){
        "IA PARA TODOS", "INTERMEDIO", "IA", 3, (Participantes *)malloc(3 * sizeof(Participantes))
    };

    taller[0].participante[0] = (Participantes){
        "LUCIA", 22, 100
    };
    taller[0].participante[1] = (Participantes){
        "JAVIER", 32, 65
    };
    taller[0].participante[2] = (Participantes){
        "EMILIA", 40, 100
    };

    taller[1] = (Talleres){
        "IAPRENDIENDO", "AVANZADO", "IA", 4, (Participantes *)malloc(4 * sizeof(Participantes))
    };
    taller[1].participante[0] = (Participantes){
        "SAMIRA", 12, 32
    };
    taller[1].participante[1] = (Participantes){
        "AGUSTINA", 66, 100
    };
    taller[1].participante[2]=(Participantes){
        "MARIANA", 72, 10
    };
    taller[1].participante[3]= (Participantes){
        "AUGUSTO", 83, 100
    };

    taller[2]= (Talleres){
        "ROBOTICA PARA TODOS", "INCIAL", "ROBOTICA", 3, (Participantes *)malloc(3 * sizeof(Participantes))
    };
    taller[2].participante[0]= (Participantes){
        "CYNTHIA", 21, 73
    };
    taller[2].participante[1] = (Participantes){
        "CAMILA", 22, 100
    };
    taller[2].participante[2] = (Participantes){
        "CELIA", 46, 100
    };


    taller[3] = (Talleres){
        "IA PARA NADIE", "AVANZADO", "IA", 5, (Participantes *)malloc(5 * sizeof(Participantes))
    };
    taller[3].participante[0] = (Participantes){
        "BENJAMIN", 82, 100
    };
    taller[3].participante[1] = (Participantes){
        "AURELIA", 32, 72
    };
    taller[3].participante[2] = (Participantes){
        "BLANCA", 87, 100
    };
    taller[3].participante[3] = (Participantes){
        "MARIANO", 14, 100
    };
    taller[3].participante[4] = (Participantes){
        "FIORELLA", 54, 72
    };

    taller[4] = (Talleres){
        "PROGRAMANDO ANDO", "INTERMEDIO", "PROGRAMACION", 5, (Participantes *)malloc(5 * sizeof(Participantes))
    };
    taller[4].participante[0] = (Participantes){
        "SOFIA", 82, 100
    };
    taller[4].participante[1] = (Participantes){
        "VICTORIA", 32, 72
    };
    taller[4].participante[2] = (Participantes){
        "PAULA", 87, 100
    };
    taller[4].participante[3] = (Participantes){
        "KEVIN", 14, 100
    };
    taller[4].participante[4] = (Participantes){
        "MAURO", 54, 72
    };


    taller[5] = (Talleres){
        "BIOTECNOLOGIA TALLER", "INICIAL", "BIOTECNOLOGIA", 5, (Participantes *)malloc(5 * sizeof(Participantes))
    };
    taller[5].participante[0] = (Participantes){
        "HUGO", 43, 10
    };
    taller[5].participante[1] = (Participantes){
        "ROCIO", 54, 100
    };
    taller[5].participante[2] = (Participantes){
        "URIEL", 64, 32
    };
    taller[5].participante[3] = (Participantes){
        "LAUREANO", 32, 64
    };
    taller[5].participante[4] = (Participantes){
        "FACUNDO", 12, 83
    };


    listarParticipantesMayoresYTallerCompleto(taller, cant);
    listarTalleresIAavanzado(taller, cant);
    printf("Ingrese una categoria de taller: ");
    gets(tallerIngresado);
    edadProm = calcularEdadPomedioTallerEspecifico(taller, cant, tallerIngresado);
    printf("EDAD PROMEDIO DE LOS PARTICIPANTES DE LOS TALLERES DE %s: %.2f\n", tallerIngresado, edadProm);

    liberarMemoria(taller, cant);

    return 0;
}



//desarrollo de los modulos

void listarParticipantesMayoresYTallerCompleto(Talleres *taller, int cant){
    int edadMax=45;
    printf("PARTICIPANTES MAYORES A 45 ANIOS QUE ALCANZARON EL 100 DE AVANCE: \n");
    for(int i=0; i<cant; i++){
        for(int j=0; j<taller[i].cantParticipantes; j++){
            if(taller[i].participante[j].edad > edadMax){
                if(taller[i].participante[j].avance == 100){
                    printf("NOMBRE: %s | TALLER: %s | EDAD: %d | AVANCE: %.2f\n", taller[i].participante[j].nombre, taller[i].nombreTaller, taller[i].participante[j].edad, taller[i].participante[j].avance);
                }
            }
        }
    }
}

void listarTalleresIAavanzado(Talleres *taller, int cant){
    int inscriptos=0, suma=0;
    float prom =0;
    printf("---TALLERES DE IA NIVEL AVANZADO---\n");

    for(int i=0; i<cant; i++){
        if(strcmp(taller[i].categoria, "IA")==0){
            if(strcmp(taller[i].nivel, "AVANZADO")==0){
                printf("NOMBRE DEL TALLER: %s\n", taller[i].nombreTaller);
                inscriptos += taller[i].cantParticipantes;
                printf("CANTIDAD DE INSCRIPTOS: %d ||", taller[i].cantParticipantes);
                for(int j=0; j<taller[i].cantParticipantes; j++){
                    suma+= taller[i].participante[j].avance;
                    
                }
                prom = (float)suma / (float)inscriptos;
                    
                    printf("PROMEDIO AVANCE TALLER: %2.f\n", prom);
            }
        }
    }
    
}

float calcularEdadPomedioTallerEspecifico(Talleres *taller, int cant, char tallerIngresado[]){
    float edadPromedio=0, suma=0, cantPart=0;
    for(int i=0; i<cant; i++){
        if(strcmp(taller[i].nombreTaller, tallerIngresado)==0){
            for(int j=0; j<taller[i].cantParticipantes; j++){
                cantPart ++;
                suma = taller[i].participante[j].edad;
            }

        }
    }
    edadPromedio = suma / cantPart;
    return edadPromedio;
}

void liberarMemoria(Talleres *taller, int cant){
    for(int i=0; i<cant; i++){
        free(taller[i].participante);
    }
    free(taller);
}