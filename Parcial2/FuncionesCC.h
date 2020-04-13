#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
    int numeroLocal;
    char estadoLocal[10];
	// Completelo con lo que quiera
} local_t;

// enum de informacion 
typedef enum informacionCC{
	centroComercial=0, Local=1
}info;

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
void buscarLocalId(local_t **pMatriz, int numPisos, int numLocales);

//elimina los locales de un piso
void eliminarLocal(local_t **pMatriz, int pisoUbicacion, int numLocales, int i);

#endif /* FUNCIONESCC_H_ */