# Python permet plusieur type de retour:

## Retourner une valeur unique

exemple: 

def addition(a, b):
    return a + b

## Retourner plusieurs valeurs  sous forme de tuple

exemple: 

def operations(a, b):
    return a + b, a - b, a * b

resultat_add, resultat_sub, resultat_mul = operations(4, 2)
print(resultat_add, resultat_sub, resultat_mul)  # ➝ 6 2 8

## Retourner une liste ou un dictionnaire

    def liste_carres(n):\
        return [i ** 2 for i in range(n)]

    print(liste_carres(5))  # ➝ [0, 1, 4, 9, 16]

    def infos_personne(nom, age):
        return {"nom": nom, "age": age}

    print(infos_personne("Alice", 25))  # ➝ {'nom': 'Alice', 'age': 25}

## Retourner None si aucune valeur n'est valide

🎯 Résumé
✅ Retourner une seule valeur → return x
✅ Retourner plusieurs valeurs → return x, y, z (tuple)
✅ Retourner une liste ou un dictionnaire → [x, y, z] ou {"clé": valeur}
❌ (à voir) Gérer les erreurs avec None ou try/except
❌ (à voir)Utiliser yield pour générer des valeurs sans les stocker