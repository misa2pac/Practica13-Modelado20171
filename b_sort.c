#include "b_sort.h"

/*  bsort: ordena un arreglo usando el algoritmo bubble sort
    base: es un apuntador a un arreglo a ordenar
    num: es el número de elementos en el arreglo
    size: es el tamaño en bytes de cada elemento en el arreglo
    compar: es el apuntador a una función comparadora, que regresa:
           número negativo si el primer elemento es menor
           0 si ambos elementos son iguales
           número positivo si el primer elemento es mayor
*/

/**
 * Funcion bubble_sort la cual ordenara un arreglo de
 * punteros, recibe como parametros la longitud del
 * arreglo y el arreglo de punteros.
 * 
 * Como funciona?:
 * 
 * 1.- Comparamos el primer elemento con el segundo, etc.
 * Cunado el resultado de una comparacion sea "mayor que",
 * se intercambian los valores de los elementos comparados.
 * Con esto conseguiremos llevar el valor mator a la posicion n.
 * 
 * 2.- Repetimos el punto 1, ahora para los n-1 primeros elementos
 * de la lista. Con esto conseguimos llevar el valor mayor de estos 
 * a la posicion n-1.
 * 
 * 3.- Repetimos el punto 1, ahora para los n-2 y asi sucecivamente.
 * 
 * 4.- La ordenacion estara finalizada cuando al repetir el iesimo 
 * proceso de comparacion no haya habido ningun intercabio. 
 */

void bsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)){
	// Convertimos la base "generica" a su tipo, en este caso int y double.
	double *baseD = base;
	int *baseI = base;
	int i, j;
	// Si el numero de bytes es menor o igual a 4 es un numero tipo entero.
	if(size <= 4){
		int aux;
		for(i = 1; i < num; i++){
			for(j = 0; j < num - i; j++){
				if((*compar)(baseI + j,baseI + j + 1) == 1){
					aux = *(baseI + j);
					*(baseI + j) = *(baseI + j + 1);
					*(baseI + j + 1) = aux;
				}
			}
		}
	}
	// Si el numero de bytes igual a 8 es un double.
	if(size == 8){
		double aux;
		for(i = 1; i < num; i++){
			for(j = 0; j < num - i; j++){
				if((*compar)(baseD + j,baseD + j + 1) > 0){
					aux = *(baseD + j);
					*(baseD + j) = *(baseD + j + 1);
					*(baseD + j + 1) = aux;
				}
			}
		}
	}
}
