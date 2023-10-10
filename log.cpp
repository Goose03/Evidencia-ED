#include <iostream>
#include <string>
#include <map>

#include "log.h"

using namespace std;

log::log(string line){ //constructor
    this -> logLine = line;

    this -> dia = stoi(line.substr(4, 2));
    if(line.size() > 18){
        if(dia > 9){
            this -> ip = line.substr(16, findPuntos(line, ':', 3)- 11);
        }
        else{
            this -> ip = line.substr(15, findPuntos(line, ':', 3)- 10);
        }

        this -> primero = stoi(ip.substr(0, findPuntos(ip, '.', 1)));

        this -> segundo = stoi(ip.substr(findPuntos(ip, '.', 1) + 1, findPuntos(ip, '.', 2)));

        this -> tercero = stoi(ip.substr(findPuntos(ip, '.', 2) + 1, findPuntos(ip, '.', 3)));

        this -> cuarto = stoi(ip.substr(findPuntos(ip, '.', 3) + 1, findPuntos(ip, '.', 4)));

        this -> port = stoi(ip.substr(findPuntos(ip, ':', 1) + 1, 4));
    }
    else{

        this -> ip = line;

        this -> primero = stoi(ip.substr(0, findPuntos(ip, '.', 1)));

        this -> segundo = stoi(ip.substr(findPuntos(ip, '.', 1) + 1, findPuntos(ip, '.', 2)));

        this -> tercero = stoi(ip.substr(findPuntos(ip, '.', 2) + 1, findPuntos(ip, '.', 3)));

        this -> cuarto = stoi(ip.substr(findPuntos(ip, '.', 3) + 1, findPuntos(ip, '.', 4)));

        this -> port = stoi(ip.substr(findPuntos(ip, ':', 1) + 1, 4));
    }
}

bool log::operator>(const log& other){ //sobrecarga operador mayor que
    if (primero != other.primero){
        return primero > other.primero;
    }
    else if(segundo != other.segundo){
        return segundo > other.segundo;
    }
    else if(tercero != other.tercero){
        return tercero > other.tercero;
    }
    else if(cuarto != other.cuarto){
        return cuarto > other.cuarto;
    }
    else{
        return port > other.port;
    }
}

bool log::operator<(const log& other){ //sobrecarga operador menor que
    if (primero != other.primero){
        return primero < other.primero;
    }
    else if(segundo != other.segundo){
        return segundo < other.segundo;
    }
    else if(tercero != other.tercero){
        return tercero < other.tercero;
    }
    else if(cuarto != other.cuarto){
        return cuarto < other.cuarto;
    }
    else{
        return port < other.port;
    }
}

bool log::operator<=(const log& other) { //sobrecarga operador menor o igual que
    if (primero != other.primero){
        return primero <= other.primero;
    }
    else if(segundo != other.segundo){
        return segundo <= other.segundo;
    }
    else if(tercero != other.tercero){
        return tercero <= other.tercero;
    }
    else if(cuarto != other.cuarto){
        return cuarto <= other.cuarto;
    }
    else{
        return port <= other.port;
    }
}

int log::findPuntos(string str, char target, int numAparicion) { //funcion que encuentra la po
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == target) {
            count++;
            if (count == numAparicion) {
                return i;
            }
        }
    }
    return -1;
}