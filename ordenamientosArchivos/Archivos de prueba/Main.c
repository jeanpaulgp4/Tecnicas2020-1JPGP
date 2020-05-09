#include <stdio.h>
#include <stdlib.h>

void guardarArregloEnteros(FILE * flujo, int tamArreglo){
    int arregloEntero[tamArreglo],i,numero;
    for( i = 0; i < tamArreglo; i++){
        numero = rand() % 20000;
        arregloEntero[i] = numero;
    }
    fwrite(arregloEntero, sizeof(int), tamArreglo, flujo);
    fclose(flujo);
}

int main(){
    FILE * flujo = fopen( "1000000datos.dat", "wb" );
    guardarArregloEnteros( flujo, 100000);
    
    return 0;
}


