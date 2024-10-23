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
    int max_pelis = stoi(cant_pelis); //pasarlo a entero 
    Pelicula * peliculas[max_pelis]; //arreglo de punteros a peliculas
    for (int i = 0; i < max_pelis; i++){
        //en cada slot del arreglo hay un puntero a una pelicula con sus respectivos campos
        peliculas[i] = new Pelicula;
        file >> peliculas[i]->nombre >> peliculas[i]->director >> peliculas[i]->rating;
    }
    file.close(); //no se usara mas el archivo
    return 0;
    //al momento de tener el constructor del director, creara una lista para cada uno de los directores con sus peliculas correspondientes
} 