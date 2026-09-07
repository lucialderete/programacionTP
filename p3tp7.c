// tp7 punto 3
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define CANT 3

typedef struct
{
    char usuario[20];
    char contrasenia[20];
} Cuenta;

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct
{
    int codigoReserva;
    Fecha fechaCheckin;
    Fecha fechaCheckout;
    char habitacion[20];
    float montoTotal;
} Reserva;

typedef struct
{
    char apellido[50];
    char nombre[50];
    int dni;
    Fecha fechanac;
    char telefono[10];
    Cuenta cuenta;
    Reserva reserva;
    int tieneReserva;

} Huesped;

Huesped agregarReserva(Huesped h)
{
    if (h.tieneReserva == 1)
    {
        printf("ya existe una reserva. debe cancelar la reserva anterior\n");
    }
    printf("nueva reserva: \n");
    printf("ingrese el codigo de reserva: ");
    scanf(" %d", &h.reserva.codigoReserva);
    fflush(stdin);
    printf("\ningrese la fecha de check-in: (dd-mm-aaaa): ");
    scanf(" %d %d %d", &h.reserva.fechaCheckin.dia, &h.reserva.fechaCheckin.mes, &h.reserva.fechaCheckin.anio);
    fflush(stdin);
    printf("\ningrese la fecha de check-out: (dd-mm-aaaa): ");
    scanf(" %d %d %d", &h.reserva.fechaCheckout.dia, &h.reserva.fechaCheckout.mes, &h.reserva.fechaCheckout.anio);
    fflush(stdin);
    printf("\nseleccione el tipo de habitacion (simple,doble, suite): ");
    gets(h.reserva.habitacion);
    printf("\nmonto total: ");
    scanf(" %f", &h.reserva.montoTotal);
    fflush(stdin);
    h.tieneReserva = 1;
    printf("reserva guardada :)\n");
    return h;
}
Huesped cancelarReserva(Huesped h){
    if(h.tieneReserva==0){
        printf("no existe ninguna reserva para cancelar \n");
    }
    int cod;
    printf("ingrese el codigo de reserva para cancelar: ");
    scanf(" %d", &cod);
    if(cod == h.reserva.codigoReserva){
        h.reserva.codigoReserva=0;
        h.tieneReserva=0;
        printf("reserva cancelada\n");
    }else{
        printf("el codigo no coincide \n");
    }
    return h;
}
void verReserva(Huesped h){
    if(h.tieneReserva==0){
        printf("no hay reserva lol\n");
        return;
    }
    printf("aver la reserva: \n");
    printf("codigo: %d\n", h.reserva.codigoReserva);
    printf("fecha check-in: %d/%d/%d\n", h.reserva.fechaCheckin.mes, h.reserva.fechaCheckin.mes, h.reserva.fechaCheckin.anio);
    printf("fecha check-out: %d/%d/%d\n", h.reserva.fechaCheckout.mes, h.reserva.fechaCheckout.mes, h.reserva.fechaCheckout.anio);
    printf("tipo de habitacion: %c\n", h.reserva.habitacion);
    printf("monto total_ %.2f\n", h.reserva.montoTotal);
}
Huesped cambiarContrasenia(Huesped h){
    char nuevaContr;
    printf("ingrese la nueva: ");
    scanf(" %c", &nuevaContr);
    fflush(stdin);
    

}
void mostrarInformacion(Huesped h){
    printf("informacion personal ...\n");
    printf("apellido y nombre: %s, %s\n", h.apellido, h.nombre);
    printf("DNI: %d\n", h.dni);
    printf("fecha nacimiento: %d/%d/%d\n", h.fechanac.dia, h.fechanac.mes, h.fechanac.anio);
    printf("telefono: %s\n", h.telefono);
    printf("usuario: %s\n", h.cuenta.usuario);
    printf("tiene reserva (0=si,1=no) %d\n", h.tieneReserva);

}

void listarHuespedes(Huesped arreglo[], int cantHuespedes)
{
    for (int i = 0; i < CANT; i++)
    {
        printf(" %d. %s, %s\n", i + 1, arreglo[i].apellido, arreglo[i].nombre);
    }
}

int main()
{
    Huesped huespedes[CANT] = {
        {"Perez", "Laura", 12345678, {12, 3, 1985}, "1122334455", {"lauraP", "clave123"}, {0}, 0},
        {"Ramirez", "Carlos", 87654321, {7, 7, 1990}, "1198765432", {"carlosR", "pass456"}, {0}, 0},
        {"Martinez", "Sofia", 45678912, {20, 12, 1975}, "1100112233", {"sofiaM", "s3gura"}, {0}, 0}};

    int seleccionarH = 0, opcion = 0;
    printf("Hotel Manager\n");
    listarHuespedes(huespedes, CANT);
    printf("seleccione un nombre: \n");
    printf("Presione 0 para salir del menu.\n");
    scanf("%d",&seleccionarH);
    fflush(stdin);

    if (seleccionarH >= 1 && seleccionarH <= CANT)
    {
        int indice = seleccionarH - 1;
        printf("Bienvenido %s, %s\n", huespedes[indice].apellido, huespedes[indice].nombre);
        printf("seleccione una opcion (1-6)\n");
        printf("1- Agregar reserva\n");
        printf("2- cancelar reserva\n");
        printf("3- ver reserva\n");
        printf("4- cambiar contrasenia\n");
        printf("5- ver informacion personal\n");
        printf("6- volver al menu principal\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            huespedes[indice] = agregarReserva(huespedes[indice]);
            break;
        case 2:
            huespedes[indice] = cancelarReserva(huespedes[indice]);
            break;
        case 3:
            verReserva(huespedes[indice]);
            break;
        case 4:
            huespedes[indice] = cambiarContrasenia(huespedes[indice]);
            break;
        case 5:
            mostrarInformacion(huespedes[indice]);
            break;
        case 6:
            printf("regresar al menu\n");
        default:
            printf("opcion invalida\n");
        }
    }

    return 0;
}