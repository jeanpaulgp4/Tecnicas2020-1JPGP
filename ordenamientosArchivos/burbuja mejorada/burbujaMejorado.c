#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void burbujamejorada(FILE * flujo, int tamArreglo){
    int arregloEntero[tamArreglo], i,  aux, j, e;
    bool bandera;
    fread(arregloEntero, sizeof(int), tamArreglo, flujo);
    fclose(flujo);
    printf("Leyendo arreglo de archivo\n");
    // APLICAR EL METODO BURBUJA
    for ( i = 0; i < tamArreglo; i++){
        bandera = false;
        for ( j = 0 ; j < tamArreglo; j++){
            if(arregloEntero[j] > arregloEntero[j + 1]){
                aux = arregloEntero[j];
                arregloEntero[j] = arregloEntero[j + 1];
                arregloEntero[j + 1] = aux;
                bandera = true;
            }
        }
        if(bandera==false){
            break;
        } 
    }

    // BUCLE PARA IMPRIMIR TODO ORDENADO
    for ( e = 0; e < tamArreglo; e++){
        printf("Arreglo en posicion %d ordenado %d\n",e,arregloEntero[e]);
    }
    FILE * pFile = fopen( "1000000burbujaMejorada.dat", "wb" );
    fwrite(arregloEntero, sizeof(int), tamArreglo, pFile);
    fclose(pFile);
}



int main(){
    FILE * flujo = fopen( "1000000datos.dat", "rb" );
    burbujamejorada( flujo, 1000000);

}