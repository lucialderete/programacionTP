#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//estructuras
typedef struct{
    char nomrbre[MAX];
    int edad;
    int puntaje;
}Asistentes;

typedef struct{
    char titulo[MAX];
    char area[MAX];
    char nivel[MAX];
    int cantAsistentes;
    Asistentes *asistente;
}Conferencias;

//modulos
void cargarArreglos(Conferencias *conf, int cant);
void listarAsistentes(Conferencias *conf, int cant);
void mostrarAreaPsicoAvanzado(Conferencias *conf, int cant);
float edadPromedio(Conferencias *conf, int cant, char areaIngresada[]);
void liberarMemoria(Conferencias *conf, int cant);


//funcion principal

int main(){
    int cant=5;
    float prom=0;
    char areaIngresada[MAX];
    Conferencias *conf = (Conferencias *)malloc(cant * sizeof(Conferencias));
    printf("--CONGRESO DE SALUD Y BIENESTAR--\n");
    cargarArreglos(conf, cant);
    listarAsistentes(conf, cant);
    mostrarAreaPsicoAvanzado(conf, cant);
    fflush(stdin);
    printf("Ingrese un area para buscar: ");
    gets(areaIngresada);
    prom=edadPromedio(conf, cant, areaIngresada);
    printf("--EDAD PROMEDIO EN EL AREA %s: %.2f \n", areaIngresada, prom);
    liberarMemoria(conf, cant);
    return 0;
}


//desarrollo de los modlulos 
void cargarArreglos(Conferencias *conf, int cant){
    //conferencia 0
    conf[0] = (Conferencias){
        "NUTRICION PARA TODOS", "NUTRICION", "BASICO", 5, (Asistentes *)malloc(5 *sizeof(Asistentes))
    };
    //asistentes conferencia 0
    conf[0].asistente[0] = (Asistentes){
        "LUCIA", 22, 8
    };
    conf[0].asistente[1] = (Asistentes){
        "EMILIA", 70, 10
    };
    conf[0].asistente[2] = (Asistentes){
        "FRANCISCO", 21, 3
    };
    conf[0].asistente[3] = (Asistentes){
        "ANTONIO", 89, 7
    };
    conf[0].asistente[4] = (Asistentes){
        "JUAN", 26, 6
    };

    //conferencia 1
    conf[1] = (Conferencias){
        "PSICO AVANZADA", "PSICOLOGIA", "AVANZADA", 6, (Asistentes *)malloc(6 * sizeof(Asistentes))
    };
    //asistentes conf 1
    conf[1].asistente[0] = (Asistentes){
        "VALERIA", 62, 10
    };
    conf[1].asistente[1] = (Asistentes){
        "ERNESTO", 46, 4
    };
    conf[1].asistente[2] = (Asistentes){
        "OSCAR", 87, 7
    };
    conf[1].asistente[3] = (Asistentes){
        "PAOLA", 46, 10
    };
    conf[1].asistente[4] = (Asistentes){
        "SOFIA", 18, 2
    };
    conf[1].asistente[5] = (Asistentes){
        "MARIA", 60, 8
    };

    //conferencia 2
    conf[2] = (Conferencias){
        "PSICO AVANZADA II", "PSICOLOGIA", "AVANZADA", 3, (Asistentes *)malloc(3 * sizeof(Asistentes))
    };
    //asistentes conf 2
    conf[2].asistente[0] = (Asistentes){
        "AGUSTINA", 65, 9
    };
    conf[2].asistente[1] = (Asistentes){
        "JOAQUIN", 29, 10
    };
    conf[2].asistente[2] = (Asistentes){
        "VICTORIA", 39, 5
    };
    
    //conferencia 3
    conf[3] = (Conferencias){
        "MED INTERMEDIA", "MEDICINA", "INTERMEDIO", 5, (Asistentes *)malloc(5 * sizeof(Asistentes))
    };
    //asistentes conf 3
    conf[3].asistente[0] = (Asistentes){
        "AGOSTINA", 43, 10
    };
    conf[3].asistente[1] = (Asistentes){
        "CYNTHIA", 21, 4
    };
    conf[3].asistente[2] = (Asistentes){
        "CAMILA", 65, 7
    };
    conf[3].asistente[3] = (Asistentes){
        "MARIANA", 75, 10
    };
    conf[3].asistente[4] = (Asistentes){
        "ROCIO", 21, 9
    };
    

    //conferencia 4
    conf[4] = (Conferencias){
        "TER ALTERNATIVA ", "TERAPIA", "INTERMEDIO", 5, (Asistentes *)malloc(5 * sizeof(Asistentes))
    };
    //asistentes conf 1
    conf[4].asistente[0] = (Asistentes){
        "PABLO", 62, 6
    };
    conf[4].asistente[1] = (Asistentes){
        "ENEAS", 32, 4
    };
    conf[4].asistente[2] = (Asistentes){
        "OMAR", 35, 5
    };
    conf[4].asistente[3] = (Asistentes){
        "DUMAS", 75, 9
    };
    conf[4].asistente[4] = (Asistentes){
        "FRANCO", 34, 6
    };
    

};

void listarAsistentes(Conferencias *conf, int cant){
    printf("--ASISTENTES MAYORES A 60 CON PUNTAJE MAYOR A 8:\n");
    for(int i=0; i<cant; i++){
        for(int j=0; j<conf[i].cantAsistentes; j++){
            if(conf[i].asistente[j].edad > 60){
                if(conf[i].asistente[j].puntaje > 8){
                    printf("NOMBRE: %s || EDAD: %d || PUNT: %d\n", conf[i].asistente[j].nomrbre, conf[i].asistente[j].edad, conf[i].asistente[j].puntaje);
                }
            }
        }
    }
};

void mostrarAreaPsicoAvanzado(Conferencias *conf, int cant)
{
    float promedio=0, cantAsist=0, suma =0;
    printf("--CONFERENCIAS AREA PSICO AVANZADA--\n");
    for (int i=0; i<cant; i++){
        if(strcmp(conf[i].area, "PSICOLOGIA")==0){
            if(strcmp(conf[i].nivel, "AVANZADA") ==0){
                for(int j=0; j<conf[i].cantAsistentes; j++){
                    suma += conf[i].asistente[j].puntaje;
                    cantAsist ++;
                }
            }
        }
    }
    promedio = suma / cantAsist;
    printf("CANTIDAD ASISTENTES: %.2f\n", cantAsist);
    printf("SASTIFACCION PROM: %.2f\n" , promedio);
};

float edadPromedio(Conferencias *conf, int cant, char areaIngresada[]){
    float promedio=0, suma=0, total=0;
    for(int i=0; i<cant;i++){
        if(strcmp(conf[i].area, areaIngresada)==0){
            for(int j=0; j<conf[i].cantAsistentes; j++){
                total ++;
                suma = conf[i].asistente[j].edad;
            }
        }
    }
    promedio = suma / total;
    return promedio;
};



void liberarMemoria(Conferencias *conf, int cant){
    for(int i=0; i<cant; i++){
        free(conf[i].asistente);
    }
    free(conf);
}