#include <stdio.h>
#include <stdlib.h>

#include "Color.h"
#include "Fecha.h"
#include "Marca.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Auto.h"
#include "menu.h"

#ifndef INFORMES_H_
#define INFORMES_H_

#endif /* INFORMES_H_ */

int listarAutosPorMarcaColor(eAuto autos[], int tamA, eMarca marcas[], int tamM,
							eColor colores[], int tamC, eCliente clientes[], int tamCL);

int listarTrabajosPorServicio(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);


int marcaMasRegistrada(eAuto autos[], int tamA, eMarca marcas[], int tamM);

int contarAutosPorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, int idMarca, int* pContador);
