#include <iostream>
#include "../ArbolBinario/ArbolBinario.h"
void ProbarArbol(ArbolBinario<int> *arbol, int cont, int min, int max);
int main() {
    ArbolBinario<int> arbol;
    ProbarArbol(&arbol,3000,0,100);
    return 0;
}

void ProbarArbol(ArbolBinario<int> *arbol, int cont, int min, int max) {
    srand(time(NULL));
    while (cont != 0) {
        try {
            arbol->put(rand() % max + min);
            cont--;
        } catch (int e) {}
    }
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