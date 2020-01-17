# arithmetic-expresion-evaluation
Pour compiler: gcc -g main.c Evaluation.c SStack.c -o main -lm

Pour Executer: ./main

## Evaluation d’expressions arithmétiques en utilisant les piles
## Objectifs du TP
* Implémentation et manipulation d’une pile dynamique (représentation chaînée)
* Implémentation et manipulation de fichiers de caractères et binaires
* Ecriture et appel de fonctions
* Comprendre le processus d’évaluation d’expressions arithmétiques, utilisant les piles.
* Initiation des étudiants à l’analyse lexicale et syntaxique d’une expression arithmétique
* Initiation des étudiants aux différentes formes d’expressions arithmétiques (infixée, postfixée)
* Implémentation des algorithmes de transformation et d’évaluation d’expressions arithmétiques en utilisant les piles.

On désire mettre en œuvre une application destinée à l’évaluation d’expressions arithmétiques en utilisant la structure de pile.

Une expression arithmétique est une chaîne de caractères composée de symboles correspondant à des opérandes, des opérateurs ```(+ - / % *)``` et des parenthèses dans le cas d’une expression parenthésée.

**Exemple**

```130/ (-2*(5+8)) = 130/-2*13= -5```

**Opérande :**

peut être une suite de symboles représentant un entier ou un réel.
Un réel est composé d’une partie entière, une partie décimale et éventuellement d’une partie puissance.

**Opérateur :** 

on considère les opérateurs usuels suivants:

```+ (addition), - (soustraction, peut être unaire ou binaire), * (multiplication), / (division) et % (reste de la division entière)```.

L’ordre décroissant de priorité des opérateurs arithmétiques est le suivant :

```* / % + -```

## Travail demandé
### Partie I : Evaluation d’une expression arithmétique saisie au clavier
#### Première étape : Analyse de l’expression

L’expression doit être saisie sous forme d’une chaîne de caractères comportant des caractères numériques (0, 1,…,9), le point décimal, le caractère ‘e’ ou ‘E’ et les caractères ```+, -, *, /, %```.
Dans cette étape, on doit effectuer une analyse lexicale et syntaxique de l’expression : il s’agit de vérifier si l’expression est correcte afin de pouvoir l’évaluer.

**Exemples :**

L’expression ```100 -/2``` n’est pas correcte syntaxiquement, symboles mal placés.
L’expression ```100 ?/2``` n’est pas correcte lexicalement car il y a un caractère non admis ( ?) dans les expressions arithmétiques.

#### Deuxième étape : Implémentation des fonctions de base

Dans cette étape, il s’agit d’écrire les fonctions suivantes :

**Opérateur (x) :** détermine si x est un opérateur.

**Opérande(x) :** détermine si x est un opérande

**Priorité(x) :** retourne la priorité de l’opérateur x (une valeur entière)

**Opération (x1, x2, operateur) :** effectue l’opération (x1 operateur x2) et retourne le résultat.

Dans cette étape, on doit générer un vecteur d’un type approprié (à définir) correspondant à l’expression arithmétique. 
En effet, chaque case du vecteur doit contenir soit un opérande, un opérateur (on mettra le code de l’opérateur) ou une parenthèse ouvrante ou fermante (on mettra aussi le code de la parenthèse)

**Exemple**

La chaine de caractères

<a href="https://zupimages.net/viewer.php?id=20/01/wqax.png"><img src="https://zupimages.net/up/20/01/wqax.png" alt="" /></a>

Sera transformée en vecteur comme suit :

<a href="https://zupimages.net/viewer.php?id=20/01/l6om.png"><img src="https://zupimages.net/up/20/01/l6om.png" alt="" /></a>

#### Troisième étape : 
dans cette étape, il s’agit d’effectuer le calcul de l’expression en utilisant les algorithmes décrits ci-dessous.
Une expression arithmétique est écrite au départ sous forme infixée (opérande1 opérateur opérande2 exemple ```48 – 65 *5```, c’est la forme habituelle d’écriture).

L’évaluation de cette expression n’est pas directe puisque dès la rencontre d’un opérateur on ne sait pas quelle opération doit-on évaluer d’abord ? Ceci dépend des priorités des opérateurs dans le cas d’une expression sans parenthèses ou de la position des parenthèses dans l’expression dans le cas d’une expression avec parenthèses.

Le compilateur, après les phases de l’analyse lexicale et syntaxique de l’expression, réalise la transformation de l’expression de la forme infixée vers une forme intermédiaire 

par exemple : la forme postfixée (opérande1 opérande2 opérateur). Lorsque l’expression est transformée en une forme postfixée, il sera ensuite facile de l’évaluer (en appliquant l’algorithme d’évaluation).

Dans une forme postfixée, l’opérateur est placé après les deux opérandes, pas au milieu.

**Exemples de transformation**

<a href="https://zupimages.net/viewer.php?id=20/01/8yvj.png"><img src="https://zupimages.net/up/20/01/8yvj.png" alt="" /></a>

### Algorithme de transformation d’une forme infixée en une forme postfixée

L’algorithme utilise deux piles P et R, il reçoit comme donnée le vecteur t (résultat de la deuxième étape) contenant l’expression arithmétiques (c'est-à-dire les opérandes, les opérateurs et les parenthèses codifiés)

On suppose les fonctions suivantes déjà écrites :

Opérateur (x) Opérande(x) Priorité(x) Operation (x1, x2, operateur)

#### Algorithme 1
```
Initialiser la pile P ; Initialiser la pile R ;
Pour i := 0 à fin faire
{Si Operande (t[i])
 Empiler (R, t[i]) ;
 Sinon
 Si Operateur (t[i])
 Tant que (non Pile vide(P) et operateur(sommetpile(P)) et
 (priorite (t[i]) <= priorite (sommetpile (P)) )
 faire Depiler (P, x) ; empiler (R, x) ; fait ;
 /* à la sortie de la boucle */
 empiler (P, t[i] );
 Sinon si ( t[i] = ‘(‘ ) /* le code de la parenthèse ouvrante */
 empiler (P, t[i] );
 sinon /* c’est le cas de la parenthèse fermante */
 Tant que (non Pile vide(P) et sommetpile (P) != ‘(’ )
 /* le code de la parenthèse ouvrante*/
 faire Depiler (P, x) ; Empiler (R, x) ; fait ;

 Depiler (P, x) ;
 Fsi ;
 Fsi ;
Fsi ;
Fait ; /*fermeture de la boucle for */
Tant que (non Pile vide(R))
 Faire Depiler (R, x) ; Empiler (P, x) ; fait ;
Fin ;
```

A la fin de cet algorithme, la pile P contiendra la forme postfixée de l’expression, elle peut être alors évaluée en utilisant l’algorithme ci-dessous.

### Algorithme d’évaluation d’une forme postfixée

L’algorithme utilise deux piles P et R, P contient la forme postfixée de l’expression et R étant initialement vide.

#### Algorithme 2
```
Initialiser la pile R ;
 Tant que (non Pile vide(P))
 Faire Depiler (P, x) ;
 si (Operande (x)) Empiler (R, x) ;
 sinon /* c’est un opérateur */
 Depiler (R, x1) ; Depiler (R, x2) ;
 Res = Operation (x1, x2, x) ;
 Empiler (P, Res) ;
 Fsi ;
 Fait ;
```

Le résultat final d’évaluation de l’expression arithmétique se trouvera dans la  pile R et la pile P devient vide.

### Partie II : Evaluation d’évaluations stockées dans un fichier de caractères
On suppose que nous avons plusieurs expressions arithmétiques stockées dans un fichier de caractères et séparées les unes des autres par une tabulation (‘\t’).

On applique les mêmes algorithmes que précédemment (transformation et évaluation) pour créer deux autres fichiers comme suit:
* Le premier comportera les formes postfixées (transformées) des expressions (séparées par ‘\t’)
* Le deuxième comportera les résultats d’évaluation des expressions contenues dans le premier fichier.
* On devra afficher les deux fichiers. Dans le cas d’expressions incorrectes, il faudra les signaler et les supprimer du fichier initial.

Le menu du programme devra comporter deux options :
1. Evaluation à partir d’une saisie
2. Evaluation à partir d’un fichier

Pour chaque option, il faudra afficher les erreurs, les formes transformées et les résultats finaux.

Remarques importantes
* Le programme doit être écrit sous forme de fonctions
* Les affichages doivent être clairs et lisibles à l’écran, il s’agit d’afficher :
* Les résultats des analyses lexicale et syntaxique de l’expression
* Le tableau comportant la forme codifiée de chaque expression
* La forme postfixée de l’expression
* Le résultat de chaque évaluation
