#ifndef PRIORITIES_H
#define PRIORITIES_H

//librairie qui gère les priorités pour aérer le code de task_v.h et de todo_app_v.h

#include <iostream>
#include <string>

class Priority {
protected:
    int number;
    std::string description;
public:
    Priority (std::string description);
    Priority() {};

    std::string describe() {return description;}; //accès en lecture uniquement

    //les operateurs suivants au cas où on ajoute une fonction de tri des taches selon leur priorité
    friend bool operator<= (Priority p1, Priority p2) {
        return p1.number <= p2.number;
    };
    friend bool operator== (Priority p1, Priority p2) {
        return p1.number = p2.number;
    };
    friend bool operator>= (Priority p1, Priority p2) {
        return p1.number >= p2.number;
    };
    void print () {std::cout << "\tPriority :\t" << description << std::endl;};
};

class None : public Priority {
public:
    None(){
        number = 0;
        description = "None";
    }
};

class Faible : public Priority {
public:
    Faible() {
        number = 1;
        description = "Faible";
    };
};

class Intermediaire : public Priority {
public:
    Intermediaire() {
        number = 5;
        description = "Intermedaire";
    };
};

class Forte : public Priority {
public:
    Forte() {
        number = 10;
        description = "Forte";
    };
};

class Personnalisee : public Priority{
public:
    Personnalisee() {Personnalisee(0);}
    Personnalisee(int n) {
        number = n;
        std::string nb = std::to_string(number);
        description = "Personnalisée " + nb;
    };
};

Priority get_priority(std::string description) {
        if (description == "None") {return(None());}
        else if (description == "Faible") {return(Faible());}
        else if (description == "Intermediaire") {return(Intermediaire());}
        else if (description == "Forte") {return(Forte());}
        else {
            std::string nombre = description.substr(13);
            return(Personnalisee(std::stoi(nombre)));
        };
    };

#endif