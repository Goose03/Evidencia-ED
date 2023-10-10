#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "log.h"

class fileVect{
    public:
        std::vector<log> vect;

        //funcion constructor
        fileVect(std::string bitacora);


        //Funcion para escribir al archivo
        void fileWrite(log s, log e, int fileNum);


        //Funcion para escribir todo el vector
        void fileWrite();


        //Funcion de Merge
        std::vector<log> merge(std::vector<log> left, std::vector<log> right);

        //Funcion para merge sort
        std::vector<log> ordenaMerge(std::vector<log> vec);

        // Wrapper para ordebaMerge
        void ordenaMerge();
};