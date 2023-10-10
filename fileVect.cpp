#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "fileVect.h"

using namespace std;

// funcion constructor
fileVect ::fileVect(string bitacora) //complejidad n
{
    ifstream unSortedFile;
    unSortedFile.open(bitacora);            // Abre el archivo
    cout << unSortedFile.is_open() << endl; // Confirma que el archivo esta abierto

    // Encontrar los valores mas grandes y pequenos dentro del parametro para ser usados como limites
    while (unSortedFile.good())
    {
        string line;
        getline(unSortedFile, line, '\n');
        log lineObj(line);

        vect.push_back(lineObj); // Esta es la linea en la que esta el archivo
    }

    unSortedFile.close();
}

// Funcion para escribir al archivo
void fileVect ::fileWrite(log s, log e, int fileNum) //complejidad n
{
    string fileName = "salida" + to_string(fileNum) + "-eq3.txt";

    ofstream sortedFile(fileName);

    for (long long unsigned int i = 0; i < this->vect.size(); i++)
    {//
        if (this->vect[i] > s && this->vect[i] < e)
        {
            sortedFile << this->vect[i].logLine << endl;
        }
    }
}

// Funcion para escribir todo el vector
void fileVect ::fileWrite()
{
    ofstream sortedFile("bitacoraOrdenada1.3-eq3.txt");
    for (long long unsigned int i = 0; i < this->vect.size(); i++)
    {
        sortedFile << this->vect[i].logLine << endl;
    }
}

// Funcion de Merge
vector<log> fileVect ::merge(vector<log> left, vector<log> right)
{ //complejidad de (n log n)
    vector<log> res;

    while ((int)left.size() > 0 || (int)right.size())
    {

        if ((int)left.size() > 0 && (int)right.size() > 0)
        {
            log x = left.front();
            log y = right.front();

            if (x <= y)
            {
                res.push_back(left.front());
                left.erase(left.begin());
            }

            else
            {
                res.push_back(right.front());
                right.erase(right.begin());
            }
        }

        else if ((int)left.size() > 0)
        {
            for (int i = 0; i < (int)left.size(); i++)
                res.push_back(left[i]);
            break;
        }

        else if ((int)right.size() > 0)
        {
            for (int i = 0; i < (int)right.size(); i++)
                res.push_back(right[i]);
            break;
        }
    }

    return res;
}

// Funcion para merge sort
vector<log> fileVect ::ordenaMerge(vector<log> vec)
{
    if (vec.size() <= 1)
    {
        return vec;
    }

    vector<log> left, right, res;

    int midd = ((int)vec.size() + 1) / 2;

    for (int i = 0; i < midd; i++)
    {
        left.push_back(vec[i]);
    }

    for (int i = midd; i < (int)vec.size(); i++)
    {
        right.push_back(vec[i]);
    }

    left = ordenaMerge(left);
    right = ordenaMerge(right);

    res = merge(left, right);

    return res;
}

// Wrapper para ordebaMerge
void fileVect ::ordenaMerge()
{
    this->vect = ordenaMerge(this->vect);
}