#ifndef STATUS_H
#define STATUS_H

//librairie qui gère les statuts des tâches

#include<iostream>

class Status {
protected:
    std::string description;
public:
    Status() {};
    std::string describe() {return description;};
    void print () {std::cout << "\tStatus :\t" << description << std::endl;};
};

class Inexisting : public Status {
public:
    Inexisting() {description = "Inexisting";};
};

class Open : public Status {
public:
    Open() {description = "Open";};
};

class Inprogress : public Status {
public:
    Inprogress() {description = "In progress";};
};

class Closed : public Status {
public:
    Closed() {description = "Closed";};
};

Status get_status(std::string type) {
        if (type == "Open") {return(Open());}
        else if (type == "In progress") {return(Inprogress());}
        else if (type == "Closed") {return(Closed());}
        else {return(Inexisting());};
    };

#endif 