#ifndef LISTA_ELEMENTOS_H
#define LISTA_ELEMENTOS_H

#include <list>
#include "elementoInteres.h"
using namespace std;

class ListaElementos {
private:
    list<ElementoInteres> elementos;

public:
    void agregar(const ElementoInteres& elemento);
    const list<ElementoInteres>& obtenerLista() const;
};

#endif
