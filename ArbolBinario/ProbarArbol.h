#ifndef PROBARARBOL_H
#define PROBARARBOL_H
#include <iostream>
#include "ArbolBinario.h"
void ProbarArbol(ArbolBinario<int> *arbol, int cant, int min, int max, bool imprimir) {
    if (cant <= 0 || min > max || cant > 1 + max - min) throw 1;
    int i = 0;
    int cantPorNivel;
    srand(time(NULL));
    while (i < cant) {
        try {
            arbol->put(rand() % max + min);
            i++;
        } catch (int e) {}
    }
    if (imprimir) {
        cout << endl << "Arbol de " << cant << " hojas, con valores desde " << min << " hasta " << max << ":" << endl
             << endl;
        arbol->print();
        cout << endl << endl << "Arbol en preorden: " << endl << "   ";
        arbol->preorder();
        cout << endl << endl << "Arbol en inorden: " << endl << "   ";
        arbol->inorder();
        cout << endl << endl << "Arbol en postorden: " << endl << "   ";
        arbol->postorder();
        cout << endl << endl << "Cantidad de nodos por nivel: ";
        i = 0;
        do {
            cantPorNivel = arbol->PorNivel(i);
            if (cantPorNivel != 0) {
                cout << endl << " Nivel " << i << ": " << cantPorNivel;
                if(cantPorNivel==1)
                    cout<< " nodo";
                else
                    cout<< " nodos";
            }
            i++;
        } while (cantPorNivel != 0);
        cout << endl << endl;

        arbol->espejo();

        cout << endl << "Arbol espejo del anterior:" << endl << endl;
        arbol->print();
        cout << endl << endl << "Arbol en preorden: " << endl << "   ";
        arbol->preorder();
        cout << endl << endl << "Arbol en inorden: " << endl << "   ";
        arbol->inorder();
        cout << endl << endl << "Arbol en postorden: " << endl << "   ";
        arbol->postorder();
        cout << endl << endl << "Cantidad de nodos por nivel: ";
        i = 0;
        do {
            cantPorNivel = arbol->PorNivel(i);
            if (cantPorNivel != 0) {
                cout << endl << " Nivel " << i << ": " << cantPorNivel;
                if(cantPorNivel==1)
                    cout<< " nodo";
                else
                    cout<< " nodos";
            }
            i++;
        } while (cantPorNivel != 0);
        cout << endl << endl;
    }
}
#endif //PROBARARBOL_H
