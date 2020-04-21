#include "Matrices.h"
#include <string.h>

/* Esta muy bien organizado tu codigo, ojo con el estándar de nombramiento para zodiaco */

//struct que pide datos de personas
persona_t llenarPersona(){
	persona_t persona;
	printf("ingrese el nombre de la persona (max 30 caracteres)\n");
	fflush( stdin );
        fgets( persona.nombre, 30, stdin );
        persona.nombre[strcspn(persona.nombre, "\n")] = 0;
	printf("ingrese el dia de nacimiento\n");
	scanf("%d", &persona.diaNacimiento);
	printf("ingrese el mes de nacimiento\n");
	scanf("%d", &persona.mesNacimiento);
	printf("ingrese el año de nacimiento\n");
	scanf("%d", &persona.anoNacimiento);
	return persona;
}



void llenarMatriz(persona_t matrizAno[12][5], int contador[12]){
	persona_t personaCopy; 
	personaCopy = llenarPersona();//<---hace una copia del struct persona a otra y la agrega
	int mes = personaCopy.mesNacimiento - 1; 
	if(contador[mes]>=5){//<--personas deben estar 5 maximo por mes sino imprime que esta lleno el mes
		printf("Esta lleno el mes ya\n");
		return;
	}else{
		matrizAno[mes][contador[mes]++] = personaCopy;
		printf("Se agrego una persona correctamente");
	}
	
	return;
}

void mostrarMatriz(persona_t matrizAno[12][5], int contador[12]){
int i,j;
  for(i = 0; i < 12; i++){ //<---- Este recorre los meses
    	printf( "*** MES %d: ", i + 1 );
    	for(j = 0; j < contador[i]; j++){// <---- Este recorre las personas del mes
			printf("[%s(", matrizAno[i][j].nombre);
			printf("%d/", matrizAno[i][j].diaNacimiento);
			printf("%d/", matrizAno[i][j].mesNacimiento);
			printf("%d)]", matrizAno[i][j].anoNacimiento);
    	}
    	printf( "\n" );
    }
}

void cumpleanos(persona_t matrizAno[12][5], int contador[12],int cumple){
	int j;
	for(j = 0; j < contador[cumple]; j++){// <---- Este recorre las personas del mes
			printf("[%s(", matrizAno[cumple][j].nombre);
			printf("%d/", matrizAno[cumple][j].diaNacimiento);
			printf("%d/", matrizAno[cumple][j].mesNacimiento);
			printf("%d)]", matrizAno[cumple][j].anoNacimiento);
    }
}


void limpiar(persona_t matrizAno[12][5],int contador[12],int cumple,int t){
	if(t == contador[cumple]){
		t++;
		contador-1;
		return limpiar(matrizAno, contador, cumple,t);
	}
	else{
		return;
	}
}




void Zodiaco(int cumple){

	meses signoz = cumple;

	//  valores del enum
	if (signoz == 	ENERO){
		printf ("Eres capricornio o acuario \n");
	}else if (signoz == FEBRERO){ 
		printf ("Eres acuario o piscis \n");
    }else if (signoz == MARZO){ 
		printf ("Eres piscis o aries \n");
	}else if (signoz == ABRIL){ 
		printf("Eres aries o pongase tauro \n");
	}else if (signoz == MAYO){ 
		printf("Eres tauro o geminis \n");
	}else if (signoz == JUNIO){ 
		printf("Eres geminis o cancer \n");
	}else if (signoz == JULIO){ 
		printf("Eres cancer o leo \n");
	}else if (signoz == AGOSTO){ 
		printf("Eres leo o virgo \n");
	}else if (signoz == SEPTIEMBRE){ 
		printf("Eres virgo o libra \n");
	}else if (signoz == OCTUBRE){ 
		printf("Eres libra o escorpio \n");
	}else if (signoz == NOVIEMBRE){ 
		printf("Eres escorpio o sagitario \n");
	}else if (signoz == DICIEMBRE){ 
		printf("Eres sagitario o capricornio \n");
	}
}
