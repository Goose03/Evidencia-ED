#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

struct log{
    int mes;
    int dia;
    int hr;
    int min;
    int seg;

    int totSec;
    string logLine;

    log(string line);

};
#endif