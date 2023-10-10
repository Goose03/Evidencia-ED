//  IMPORTANTE
//  PARA COMPILAR EL PROGRAMA SE TIENE QUE USAR EL SIGUIENTE COAMDO
//  g++ -Wall -Wextra -g3 /../main.cpp /../log.cpp /../fileVect.cpp -o /../output/main   
//  LOS PUNTOS REPRESENTAN EL PATH DEL ARCHIVO

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
        system("cls");

        string fecha1 = "";
        string fecha2 = "";

        cout << "Ingresa la primera fecha de filtro en el siguiente formato: Oct 3" << endl;
        getline(cin, fecha1, '\n');

        cout << "Ingresa la segunda fecha limite en el mismo formato" << endl;
        getline(cin, fecha2, '\n');

        log f1(fecha1);
        log f2(fecha2);

        if(f1.totSec > f2.totSec){
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