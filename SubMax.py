def SubMax(arr):
    if len(arr) == 1:
        return arr[0]

    mitad = len(arr)//2
    arr_izq = arr[0:mitad]
    arr_der = arr[mitad:]
    max_izq = SubMax(arr_izq)
    max_der = SubMax(arr_der)
    max_mitad = MaxMit(arr, mitad)
    return max(max_izq, max_der, max_mitad)

def MaxMit(arr, mitad):
    suma = 0
    max_izq = -1000000
    for i in arr[mitad-1::-1]:
        suma = suma + i
        if(suma > max_izq):
            max_izq = suma

    suma = 0
    max_der = -1000000
    for j in arr[mitad:]:
        suma = suma + j
        if(suma > max_der):
            max_der = suma

    return max_izq + max_der

arr = [-2, 1, -3, 4, -1, 2, 1, -5]
print("La suma máxima del arreglo es: {}".format(SubMax(arr)))
