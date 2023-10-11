#ifndef FILEBITACORA_H
#define FILEBITACORA_H

#include <string>

using namespace std;

struct Registro{
    string date;
    string time;
    string ip;
    string message;
    
    Registro* next;

    Registro(string date, string time, string ip, string message, Registro* next){
        this->date = date;
        this->time = time;
        this->ip = ip;
        this->message = message;
        this->next = next;
    }

    Registro(string date, string time, string ip, string message){
        date = time = ip = message = nullptr;
    }
};

class FileBitacora{
    public:
        int size;
        int search;
        Registro* head;
        Registro* tail;

        FileBitacora(); //TERMINADO
        ~FileBitacora(); //TERMINADO
        string checkIP(string ip);
        Registro* partition(Registro* low, Registro* high);
        void sortIP(); //TERMINADO
        int compareIP(string& ip1, string& ip2); //TERMINADO
        void searchIP(string& startIP, string& endIP, int search); //MAS O MENOS
        void saveOrdered(); //TERMINADO
        void addRegistro(string date, string time, string ip, string message);
        void quickSort(Registro* low, Registro* high);
};

#endif