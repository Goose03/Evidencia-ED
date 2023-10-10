#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H

#include <iostream>
#include <string>
#include <map>

struct log{
    int dia;
    int primero;
    int segundo;
    int tercero;
    int cuarto;
    int port;

    std::string logLine;
    std::string ip;

    log(std::string line);
    bool operator>(const log& other);
    bool operator<(const log& other);
    bool operator<=(const log& other);
    int findPuntos(std::string str, char target, int numAparicion); //funcion que encuentra la posición de un caractér en un string
};
#endif