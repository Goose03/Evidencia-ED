#include <iostream>
#include <fstream>
#include "fileBitacora.h"
#include "fileBitacora.cpp"

using namespace std;

int main() {
    FileBitacora bitacora;
    ifstream unSortedFile("bitacora.txt");

    if (!unSortedFile) {
        cout << "No se pudo abrir el archivo bitacora.txt" << endl;
        return 1;
    }

    string date, time, ip, port, message;
    while (unSortedFile >> date >> time >> ip >> message) {
        getline(unSortedFile, message);
        bitacora.addRegistro(date, time, ip, message);
    }

    unSortedFile.close();

    bitacora.sortIP();

    int search = 1;
    string startIP, endIP;
    char continuar = 'S';

    while (continuar == 'S' || continuar == 's') {
        cout << "Ingrese la IP de inicio de búsqueda (formato ###.###.###.###): ";
        cin >> startIP;
        cout << "Ingrese la IP de fin de búsqueda (formato ###.###.###.###): ";
        cin >> endIP;

        bitacora.searchIP(startIP, endIP, search);

        cout << "¿Desea realizar otra búsqueda? (S/N): ";
        cin >> continuar;

        search++;
    }

    return 0;
}