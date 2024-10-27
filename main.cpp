#include <iostream>
#include <string>
#include <fstream>
#include "tda.hpp"
#include <sstream>

//#MA10
using namespace std;

int main(){

    ifstream file;
    string cant_pelis, comando, linea;

    file.open("Peliculas.txt");
    if (!file.is_open()){
        cerr << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    getline (file, cant_pelis); //obtener el valor de cantidad de lineas
    int max_pelis = stoi(cant_pelis); //pasarlo a entero 
    Pelicula * peliculas[max_pelis]; //arreglo de punteros a peliculas
    for (int i = 0; i < max_pelis; i++){
        getline(file, linea); //obtener cada linea
        string nombre, director, rating_str;
        float rating;
        stringstream ss(linea);
        // Separar los campos usando ';' como delimitador
        getline(ss, nombre,';');
        getline(ss, director,';');
        getline(ss, rating_str,';');
        rating = stof(rating_str); //pasar el rating a float

        //en cada slot del arreglo hay un puntero a una pelicula con sus respectivos campos
        peliculas[i] = new Pelicula;
        peliculas[i]->nombre = nombre;
        peliculas[i]->director = director;
        peliculas[i]->rating = rating;
    }
    file.close(); //no se usara mas el archivo
    bool flag = true;
    Arboles arbol1,arbolcopy;
    for (int i = 0; i < max_pelis; i++){
        arbol1.insertar_pelicula(peliculas[i]);
    }




    while (flag){
        
        cin >> comando;
        if (comando == "e"){
            flag = false;
        } else if (comando == "sm"){
            string nombre_peli;
            cin.ignore();
            getline(cin, nombre_peli);
            Pelicula* peli = arbol1.buscar_pelicula(nombre_peli);
        } else if (comando == "br"){
            int n;
            string temp;
            cin.ignore();
            getline(cin, temp);
            n = stoi(temp);
            arbol1.mejores_directores(n);
            
        } else if (comando == "sd"){
            string director;
            cin.ignore();
            getline(cin, director);
            Director* dir = arbol1.buscar_director(director);
            if (dir != nullptr){
                dir->mostrar_peliculas();
            }
        } else if (comando == "wr"){
            int n;
            string temp;
            cin.ignore();
            getline(cin, temp);
            n = stoi(temp);
            arbol1.peores_directores(n);
        }

    }
    for (int i = 0; i < max_pelis; i++){
        delete peliculas[i];
    }
    return 0;
}

    //al momento de tener el constructor del director, creara una lista para cada uno de los directores con sus peliculas correspondientes

