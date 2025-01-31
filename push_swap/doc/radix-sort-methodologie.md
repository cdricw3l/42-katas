# Implementation de l'algorithme radix sort

## 1 - trouver l'element le plus grand du tableau (fonction get_max_value)

## 2 - Construire un tableau de frequence pour chaque unité en fonction de exp (1, 10, 100 ...). Bien penser à initialiser le tableau à 0

exemple: 

Lors de la premiere passe, exp = 1;

arr[] = {10, 100, 11, 24, 243, 34, 2}

formule: (arr[i] / exp) % 10

frequence[10] = {2, 1, 1, 1, 2, 0, 0, 0, 0, 0}

## 3 - construire un tableau cumulatif. Cela permet de connaitre la plage d'index pour chaque unité.

formule: cumulatif[i] = frequence[i] + cumulatif[i - 1];

exemple:

frequence[10] = {2, 1, 1, 1, 2, 0, 0, 0, 0, 0}

cumulatif[10] = {frequence[i] , frequence[i] + cumulatif[i - 1], frequence[i] + cumulatif[i - 1], frequence[i] + cumulatif[i - 1], frequence[i] + cumulatif[i - 1], frequence[i] + cumulatif[i - 1] ,frequence[i] + cumulatif[i - 1], frequence[i] + cumulatif[i - 1], frequence[i] + cumulatif[i - 1], frequence[i] + cumulatif[i - 1]}

Output:

cumulatif[10] = {2, 3, 4, 5, 7, 7 ,7, 7, 7, 7}

## 4 - construire le tableau trié pour l'unité analysé

Il faut parcourir notre tableau d'entier de droite à gauche, extraire l'unité, placer la valeur a l'index cumulatif puis decrementer l'index cmulatif.

Exemple: 

arr[] = {10, 100, 11, 24, 243, 34, 2}

cumulatif[10] = {2, 3, 4, 5, 7, 7 ,7, 7, 7, 7}

la valeur 2 doit est placer a l'index new_arr[ cumulatif[2] ], puis cumulatif[2] est decrementé de 1;

cumulatif[10] = {2, 3, 3, 5, 7, 7 ,7, 7, 7, 7}

la valeur 34 est placer a new_arr[ cumulatif[4] ] puis cumulatif[4] est decrementer de 1

cumulatif[10] = {2, 3, 3, 5, 6, 7 ,7, 7, 7, 7}

La valeur 243  est plaecé a new_arr[ cumulatif[3] ] puis cumulatif[3] est decrementé de 1

cumulatif[10] = {2, 3, 3, 4, 6, 7 ,7, 7, 7, 7}

La valeur 24  est plaecé a new_arr[ cumulatif[4] ] puis cumulatif[4] est decrementé de 1

cumulatif[10] = {2, 3, 3, 4, 5, 7 ,7, 7, 7, 7}

La valeur 11  est placé a new_arr[ cumulatif[1] ] puis cumulatif[1] est decrementé de 1

cumulatif[10] = {2, 2, 3, 4, 5, 7 ,7, 7, 7, 7}

La valeur 100  est placé a new_arr[ cumulatif[0] ] puis cumulatif[0] est decrementé de 1

cumulatif[10] = {1, 2, 3, 4, 5, 7 ,7, 7, 7, 7}

La valeur 100  est placé a new_arr[ cumulatif[0] ] puis cumulatif[0] est decrementé de 1

cumulatif[10] = {0, 2, 3, 4, 5, 7 ,7, 7, 7, 7}


## 4 - reproduire la meme chose tant que max / exp > 0. Incrementé exp *= 10:

for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(arr, n, exp);
}
Exemple pour notre valeur max 243:

A la premiere evaluation de boucle, exp = 1. 243 / 1 > 0 donc 1er passage.

A la seconde evaluation, exp = 10. 243 / 10 > 0 donc 2eme passage.

A la troisieme evaluation, exp = 1000. 243 / 1000 < 0 donc fin de boucle.

Le tableau devrait etre trié.


# NOTA BENE

## Bien initialiser le tableau cumulatif a zero. En effet le tableau pourais contenir des valeur residuel en memoire.

