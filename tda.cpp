#include <iostream>
#include <tda.hpp>
#include <string>
using namespace std;
//todos estos metodos los hizo github copilot, asi que hay que revisarlos bien
Director::Director(){
    
    //inicializa cada parametro en null de la clase
    head = nullptr;
    curr = nullptr;
    tail = nullptr;
    size = 0;
    nombre_director;
    rating_promedio = 0;
    
}
Director::~Director(){
    
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
    
}
//agrega la pelicula de manera del append
void Director::agregar_pelicula(Pelicula* pelicula){
    
    //crea un nuevo nodo de lista
    lNodo* nuevo = new lNodo;
    //le asigna la pelicula correspondiente al nodo
    nuevo->val = pelicula;
    nuevo->val->nombre = pelicula->nombre;
    nuevo->val->director = pelicula->director;
    nuevo->val->rating = pelicula->rating;
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
    
}
void Director::calcular_rating_promedio(){
    
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

    
}
void Director::ordenar(){
    
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
    
}
void Director::mostrar_peliculas(){
    
    //crea un nodo temporal en la cabeza de la lista
    lNodo* temp = head;
    while (temp != nullptr){
        //pasa de uno en uno cada pelicula del director
        cout << temp->val->nombre << endl;
        temp = temp->sig;
    }
    
}
string Director::nombre(){
    return nombre_director;
}

Arboles::Arboles(){
    
    //inicializa todos los parametros de ambos arboles en null
    root_dir = nullptr;
    curr_dir = nullptr;
    size_dir = 0;
    root_rat = nullptr;
    curr_rat = nullptr;
    size_rat = 0;
    
}
Arboles::~Arboles(){
    borrarNodo(root_dir);
    borrarNodo(root_rat);
}
void Arboles::borrarNodo(aNodo* nodo) {
        if (nodo == nullptr) return;
        borrarNodo(nodo->izq);
        borrarNodo(nodo->der);
        delete nodo;
}

void Arboles::insertar_pelicula(Pelicula * pelicula){
    
    aNodo* nuevo = new aNodo;
    nuevo->val = new Director;
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
    
}
void Arboles::insertar_dir(Director* director){
        
    aNodo* nuevo = new aNodo;
    nuevo->val = director;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    curr_rat = root_rat;
    while (curr_rat != nullptr){
        if (director->rating_promedio < curr_rat->val->rating_promedio){
            if (curr_rat->izq == nullptr){
                curr_rat->izq = nuevo;
                break;
            } else {
                curr_rat = curr_rat->izq;
            }
            if (curr_rat->der == nullptr){
                curr_rat->der = nuevo;
                break;
            } else {
                curr_rat = curr_rat->der;
            }
        }
    }
        size_rat++;
}

void Arboles::copiar_arbol(){
    if (root == nullptr) return;
    Arboles *arbol = new Arboles();

    void preorden(aNodo* root){
        if (root == nullptr) return;
            aNodo* nuevo = new aNodo;
            nuevo->val = root->val;
            nuevo->izq = preorden(root->izq);
            nuevo->der = preorden(root->der);
    }

    aNodo* temp = root_dir;
    while (temp != nullptr){
        insertar_pelicula(temp->val->head->val);
        temp = temp->izq
        temp = temp->der;
    }
}
int Arboles::size(){
    return size_dir;
}

Director* Arboles::buscar_director(string director){
    
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
    tCola cola;
    void inonOrden(root_rat){
        if (root_rat == nullptr) return;
        inonOrden(root_rat->der);
        cola.enqueue(root_rat->val);
        inonOrden(root_rat->izq);
    }
    for(int i = 0; i < n; i++){
        cout << cola.frontValue()->nombre_director << endl;
        cola.dequeue();
    }
    
}
void Arboles::peores_directores(int n){
    tCola cola;
    void inonOrden(root_rat){
        if (root_rat == nullptr) return;
        inonOrden(root_rat->izq);
        cola.enqueue(root_rat->val);
        inonOrden(root_rat->der);
    }
    for(int i = 0; i < n; i++){
        cout << cola.frontValue()->nombre_director << endl;
        cola.dequeue();
    }
}
