//  IMPORTANTE
//  PARA COMPILAR EL PROGRAMA SE TIENE QUE USAR EL SIGUIENTE COAMDO
//  g++ -Wall -Wextra -g3 main.cpp log.cpp fileVect.cpp -o main  
//  ESTANDO EN EL FOLDER QUE CONTIENE LOS ARCHIVOS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "log.h"
#include "fileVect.h"

using namespace std;


void menu(fileVect h){
    string cont = "1"; // continue
    int fAmnt = 1;

    while(cont == "1"){
        system("clear");
        system("cls");

        string ip1 = "";
        string ip2 = "";

        cout << "Ingresa la primera ip de filtro" << endl;
        getline(cin, ip1, '\n');

        cout << "Ingresa la ip limite" << endl;
        getline(cin, ip2, '\n');

        log f1(ip1);
        log f2(ip2);

        if(f1 > f2){
            log tmp = f1;
            f1 = f2;
            f2 = tmp;
        }

        h.fileWrite(f1, f2, fAmnt);

        cout << "Tu archivo deberia de aparecer en la carpeta de output" << endl;
        cout << "Escribe 1 si deseas continuar, 0 si no" << endl;

        fAmnt++;

        getline(cin, cont);
    }
}


int main(){
    system("cls");

    fileVect h("bitacora.txt");

    h.ordenaMerge();

    h.fileWrite();

    menu(h);

    return 0;
}