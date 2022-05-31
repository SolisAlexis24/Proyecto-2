def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if arr[j]> arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

arr = [9, 8, 4, -10, 5, 7, 2]
print("Sin ordenar:")
print(arr)
bubbleSort(arr)
print("Ordenado:")
print(arr)