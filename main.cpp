#include <iostream>
#include <string>
#include <fstream>
#include "tda.hpp"
//#MA10
using namespace std;

int main(){

    ifstream file;
    string cant_pelis;

    file.open("Peliculas.txt");
    if (!file.is_open()){
        cerr << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    getline (file, cant_pelis); //obtener el valor de cantidad de lineas
    int max_pelis = stoi(cant_pelis); 
    return 0;
} 