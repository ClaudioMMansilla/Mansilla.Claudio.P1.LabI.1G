// Mansilla Claudio Matias - clau.mmatt@gmail.com

#include <stdio.h>
#include <stdlib.h>

#include "Color.h"
#include "Fecha.h"
#include "Marca.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Auto.h"
#include "Cliente.h"
#include "informes.h"
#include "hardcodear.h"
#include "menu.h"

#define TAM_AUT 15
#define TAM_TRAB 15
#define TAM_MAR 5
#define TAM_COL 5
#define TAM_SERV 4
#define TAM_CLI 10

int main(void) {
	setbuf(stdout, NULL);

	eMarca marcas[TAM_MAR]={
			{1000, "Renault"},
			{1001, "Ford"},
			{1002, "Fiat"},
			{1003, "Chevrolet"},
			{1004, "Peugeot"}
	};

	eColor colores[TAM_COL]={
			{5000, "Negro"},
			{5001, "Blanco"},
			{5002, "Rojo"},
			{5003, "Verde"},
			{5004, "Azul"}
	};

	eServicio servicios[TAM_SERV]={
			{20000, "Lavado", 450},
			{20001, "Pulido", 500},
			{20002, "Encerado", 600},
			{20003, "Completo", 900}
	};


	eCliente clientes[TAM_CLI]={
			{4000, "Carlos", 'M'},
			{4001, "Juan", 'M'},
			{4002, "Raquel", 'F'},
			{4003, "Mabel", 'F'},
			{4004, "Jony", 'M'},
			{4005, "Castolo", 'M'},
			{4006, "Marta", 'F'},
			{4007, "Alicia", 'F'},
			{4008, "Pedro", 'M'},
			{4009, "Mario", 'M'}
	};
	// ---- fin datos hardcodeados ----

	eAuto autos[TAM_AUT];
	inicializarAutos(autos, TAM_AUT);

	eTrabajo trabajos[TAM_TRAB];
	inicializarTrabajo(trabajos, TAM_TRAB);


	char opcion;
	int idInicialTrab = 1;

	// hardc para testing
	hardcodearAutos(autos, TAM_AUT, 10);
	hardcodearTrabajos(trabajos, TAM_TRAB, 8, &idInicialTrab);
	// fin hardcodeo


	do
	{
		switch(menuBienvenida()){

		case 'A': // ABM
			switch(menuOpciones()){

			case 'A':// "A. ALTA AUTO\n");
				altaAuto(autos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 'B':// "B. MODIFICAR AUTO:\n");
				modificarAuto(autos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 'C':// "C. BAJA AUTO:\n");
				bajaAuto(autos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 'D'://	"D. LISTAR AUTOS:\n");
				listarAutos(autos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 'E'://	"E. LISTAR MARCAS\n");
				listarMarcas(marcas, TAM_MAR);
				system("pause");
				break;

			case 'F'://	"F. LISTAR COLORES\n");
				listarColores(colores, TAM_COL);
				system("pause");
				break;

			case 'G':// "G. LISTAR SERVICIOS\n");
				listarServicios(servicios, TAM_SERV);
				system("pause");
				break;

			case 'H': // "H. ALTA TRABAJO:\n");
				altaTrabajo(trabajos, TAM_TRAB, autos, TAM_AUT, servicios, TAM_SERV, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI, &idInicialTrab);
				break;

			case 'I':// "I. LISTAR TRABAJOS\n");
				listarTrabajos(trabajos, TAM_TRAB, servicios, TAM_SERV);
				system("pause");
				break;
			}
			break; // fin submenu Opciones
		//------------------------------


		case 'B': // INFORMES
			switch(menuInformes()){

			case 1:// 1- Mostrar autos del color seleccionado por el usuario.\n");
				listarAutosIdColor(autos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 2:// " 2- Mostrar autos de una marca seleccionada.\n");
				listarAutosIdMarca(autos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 3:// 3- Informar Promedio de autos con caja manual y promedio de autos con caja autom?tica\n");

				system("pause");
				break;

			case 4:// " 4- Mostrar un listado de los autos separados por tipo de caja.\n");
				ordenarAutosPorCaja(autos, TAM_AUT);
				listarAutos(autos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 5:// 5- Elegir un color y una marca y contar cuantos autos hay de ese color y esa marca.\n");
				listarAutosPorMarcaColor(autos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 6:// 6- Mostrar la o las marcas m?s elegidas por los clientes.\n");
				marcaMasRegistrada(autos, TAM_AUT, marcas, TAM_MAR);
				system("pause");
				break;

			case 7:// 7- Pedir un auto y mostrar todos los trabajos que se le hicieron al mismo.\n");
				listarTrabajosPorIdAuto(trabajos, TAM_TRAB, autos, TAM_AUT, servicios, TAM_SERV, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 8://  8- Pedir un auto e informar la suma de los importes que se le hicieron al mismo.\n");
				informeIngresosPorAuto(trabajos, TAM_TRAB, servicios, TAM_SERV, autos, TAM_AUT, marcas, TAM_MAR, colores, TAM_COL, clientes, TAM_CLI);
				system("pause");
				break;

			case 9:// 9- Pedir un servicio y mostrar los autos a los que se realizo ese servicio y la fecha.\n");
				listarTrabajosPorServicio(trabajos, TAM_TRAB, servicios, TAM_SERV);
				system("pause");
				break;

			case 10: // 10- Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
				listarTrabajosPorFechaExacta(trabajos, TAM_TRAB, servicios, TAM_SERV);
				system("pause");
				break;

			}
			break;


		case 'Z':
			opcion = 's';
			break;
		}

	} while (opcion != 's');


	return EXIT_SUCCESS;
}
