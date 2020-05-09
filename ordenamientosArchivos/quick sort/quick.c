#include <stdio.h>
#include <stdlib.h>

/*funcion para comparar dos elementos del arreglo*/
int comparacion(const void *i, const void *j) {
    return *(int *)i - *(int *)j;
}

void leerArregloEnteros(FILE * flujo, int tamArreglo){
    int arregloEntero[tamArreglo], i,  auxiliar, j, e;
    fread(arregloEntero, sizeof(int), tamArreglo, flujo);
    fclose(flujo);
    printf("Leyendo arreglo de archivo\n");
 
    /*hacemos el llamado a la funcion qsort
      para que ordene el arreglo*/
    qsort(arregloEntero, tamArreglo, sizeof(int), comparacion);
           
            // BUCLE PARA IMPRIMIR TODO ORDENADO
            for ( e = 0; e < tamArreglo; e++){
                printf("Arreglo en posicion %d ordenado %d\n",e,arregloEntero[e]);

            }
            FILE * pFile = fopen( "1000000qsort.dat", "wb" );
            fwrite(arregloEntero, sizeof(int), tamArreglo, pFile);
            fclose(pFile);
    
}

int main(){
    FILE * flujo = fopen( "1000000datos.dat", "rb" );
    leerArregloEnteros( flujo, 1000000);
    
    return 0;
}
