#include "FuncionesCC.h"
#include <string.h>

/* Funcion de ejemplo que imprimiria la informacion de un local */
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso) {
	
	//Se valida si el numero ingresado esta en el rango
	if(numPiso<=numLocalxPiso && numLocalxPiso <= numLocalesxPiso)
	{
		printf("Nombre local : %s", centroComercial[numPiso][numLocalxPiso].nombreLocal);
		printf("Numero local : %d ", centroComercial[numPiso][numLocalxPiso].numeroLocal);
	}
	//TODO completarlo con los datos que le sirvan en su caso
}


//reserva la memoria para la matriz dinamica
local_t ** reservarMemoriaMatriz(int numPiso, int numLocal){
    local_t** matriz= malloc(sizeof(local_t*)*(numPiso));
    for(int i=0;i<numPiso;i++){
        matriz[i]=malloc(sizeof(local_t)*(numLocal));
    }
    return matriz;
}

//crea un nuevo local 
local_t nuevoLocal(int numPiso, int numLocal){
    int id;
    local_t copyLocal;
    printf("ingrese el nombre del local\n");
    fflush(stdin);
        fgets(copyLocal.nombreLocal, 35, stdin);
        copyLocal.nombreLocal[strcspn(copyLocal.nombreLocal, "\n")] = 0;
    copyLocal.pisoLocal = numPiso;
    copyLocal.numeroLocal = numLocal;
    printf("ingrese el id del local\n");
    scanf("%d", &id);
    copyLocal.idLocal = id;
    printf("Ingrese ocupado ya que se ocupara el local\n");
    fflush(stdin);
        fgets(copyLocal.estadoLocal, 10, stdin);
    return copyLocal;
}


//busca un local por su nombre
void buscarLocalNombre(local_t **pMatriz, int numPisos, int numLocales ){
    char nombre[35];
    int i = 0, j = 0;
    local_t copyLocal;
    printf("escribe el nombre del local: \n");
     fgets( copyLocal.nombreLocal, 30, stdin );
    for(int i; i < numPisos; i++){
        for(int j; j < numLocales; j++){
            if( !strcmp(pMatriz[i][j].nombreLocal, nombre)){
                printf("Almacen: %s\n id: %d\n numero piso: %d\n numero local: %d\n",pMatriz[i][j].nombreLocal,
                pMatriz[i][j].idLocal,pMatriz[i][j].pisoLocal);

                return pMatriz;
            }
        }
    }
}

//busca un local por su id
void buscarLocalId(local_t **pMatriz, int numPisos, int numLocales ){
    int id;
    int i = 0, j = 0;
    printf("escribe el numero del id del local: \n");
    scanf("%d", &id);
    for(int i; i < numPisos; i++){
        for(int j; j < numLocales; j++){
            if(pMatriz[i][j].idLocal == id ){
                printf("Almacen: %s\n id: %d\n numero piso: %d\n numero local: %d\n",pMatriz[i][j].nombreLocal,
                pMatriz[i][j].idLocal,pMatriz[i][j].pisoLocal);

                return pMatriz;
            }
        }
    }
}

//elimina los locales de un piso
void eliminarLocal(local_t **pMatriz, int pisoUbicacion, int numLocales, int i){
    if(numLocales>0){
        for(i;i<=numLocales;i++){
            pMatriz[pisoUbicacion][i] = NULL;
            
        }
        return eliminarLocal(pMatriz, pisoUbicacion,  numLocales,  i++);

    }
    else if(i==numLocales){
        printf("Los locales fueron eliminados");
    }

}


//actualiza la informacion de un local
local_t actualizarLocal(int numPiso, int numLocal){
    int id;
    local_t copyLocal;
    printf("ingrese el nombre del local\n");
    fflush(stdin);
        fgets(copyLocal.nombreLocal, 35, stdin);
        copyLocal.nombreLocal[strcspn(copyLocal.nombreLocal, "\n")] = 0;
    copyLocal.pisoLocal = numPiso;
    copyLocal.numeroLocal = numLocal;
    printf("ingrese el id del local\n");
    scanf("%d", &id);
    copyLocal.idLocal = id;
    printf("Ingrese ocupado ya que se ocupara el local\n");
    fflush(stdin);
        fgets(copyLocal.estadoLocal, 10, stdin);
    return copyLocal;
}

//funcion donde se ejecuta el enum
int informacionCC(numero){
    if (numero == 0){
        printf("Es una construcción que consta de uno o varios edificios, por lo general de gran tamaño, que albergan servicios, locales y oficinas comerciales aglutinados en un espacio determinado concentrando mayor cantidad de clientes potenciales dentro del recinto.");
    }
    else if(numero == 1){
        printf("Establecimiento comercial es el espacio físico donde se ofrecen bienes económicos para su venta al público");
    }

}
