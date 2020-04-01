#ifndef TASK_H_V
#define TASK_H_V

#include<iostream>
#include <sstream>
#include "priorities.h"
#include<vector>
#include "status.h"
#include "time.h"
#include <string>
#include<limits>
#include <cstdlib>
#include "entrees_sorties.h"

class Task{     //une classe tache
private:
    std::string title;          //tous les attributs qu'on demande à une tâche
    std::string description;
    std::string creation;
    std::string closing;
    Status status;
    int progress;
    Priority priority;
    std::string commentaries;
    int id;

    std::vector<Task> undertasks; //un vecteur de sous-taches
    

public:

    Task(std::string ti, std::string de, std::string cr, std::string cl, Status st, int pro, Priority pri, std::string co, int i, std::vector<Task> un) {
    title = ti;
    description = de;
    creation = cr;
    closing = cl;
    status = st;
    progress = pro;
    priority = pri;
    commentaries = co;
    id = i;
    undertasks = un;
    };
    Task (std::string ti, int i, std::string desc = "") : title(ti), id(i), description (desc), progress(0), status(Open()), priority(None()) {
        creation = now();
        closing = "Thu Jan  1 00:59:46 1970";
    };
    
    Task () : title("empty task"), description(""), commentaries(""), progress(0), status(Inexisting()), priority(None()) {
        creation = "Thu Jan  1 00:59:46 1970";
        closing = "Thu Jan  1 00:59:46 1970";
    };
    
    ~Task () {};

    void change_description() {//interactif
        std::string new_description;
        new_description = entree(new_description, "Entrez la nouvelle description :\n");
        description = new_description;
    };
    void change_status() {
        int new_status;//interactif
        std::string residu;
        std::cout << "Choissisez le nouveau statut de la tâche :" << std::endl;
        std::cout << "1 Inexisting" << std::endl;
        std::cout << "2 Open" << std::endl;
        std::cout << "3 Inprogress" << std::endl;
        std::cout << "4 Closed" << std::endl;
        new_status = entree(new_status, "");
        switch(new_status) {
            case 1:
                status = Inexisting();
                break;
            case 2:
                status = Open();
                break;
            case 3:
                status = Inprogress();
                break;
            case 4:
                status = Closed();
                break;
            default:
                status = Open();
                break;
        };
    };

    void modify() {//interactif
        bool en_cours = true;
        std::string modif;
        std::string reponse;
        std::string residu;
        bool confirmation;
        while (en_cours){
            print();
            std::cout << "Modifier :" << std::endl;
            std::cout << "1 Description" << std::endl;
            std::cout << "2 Statut" << std::endl;
            std::cout << "3 Priorité" << std::endl;
            std::cout << "4 Progression" << std::endl;
            std::cout << "5 Commentaires" << std::endl;
            std::cout << "6 Rien du tout" << std::endl;
            modif = entree(modif,"");
            if (modif == "1"){
                change_description();
            }
            else if (modif == "2"){
                change_status();
            }
            else if (modif == "3"){
                new_priority();
            }
            else if (modif == "4"){
                progression();
            }
            else if (modif == "5"){
                change_comment();
            }
            else if (modif == "6"){
                std::cout << "Aucune modification" << std::endl;
            }
            else {
                std::cout << "Commande inconnue" << std::endl;
            };
            reponse = entree(reponse, "Souhaitez-vous modifier autre chose?\n[y/n] (default n) : ");
            if (!(reponse == "y"|| reponse == "Y")) {
                en_cours = false;
            };
        };
    };

    void print_resume () {//affichage du titre et de l'identifiant
        std::cout << title << "\tid: " << id << std::endl;
    };
    void print () {//affichage de tous les attributs
        print_resume();
        std::cout << "\t" << "Description :\t" << description << std::endl;
        std::cout << "\t" << "Commentaries :\t" << commentaries << std::endl;
        status.print();
        std::cout << "\t" << "Creation :\t" << creation << std::endl;
        std::cout << "\t" << "Closing :\t" << closing << std::endl;
        std::cout << "\tProgress :\t" << progress << std::endl;
        priority.print();
        std::cout << "\tUndertasks :" << std::endl;

        std::vector<Task>::iterator it;
        for(it = undertasks.begin(); it != undertasks.end(); it++) {
            std::cout << "\t\t";
            it->print_resume();
        };
        
    };
    
    void start() {
        status = Inprogress();
    };
    void close() {
        status = Closed();
        closing = now(); //date de fermeture mise à jour
    };

    void new_priority(int p) {
        switch (p)
        {
        case 0:
            priority = None();
            break;
        case 1:
            priority = Faible();
            break;
        case 5:
            priority = Intermediaire();
            break;
        case 10:
            priority = Forte();
            break;

        default:
            priority = Personnalisee(p);
            break;
        };
    };
    void new_priority() {//interactif
        int p;
        p = entree(p,"Définir la nouvelle priorité :\n0 pour None\n1 pour Faible\n5 pour Intermediaire\n10 pour Forte\nN'importe quel autre entier pour Personnalisée\n");
        new_priority(p);
    };

    void progression (int p) {
        progress = p;
    };
    
    void progression () {//intractif
        int p;
        p = entree(p, "Définir la progression de la tâche sur 100\n");
        progression(p);
    };

    void new_comment (std::string com) {
        commentaries = com;
    };
    
    std::string comment () {
        return commentaries;
    };

    void add_comment (std::string com) {
        commentaries += com;
    };
    
    void change_comment() {//interactif
        int p;
        std::string com;
        std::string residu;
        p = entree(p, "Ajouter (1) ou remplacer (2)?\n");
        switch(p) {
            case 1:
                com = entree(com,"Ajout\n");
                add_comment(com);
                break;
            case 2:
                com = entree(com,"Remplacement\n");
                new_comment(com);
                break;
            default:
                std::cout << "Taper 1 ou 2" << std::endl;
                change_comment();
        };
    };
    void add_under (Task tache) {//pour rajouter une sous-tâche
        undertasks.push_back(tache);
    };

    int idi() {return id;}; //acces a id en lecture uniquement

    std::string get_csv() { // renvoie une ligne du fichier csv qui contient la tache en question
        std::string csv;
        std::string virgule = ",";
        std::string retour = "\n";
        std::string Progress = std::to_string(progress);
        std::string Id = std::to_string(id);
        csv = title + virgule + description + virgule + creation + virgule + closing + virgule + status.describe() + virgule + Progress + virgule + priority.describe() + virgule + commentaries + virgule + Id + virgule + retour;
        return csv;
    };
};

#endif