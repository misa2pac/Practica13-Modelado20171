/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"
#include <stdio.h>

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int main()
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int *arr1 = arreglo_int(20, 0, 10);
    double *arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo
    imprime_int(arr1, 20);
    bsort(arr1, 20, sizeof(int), &cmp_int);
    imprime_int(arr1, 20);

    // Se imprime ordena e imprime el segundo arreglo
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double);
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
    free(arr1);
    free(arr2);

    return 0;
}

/**
 * Funcion que compara dos numeros del tipo int recibe 
 * como para metros dos apuntadores. Regresa 0 si los 
 * numeros son iguales, 1 si el primer numero es mayor 
 * al segundo y -1 en otro caso.
 */
int cmp_int(const void *a, const void *b){
    // Los apuntadores se convierten en enteros.
    int _a = *(int *)a;
    int _b = *(int *)b;
    // Se comparan los numeros.
    if(_a == _b){
        return 0;
    }else if(_a > _b){
        return 1;
    }
    return -1;
}

/**
 * Funcion que compara dos numeros del tipo double recibe 
 * como para metros dos apuntadores. Regresa 0 si los 
 * numeros son iguales, 1 si el primer numero es mayor 
 * al segundo y -1 en otro caso.
 */
int cmp_double(const void *a, const void *b){
    // Los apuntadores se convierten en doubles.
    double _a = *(double *)a;
    double _b = *(double *)b;
    // Se comparan los numeros.
    if(_a == _b){
        return 0;
    }else if(_a > _b){
        return 1;
    }
    return -1;
}

/**
 * Funcion que imprime un arreglo del tipo int, recibe 
 * como parametros un apuntador tipo "arreglo" y el 
 * tamaño del arreglo.
 */
void imprime_int(int *arreglo, size_t num){
    int i = 0;
    printf("[");
    for(i = 0; i < num; i++)
        printf("%d ",arreglo[i]);
    printf("]\n");

}

/**
 * Funcion que imprime un arreglo del tipo double, recibe 
 * como parametros un apuntador tipo "arreglo" y el 
 * tamaño del arreglo.
 */
void imprime_double(double *arreglo, size_t num){
    int i = 0;
    printf("[");
    for(i = 0; i < num; i++)
        printf("%f ",arreglo[i]);
    printf("]\n");

}