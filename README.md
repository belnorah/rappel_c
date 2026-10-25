# Projet T3C - Générateur et Chercheur de Condensats

Ce projet permet de générer des condensats cryptographiques (hash MD5) à partir d'un dictionnaire de mots, puis de rechercher rapidement le mot d'origine à partir de son hash.

Il a été développé en C et testé sous un environnement Linux (Debian/Kali) avec une gestion propre de la mémoire (vérifiée via Valgrind).

## Prérequis

Pour compiler et exécuter ce programme nativement, vous aurez besoin de :
* Un OS Linux (Debian, Ubuntu, Kali, etc.)
* Le compilateur GCC et l'outil Make
* La bibliothèque OpenSSL (`libssl-dev`)

Installation des prérequis sous Debian/Ubuntu/Kali :
```bash
sudo apt update && sudo apt install build-essential libssl-dev
```

## Compilation

Un fichier `Makefile` est fourni à la racine du dépôt. Pour compiler le projet, exécutez simplement la commande suivante à la racine :
```bash
make
```
Cela générera l'exécutable nommé `t3c` à la racine du projet.

## Utilisation

Le programme propose deux modes de fonctionnement : **G** (Génération) et **L** (Lookup/Recherche).

### Mode G : Génération de la T3C
Ce mode lit un fichier texte (dictionnaire) contenant un mot par ligne et génère un fichier de correspondance (T3C) contenant les hashs MD5 associés à chaque mot.

**Syntaxe :**
```bash
./t3c G -i <chemin_dictionnaire> -o <chemin_fichier_sortie> [-a md5]
```

**Exemple :**
```bash
./t3c G -i src/dictionnaire.txt -o table.t3c
```

### Mode L : Recherche rapide
Ce mode charge la table T3C en mémoire (via une liste chaînée allouée dynamiquement) et attend la soumission de condensats sur l'entrée standard (`stdin`). Le flux standard de sortie (`stdout`) est exclusivement réservé au résultat.

* Si le condensat est trouvé, le mot d'origine s'affiche.
* Si le condensat est introuvable, une ligne vide s'affiche.

**Syntaxe :**
```bash
./t3c L -t <chemin_fichier_t3c>
```

**Exemple interactif :**
```bash
./t3c L -t table.t3c
# Le programme attend votre entrée. Collez un hash et appuyez sur Entrée.
# Utilisez Ctrl+D pour quitter proprement.
```

**Exemple automatisé (via un pipe) :**
```bash
echo "f02368945726d5fc2a14eb576f7276c0" | ./t3c L -t table.t3c
```

## Utilisation avec Docker

Un fichier `Dockerfile` est inclus à la racine pour compiler et exécuter le projet dans un environnement Debian isolé, garantissant ainsi son fonctionnement sur n'importe quel système hôte disposant de Docker.

1. **Construire l'image Docker :**
```bash
docker build -t projet-t3c .
```

2. **Lancer le conteneur :**
```bash
docker run -it -v ${PWD}:/app projet-t3c
```

Une fois à l'intérieur du conteneur, vous pouvez utiliser les commandes `make` et `./t3c` détaillées ci-dessus.