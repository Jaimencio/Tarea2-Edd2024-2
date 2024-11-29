#ifndef TDA_H
#define TDA_H
#include <string>
using namespace std;
struct Pelicula {
    string nombre;
    string director;
    float rating;
};

class Director {
private :
    //nodo de lista enlazada
    struct lNodo {
    Pelicula* val;
    lNodo* sig;
    };
    lNodo* head;
    lNodo* curr;
    lNodo* tail;
    size_t size; // longitud lista, o tambien cantidad de peliculas
public:
    float rating_promedio; //variable para calcular solo 1 vez el rating
    string nombre_director;
    Director (); // constructor
    ~ Director (); // destructor
    void agregar_pelicula ( Pelicula* pelicula ); // agrega pelicula al final de la lista enlazada
    void ordenar (); // ordena la lista de menor a mayor rating
    void calcular_rating_promedio ();
    void mostrar_peliculas ();
    string nombre();
    lNodo* get_head() const { return head; }

};

class Arboles {
private :
    //nodo de arbol
    struct aNodo {
    Director* val;
    aNodo* izq;
    aNodo* der;
    };
    aNodo* root_dir; // raiz arbol ordenado por directores
    aNodo* curr_dir;
    size_t size_dir;
    aNodo* root_rat; // raiz arbol ordenado por rating
    aNodo* curr_rat;
    size_t size_rat;
public :
    Arboles (); // constructor
    ~ Arboles (); // destructor
    void insertar_pelicula ( Pelicula* pelicula );
    void copiar_arbol (); // hace copia de arbol 1 en arbol 2 ordenado respecto de rating
    Director* buscar_director ( string director ); // retorna arreglo de peliculas
    Pelicula* buscar_pelicula ( string pelicula ); // retorna peliculas
    void mejores_directores ( int n); // Muestra por pantalla los mejores n directores. Enumerando de 1 a n.
    void peores_directores ( int n ); // Muestra por pantalla los peores n directores.Enumerando desde m ( cantidad de directores ) hasta m-n.
    int size();
    void borrarNodo(aNodo* nodo);
    // void copiar_arbol_rec(aNodo* nodo);
    //void insertar_dir(Director* director);
    // void inonOrden(aNodo* nodo, tCola& cola);

};
#endif // TDA_H;