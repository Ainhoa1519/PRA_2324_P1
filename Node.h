#include <ostream>

template <typename T>
class Node {
public:
    T data;                    // Elemento almacenado tipo genérico
    Node<T>* next;             // Puntero al siguiente nodo
//metodo constructor: next será nullptr en caso de que no se proporcione
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {
    
    }  
//sobrecarga el operador << para imprimir una instancia de Node<T> por pantalla
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;      // Imprime solo el dato/ atributo
        return out;
    }
};

