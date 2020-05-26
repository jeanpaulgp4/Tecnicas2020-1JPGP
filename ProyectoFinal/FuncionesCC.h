#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

// enum de informacion 
typedef enum informacionCC{
	centroComercial=0, Local=1
}info_e;

// enum de informacion 
typedef enum estadoLocal{
	LIBRE = 0, OCUPADO = 1
}estado_Local_e;

//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
    int numeroLocal;
	int cantidadProductosInventario;
    estado_Local_e estadoLocal;
} local_t;


//muestra la informacion de un local agregado
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso);

//reserva la memoria de una matriz dinamica
local_t ** reservarMemoriaMatriz(int numPisos, int numLocales); 

// LLena la matriz con nÃºmeros consecutivos desde el 10 hasta que se acaben los espacios de la matriz

void llenarMatriz(local_t ** pMatriz , int numPisos, int numLocales,int contador[]); 

//busca por nombre en la matriz un local

void buscarLocalNombre(local_t **pMatriz, int numPisos, int numLocales);
//busca por id en la matriz un local

local_t ** buscarLocalId(local_t **pMatriz, int numPisos, int numLocales);

//elimina los locales de un piso

local_t eliminaLocales (local_t local);

//funcion auxiliar de la funcion eliminarLocal
void eliminarLocal(local_t **pMatriz, int pisoUbicacion, int numLocales, int i);

//funcion que ordena por id de local
void ordenamientoSeleccion(local_t **pMatriz, int numPisos, int numLocales);

//funcion que ordena por numero de local
void ordenamientoInserccion(local_t **pMatriz, int numPisos, int numLocales);

//funcion que ordena por cantidad de productos inventario de local
void ordenarCantidadProductosQuickSort(local_t **pMatriz, int numPisos, int numLocales);

//funcion que ordena por cantidad de productos inventario de local
int ordenarMergerSort(local_t **pMatriz, int numPisos, int numLocales);

#endif /* FUNCIONESCC_H_ */