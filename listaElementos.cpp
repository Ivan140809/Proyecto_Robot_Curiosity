#include "listaElementos.h"

void ListaElementos::agregar(const ElementoInteres& e) {
    elementos.push_back(e);
}

const list<ElementoInteres>& ListaElementos::obtenerLista() const {
    return elementos;
}
