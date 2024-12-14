# Implementation de l'algorithme quick sort (pour les entier. Possible d'implmenter une version generique).


prototype fonction: void	ft_qsort_int(int *base, int low, int high)

base = tableau d'entier.
low = index mini = 0;
high = nombre d'element.

La fonction qsort est apeller recursivement tant que low < high et utilise une fonction de partionnage pour effectuer le tri.


## 1 - Fonction de partitionnage.

prototype : int	ft_partition(int *arr, int low, int high).

Exemple:

arr[] = {10, 100, 11, 24, 243, 34, 2}

low = 0;
high = 7;

* 1) Definir un pivot:

Plusieur maniere de definir un pivot, un mauvais choix de pivot peut impacté l'efficacité de l'algorithme.

Le pivot peut etre le premier element du tableau, le dernier  ou l'element arr[high / 2].

Idealement choisir comment pivot la medianne des valeurs du tableau.

* 2) Etablir deux index de boucle. Faire tourner tant que i <= j

i = low.
j = high - 1

arr[] = {10, 100, 11, 24, 243, 34, 2}
         |             |           |
         i           pivot         j

Tant que i < pivot i est incrementé.

arr[] = {10,  100, 11, 24, 243, 2 ,34}
               |       |            |
               i     pivot          j

Tant que j > pivot , decrementé j.

arr[] = {10,  100, 11, 24, 243, 2 ,34}
               |       |        |
               i     pivot      j

swaper les deux valeurs.

arr[] = {10, 2, 11, 24, 243, 100 ,34}
             |       |        |
             i     pivot      j

arr[] = {10, 2, 11, 24, 243, 100 ,34}
                |   |    |
                i   p    j

arr[] = {10, 2, 11, 24, 243, 100 ,34}
                    |    
                    p
                    i
                    j
Fin de boucle.

Ici, la fonction de partion renvoie l'index du pivot.
Les deux sous ensemble:

sub1[] = {10, 2, 11, 24}
sub2[] = {243, 100, 34}

shemas de recursivité:

[7, 2, 1, 6, 8, 5, 3, 4] (pivot = 6)  <-- 1
├── [2, 1, 3, 4, 5] (pivot = 3)       <-- 2
│   ├── [2, 1] (pivot = 1)            <-- 3
│   │   ├── [] (terminé)              <-- 4
│   │   └── [2] (terminé)             <-- 5
│   └── [4, 5] (pivot = 5)            <-- 6
│       ├── [4] (terminé)             <-- 7
│       └── [] (terminé)              <-- 8
└── [8, 7] (pivot = 7)                <-- 9
    ├── [] (terminé)                  <-- 10
    └── [8] (terminé)                 <-- 11