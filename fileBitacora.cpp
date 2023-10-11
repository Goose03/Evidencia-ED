#include "fileBitacora.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

FileBitacora::FileBitacora(){
    this->size = 0;
    this->search = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

FileBitacora::~FileBitacora(){
    while (this->head != nullptr){
        Registro* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    this->tail = nullptr;
}

/*string FileBitacora::checkIP(string ip){
    size_t pos = ip.find(':');
    if (pos == string::npos) {
        return "Formato incorrecto";
    }
    string firstPart = ip.substr(0, pos);
    string secondPart = ip.substr(pos + 1);

    // Dividir la primera parte en octetos
    istringstream ss(firstPart);
    string octet;
    string adjustedIP;

    while (getline(ss, octet, '.')) {
        // Asegurarse de que cada octeto tenga 3 dígitos
        while (octet.length() < 3) {
            octet = '0' + octet;
        }

        adjustedIP += octet + '.';
    }

    // Eliminar el último '.'
    adjustedIP.pop_back();

    // Reconstruir la cadena
    return adjustedIP + ":" + secondPart;
}

void FileBitacora::sortIP(){
    if (this->head == nullptr || this->head->next == nullptr) {
        return;
    }

    Registro* tail = this->head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    quickSort(this->head, tail);
}*/

/*int FileBitacora::compareIP(string& ip1, string& ip2) {
    string adjustedIP1 = checkIP(ip1);
    string adjustedIP2 = checkIP(ip2);

    if (adjustedIP1 == "Formato incorrecto" || adjustedIP2 == "Formato incorrecto") {
        return 0; // Manejo de errores
    }

    return adjustedIP1.compare(adjustedIP2);
}*/

void FileBitacora::saveOrdered(){
    ofstream sortedFile("bitacoraOrdenada1.3-eq3.txt");

    Registro* aux = this->head;
    while (aux != nullptr) {
        sortedFile << aux->date << " " << aux->time << " " << aux->ip << " " << aux->message << endl;
        aux = aux->next;
    }

    sortedFile.close();
}

void FileBitacora::searchIP(string& startIP, string& endIP, int search){
    Registro* aux = this->head;
    ofstream sortedFile("salida" + to_string(search) + "-Eq3.txt");

    while (aux != nullptr) {
        if (compareIP(aux->ip, startIP) >= 0 && compareIP(aux->ip, endIP) <= 0) {
            sortedFile << aux->date << " " << aux->time << " " << aux->ip << " " << aux->message << endl;
        }
        aux = aux->next;
    }
    sortedFile.close();
}

void FileBitacora::addRegistro(string date, string time, string ip, string message){
    string ipCorrected = checkIP(ip);

    Registro* newRegistro = new Registro(date, time, ipCorrected, message, this->head);
    /*newRegistro->date = date;
    newRegistro->time = time;
    newRegistro->ip = ipCorrected;
    newRegistro->message = message;
    newRegistro->next = this->head;*/
    this->head = newRegistro;
}

Registro* FileBitacora::partition(Registro* low, Registro* high) {
    std::string pivot = high->ip;
    Registro* i = low;

    for (Registro* j = low; j != high; j = j->next) {
        if (compareIP(j->ip, pivot) <= 0) {
            i = (i == nullptr) ? low : i->next;
            // Intercambiar los campos directamente, no se necesita una función swap
            std::swap(i->date, j->date);
            std::swap(i->time, j->time);
            std::swap(i->ip, j->ip);
            std::swap(i->message, j->message);
        }
    }

    i = (i == nullptr) ? low : i->next;
    std::swap(i->date, high->date);
    std::swap(i->time, high->time);
    std::swap(i->ip, high->ip);
    std::swap(i->message, high->message);
    
    return i;
}

void FileBitacora::quickSort(Registro* low, Registro* high) {
    if (low != nullptr && high != nullptr && low != high && low != high->next) {
        Registro* pivot = partition(low, high);
        quickSort(low, pivot);
        quickSort(pivot->next, high);
    }
}