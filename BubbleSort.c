#include <stdio.h>

void bubbleSort(int arr[], int n);
void Imprimir(int arr[], int n);

int main(){
    int arr[] = {9, 8, 6, -2, 5, 33, 20};
    int n = sizeof(arr)/sizeof(int);
    printf("Sin ordenar:\n");
    Imprimir(arr, n);
    bubbleSort(arr, n);
    printf("Ordenbado:\n");
    Imprimir(arr, n);
}

/**
 * @author Alexis Solis
 * @brief El programa toma un arreglo y compara los elementos al inetrior de
 * la lista de valores, compara el siguiente con el que esta
 * 
 * @param arr Arreglo a ordenar
 * @param n Longitud de la lista
 */
void bubbleSort(int arr[], int n) {
    for (int paso = 0; paso < n - 1; ++paso) {
        for(int i = 0; i < n - paso - 1; ++i){
            if(arr[i] > arr[i + 1]){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

void Imprimir(int arr[], int size){
    printf("[");
    for(int i = 0; i < size; ++i){
        printf("%d  ", arr[i]);
    }
    printf("]\n");
}