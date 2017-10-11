#include <iostream>
#include "../ArbolBinario/ArbolBinario.h"
void ProbarArbol(ArbolBinario<int> *arbol, int cant, int min, int max, bool imprimir) {
    if (cant < 0 || min > max || cant > 1 + max - min) throw 1;
    int i=0;
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
        cout << endl << "Arbol en preorden: " << endl << "   ";
        arbol->preorder();
        cout << endl << "Arbol en inorden: " << endl << "   ";
        arbol->inorder();
        cout << endl << "Arbol en postorden: " << endl << "   ";
        arbol->postorder();
        cout << endl << endl;
    }
}

int main() {
    system("clear");
    char n;
    ArbolBinario<int> arbol;
    char x;
    try {
        ProbarArbol(&arbol, 30, 100, 500, true);
    } catch (int e) {}
    cin>>n;
    main();
}
