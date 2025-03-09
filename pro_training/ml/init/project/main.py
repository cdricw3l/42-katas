import numpy as np
import math as math



def get_euclidian_d(p1, p2):
    d = math.sqrt((p2[0] - p1[0])**2 + (p2[1] - p1[1])**2)
    return d

def get_matrice(city, mat):
    for i in range(len(city)):
        for j in range(len(city)):
            mat[i][j] = round(get_euclidian_d(city[i], city[j]), 2)

def ft_swap(arr, i, j):
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def get_parcour_value(arr, str):
    value = 0.00
    for i in range(len(arr) - 2):
        #print("euclidian : ", get_euclidian_d(str[arr[i]], str[arr[i + 1]]))
        value = value + get_euclidian_d(str[arr[i]], str[arr[i + 1]])
    print("Valeur du chemin : ", arr, " : ", round(value,2))


def permutation(arr,  idx, str):
    if(idx == len(arr)):
        get_parcour_value(arr, str)
        return
    for i in range(idx,len(arr)):
        ft_swap(arr,idx,i)
        permutation(arr, idx + 1, str)
        ft_swap(arr,idx,i)



def main():

    arr = [0,1,2,3]
   # str = [[0.0, 0.0],[1.0, 0.0],[2.0, 0.0], [0.0, 1.0]]
    str = [[0.0, 0.0],[1.0, 0.0],[2.0, 0.0], [0.0, 1.0]]
    mat = np.empty((len(str) , len(str)), dtype=float)
    get_matrice(str, mat)
    #ft_arr_iter(str, 3, 3, 0, 0)
    permutation(arr, 0,str)
    # for i in mat:
    #     for j in i:
    #         print(j, end=" ")
    #     print()
main()