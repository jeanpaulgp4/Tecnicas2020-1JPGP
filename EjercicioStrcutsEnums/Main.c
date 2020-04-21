#include "Matrices.c"

int mostrarMenu() {
//menu de opciones
		int opcion = 0,resultado; // Luisa: no estas usando la función resultado
		printf("\nOpciones que puedes realizar\n");
		printf("1. Agregar un usuario\n");
		printf("2. Imprimir matriz\n");
		printf("3. Imprime cumpleaños del mes\n");
		printf("4. Limpia los datos de un mes\n");
		printf("5. Imprime el signo zoodiacal de cada mes\n");
		printf("0. Salir\n");
		printf(" Opc: ");
		scanf("%d", &opcion);
  return opcion;
}

int main()
{
	//Menu que muestra las opciones disponibles
  int opcion;
  persona_t matrizAno[13][5];//<---matriz del año a llenar
  int contador[13] = {}; //<---contador es la lista con los 12 meses del año 
  int cumple;//<--numero entero que me perimte preguntar un mes al usuario
  do{
  	opcion = mostrarMenu();
  	switch (opcion) {
			case 1:
				llenarMatriz(matrizAno, contador);
				break;
			case 2:
				mostrarMatriz(matrizAno, contador);
				break;
			case 3:
				printf("Digite el mes a mostrar");
				scanf("%d", &cumple);
				cumpleanos(matrizAno, contador, cumple - 1 );
				break;
			case 4:
				printf("Digite el mes a limpiar: ");
				scanf("%d", &cumple);
				limpiar(matrizAno, contador, cumple - 1,0);//<--cumple es el mes que limpiara
				printf("Se limpio el mes");
				break;
			case 5:
				printf(" 1. Enero\n 2. Febrero\n 3. Marzo\n 4. Abril\n 5. Mayo\n 6. Junio\n 7. Julio\n 8. Agosto\n 9. Septiembre\n 10. Octubre\n 11. Noviembre\n 12. diciembre\n");
				printf("digite un mes: ");
				scanf("%d", &cumple);
				for(int k=1;k<=1;k++){
					if(cumple>=1 && cumple<=12){
						Zodiaco(cumple );
					}
					else{
						printf("fuera del rango");
					}
				}
				break;
        }
  } while(opcion != 0);
  //opcion debe ser diferente a cero para seguir en el ciclo
	
	return 0;
}
