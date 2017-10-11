#include <iostream>
#include "../ArbolBinario/ArbolBinario.h"
void ProbarArbol(ArbolBinario<int> *arbol, int cont, int min, int max, bool imprimir);
int main() {
    ArbolBinario<int> arbol;
    try {
        ProbarArbol(&arbol, 30, 100, 500, true);
    }catch (int e) {}
    return 0;
}

void ProbarArbol(ArbolBinario<int> *arbol, int cont, int min, int max, bool imprimir) {
    if(cont<0||min>max) throw 1;
    srand(time(NULL));
    while (cont != 0) {
        try {
            arbol->put(rand() % max + min);
            cont--;
        } catch (int e) {}
    }
    if(imprimir) {
        cout << endl << "Arbol de " << cont << " hojas, con valores desde " << min << " hasta " << max << ":" << endl;
        arbol->print();
        cout << endl << "Arbol en preorden: " << endl << "   ";
        arbol->preorder();
        cout << endl << "Arbol en inorden: " << endl << "   ";
        arbol->inorder();
        cout << endl << "Arbol en postorden: " << endl << "   ";
        arbol->postorder();
        cout << endl;
    }
}