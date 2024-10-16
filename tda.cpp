#include <iostream>
#include <tda.hpp>
#include <string>
using namespace std;
//todos estos metodos los hizo github copilot, asi que hay que revisarlos bien
Director::Director(){
    /*
    head = nullptr;
    curr = nullptr;
    tail = nullptr;
    size = 0;
    */
}
Director::~Director(){
    /*
    lNodo * temp = head;
    while (temp != nullptr){
        lNodo * temp2 = temp;
        temp = temp->sig;
        delete temp2;
    }
    */
}
Director::agregar_pelicula(Pelicula * pelicula){
    /*
    lNodo * nuevo = new lNodo;
    nuevo->val = pelicula;
    nuevo->sig = nullptr;
    if (head == nullptr){
        head = nuevo;
        tail = nuevo;
    } else {
        tail->sig = nuevo;
        tail = nuevo;
    }
    size++;
    */
}
Director::calcular_rating_promedio(){
    /*
    lNodo * temp = head;
    float suma = 0;
    while (temp != nullptr){
        suma += temp->val->rating;
        temp = temp->sig;
    }
    float promedio = suma / size;
    cout << "El rating promedio de " << nombre_director << " es: " << promedio << endl;
    */
}
Director::ordenar(){
    /*
    lNodo * temp = head;
    lNodo * temp2 = head;
    while (temp != nullptr){
        while (temp2 != nullptr){
            if (temp->val->rating > temp2->val->rating){
                Pelicula * aux = temp->val;
                temp->val = temp2->val;
                temp2->val = aux;
            }
            temp2 = temp2->sig;
        }
        temp = temp->sig;
    }
    */
}
Director::mostrar_peliculas(){
    /*
    lNodo * temp = head;
    while (temp != nullptr){
        cout << temp->val->nombre << " " << temp->val->director << " " << temp->val->rating << endl;
        temp = temp->sig;
    }
    */
} 
Arboles::Arboles(){
    /*
    root_1 = nullptr;
    curr_1 = nullptr;
    size_1 = 0;
    root_2 = nullptr;
    curr_2 = nullptr;
    size_2 = 0;
    */
}
Arboles::~Arboles(){
    /*
    aNodo * temp = root_1;
    while (temp != nullptr){
        aNodo * temp2 = temp;
        temp = temp->der;
        delete temp2;
    }
    temp = root_2;
    while (temp != nullptr){
        aNodo * temp2 = temp;
        temp = temp->der;
        delete temp2;
    }
    */
}
Arboles::insertar_pelicula(Pelicula * pelicula){
    /*
    aNodo * nuevo = new aNodo;
    nuevo->val = new Director;
    nuevo->val->nombre_director = pelicula->director;
    nuevo->val->agregar_pelicula(pelicula);
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    if (root_1 == nullptr){
        root_1 = nuevo;
        curr_1 = nuevo;
    } else {
        curr_1 = root_1;
        while (curr_1 != nullptr){
            if (pelicula->director < curr_1->val->nombre_director){
                if (curr_1->izq == nullptr){
                    curr_1->izq = nuevo;
                    break;
                } else {
                    curr_1 = curr_1->izq;
                }
            } else {
                if (curr_1->der == nullptr){
                    curr_1->der = nuevo;
                    break;
                } else {
                    curr_1 = curr_1->der;
                }
            }
        }
    }
    size_1++;
    */
}
Arboles::copiar_arbol(){
    /*
    aNodo * temp = root_1;
    while (temp != nullptr){
        insertar_pelicula(temp->val->head->val);
        temp = temp->der;
    }
    */
}
Arboles::buscar_director(string director){
    /*
    aNodo * temp = root_1;
    while (temp != nullptr){
        if (temp->val->nombre_director == director){
            return temp->val;
        }
        if (director < temp->val->nombre_director){
            temp = temp->izq;
        } else {
            temp = temp->der;
        }
    }
    return nullptr;
    */
}
Arboles::buscar_pelicula(string pelicula){
    /*
    aNodo * temp = root_1;
    while (temp != nullptr){
        lNodo * temp2 = temp->val->head;
        while (temp2 != nullptr){
            if (temp2->val->nombre == pelicula){
                return temp2->val;
            }
            temp2 = temp2->sig;
        }
        temp = temp->der;
    }
    return nullptr;
    */
}
Arboles::mejores_directores(int n){
    /*
    aNodo * temp = root_2;
    for (int i = 0; i < n; i++){
        cout << i+1 << ". " << temp->val->nombre_director << endl;
        temp = temp->der;
    }
    */
}
Arboles::peores_directores(int n){
    /*
    aNodo * temp = root_2;
    for (int i = 0; i < size_1-n; i++){
        temp = temp->der;
    }
    for (int i = 0; i < n; i++){
        cout << size_1-i << ". " << temp->val->nombre_director << endl;
        temp = temp->izq;
    }
    */
}
