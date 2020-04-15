#include <stdlib.h>
#include <stdio.h>

/*funcion para comparar dos elementos del arreglo*/
int comparacion(const void *i, const void *j) {
    return *(int *)i - *(int *)j;
}

int main(void) {
    int i;
    int tam;
 
    /*definimos el tamaño del arreglo*/
    printf("Ingrese el tamanho del arreglo: ");
    scanf("%d", &tam);
    int arreglo[tam];
  
    /*llenamos el arreglo*/
    printf("Ingrese valores para el arreglo: ");
    for (i = 0; i < tam; i++){
        scanf("%d", &arreglo[i]);
    }
  
    /*mostramos el arreglo original*/
    printf("Arreglo Original: ");
    for (i = 0; i < tam; i++){
        printf("%d ", arreglo[i]);
    }
 
    /*hacemos el llamado a la funcion qsort
      para que ordene el arreglo*/
    qsort(arreglo, tam, sizeof(int), comparacion);
 
    /*mostramos el arreglo ordenado*/
    printf("Arreglo Ordenado: ");
    for (i = 0; i < tam; i++){
        printf("%d ", arreglo[i]);
    }
    return 0;

}