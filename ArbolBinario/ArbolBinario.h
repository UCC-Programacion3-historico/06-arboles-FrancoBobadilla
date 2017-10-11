#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbol.h"

template<class T>
class ArbolBinario {
private:
    NodoArbol<T> *raiz;
public:
    ArbolBinario();

    void put(T dato);

    T search(T dato);

    void remove(T dato);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void print();

};

template<class T>
ArbolBinario<T>::ArbolBinario() {
    raiz = NULL;
}

template<class T>
ArbolBinario<T>::~ArbolBinario() {
    while (!esVacio())
        remove(raiz->getDato());
}

template<class T>
T ArbolBinario<T>::search(T dato) {
    if (raiz == NULL)throw 1;
    return raiz->search(dato);
}

template<class T>
void ArbolBinario<T>::put(T dato) {
    if (raiz == NULL) {
        raiz = new NodoArbol<T>(dato);
    } else {
        raiz->put(dato);
    }


}

template<class T>
void ArbolBinario<T>::remove(T dato) {
    NodoArbol<T> *aux;
    if (raiz == NULL)throw 1;
    aux = raiz;
    raiz = raiz->remover(dato);
    if (raiz != aux)
        delete aux;
}

template<class T>
bool ArbolBinario<T>::esVacio() {
    return raiz == NULL;
}

template<class T>
void ArbolBinario<T>::preorder() {
    if (raiz != NULL)
        raiz->preorder();
}

template<class T>
void ArbolBinario<T>::inorder() {
    if (raiz != NULL)
        raiz->inorder();
}

template<class T>
void ArbolBinario<T>::postorder() {
    if (raiz != NULL)
        raiz->postorden();
}

template<class T>
void ArbolBinario<T>::print() {
    if (raiz != NULL)
        raiz->print(false,"");
}


#endif //ARBOLBINARIO_H