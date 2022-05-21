#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"

#include "menu.h"



int menuModifAuto(){

    int opcion;

    printf("\n     *** Campo a modificar *** \n");
    printf("1. Marca\n");
    printf("2. Color\n");
    printf("3. Cliente\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int menuModifTrabajo(){

    int opcion;

    printf("\n     *** Campo a modificar *** \n");
    printf("1. Dominio/Patente del auto\n");
    printf("2. Tipo de Servicio\n");
    printf("3. Fecha de realizacion\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int menuInformes(){

	int opcion;

    system("cls");
    printf("\n     *** Informes Varios *** \n");
    printf(" 1- Mostrar autos del color seleccionado por el usuario.\n");
    printf(" 2- Mostrar autos de una marca seleccionada.\n");
    printf(" 3- Promedio de autos con caja manual y con caja automática\n");
    printf(" 4- Mostrar un listado de los autos separados por tipo de caja.\n");
    printf(" 5- Contar Autos segun Marca y Color.\n");
    printf(" 6- Mostrar la o las marcas más elegidas por los clientes.\n");
    printf(" 7- Trabajos realizados a auto.\n");
    printf(" 8- Ingresos obtenidos por auto.\n");
    printf(" 9- Mostrar autos segun servicio y fecha.\n");
    printf("10- Mostrar  servicios realizados segun fecha.\n");

    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}




int menuOrdenamiento(){

    int opcion;

    system("cls");
    printf("\n     *** Menu de ordenamiento de datos *** \n");
    printf("1. Ordenar trabajos por tipo de servicio\n"); // ordenarTrabajosPorServicio(listaTrabajos, TAM_TRAB);
    printf("2. Ordenar trabajos por fecha\n"); // ordenarTrabajosPorFecha(listaTrabajos, TAM_TRAB);

    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}




char menuOpciones(){

    char opcion;

    system("cls");
    printf("     *** Lavadero: MENU DE OPCIONES ***\n\n");
    printf("A. ALTA AUTO\n");
    printf("B. MODIFICAR AUTO:\n");
    printf("C. BAJA AUTO:\n");
    printf("D. LISTAR AUTOS:\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO:\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("\n");
    printf("Z. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;

}


char menuBienvenida(){

    char opcion;

    system("cls");
    printf("   *** MENU DE GESTION ***\n\n");
    printf("Ingrese la opcion que desea utilizar\n");
    printf("A. MENU ABM\n");
    printf("B. MENU INFORMES:\n");
    printf("\n");
    printf("Z. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;

}
