#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "Cliente.h"


void mostrarCliente(eCliente vec){
// recibe 1 solo vector por cada llamado
	printf("|%d            %10s    %c| \n", vec.id, vec.nombre, vec.sexo);
}

int listarClientes(eCliente clientes[], int tamCL){

	int control = 0;
    if( clientes != NULL && tamCL > 0 )
    {
    	system("cls");
    	printf(" ** Listado de clientes registrados **\n");
    	printf("--------------------------------------\n");
    	printf(" id           Nombre     Sexo         \n");
    	printf("--------------------------------------\n");

    	for(int i = 0; i < tamCL; i++){
    		mostrarCliente(clientes[i]);
    	}
        printf("______________________________________\n\n");

    	control = 1;
//    	system("pause");
    }
    return control;
}




int buscarCliente(eCliente clientes[], int tamCL, int id, int* pIndice){

    int control = 0;
    if( clientes != NULL && pIndice != NULL && tamCL > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamCL; i++)
        {
            if(clientes[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        control = 1;
    }
    return control;
}


int validarCliente(eCliente clientes[], int tamCL, int id){
	int validacion = 0;
	int indice;

	if (buscarCliente(clientes, tamCL, id, &indice) ){
		if(indice != -1){
			validacion = 1;
		}
	}
	return validacion;
}


int cargarNombreCliente(eCliente clientes[], int tamCL, int id, char descrip[]){

    int control = 0;
    if(clientes != NULL && tamCL > 0 && descrip != NULL){

         for(int i= 0; i < tamCL; i++){

            if( clientes[i].id == id){
                strcpy( descrip, clientes[i].nombre);
                control = 1;
                break;
            }
         }
    }
    return control;
}
