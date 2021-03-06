#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"


#include "Color.h"
#include "Fecha.h"
#include "Marca.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Auto.h"
#include "Cliente.h"
#include "menu.h"
#include "informes.h"


int informeIngresosPorServicio(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

	int control = 0;

	int idBuscado;
    int contTrabajos = 0;
    float precio = 0;
    float importeTotal = 0;
    char descrip[25];

    listarServicios(servicios, tamS);
	printf("Id Servicio: (ingrese el codigo que corresponda)\n");
	scanf("%d", &idBuscado);
	while( !validarServicio(servicios, tamS, idBuscado))
	{
		printf("Id invalido. Reingrese id servicio: \n");
		scanf("%d", &idBuscado);
	}

    cargarServDescrip(servicios, tamS, idBuscado, descrip, &precio);

    if( trabajos != NULL && tamT > 0 && servicios != NULL && tamS > 0)
    {
    	for(int i=0; i < tamT; i++)
    	{
    		if( !trabajos[i].isEmpty && trabajos[i].idServicio == idBuscado)
    		{
    			contTrabajos++;

    			for(int j=0; j < tamS; j++){

    				if(servicios[j].precio == idBuscado){
    					precio = servicios[j].precio;
    				}
    			}
    		}
    	}

        if(contTrabajos > 0)
        {
        	importeTotal = contTrabajos * precio;
        }

        system("cls");
        printf("   *** Informe de saldos por %s ***\n\n", descrip);
        printf("Trabajos registrados: %d  || Ingresos $ %.2f\n\n", contTrabajos, importeTotal);
        printf("______________________________________________\n");
        control = 1;
    }
    return control;
}

int informeIngresosPorAuto(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS,
						   eAuto autos[], int tamA, eMarca marcas[], int tamM,
						   eColor colores[], int tamC, eCliente clientes[], int tamCL){

	int control = 0;
	int flagEmpty = 1;
	char autoId[8];
    float acumTrabajos = 0;


    if( trabajos != NULL && tamT > 0 && servicios != NULL && tamS > 0 && autos != NULL && tamA > 0
    		&& marcas != NULL && tamM > 0 && colores != NULL && tamCL > 0)
    {
    	system("cls");
       	listarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCL);
        printf("Ingrese id de auto para calcular ingresos por trabajos realizados)\n");
        fflush(stdin);
        gets(autoId);
        strupr(autoId);
        while( !validarAuto(autos, tamA, autoId) )
        {
            printf("Id invalido. Reintente nuevamente: \n");
            fflush(stdin);
            gets(autoId);
            strupr(autoId);
        }



    	system("cls");
    	printf(" 		** Listado de trabajos registrados ** \n");
    	printf("-------------------------------------------------------------------\n");
    	printf(" id    Auto (patente)     Fecha Trabajo       Servicio     Precio \n");
    	printf("-------------------------------------------------------------------\n");
//    	printf("%2d          %8s       %02d/%02d/%4d              %10s       %.2f \n",

        for(int i=0; i < tamT; i++)
        {
        	if( !trabajos[i].isEmpty && ( strcmp(trabajos[i].idAuto, autoId) == 0) )
        	{
        		for(int j=0; j< tamS; j++){
        			if(trabajos[i].idServicio == servicios[j].id){

        				mostrarTrabajo(trabajos[i], servicios, tamS);
        				acumTrabajos += servicios[j].precio;
        				flagEmpty = 0;

        			}
        		}
        	}
        }

        if(flagEmpty)
        {
            printf(" No hay trabajos registrados en el sistema\n");
        }
        else
        {

        	printf("-------------------------------------------------------------------\n");
        	printf("            TOTAL DE INGRESOS POR SERVICIOS REALIZADOS = $ %.2f \n\n", acumTrabajos);
        }

    	control = 1;
//    	system("pause");
    }

	return control;
}



int listarAutosPorMarcaColor(eAuto autos[], int tamA, eMarca marcas[], int tamM,
							eColor colores[], int tamC, eCliente clientes[], int tamCL){

	int control = 0;
	int flagEmpty = 1;
//	char autoId[8];
    int contadorAutos = 0;
    int idMarcaAux;
    int idColorAux;



    if( autos != NULL && tamA > 0 && marcas != NULL && tamM > 0)
    {
    	system("cls");
       	listarMarcas(marcas, tamM);
        printf("Ingrese id de la marca que desea consultar\n");
        fflush(stdin);
        scanf("%d", &idMarcaAux);
        while( !validarMarca(marcas, tamM, idMarcaAux))
        {
            printf("Id invalido. Reintente nuevamente: \n");
            fflush(stdin);
            scanf("%d", &idMarcaAux);
        }


       	listarColores(colores, tamC);
        printf("Ingrese id del color que desea consultar\n");
        fflush(stdin);
        scanf("%d", &idColorAux);
        while( !validarColor(colores, tamC, idColorAux))
        {
            printf("Id invalido. Reintente nuevamente: \n");
            fflush(stdin);
            scanf("%d", &idColorAux);
        }


    	system("cls");
    	printf("        *****     Listado de vehiculos registrados    *****   \n");
    	printf("--------------------------------------------------------------\n");
    	printf("id (patente)   Cliente     Tipo Caja       Marca        Color \n");
    	printf("--------------------------------------------------------------\n");

        for(int i=0; i < tamA; i++)
        {
            if( !autos[i].isEmpty && autos[i].idMarca == idMarcaAux && autos[i].idColor == idColorAux)
            {
            	mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCL);
                contadorAutos++;
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay vehiculos registrados en el sistema\n");
        }

    	printf("--------------------------------------------------\n");
    	printf("Autos encontrados en registros segun busqueda: %d \n\n", contadorAutos);


        if(flagEmpty)
        {
            printf(" No hay trabajos registrados en el sistema\n");
        }

    	control = 1;
//    	system("pause");
    }

	return control;
}


int listarAutosPorColorCaja(eAuto autos[], int tamA, eMarca marcas[], int tamM,
		eColor colores[], int tamC, eCliente clientes[], int tamCL){

	int control = 0;
	int flagEmpty = 1;
//	char autoId[8];
    int contadorAutos = 0;
    char cajaAux;
    int idColorAux;



    if( autos != NULL && tamA > 0 && marcas != NULL && tamM > 0)
    {

       	listarColores(colores, tamC);
        printf("Ingrese id del color que desea consultar\n");
        fflush(stdin);
        scanf("%d", &idColorAux);
        while( !validarColor(colores, tamC, idColorAux))
        {
            printf("Id invalido. Reintente nuevamente: \n");
            fflush(stdin);
            scanf("%d", &idColorAux);
        }

        printf("Ingrese tipo de transmision: M (manual) - A (automatica)\n");
        fflush(stdin);
        scanf("%c", &cajaAux);
        cajaAux = tolower(cajaAux);


    	system("cls");
    	printf("        *****     Listado de vehiculos registrados    *****   \n");
    	printf("--------------------------------------------------------------\n");
    	printf("id (patente)   Cliente     Tipo Caja       Marca        Color \n");
    	printf("--------------------------------------------------------------\n");

        for(int i=0; i < tamA; i++)
        {
            if( !autos[i].isEmpty && autos[i].caja == cajaAux && autos[i].idColor == idColorAux)
            {
            	mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCL);
                contadorAutos++;
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay vehiculos registrados en el sistema\n");
        }
        else
        {
        	printf("--------------------------------------------------\n");
        	printf("Autos encontrados en registros segun busqueda: %d \n\n", contadorAutos);

        }

    	control = 1;
//    	system("pause");
    }

	return control;
}


int listarTrabajosPorServicio(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS){

	int control = 0;
	int flagEmpty = 1;
//	char autoId[8];
    int contadorTrabajos = 0;
//    char cajaAux;
    int idServicioAux;



    if( trabajos != NULL && tamT > 0 && servicios != NULL && tamS > 0 )
    {

       	listarServicios(servicios, tamS);
        printf("Ingrese id del servicio para listar trabajos realizados\n");
        fflush(stdin);
        scanf("%d", &idServicioAux);
        while( !validarServicio(servicios, tamS, idServicioAux))
        {
            printf("Id invalido. Reintente nuevamente: \n");
            fflush(stdin);
            scanf("%d", &idServicioAux);
        }


    	system("cls");
    	printf(" 		    ** Listado de trabajos registrados ** \n");
    	printf("-------------------------------------------------------------------\n");
    	printf(" id    Auto (patente)     Fecha Trabajo       Servicio     Precio \n");
    	printf("-------------------------------------------------------------------\n");

        for(int i=0; i < tamT; i++)
        {
            if( !trabajos[i].isEmpty && trabajos[i].idServicio == idServicioAux )
            {
                mostrarTrabajo(trabajos[i], servicios, tamS);
                contadorTrabajos++;
                flagEmpty = 0;
            }
        }

        if(flagEmpty)
        {
            printf(" No hay trabajos registrados en el sistema\n");
        }
        else
        {
        	printf("--------------------------------------------------\n");
        	printf("Trabajos encontrados en registros segun busqueda: %d \n\n", contadorTrabajos);
        }

    	control = 1;
//    	system("pause");
    }

	return control;
}


int contarAutosPorColor(eAuto autos[], int tamA, eColor colores[], int tamC, int idColor, int* pContador){

    int control = 0;
    int contAux = 0; // uso localmente para incrementar y luego paso su valor final por referencia

    if( autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && pContador != NULL)
    {
        for(int i=0; i < tamA; i++)
        {
            if( !autos[i].isEmpty && autos[i].idColor == idColor)
            {
            	contAux++;
            }
        }

        *pContador = contAux;

        control = 1;
    }
    return control;

}


int mayorColorAutos(eAuto autos[], int tamA, eColor colores[], int tamC){

    int control = 0;
    int flag = 1;

    int totales[5] = {0};
    int mayor;

    if( autos != NULL && tamA > 0 && colores != NULL && tamC > 0)
    {

        for(int i=0; i < tamC; i++)
        {
        	contarAutosPorColor(autos, tamA, colores, tamC, colores[i].id, &totales[i]);
        	// autosPorColor recorre autos, matchea idColor y devuelve por ref el contador obtenido
        }

        for(int i=0; i < tamC; i++)
        {
            if(flag || totales[i] > mayor)
            {
                mayor = totales[i];
                flag = 0;
            }
        }

        printf("El color de auto mas registrado es: ");

        for(int i=0; i < tamC; i++)
        {

            if(totales[i] == mayor)
            {
                printf("%s\n", colores[i].nombreColor);
            }
        }
        printf("\n\n");
        control = 1;
    }
    return control;
}


int marcaMasRegistrada(eAuto autos[], int tamA, eMarca marcas[], int tamM){

    int control = 0;
    int flag = 1;

    int totales[5] = {0};
    int mayor;

    if( autos != NULL && tamA > 0 && marcas != NULL && tamM > 0)
    {

        for(int i=0; i < tamM; i++)
        {
        	contarAutosPorMarca(autos, tamA, marcas, tamM, marcas[i].id, &totales[i]);

        }

        for(int i=0; i < tamM; i++)
        {
            if(flag || totales[i] > mayor)
            {
                mayor = totales[i];
                flag = 0;
            }
        }

        printf("El color de auto mas registrado es: ");

        for(int i=0; i < tamM; i++)
        {

            if(totales[i] == mayor)
            {
                printf("%s\n", marcas[i].descripcion);
            }
        }
        printf("\n\n");
        control = 1;
    }
    return control;
}

int contarAutosPorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, int idMarca, int* pContador){

    int control = 0;
    int contAux = 0; // uso localmente para incrementar y luego paso su valor final por referencia

    if( autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && pContador != NULL)
    {
        for(int i=0; i < tamA; i++)
        {
            if( !autos[i].isEmpty && autos[i].idMarca == idMarca)
            {
            	contAux++;
            }
        }

        *pContador = contAux;

        control = 1;
    }
    return control;

}

//
//int contarAutosPorCaja(eAuto autos[], int tamA, int* pProM, int* pPromA){
//
//    int control = 0;
//    int contAuxM = 0;
//    int contAuxA = 0;// uso localmente para incrementar y luego paso su valor final por referencia
//    int contadorTotal = 0;
//
//
//    if( autos != NULL && tamA > 0 && pProM != NULL && pPromA != NULL)
//    {
//        for(int i=0; i < tamA; i++)
//        {
//            if( !autos[i].isEmpty && autos[i].caja == ('m' || 'M') )
//            {
//            	contAuxM++;
//            	contadorTotal++;
//            }
//            else
//            {
//            	if( !autos[i].isEmpty && autos[i].caja == ('a' || 'A') ){
//            		contAuxA++;
//            	    contadorTotal++;
//            	}
//            }
//        }
//
//        pProM
//        *pContador = contAux;
//
//        control = 1;
//    }
//    return control;
//
//}
