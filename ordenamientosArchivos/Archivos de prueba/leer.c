#include <stdio.h>
#include <stdlib.h>

void leerArregloEnteros(FILE * flujo, int tamArreglo){
    int arregloEntero[tamArreglo],i;
    fread(arregloEntero, sizeof(int), tamArreglo, flujo);
    fclose(flujo);
    printf("Leyendo arreglo de archivo\n");
    for ( i = 0; i < tamArreglo; i++){
        printf("Arreglo en posicion %d con valor %d\n",i,arregloEntero[i]);

    }

    
}

int main(){
    FILE * flujo = fopen( "1000000datos.dat", "rb" );
    leerArregloEnteros( flujo, 1000000);
    
    return 0;
}
