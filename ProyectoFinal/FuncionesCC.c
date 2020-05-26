#include "FuncionesCC.h"
#include <string.h>

/* Funcion de ejemplo que imprimiria la informacion de un local */
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso) {
	
	//Se valida si el numero ingresado esta en el rango
	if(numPiso<=numLocalxPiso && numLocalxPiso <= numLocalesxPiso)
	{
		printf("Nombre local : %s ", centroComercial[numPiso][numLocalxPiso].nombreLocal);
		printf("Numero local : %d  ", centroComercial[numPiso][numLocalxPiso].numeroLocal);
        printf("Numero id local : %d  ", centroComercial[numPiso][numLocalxPiso].idLocal);
        printf("Numero de productos local : %d \n ", centroComercial[numPiso][numLocalxPiso].cantidadProductosInventario);
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
    int id, cantidadProductos;
    local_t copyLocal;
    printf("ingrese el nombre del local\n");
    fflush(stdin);
        fgets(copyLocal.nombreLocal, 35, stdin);
        copyLocal.nombreLocal[strcspn(copyLocal.nombreLocal, "\n")] = 0;
    copyLocal.pisoLocal = numPiso;
    copyLocal.numeroLocal = numLocal;
    id = rand() % 1000;
    copyLocal.idLocal = id;
    printf("ingrese la cantidad de productos del local\n");
    scanf("%d", &cantidadProductos);
    copyLocal.cantidadProductosInventario = cantidadProductos;
    copyLocal.estadoLocal = OCUPADO;
    return copyLocal;
}


//busca un local por su nombre
void buscarLocalNombre(local_t **pMatriz, int numPisos, int numLocales ){
    char nombre[35];
    printf("Escribe el nombre del local: \n");
    scanf("%s",nombre);
    for(int i=0; i < numPisos+1; i++){
        for(int j=0; j < numLocales+1; j++){
            if( strcmp(pMatriz[i][j].nombreLocal, nombre)==0){
                printf("Almacen: %s\n id: %d\n numero piso: %d\n numero local: %d\n",pMatriz[i][j].nombreLocal,
                pMatriz[i][j].idLocal,pMatriz[i][j].pisoLocal,pMatriz[i][j].numeroLocal);

            }
        }
    }
}

//busca un local por su id
local_t ** buscarLocalId(local_t **pMatriz, int numPisos, int numLocales ){
    int id;
    printf("escribe el numero del id del local: \n");
    scanf("%d", &id);
    for(int i = 0; i < numPisos+1; i++){
        for(int j= 0; j < numLocales+1; j++){
            if(pMatriz[i][j].idLocal == id ){
                printf("Almacen: %s\n id: %d\n numero piso: %i\n numero local: %i\n",pMatriz[i][j].nombreLocal,
                pMatriz[i][j].idLocal,pMatriz[i][j].pisoLocal+1,pMatriz[i][j].numeroLocal+1 );

                return pMatriz;
            }
        }
    }
}

local_t eliminaLocales (local_t local){
    char vacio[6] = {"\0"};
    strcpy(local.nombreLocal,vacio);
    local.estadoLocal = LIBRE;
    local.cantidadProductosInventario = 0;
    return local;
}

//elimina los locales de un piso
void eliminarLocal(local_t **pMatriz, int pisoUbicacion, int numLocales, int i){
    if(numLocales>0){
        for(i;i<=numLocales;i++){
            eliminaLocales(pMatriz[pisoUbicacion][i]);
            
        }
        return eliminarLocal(pMatriz, pisoUbicacion,  numLocales,  i++);

    }
    else if(i==numLocales){
        printf("Los locales fueron eliminados");
    }

}


//actualiza la informacion de un local
local_t actualizarLocal(int numPiso, int numLocal){
    int id, cantidadProductos;
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
    printf("ingrese la cantidad de productos del local\n");
    scanf("%d", &cantidadProductos);
    copyLocal.cantidadProductosInventario = cantidadProductos;
    copyLocal.estadoLocal = OCUPADO;
    return copyLocal;
}

//funcion donde se ejecuta el enum
int informacionCC(info_e numero){
    if (numero == centroComercial){
        printf("Es una construcción que consta de uno o varios edificios, por lo general de gran tamaño, que albergan servicios, "
            "locales y oficinas comerciales aglutinados en un espacio determinado concentrando mayor cantidad de clientes potenciales "
            "dentro del recinto.");
    }
    else if(numero == Local){
        printf("Establecimiento comercial es el espacio físico donde se ofrecen bienes económicos para su venta al público");
    }
    return 0;

}

//funcion de selection sort
void selectionsort( local_t arr[],int numLocales ){
    local_t temp;
    for(int i = 0;i <= numLocales-1; i++){
        int min = i;
        for (int  j = i + 1; j <= numLocales-1; j++){
            if(arr[j].idLocal < arr[min].idLocal){
                min=j;
            }
        }
        temp = arr[ i ];
        arr[ i ] = arr[ min ];
        arr[min] = temp;
    }
}
//ordena por id local con el ordenamiento selection sort
void ordenamientoSeleccion( local_t ** pMatriz, int numPiso, int numLocales ){
    int numPisosUbi;
    int arr_size = 0, contador = 0;
    
    printf("Piso a organizar");
    scanf("%d",&numPisosUbi);
    for ( int i = 0; i < numLocales; i++){
        if(pMatriz[numPisosUbi - 1][i].estadoLocal == 1){
            arr_size = arr_size + 1;
        }
    }
    printf("arr_Size %d \n",arr_size);
    local_t arr[arr_size];
    for ( int i = 0; i < numLocales; i++){
        if(pMatriz[numPisosUbi - 1][i].estadoLocal == 1){ 
            arr[contador]=pMatriz[numPisosUbi - 1][i]; 
            contador = contador + 1;
        }
    }
   
    selectionsort( arr,arr_size  );
    printf( "Estos son los id de los locales organizados:\n" );

    for(int i = 0; i < arr_size; i++ ){
        printf(" * %s %d \n",arr[i].nombreLocal,arr[i].idLocal);
    }
    printf( "\n" );
    
}

//ordena por numero de local con inserccion
void insertFuntion( local_t pMatriz[], int arr_size ) { 
    for ( int i = 1; i < arr_size; i++ ){ 
        int temp = pMatriz[ i ].numeroLocal; 
        int j = i - 1; 
        while ( j >= 0 && pMatriz[ j ].numeroLocal > temp ){ 
            pMatriz[ j + 1 ] = pMatriz[ j ]; 
            j = j - 1; 
        } 
        pMatriz[ j + 1 ].numeroLocal = temp; 
    }
} 
void ordenamientoInserccion(local_t **pMatriz, int numPisos, int numLocales){
    int numPisosUbi;
    int arr_size = 0, contador = 0;
    
    printf("piso a organizar");
    scanf("%d",&numPisosUbi);
    for ( int i = 0; i < numLocales; i++){
        if(pMatriz[numPisosUbi - 1][i].estadoLocal == 1){
            arr_size = arr_size + 1;
        }
    }
    local_t arr[arr_size];
    for ( int i = 0; i < numLocales; i++){
        if(pMatriz[numPisosUbi - 1][i].estadoLocal == 1){
            arr[contador]=pMatriz[numPisosUbi - 1][i];
            contador = contador + 1;
        }
    }
    insertFuntion( arr,arr_size );
    printf( "Estos son los locales organizados por numero de local:\n" );

    for(int i = 0; i < arr_size; i++ ){
        printf(" * %s %d \n",arr[i].nombreLocal,arr[i].numeroLocal);
    }
    printf( "\n" );
}


void quicksort(local_t *target, int left, int right){
    if( left >= right ) 
        return;
    int i = left, j = right;
    local_t tmp; 
    local_t pivot = target[ i ];
    for(;;) {
        while( target[ i ].cantidadProductosInventario < pivot.cantidadProductosInventario) i++;
        while(pivot.cantidadProductosInventario < target[ j ].cantidadProductosInventario) j--;
        if( target[i].cantidadProductosInventario  >= target[j].cantidadProductosInventario ) 
            break;
        tmp = target[ i ];
        target[ i ] = target[ j ];
        target[ j ] = tmp;
        i++; 
        j--;
    }
    quicksort( target, left, i - 1 );
    quicksort( target, j + 1, right );
}
//ordena por cantidad de productos en el inventario
void ordenarCantidadProductosQuickSort(local_t **pMatriz, int numPisos, int numLocales){
    int pisoUbi;
    int arr_size = 0, contador = 0;

    printf("Piso a organizar");
    scanf("%d",&pisoUbi);
    for ( int i = 0; i < numLocales; i++){
        if( pMatriz[pisoUbi - 1][ i ].estadoLocal == 1 ){
            arr_size = arr_size + 1;
        }
    }
    local_t arr[arr_size];
    for ( int i = 0; i < numLocales; i++){
        if(pMatriz[pisoUbi - 1][i].estadoLocal == 1){ 
            arr[contador]=pMatriz[pisoUbi - 1][i]; 
            contador = contador + 1;
        }
    }
    quicksort(arr, 0, arr_size );
    printf( "Estos son los locales organizados por cantidad de productos:\n" );

    for(int i = 0; i < arr_size; i++ ){
        printf(" * %s %d \n",arr[i].nombreLocal,arr[i].cantidadProductosInventario);
    }
    printf( "\n" );
}

//funcion de merge
void merge(local_t arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    local_t L[n1];
    local_t R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0;  
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i].cantidadProductosInventario <= R[j].cantidadProductosInventario) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(local_t arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  

void printArray(local_t A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf(" * %s %d \n",A[i].nombreLocal,A[i].cantidadProductosInventario);
    printf("\n"); 
} 
  
//ordena por inventario de productos de un piso en especifico
int ordenarMergerSort(local_t **pMatriz, int numPisos, int numLocales){ 
    int numPisosUbi;
    int arr_size = 0, contador = 0;
    
    printf("piso a organizar");
    scanf("%d",&numPisosUbi);
    for ( int i = 0; i < numLocales; i++){
        if(pMatriz[numPisosUbi - 1][i].estadoLocal == 1){
            arr_size = arr_size + 1;
        }
    }
    local_t arr[arr_size];
    for ( int i = 0; i < numLocales; i++){
        if(pMatriz[numPisosUbi - 1][i].estadoLocal == 1){
            arr[contador]=pMatriz[numPisosUbi - 1][i];
            contador = contador + 1;
        }
    }
    mergeSort(arr, 0, arr_size - 1); 
    printArray(arr, arr_size);
} 