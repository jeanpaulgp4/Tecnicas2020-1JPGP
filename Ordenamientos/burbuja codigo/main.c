#include <stdio.h>
 
int main()
{
    // VARIABLES EN GENERAL
    int i , j , cantidad , auxiliar;
   
    // ALMACENAMOS LA CANTIDAD DE ELEMENTOS
    printf("\nDigite la cantidad de elementos que tendra su matriz: ");
    scanf("%i" , &cantidad);
   
    // CREAMOS LA MATRIZ CON LA CANTIDAD EXACTA
    int matriz_numeros[cantidad];
   
    // PEDIRLE AL USUARIO QUE DIGITE LOS VALORES DENTRO DE LA MATRIZ
    for (j=0; j<cantidad; j++)
    {
        fflush(stdin); // LIMPIAMOS LA MEMORIA
        printf("\nDigite valor para matriz[%i] : " , j);
        scanf("%i" , &matriz_numeros[j]);
    }
   
    // APLICAR EL METODO BURBUJA
    for (i=0; i<cantidad; i++)
    {
        for (j=0; j<cantidad; j++)
        {
           
            // CONDICIONAL QUE ACTIVARA EL METODO BURBUJA
            if ( matriz_numeros[j] > matriz_numeros[j+1] ) // SI ESTO SE CUMPLE, ORDENAMOS CON EL METODO BURBUJA
            {
                auxiliar = matriz_numeros[j]; // COPIAMOS EL VALOR 0 DENTRO DE AUXILIAR
                matriz_numeros[j] = matriz_numeros[j+1];
                matriz_numeros[j+1] = auxiliar;
               
            }
            }
            }
           
            // BUCLE PARA IMPRIMIR TODO ORDENADO
            for (i=0; i<cantidad; i++)
            {
                printf("\nOrdenado %i " , matriz_numeros[i] );
            }
   
   
   
   
    return 0;
}