#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H

#include <iostream>
#include <string>
#include <map>

struct log{
    int mes;
    int dia;
    int hr;
    int min;
    int seg;

    int totSec;
    std::string logLine;

    log(std::string line);

};
#endif