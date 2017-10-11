#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <iostream>

using namespace std;

template<class T>
class NodoArbol {
private:
    NodoArbol<T> *izq, *der;
    T dato;
public:
    NodoArbol(T dato);

    T getDato();

    void put(T dato);

    void put(NodoArbol<T> *nodo);

    T search(T d);

    NodoArbol<T> *remover(T d);

    void preorder();

    void inorder();

    void postorden();

    void print(bool esDerecho, string identacion);

    int PorNivel(int nivel,int cont);
};

template<class T>
NodoArbol<T>::NodoArbol(T dato) {
    this->dato = dato;
    izq = NULL;
    der = NULL;
}

template<class T>
T NodoArbol<T>::getDato() {
    return dato;
}

template<class T>
void NodoArbol<T>::put(T d) {
    if (d == dato)throw 1;
    if (d < dato) {
        if (izq == NULL) {
            izq = new NodoArbol<T>(d);
        } else {
            izq->put(d);
        }
    } else {
        if (der == NULL) {
            der = new NodoArbol<T>(d);
        } else {
            der->put(d);
        }
    }
}

template<class T>
void NodoArbol<T>::put(NodoArbol<T> *nodo) {
    if (nodo->getDato() == dato)throw 1;
    if (nodo->getDato() < dato) {
        if (izq == NULL) {
            izq = new NodoArbol<T>(nodo->getDato());
        } else {
            izq->put(nodo);
        }
    } else {
        if (der == NULL) {
            der = new NodoArbol<T>(nodo->getDato());
        } else {
            der->put(nodo);
        }
    }
}

template<class T>
T NodoArbol<T>::search(T d) {
    if (d == dato)
        return dato;
    if (d < dato) {
        if (izq == NULL)
            throw 1;
        return izq->search(d);
    } else {
        if (der == NULL)
            throw 1;
        return der->search(d);
    }
}

template<class T>
NodoArbol<T> *NodoArbol<T>::remover(T d) {
    NodoArbol<T> *aux;
    if (d == dato) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;
    }
    if (d < dato) {
        if (izq == NULL)throw 1;
        aux = izq;
        izq = izq->remover(d);
        if (izq != aux)delete aux;
    } else {
        if (der == NULL)throw 1;
        aux = der;
        der = der->remover(d);
        if (der != aux)delete aux;
    }
    return this;
}

template<class T>
void NodoArbol<T>::preorder() {
    cout << dato << ", ";
    if (izq != NULL)izq->preorder();
    if (der != NULL)der->preorder();
};

template<class T>
void NodoArbol<T>::inorder() {
    if (izq != NULL)izq->inorder();
    cout << dato << ", ";
    if (der != NULL)der->inorder();
};

template<class T>
void NodoArbol<T>::postorden() {
    if (izq != NULL)izq->postorden();
    if (der != NULL)der->postorden();
    cout << dato << ", ";
}

template<class T>
void NodoArbol<T>::print(bool esDerecho, string identacion) {
    if (der != NULL) {
        der->print(true, identacion + (esDerecho ? "     " : "|    "));
    }
    cout << identacion;
    if (esDerecho) {
        cout << " /";
    } else {
        cout << " \\";
    }
    cout << "-- ";
    cout << dato << endl;
    if (izq != NULL) {
        izq->print(false, identacion + (esDerecho ? "|    " : "     "));
    }
}

template<class T>
int NodoArbol<T>::PorNivel(int nivel,int cont) {
}
#endif //NODOARBOL_H