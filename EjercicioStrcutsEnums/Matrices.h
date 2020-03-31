#include <stdio.h>

//Struct de persona
typedef struct persona{
   char nombre[ 30 ];
   int diaNacimiento, mesNacimiento, anoNacimiento; 

}persona_t;
//enum de los meses del año para la funcion zoodiaco().
 typedef enum mesesdelano{
	   ENERO = 1, FEBRERO = 2, MARZO = 3, ABRIL = 4, MAYO = 5, JUNIO = 6, JULIO = 7, AGOSTO = 8, SEPTIEMBRE = 9, OCTUBRE = 10, NOVIEMBRE = 11, DICIEMBRE = 12
} meses;

//agrega una persona a la matriz
void llenarMatriz(persona_t matrizAno[12][5], int contador[12]); 
//imprime la matriz
void mostrarMatriz(persona_t matrizAno[12][5], int contador[12]);
//muestra las personas que cumplen en ese mes
void cumpleanos(persona_t matrizAno[12][5],int contador[12],int cumple); 
//Limpiar un mes
void limpiar(persona_t matrizAno[12][5],int contador[12],int cumple,int j );
//imprime informacion sobre lso signos zoodiacales
void Zodiaco(int cumple);