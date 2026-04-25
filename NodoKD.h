#ifndef NODOKD_H
#define NODOKD_H

#include "elementoInteres.h"

class NodoKD {
private:
    ElementoInteres dato;
    NodoKD* hijoIzquierdo;
    NodoKD* hijoDerecho;
public:
    NodoKD();
    NodoKD(ElementoInteres elemento);
    ~NodoKD();
    ElementoInteres obtenerDato() const;
    NodoKD* obtenerHijoIzquierdo() const;
    NodoKD* obtenerHijoDerecho() const;
    void fijarHijoIzquierdo(NodoKD* nodo);
    void fijarHijoDerecho(NodoKD* nodo);
};

#endif
