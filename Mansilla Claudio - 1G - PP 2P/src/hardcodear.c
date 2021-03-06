#include "hardcodear.h"

#include <stdio.h>
#include <stdlib.h>

#include "Auto.h"
#include "Trabajo.h"
#include "Fecha.h"


int hardcodearAutos(eAuto autos[], int tamA, int cant){
    int control = 0;

	eAuto hardAutos[10]= {
		//      id,    marca,color,caja,isEmpty
			{"AA420AR", 1000, 5000, 'm', 4000, 0},
			{"LQR085", 1001, 5001, 'a', 4001, 0},
			{"MYP499", 1002, 5002, 'm', 4002, 0},
			{"KSX685", 1003, 5003, 'a', 4003, 0},
			{"AE388AR", 1000, 5004, 'a', 4004, 0},
			{"SZZ808", 1001, 5002, 'm', 4005, 0},
			{"GHL150", 1002, 5001, 'a', 4006, 0},
			{"AEA410", 1003, 5000, 'm', 4007, 0},
			{"JPE773", 1004, 5003, 'm', 4008, 0},
			{"QNA956", 1001, 5004, 'a', 4009, 0},

	};
	  if( autos != NULL && tamA > 0 && cant <= 10 && cant <= tamA) {

			for(int i=0; i<10; i++){
				autos[i] = hardAutos[i];
		    }
			control = 1;
	  }
    return control;
}


int hardcodearTrabajos(eTrabajo trabajos[], int tamT, int cant, int* pNextId){
    int control = 0;

	eTrabajo hardTrabajos[8]= {
		//  id,  idAuto , idServ,    fecha   , isEmpty
			{0, "QNA956", 20000, {7,1,2022}, 0},
			{0, "JPE773", 20001, {2,2,2022}, 0},
			{0, "AEA410", 20002, {15,12,2021}, 0},
			{0, "JPE773", 20001, {2,10,2021}, 0},
			{0, "GHL150", 20002, {28,3,2022}, 0},
			{0, "AEA410", 20001, {2,2,2021}, 0},
			{0, "AEA410", 20002, {10,12,2021}, 0},
			{0, "GHL150", 20003, {2,2,2022}, 0}
	};

    if( trabajos != NULL && pNextId != NULL && tamT > 0 && cant <= 8 && cant <= tamT)
    {
        for(int i=0; i < cant; i++)
        {
        	trabajos[i] = hardTrabajos[i];
        	trabajos[i].id = *pNextId;
        	(*pNextId)++;
        }
        control = 1;
    }
    return control;

}
