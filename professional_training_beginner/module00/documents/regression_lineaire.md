#  Qu'est ce qu'un modele lineaire regressif?

## intro

Un modele lineaire regressif simple est une recette qui appliquer a un jeu de donnee permet de predire la valeur d'une variable dependante d'une ou plusieur autre.

Le modele est dit simple car la variable dependante, n'est dependdante que d'une seul variable independante.

## visualisation:

Le diagramme de dispertion (scatter plot) est le meilleur moyen de visualiser un modele lineraire regressif.

Dans l'illustration ci-dessous, la variable dependante  est l'experience. La variable independante le salaire.

Le diagramme ci dessous est compose d'un nuage de points representant la relation entre notre variable independante (x) et notre variable dependante (y).

![alt text](diagramme_dispertion.png "diagramme_dispersion")

A ce set de donnes une fonction lineaire (pour les modele simple) va etre appliquer permmetant de tracer une droite et de decrire au mieux la relation linaire entre nos  variable.

La droite est calcule de maniere a passer  de maniere la plus optimal, au plus pres, de chacun des points du nuage.

Plus les points ce regroupe autour de cette droite, plus la relation lineaire entre les varibles independantes et les variables dependantes est grande. (voir diagramme_dispersion_2)


![alt text](diagramme_dispersion_2.png "diagramme_dispersion_2")

# Methodologie:

    * Creer le diagramme de dispertion: la variable dependante en y, la variable dependante en x, placer les points.

    * Tracer la droite de regression lineaire d'apres la methode des moindres carres.
        Methodologie: https://www.youtube.com/watch?v=HaDrhuQPOQ4


        formule: 

        Il faut resoudre l'equation y = ax + b
            
            y = variable dependante a predire.
            x = variable independante
            a = donne par la formule :  a = (moyenne(x * y) - (moyenne(x) * moyenne(y))) / moyenne(x^2 - (moyenne(x)^2))
            b = donne par la formule : b = (moyenne(y) - a * moyenne(x))
    
    Dans y = ax + b , a represente la pente de la droite;

*Methode des moindres carres
    