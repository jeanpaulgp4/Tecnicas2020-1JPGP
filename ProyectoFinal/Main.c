
#include "FuncionesCC.h"
#include <stdio.h>
#include "FuncionesCC.c"

int menu(){

    int opcion = 0;

    printf(" Opciones\n");
    printf("1. Añadir un local \n");
    printf("2. Buscar local nombre\n");
    printf("3. Buscar local por id\n");
    printf("4. Eliminar locales de un piso\n");
    printf("5. Actualizar local\n");
    printf("6. Informacion centro comercial\n");
    printf("7. Organizar por id de local \n");
    printf("8. Organizar por numero local\n");
    printf("9. Organizar por cantidad de productos (Quick Sort)\n");
    printf("10. Organizar por cantidad de productos (merge)\n");
    printf("11. Salir\n");
    scanf("%d", &opcion);

    return opcion;
}
int menu2()
{
    int opcion2 = 0;
    printf(" Opciones: \n");
    printf("1. Crear una matriz nueva \n");
    printf("2. Leer un archivo\n");
    printf("3. Salir\n");
    scanf("%d", &opcion2);
    return opcion2;
}


int main(){
    int opcion2;
    do{
        opcion2 = menu2();
        switch (opcion2){//este switch es para preguntar si leer un archivo nuevo o leer uno
            case 1:{
                //pide el numero de pisos y locales que habran en la matriz
                int numPisos, numLocales;
                printf("Digite el numero de pisos del centro comercial: ");
                scanf("%d", &numPisos);
                printf("Digite el numero de locales por piso del centro comercial: ");
                scanf("%d", &numLocales);
                local_t ** pMatriz;
                //reserva la memoria para la matriz dinamica
                pMatriz= reservarMemoriaMatriz(numPisos, numLocales);

                FILE * pFile = fopen( "CentroComercial.dat", "wb" );
                fwrite(pMatriz, sizeof(int), numPisos, pFile);
                fclose(pFile);

                int opcion;
                do{
                    opcion = menu();
                    switch (opcion){
                        case 1:{
                            int pisoUbicacion = 0;
                            int localUbicar;
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
                                FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                                fwrite(pMatriz, sizeof(int), numPisos, pFile);
                                fclose(pFile);
                            }
                        
                            break;
                        }

                        case 2:{
                            buscarLocalNombre(pMatriz,numPisos,numLocales);
                            break;
                        }
                        case 3:{
                            buscarLocalId(pMatriz,numPisos,numLocales);
                            break;
                        }
                        case 4:{
                            int pisoUbicacion;
                            printf("Digite el piso para eliminar todos los locales: ");
                            scanf("%d", &pisoUbicacion);
                            eliminarLocal(pMatriz,pisoUbicacion,numLocales,0);
                            FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                            fwrite(pMatriz, sizeof(int), numPisos, pFile);
                            fclose(pFile);
                            break;
                        }
                        case 5:{
                            int pisoUbicacion, localUbicar;
                            printf("Digite el piso a ubicar el local: ");
                            scanf("%d", &pisoUbicacion);
                            printf("Digite el numero del local: ");
                            scanf("%d", &localUbicar);
                            pMatriz[pisoUbicacion-1][localUbicar-1] = actualizarLocal(pisoUbicacion, localUbicar);
                            mostrarLocal(pMatriz,pisoUbicacion-1,localUbicar-1,numPisos,numLocales);
                            FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                            fwrite(pMatriz, sizeof(int), numPisos, pFile);
                            fclose(pFile);

                            break;
                        }
                        case 6:{
                            int numero;
                            printf("0.¿Que es un centro comercial?\n 1.¿que es un local?\n");
                            scanf("%d", &numero);
                            informacionCC(numero);
                            break;
                        }
                        case 7:{
                            ordenamientoSeleccion(pMatriz, numPisos, numLocales);
                            FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                            fwrite(pMatriz, sizeof(int), numPisos, pFile);
                            fclose(pFile);
                            break;
                        }
                        case 8:{
                            ordenamientoInserccion(pMatriz, numPisos, numLocales);
                            FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                            fwrite(pMatriz, sizeof(int), numPisos, pFile);
                            fclose(pFile);
                            break;
                        }
                        case 9:{
                            ordenarCantidadProductosQuickSort(pMatriz, numPisos, numLocales);
                            FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                            fwrite(pMatriz, sizeof(int), numPisos, pFile);
                            fclose(pFile);
                            break;
                        }
                        case 10:{
                            ordenarMergerSort(pMatriz, numPisos, numLocales);
                            FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                            fwrite(pMatriz, sizeof(int), numPisos, pFile);
                            fclose(pFile);
                        }

                    }
                }while (opcion != 11);//<---la opcion debe ser diferete a 10 o se saldra del ciclo
                break;
            }
            case 2:{
                    FILE * pFile = fopen( "archivo.dat", "rb" );
                    if (pFile == NULL){
                        printf("el archivo no existe"); //si no existe el archivo mostrara este mensaje
                        return 1;
                    }
                    else
                    {
                        printf("Se abrio exitosamente");
                        fclose(pFile);
                        local_t ** pMatriz;
                        //reserva la memoria para la matriz dinamica
                        int numPisos = 1,numLocales = 1;
                        pMatriz= reservarMemoriaMatriz(numPisos, numLocales);
                        int opcion;
                        do{
                            opcion = menu();
                            switch (opcion){
                                case 1:{
                                    int pisoUbicacion = 0;
                                    int localUbicar;
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
                                        FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                                        fwrite(pMatriz, sizeof(int), numPisos, pFile);
                                        fclose(pFile);
                                    }
                                
                                    break;
                                }

                                case 2:{
                                    buscarLocalNombre(pMatriz,numPisos,numLocales);
                                    break;
                                }
                                case 3:{
                                    buscarLocalId(pMatriz,numPisos,numLocales);
                                    break;
                                }
                                case 4:{
                                    int pisoUbicacion;
                                    printf("Digite el piso para eliminar todos los locales: ");
                                    scanf("%d", &pisoUbicacion);
                                    eliminarLocal(pMatriz,pisoUbicacion,numLocales,0);
                                    break;
                                }
                                case 5:{
                                    int pisoUbicacion, localUbicar;
                                    printf("Digite el piso a ubicar el local: ");
                                    scanf("%d", &pisoUbicacion);
                                    printf("Digite el numero del local: ");
                                    scanf("%d", &localUbicar);
                                    pMatriz[pisoUbicacion-1][localUbicar-1] = actualizarLocal(pisoUbicacion, localUbicar);
                                    mostrarLocal(pMatriz,pisoUbicacion-1,localUbicar-1,numPisos,numLocales);

                                    break;
                                }
                                case 6:{
                                    int numero;
                                    printf("0.¿Que es un centro comercial?\n 1.¿que es un local?\n");
                                    scanf("%d", &numero);
                                    informacionCC(numero);
                                    break;
                                }
                                case 7:{
                                    ordenamientoSeleccion(pMatriz, numPisos, numLocales);
                                    FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                                    fwrite(pMatriz, sizeof(int), numPisos, pFile);
                                    fclose(pFile);
                                    break;
                                }
                                case 8:{
                                    ordenamientoInserccion(pMatriz, numPisos, numLocales);
                                    FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                                    fwrite(pMatriz, sizeof(int), numPisos, pFile);
                                    fclose(pFile);
                                    break;
                                }
                                case 9:{
                                    ordenarCantidadProductosQuickSort(pMatriz, numPisos, numLocales);
                                    FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                                    fwrite(pMatriz, sizeof(int), numPisos, pFile);
                                    fclose(pFile);
                                    break;
                                }
                                case 10:{
                                    ordenarMergerSort(pMatriz, numPisos, numLocales);
                                    FILE * pFile = fopen( "CentroComercial.dat", "ab" );
                                    fwrite(pMatriz, sizeof(int), numPisos, pFile);
                                    fclose(pFile);
                                }

                            }
                        }while (opcion != 10);//<---la opcion debe ser diferete a 10 o se saldra del ciclo
                        break;
                    }
                return 0;
            }
        }
    }while (opcion2 != 3);//<---la opcion debe ser diferete a 3 o se saldra del ciclo
}


