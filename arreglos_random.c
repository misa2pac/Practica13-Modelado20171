#include "arreglos_random.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max){
	// Instrucción que inicializa el generador de números aleatorios.
	srand(time(NULL));
	// Usamos malloc para apartar memoria(un arreglo) y se guarda en un apuntador.
	int *arr = malloc(num * sizeof(int));
	int i;
	/**
	 * Con un for agregamos al arreglo numeros aleatorios 
	 * usando rand() y los generamos entre un minimo y un
	 * maximo.
	 */
	for(i = 0; i < num; i++){
		arr[i] = min + (rand() % (max - min + 1));
	}
	// Retornamos el arreglo generado con numeros aleatorios.
	return arr;
}

/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max){
	// Instrucción que inicializa el generador de números aleatorios.
	srand(time(NULL));
	// Usamos malloc para apartar memoria(un arreglo) y se guarda en un apuntador.
	double *arr = malloc(num * sizeof(double));
	int i;
	/**
	 * Con un for agregamos al arreglo numeros aleatorios 
	 * usando rand() y los generamos entre un minimo y un
	 * maximo.
	 */
	for(i = 0; i < num; i++){
		/** Como la operacion "%" es solo para enteros aqui
		 * hacemos el cast a double y dividimos con RAND_MAX
		 * y el resultado lo sumamos y multiplicamos.
		 */
		double aux = (double)rand() / RAND_MAX;
		arr[i] = min + aux *(max - min);
	}
	// Retornamos el arreglo generado con numeros aleatorios.
	return arr;
}