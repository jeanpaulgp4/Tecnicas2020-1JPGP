#include <stdio.h>
#include <stdlib.h>

void leerArregloEnteros(FILE * flujo, int tamArreglo){
    int arregloEntero[tamArreglo], i,  auxiliar, j, e;
    fread(arregloEntero, sizeof(int), tamArreglo, flujo);
    fclose(flujo);
    printf("Leyendo arreglo de archivo\n");
    // APLICAR EL METODO BURBUJA
    for (i=0; i<tamArreglo; i++)
    {
        for (j=0; j<tamArreglo; j++)
        {
           
            // CONDICIONAL QUE ACTIVARA EL METODO BURBUJA
            if ( arregloEntero[j] > arregloEntero[j+1] ) // SI ESTO SE CUMPLE, ORDENAMOS CON EL METODO BURBUJA
            {
                auxiliar = arregloEntero[j]; // COPIAMOS EL VALOR 0 DENTRO DE AUXILIAR
                arregloEntero[j] = arregloEntero[j+1];
                arregloEntero[j+1] = auxiliar;
               
            }
        }
    }
           
            // BUCLE PARA IMPRIMIR TODO ORDENADO
            for ( e = 0; e < tamArreglo; e++){
                printf("Arreglo en posicion %d ordenado %d\n",e,arregloEntero[e]);

            }
            FILE * pFile = fopen( "1000000burbuja.dat", "wb" );
            fwrite(arregloEntero, sizeof(int), tamArreglo, pFile);
            fclose(pFile);
    
}

int main(){
    FILE * flujo = fopen( "1000000datos.dat", "rb" );
    leerArregloEnteros( flujo, 1000000);
    
    return 0;
}
