# creer dossier project

# Dans dossier project : creer un environnement

python -m venv mon_env 

ou 

python3 -m venv mon_env 

# activer l'environnement

source mon_env/bin/activate

# installer les package

pip install ...

# generer le fichier requierment.txt

# include venv dans gitignore

# supprimmer un package

pip uninstall nom_du_package

# installer depuis requiement

pip install -r requirements.txt


# Les dépendances incontournables à installer

📌 Développement général :

pip install requests tqdm rich python-dotenv

* requests → Pour les requêtes HTTP.
* tqdm → Pour afficher des barres de progression.
* rich → Pour afficher du texte coloré.
* python-dotenv → Pour gérer les variables d’environnement.

📌 Développement scientifique & IA :

pip install numpy pandas seaborn matplotlib scipy scikit-learn
* numpy → Calculs mathématiques et manipulation de matrices.
* pandas → Manipulation de données tabulaires.
* seaborn → Visualisation avancée.
* matplotlib → Graphiques.
* scipy → Algorithmes scientifiques.
* scikit-learn → Machine learning.

📌 Développement web (Django ou Flask) :

pip install django djangorestframework flask fastapi uvicorn
* django → Framework web complet.
* djangorestframework → API avec Django.
* flask → Framework léger.
* fastapi → API rapide et asynchrone.
* uvicorn → Serveur pour FastAPI.

📌 Tests & Qualité du Code :

pip install pytest black flake8 mypy pre-commit
* pytest → Tests unitaires avancés.
* black → Formatage automatique.
* flake8 → Vérification de la qualité du code.
* mypy → Vérification des types.
* pre-commit → Exécuter Black et Flake8 avant chaque commit.



