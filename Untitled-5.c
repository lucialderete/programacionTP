#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 50

//estructuras
typedef struct{
    char nombre[MAX];
    int legajo;
    int antiguedad;
    int notaFinal;
}Empleados;

typedef struct{
    char nombreCurso[MAX];
    char area[MAX];
    char modalidad[MAX];
    int cantEmpleados;
    Empleados *empleado;
}Cursos;

//modulos
void cargarEmpleados(Cursos *curso, int cant);
void listaEmpleados(Cursos *curso, int cant);
void mostrarCursosIT(Cursos *curso, int cant);
float antiguedadPromedio(Cursos *curso, int cant, char areaIngresada[]);
void liberarMemoria(Cursos *curso, int cant);

//funcion principal
int main(){
    int cant=5;
    char areaIngresada[MAX];
    float promedio =0;
    printf("--PROGRAMA DE CAPACITACION EMPRESARIAL --\n");
    Cursos *curso = (Cursos *)malloc(cant * sizeof(Cursos));
    cargarEmpleados(curso, cant);
    listaEmpleados(curso, cant);
    mostrarCursosIT(curso, cant);
    printf("Ingrese el area que desea buscar: ");
    gets(areaIngresada);
    promedio=antiguedadPromedio(curso, cant, areaIngresada);
    printf("--ANTIGUEDAD PROMEDIO DEL AREA: %s: %.2f", areaIngresada, promedio);
    liberarMemoria(curso, cant);
    return 0;
}
//precarga de datos
void cargarEmpleados(Cursos *curso, int cant){
    curso[0] = (Cursos){
        "IT", "IT", "VIRTUAL", 5, (Empleados *)malloc(5 * sizeof(Empleados))
    };
    curso[0].empleado[0]=(Empleados){
        "LUCIA", 454, 10, 90
    };
    curso[0].empleado[1]=(Empleados){
        "MARIA", 643, 12, 100
    };
    
    curso[0].empleado[2]=(Empleados){
        "ORLANDO", 643, 21, 99
    };
    
    curso[0].empleado[3]=(Empleados){
        "PAUlA", 213, 3, 20
    };
    
    curso[0].empleado[4]=(Empleados){
        "JORGE", 754, 9, 40
    };
    
    //curso 1
    curso[1] = (Cursos){
        "IT", "IT", "PRESENCIAL", 3, (Empleados *)malloc(3 * sizeof(Empleados))
    };
    curso[1].empleado[0]=(Empleados){
        "ISABELA", 432, 10, 90
    };
    curso[1].empleado[1]=(Empleados){
        "BAUTISTA", 643, 11, 91
    };
    
    curso[1].empleado[2]=(Empleados){
        "YESABELLA", 754, 21, 78
    };

    //Curso 2
    curso[2] = (Cursos){
        "MARKETING", "MARKETING", "VIRTUAL", 4, (Empleados *)malloc(4 * sizeof(Empleados))
    };
    curso[2].empleado[0]=(Empleados){
        "SOFIA", 643, 10, 90
    };
    curso[2].empleado[1]=(Empleados){
        "PAULA", 865, 32, 46
    };
    
    curso[2].empleado[2]=(Empleados){
        "VALENTINA", 543, 23, 99
    };
    
    curso[2].empleado[3]=(Empleados){
        "JOAQUIN", 342, 13, 97
    };
    
    //curso 3

    curso[3] = (Cursos){
        "IT 2ANIO", "IT", "VIRTUAL", 5, (Empleados *)malloc(5 * sizeof(Empleados))
    };
    curso[3].empleado[0]=(Empleados){
        "KAILA", 534, 10, 90
    };
    curso[3].empleado[1]=(Empleados){
        "TAMARA", 655, 12, 100
    };
    
    curso[3].empleado[2]=(Empleados){
        "JULIETA", 675, 21, 99
    };
    
    curso[3].empleado[3]=(Empleados){
        "PABLO", 534, 3, 20
    };
    
    curso[3].empleado[4]=(Empleados){
        "JAVIER", 432, 20, 100
    };


    //curso 4
    curso[4] = (Cursos){
        "FINANZAS", "FINANZAS", "PRESENCIAL", 5, (Empleados *)malloc(5 * sizeof(Empleados))
    };
    curso[4].empleado[0]=(Empleados){
        "SOLDEDAD", 454, 23, 70
    };
    curso[4].empleado[1]=(Empleados){
        "MARIO", 643, 12, 65
    };
    
    curso[4].empleado[2]=(Empleados){
        "IVAN", 643, 16, 98
    };
    
    curso[4].empleado[3]=(Empleados){
        "SAMUEL", 213, 4, 50
    };
    
    curso[4].empleado[4]=(Empleados){
        "AGUSTIN", 754, 8, 60
    };
    

    


}
//desarrollo de modulos

void listaEmpleados(Cursos *curso, int cant){
    printf("--EMPLEADOS CON ANTIGUEDAD MAYOR A 10 ANIOS Y NOTA MAYOR A 90--\n");
    for(int i=0; i < cant; i++){
        for(int j=0; j<curso[i].cantEmpleados; j++){
            if(curso[i].empleado[j].antiguedad > 10){
                if(curso[i].empleado[j].notaFinal > 90){
                    printf("NOMBRE: %s || LEGAJO: %d || ANTIGUEDAD: %d || NOTA FINAL: %d\n", curso[i].empleado[j].nombre, curso[i].empleado[j].legajo, curso[i].empleado[j].antiguedad, curso[i].empleado[j].notaFinal);
                }
            }
        }
    }
}


void mostrarCursosIT(Cursos *curso, int cant){
    int totalempleados=0, suma=0;
    float promedio=0;
    printf("--CURSOS IT CON MODALIDAD VIRTUAL --\n");
    for(int i=0; i<cant; i++){
        if(strcmp(curso[i].area, "IT")==0){
            if(strcmp(curso[i].modalidad, "VIRTUAL")==0){
                printf("NOMBRE DEL CURSO: %s\n", curso[i].nombreCurso);
                for(int j=0; j<curso[i].cantEmpleados; j++){
                    suma += curso[i].empleado[j].notaFinal;
                    totalempleados++;
                }
                promedio=(float)suma / (float)totalempleados;
    printf("TOTAL EMPLEADOS EN AREA IT: %d\n", totalempleados);
    printf("PROMEDIO NOTAS AREA IT: %.2f\n", promedio);
            }
        }
    }
    
}

float antiguedadPromedio(Cursos *curso, int cant, char areaIngresada[]){
    float prom=0;
    int cantTotal=0, suma=0;
    for(int i=0; i<cant; i++){
        if(strcmp(curso[i].nombreCurso, areaIngresada)==0){
            for(int j=0; j<curso[i].cantEmpleados; j++){
                cantTotal ++;
                suma += curso[i].empleado[j].antiguedad;
            }
        }
    }
    
    prom = (float)(suma) / (float)(cantTotal);
    return prom;
}

void liberarMemoria(Cursos *curso, int cant){
    for(int i=0; i<cant; i++){
        free(curso[i].empleado);
    }
    free(curso);
}