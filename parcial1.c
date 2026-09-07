#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_PAC 5

typedef struct{
    char apellido[50];
    char nombre[50];
    char matricula[20];
}Medico;

typedef struct{
    char apellido[50];
    char nombre[50];
    int dni;
    int edad;
    char tipoEco[50];
    
}Paciente;

typedef struct{
    char obraSoc[20];
    int mesFacturacion;
    int nfactura;
    float importe;
    Medico medico;
    Paciente pacientes[MAX_PAC];
    int cantPacientes;
}Datos;

Paciente cargarPacientes(){
    Paciente p;
    printf("\nIngrese el apellido del paciente: ");
    gets(p.apellido);
    fflush(stdin);
    printf("\ningrese el nombre del paciente: ");
    gets(p.nombre);
    fflush(stdin);
    printf("\nedad del paciente: ");
    scanf("%d", &p.edad);
    fflush(stdin);
    printf("\ntipo de ecografia a realizar: (ginecologica, abdominal, renal, tiroidea): ");
    gets(p.tipoEco);
    return p;
}

int contarEco(Paciente tipoEco, int cantEco){
    int cantEco=0;


    return cantEco;
}

int main(){
    
    pirntf("Bienvenido al centro medico!");
    for(int i=0; i<MAX_PAC; i++){
        Paciente p.pacientes[i]=cargarPacientes(pacientes[i]);
    }


    return 0;
}