#include "FuncionesCC.h"
#include <stdio.h>
#include "FuncionesCC.c"

int menu()
{

    int opcion = 0;

    printf(" Opciones\n");
    printf("1. Añadir un local \n");
    printf("2. Buscar local nombre\n");
    printf("3. Buscar local por id\n");
    printf("4. Eliminar locales de un piso\n");
    printf("5. Actualizar local\n");
    printf("6. Informacion centro comercial\n");
    printf("7. Salir\n");
    scanf("%d", &opcion);

    return opcion;
}
int main(){
    //pide el numero de pisos y locales que habran en la matriz
    int numPisos, numLocales;
    printf("Digite el numero de pisos del centro comercial: ");
    scanf("%d", &numPisos);
    printf("Digite el numero de locales por piso del centro comercial: ");
    scanf("%d", &numLocales);
    local_t ** pMatriz;
    //reserva la memoria para la matriz dinamica
    pMatriz= reservarMemoriaMatriz(numPisos, numLocales);

    int opcion;
    do
    {
        opcion = menu();
        switch (opcion)
        {
            case 1:

                int pisoUbicacion, localUbicar;
                printf("Digite el piso a ubicar el local: ");
                scanf("%d", &pisoUbicacion);
                printf("Digite el numero del local: ");
                scanf("%d", &localUbicar);
                if (pisoUbicacion > numPisos || localUbicar > numLocales){
                    printf("Fuera del rango\n");
                    break;
                }else{
                    pMatriz[pisoUbicacion-1][localUbicar-1] = nuevoLocal(pisoUbicacion, localUbicar);
                    mostrarLocal(pMatriz,pisoUbicacion-1,localUbicar-1,numPisos,numLocales);
                }
            
                break;

            case 2:
                    buscarLocalNombre(pMatriz,numPisos,numLocales);
                break;

            case 3:
                    buscarLocalId(pMatriz,numPisos,numLocales);
                break;

            case 4:
                int pisoUbicacion;
                printf("Digite el piso para eliminar todos los locales: ");
                scanf("%d", &pisoUbicacion);
                eliminarLocal(pMatriz,pisoUbicacion,numLocales,0);
                break;
            case 5:
                int pisoUbicacion, localUbicar;
                printf("Digite el piso a ubicar el local: ");
                scanf("%d", &pisoUbicacion);
                printf("Digite el numero del local: ");
                scanf("%d", &localUbicar);
                pMatriz[pisoUbicacion-1][localUbicar-1] = actualizarLocal(pisoUbicacion, localUbicar);
                mostrarLocal(pMatriz,pisoUbicacion-1,localUbicar-1,numPisos,numLocales);

                break;
            case 6:
                int numero;
                printf("0.¿Que es un centro comercial?\n 1.¿que es un local?\n");
                scanf("%d", &numero);
                informacionCC(numero);
                break;
        }
    } while (opcion != 7);//<---la opcion debe ser diferete a 7 o se saldra del ciclo
	
	return 0;
}