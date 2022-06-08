#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 15

int SubMax(int *, int);
void Copiar(int*,int*, int, int);
int MaxMed(int*, int, int);
int CalcMax(int, int, int);
void imprimir(int*, int);

int main(){
    int arr[] = {-2,1,-3,4,-1,2,1,-5};
    int lon = sizeof(arr)/sizeof(int);
    int x = SubMax(arr, lon);
    printf("La suma máxima del arreglo es: %d", x);
    return 0;
}

/**
 * @author Alexis Solis 
 * @date 07/06/22
 * @brief Función recursiva que divide cada vez a los arreglos
 * para comprobar su suma máxima
 * 
 * @param arr arreglo a resolver
 * @param lon longitud de dicho arreglo
 * @return int Máxima suma entre las tres posibilidades, suma
 * izquierda, derecha y la que intersecata a ambas
 */
int SubMax(int *arr, int lon){
    if (lon == 1)return arr[0];
    int mitad = lon/2;
    int *arr_izq = (int*)malloc(MAX*sizeof(int));
    Copiar(arr, arr_izq, 0, mitad-1);
    int *arr_der = (int*)malloc(MAX*sizeof(int));
    Copiar(arr, arr_der, mitad, lon);
    int max_izq = SubMax(arr_izq, mitad);
    int max_der = SubMax(arr_der, mitad);
    int max_mitad = MaxMed(arr, mitad, lon);
    return CalcMax(max_izq, max_der, max_mitad);
}

void Copiar(int* arri, int* arrd, int inicio, int final){
	int j = 0;
	for(int i = inicio; i <= final; i++){
		arrd[j] = arri[i];
		j++;
	}
}

/**
 * @author Alexis Solis 
 * @date 07/06/22
 * @brief Función que calcula la suma máxima entre las dos partes 
 * del arreglo
 * 
 * @param arr Arreglo a sumar
 * @param mitad mitad del arreglo
 * @param lon longitud del arreglo
 * @return int Suma de ambas partes
 */
int MaxMed(int *arr, int mitad, int lon){  
    int suma = 0;
    int max_izq = -10000000;
    for(int i = mitad-1; i >= 0; i--){
        suma = suma + arr[i];
        if(suma > max_izq){
            max_izq = suma;
        }
    }
    suma = 0;
    int max_der = -1000000;
    for(int i = mitad; i < lon; i++){
        suma = suma + arr[i];
        if(suma > max_der){
            max_der = suma;
        }
    }
    return max_izq + max_der;
}

int CalcMax(int max_izq, int max_der, int max_mitad){
    if(max_izq > max_der && max_izq > max_mitad)return max_izq;
    if(max_der > max_izq && max_der > max_mitad)return max_der;
    return max_mitad;
}

void imprimir(int *arr, int len){
    printf("[");
    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}