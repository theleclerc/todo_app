Projet d'informatique Todo_list Théophile Le Clerc

Compiler:
    g++.exe -std=c++11 test_main.cxx -o test_main.exe 
    g++.exe -std=c++11 command_todo_app.cxx -o command_todo_app.exe

Executer:
    ./test_main.exe
    |-> Pour avoir une idée du menu interactif à partir d'une todo_list vide qu'on peut remplir mais sans la fonction de sauvegarde

    ./command_todo_app.exe todolist.csv
    |-> Lit les informations dans todolist.csv qu'il convertit en information sur une Todolist, puis ouvre le menu interactif permettant de modifier cette Todolist, et enfin écrit les informations dans le fichier todolist.csv. Ceci étant le fonctionnement visé. J'ai l'impression que la lecture ne marche pas mais l'écriture fonctionne puisqu'à la fin du programme le csv est rempli avec les informations que l'on a données. L'autre petite modification à apporter est que pour l'instant le programme ne modifie que le fichier todolist.csv car je n'arrive pas à passer l'argument de ./command_todo_app.exe en nom de fichier sans que l'écriture dans le fichier ne marche.


J'ai fait le choix pour l'application de faire un menu interactif pour que ce soit plus ergonomique pour l'utilisateur qui n'a plus qu'à suivre les indications de la console sans avoir besoin de connaître des commandes spécifiques.

Au niveau du codage, j'ai séparé dans des .h différents les classes Todolist, Task, Priority et Status pour ne pas surcharger le code sur un fichier.
Le .h entrees_sorties.h résume plusieurs semaines de recherche sur la saisie console. Elle comporte une fonction utilisée dans la plupart des autres .h qui est entree qui permet de récupérer un string ou un int à la console avec un message qui s'affiche.
Le .h time me permet juste d'avoir accès à une fonction now() qui donne la date et l'heure du jour dans un format string "Thu Jan  1 00:59:46 1970".
