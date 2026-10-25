# Notes sur le projet T3C

Juste un petit fichier pour expliquer rapidement comment j'ai structuré mon code.

## 1. Chargement en mémoire (Mode L)
Pour charger le fichier de hashs en mémoire, je suis parti sur une liste chaînée simple.
En gros, pour que le chargement du fichier soit le plus rapide possible, j'insère chaque nouvelle ligne lue directement au début de la liste (en O(1)).

Côté stockage des mots, au lieu de bloquer des gros tableaux de taille fixe (ce qui gâche de la place ou risque de planter si la ligne est trop longue), je fais un `malloc` de la taille exacte de la chaîne avec `strlen`. Ça prend juste ce qu'il faut en mémoire.

## 2. Le warning OpenSSL à la compilation (Mode G)
À la compilation, GCC lâche un warning du style "MD5 is deprecated". C'est normal vu que MD5 n'est plus vraiment utilisé pour de la vraie sécurité aujourd'hui, mais comme le sujet demande explicitement cet algorithme, j'ai utilisé la fonction d'OpenSSL telle quelle.

## 3. Nettoyage de la mémoire
Vu que le cahier des charges insiste pas mal sur la gestion de la mémoire, j'ai fait gaffe à bien nettoyer toutes mes allocations dynamiques. La fonction `free_liste` repasse sur toute la liste à la fin du mode L pour libérer les chaînes et les nœuds un par un. Normalement, Valgrind affiche bien "0 leaks" à la fin de l'exécution.