# Dîner des Philosophes

## Compilation & création des exécutables

Nous avons divisé les 4 éxigences en 4 sous-dossier noté Qn avec n allant de 1 à 4.
Dans chaque sous-dossier, il y a un dossier avec les sources (src), un dossier avec les fichiers headers (inc) et un Makefile.
Pour créer un exécutable il faut utiliser la commande "make". Le projet nécessite clang++ pour la compilation de version 3.5 ou supérieur.

## Résultats / réponses

De la question 1 à 3 les éxecutables s'appellent "philosophes". Pour la question 4, deux exécutables sont créer respectivement "thread" et "fork".
Concernant ceux-ci, on peut constater grâce aux résultats que le fork consomme en moyenne 13 fois plus de cycles que le thread.
Le programme fork à un temps d'exécution 10 fois plus grand que le programme thread.
Avec les résultats de la commande "time" on observe que le système time est 2 à 3 fois plus élevé en moyenne pour le programme utilisant les forks.
L'utilisation des threads est donc la manière la plus optimisé de façon conséquente de réaliser l'implémentation de cet algorithme.
