
#include <stdio.h>
#include <stdlib.h>

//ordenamiento por seleccion 
void ordenamientoSeleccion(FILE * flujo, int tamArreglo){
    int arregloEntero[tamArreglo], i,  aux, j, e, min;
    fread(arregloEntero, sizeof(int), tamArreglo, flujo);
    fclose(flujo);
    printf("Leyendo arreglo de archivo\n");
    for(i = 0;i < tamArreglo; i++){
        min = i;
        for ( j = i + 1; j < tamArreglo; j++){
            if(arregloEntero[j] < arregloEntero[min]){
                min = j;
            }
        }
        aux = arregloEntero[i];
        arregloEntero[i] = arregloEntero[min];
        arregloEntero[min] = aux;
    }
    // BUCLE PARA IMPRIMIR TODO ORDENADO
    for ( e = 0; e < tamArreglo; e++){
        printf("Arreglo en posicion %d ordenado %d\n",e,arregloEntero[e]);

    }
    FILE * pFile = fopen( "1000000seleccion.dat", "wb" );
    fwrite(arregloEntero, sizeof(int), tamArreglo, pFile);
    fclose(pFile);
}

int main(){
    FILE * flujo = fopen( "1000000datos.dat", "rb" );
    ordenamientoSeleccion( flujo, 1000000);
    
    return 0;
}