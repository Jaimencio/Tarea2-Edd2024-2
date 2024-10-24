#include <iostream>
#include <tda.hpp>
#include <string>
using namespace std;
//todos estos metodos los hizo github copilot, asi que hay que revisarlos bien
Director::Director(){
    /*
    //inicializa cada parametro en null de la clase
    head = nullptr;
    curr = nullptr;
    tail = nullptr;
    size = 0;
    nombre_director = "";
    rating_promedio = 0;
    */
}
Director::~Director(){
    /*
    //crea un nodo temporal al inicio de la lista
    lNodo* temp = head;
    //se crea un segundo nodo temporal para ir manteniendo el registro de la lista y elimina los nodos
    while (temp != nullptr){
        lNodo* temp2 = temp;
        temp = temp->sig;
        delete temp2;
    }
    //vuelve los parametros a null
    head = nullptr;
    curr = nullptr;
    tail = nullptr;
    size = 0;
    nombre_director = "";
    rating_promedio = 0;
    */
}
//agrega la pelicula de manera del append
void Director::agregar_pelicula(Pelicula* pelicula){
    /*
    //crea un nuevo nodo de lista
    lNodo* nuevo = new lNodo;
    //le asigna la pelicula correspondiente al nodo
    nuevo->val = pelicula;
    //hace la referencia al siguiente nodo en null
    nuevo->sig = nullptr;
    //si la lista esta vacia, el nuevo nodo es la cabeza y la cola
    if (head == nullptr){
        head = nuevo;
        tail = nuevo;
    } else {
        //lo agrega al final de la lista
        tail->sig = nuevo;
        //lo convierte en la cola
        tail = nuevo;
    }
    //aumenta el tamaño de la lista
    size++;
    */
}
void Director::calcular_rating_promedio(){
    /*
    //crea un nodo temporal para comenzar la suma de ratings de todas las peliculas
    lNodo* temp = head;
    float suma = 0;
    while (temp != nullptr){
        //se añade el rating a la suma total y pasa al siguiente nodo
        suma += temp->val->rating;
        temp = temp->sig;
    }
    //saca el promedio
    rating_promedio = suma / size;

    */
}
void Director::ordenar(){
    /*
    //crea dos nodos en la cabeza de la lista
    lNodo* temp = head;
    lNodo* temp2 = head;
    //entra al while siempre y cuando el head no sea null
    while (temp != nullptr){
        while (temp2 != nullptr){
        //si el rating del PRIMER nodo es MAYOR al rating del SEGUNDO nodo, se intercambian
            if (temp->val->rating > temp2->val->rating){
                Pelicula* aux = temp->val;
                temp->val = temp2->val;
                temp2->val = aux;
            }
            //se desplaza en uno el segundo nodo
            temp2 = temp2->sig;
        }
        //tras recorrer toda la lista con el segundo nodo, se DESPLAZA en uno el PRIMER nodo
        temp = temp->sig;
    }
    */
}
void Director::mostrar_peliculas(){
    /*
    //crea un nodo temporal en la cabeza de la lista
    lNodo* temp = head;
    while (temp != nullptr){
        //pasa de uno en uno cada pelicula del director
        cout << temp->val->nombre << endl;
        temp = temp->sig;
    }
    */
} 
Arboles::Arboles(){
    /*
    //inicializa todos los parametros de ambos arboles en null
    root_dir = nullptr;
    curr_dir = nullptr;
    size_dir = 0;
    root_rat = nullptr;
    curr_rat = nullptr;
    size_rat = 0;
    */
}
Arboles::~Arboles(){
    /*
    //REVISAR ESTO!!!! BORRAR EN POST-ORDEN
    aNodo* temp = root_dir;
    if (temp == nullptr){
        return;
    }
    
    temp = root_rat;
    while (temp != nullptr){
        aNodo* temp2 = temp;
        temp = temp->der;
        delete temp2;
    }
    */
}
void Arboles::insertar_pelicula(Pelicula * pelicula){
    /*
    aNodo* nuevo = new aNodo;
    nuevo->val = new Director;
    nuevo->val->nombre_director = pelicula->director;
    nuevo->val->agregar_pelicula(pelicula);
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    if (root_dir == nullptr){
        root_dir = nuevo;
        curr_dir = nuevo;
    } else {
        curr_dir = root_dir;
        while (curr_dir != nullptr){
            if (pelicula->director < curr_dir->val->nombre_director){
                if (curr_dir->izq == nullptr){
                    curr_dir->izq = nuevo;
                    break;
                } else {
                    curr_dir = curr_dir->izq;
                }
            } else {
                if (curr_dir->der == nullptr){
                    curr_dir->der = nuevo;
                    break;
                } else {
                    curr_dir = curr_dir->der;
                }
            }
        }
    }
    size_dir++;
    */
}
void Arboles::copiar_arbol(){
    /*
    aNodo* temp = root_dir;
    while (temp != nullptr){
        insertar_pelicula(temp->val->head->val);
        temp = temp->der;
    }
    */
}
Director* Arboles::buscar_director(string director){
    /*
    aNodo* temp = root_dir;
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
Pelicula* Arboles::buscar_pelicula(string pelicula){
    /*
    aNodo* temp = root_dir;
    while (temp != nullptr){
        lNodo* temp2 = temp->val->head;
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
void Arboles::mejores_directores(int n){
    /*
    aNodo* temp = root_rat;
    for (int i = 0; i < n; i++){
        cout << i+1 << ". " << temp->val->nombre_director << endl;
        temp = temp->der;
    }
    */
}
void Arboles::peores_directores(int n){
    /*
    aNodo* temp = root_rat;
    for (int i = 0; i < size_1-n; i++){
        temp = temp->der;
    }
    for (int i = 0; i < n; i++){
        cout << size_dir-i << ". " << temp->val->nombre_director << endl;
        temp = temp->izq;
    }
    */
}
