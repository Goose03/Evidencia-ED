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

    log(string line){
        this -> logLine = line;

        map<string, int> m; //Diccionario de mes a val numerico

        //Valores de los meses expresados en cuantos dias han pasado del año
        m["Jan"] = 0;
        m["Feb"] = 31;
        m["Mar"] = 59;
        m["Apr"] = 90;
        m["May"] = 120;
        m["Jun"] = 151;
        m["Jul"] = 182;
        m["Aug"] = 212;
        m["Sep"] = 243;
        m["Oct"] = 273;
        m["Nov"] = 304;
        m["Dec"] = 334;

        map<string,int> :: iterator tmp = m.find(line.substr(0, 3)); //Convierte el str de mes a dia

        //El mes y el dia los usa de afuerza para todo tipo de objeto
        this -> mes = (tmp -> second) - 1;

        this -> dia = stoi(line.substr(4, 2));

        
        if(line.size() > 6){

            //El resto de los tiempos solo los usa en caso de que se le de un log completo
            if(dia > 9){
                this -> hr = stoi(line.substr(7, 2));

                this -> min = stoi(line.substr(10, 2)); 

                this -> seg = stoi(line.substr(13, 2));
            }
            else{
                this -> hr = stoi(line.substr(6, 2));

                this -> min = stoi(line.substr(9, 2)); 

                this -> seg = stoi(line.substr(12, 2));
            }
            
            this -> totSec = (mes * 86400) + (dia * 86400) + (hr * 3600) + (min * 60) + (seg);
        }
        else{
            this -> totSec = (mes * 86400) + (dia * 86400);
        }

        //Las separaciones se hacen para poder tener objetos que se puedan
        //utilizar a los limites si solo les damos mes y dia
    }
};
#endif