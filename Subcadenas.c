#include <stdio.h>
#include <string.h>


int BuscarSubcadena(char *Arr1, char *Arr2);
int main(){
    char *cad = "Holamundo";
    char *sub = "mundo";
    int x = BuscarSubcadena(cad, sub);
    printf("La cadena %s se encuentra en el indice %i de %s", sub, x, cad);
    return 0;
}

/**
 * @author Alexis Solis
 * @date 31/05/22
 * @brief La funcion toma dos arreglops para comparar uno a uno
 * sus caracteres, si en alguno coincide el inicio del que se busca, se verifica que de verdad
 * se aese, si es asi, se devuelve la posicion del elemento inicial
 * 
 * @param Arr1 Cadena donde se busca
 * @param Arr2 Cadena que se busca
 * @return int Posicion
 */
int BuscarSubcadena(char *Arr1, char *Arr2){
    int n = strlen(Arr1);
    int m = strlen(Arr2);
    for(int i = 0; i <= n-m; i++){
        int j = 0;
        while(j<m && Arr2[j] == Arr1[i+j]){
            j++;
        }
        if(j == m)return i;
    }
    return -1;
}