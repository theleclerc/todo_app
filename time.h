#ifndef TIME_H
#define TIME_H

//librairie pour un accès plus facile a la date actuelle en string
#include<ctime>
#include<iostream>

std::string now () {
    time_t rawtime;
        struct tm * timeinfo;
        time (&rawtime);
        timeinfo = localtime (&rawtime);
        std::string str =  asctime(timeinfo);
        str.pop_back(); //on enleve le \n final pour ne pas sauter de ligne dans le csv
        return str;
};

#endif