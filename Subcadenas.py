
def Buscar(Arr1, Arr2):
    n = len(Arr1)
    m = len(Arr2)
    for i in range(n-m+1):
        j = 0
        while j<m and Arr2[j] == Arr1[i+j]:
            j = j+1
        if j == m:
            return i
    return -1


a = "Holamundo"
b = "mundo"
x = Buscar(a, b)
print("La cadena {} se encuentra en el indice {} de {}".format(b, x, a))