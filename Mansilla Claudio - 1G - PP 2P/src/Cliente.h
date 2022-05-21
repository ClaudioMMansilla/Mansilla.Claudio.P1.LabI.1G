
#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{

	int id;
	char nombre[20];
	char sexo;

}eCliente;

#endif /* CLIENTE_H_ */

void mostrarCliente(eCliente vec);

int listarClientes(eCliente clientes[], int tamCL);

int buscarCliente(eCliente clientes[], int tamCL, int id, int* pIndice);

int validarCliente(eCliente clientes[], int tamCL, int id);

int cargarNombreCliente(eCliente clientes[], int tamCL, int id, char descrip[]);

