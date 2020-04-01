#ifndef TODO_APP_H_V
#define TODO_APP_H_V

#include "task_v.h"
#include <iostream>
#include "time.h"
#include <vector>
#include <string>
#include "entrees_sorties.h"


class Todolist{     //une classe liste de taches
private:
    std::string titre;
    int id_max; //identifiant de la prochaine tâche ie la dernier tâche a pour id=id_max-1
public:
    std::vector<Task> list; //vecteurs des taches de la Todolist

    Todolist (std::string t) : titre(t), id_max(0) {}; //création d'une Todolist vide
    
    Todolist (const Todolist& other) : titre(other.titre), id_max(other.id_max) { //copie d'une autre Todolist
        for(auto it : other.list) {
            list.push_back(it);
        };
    };

    ~Todolist () {};
    
    void new_task(std::string ti, std::string desc = "") {//création d'une nouvelle tâche directement ajoutée à la Todolist
        Task tache(ti, id_max++, desc);
        list.push_back(tache);
    };

    void new_task(Task tache) {//création d'une nouvelle tâche directement ajoutée à la Todolist
        int idi = tache.idi();
        if (idi = id_max) {list.push_back(tache); id_max++;}
        else {std::cout << "Le format ne convient pas ce n'est pas une todolist (problème d'identifiant";};
    };

    void modify () {//permet à l'utilisateur de modifier la Todolist en interactif
        bool en_cours = true;
        std::string reponse;
        int id;
        bool confirmation;
        while (en_cours) {
            print();
            id = entree(id,"Sélectionner une tâche à modifier ou à créer en tapant son id:\n");
            if (id == id_max) {new_task();}
            else {list[id].modify();}

            reponse = entree(reponse,"Souhaitez-vous modifier ou créer une autre tâche?\n[y/n] (default n) : ");
            if (reponse == "y"|| reponse == "Y") {
                en_cours = true;
            }
            else {en_cours = false;};
        };
    };
    
    void new_task() {//permet à l'utilisateur de créer une nouvelle tâche et de l'ajouter avec une console interactive
        std::string ti;
        std::string des;
        std::string residu;
        ti = entree(ti, "Titre de la nouvelle tâche?\n");
        des = entree(des, "Description?\n");
        new_task(ti, des);
    };
    void print () {//impression dans la console des différentes tâches qui composent la Todolist
        for(auto it : list) {
            it.print();
        };
        std::cout << "Nouvelle tâche\t\tid:" << id_max << std::endl;
    };
};



#endif