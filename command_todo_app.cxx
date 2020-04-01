#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "todo_app_v.h"


int main(int argc, char** argv)
{
    const std::string nom = argv[0];
    Todolist todolist(nom);
    std::ifstream fichier("todolist.csv", std::ios::in);
    if (fichier)
    {
        //L'ouverture s'est bien passée, on peut donc lire

        std::string ligne; //Une variable pour stocker les lignes lues
        std::string arg;
        //int i;
        while(not(getline(fichier, ligne))) //Tant qu'on n'est pas à la fin, on lit
        {
        //int i;
        std::stringstream ss(ligne);
        std::string title;
        getline(ss,title,',');
        std::string description;
        getline(ss,description,',');
        std::string creation;
        getline(ss,creation,',');
        std::string closing;
        getline(ss,closing,',');
        std::string desc;
        getline(ss,desc,',');
        Status status = get_status(desc);
        std::string p;
        getline(ss,p,',');
        int progress = std::stoi(p);
        getline(ss,desc,',');
        Priority priority = get_priority(desc);
        std::string commentaries;
        getline(ss,commentaries,',');
        std::string in;
        getline(ss,in,',');
        int id = std::stoi(in);
        /*std::string sous_taches;
        getline(ss, sous_taches, ',');*/
        std::vector<Task> undertasks;

        Task tache(title,description,creation,closing,status,progress,priority,commentaries,id,undertasks);
        todolist.new_task(tache);
        
        }
        fichier.close();
    }
    else
        {
            std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
        }

    todolist.modify();

    std::ofstream ecrire("todolist.csv", std::ios::out | std::ios::trunc);

    if (ecrire) {
        std::string ligne;
        for (auto tache: todolist.list) {
            ecrire << tache.get_csv();
        };
        ecrire.close();
    }
    else {std::cout << "impossible d'écrire dans le fichier" << std::endl;}

    return 0;
}