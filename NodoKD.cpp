#include "NodoKD.h"
NodoKD::NodoKD() {
    this->hijoIzquierdo = nullptr;
    this->hijoDerecho = nullptr;
}

NodoKD::NodoKD(ElementoInteres elemento) {
    this->dato = elemento;
    this->hijoIzquierdo = nullptr;
    this->hijoDerecho = nullptr;
}

NodoKD::~NodoKD() {
    delete this->hijoIzquierdo;
    delete this->hijoDerecho;

    this->hijoIzquierdo = nullptr;
    this->hijoDerecho = nullptr;
}

ElementoInteres NodoKD::obtenerDato() const {
   return this-> dato;
}

NodoKD* NodoKD::obtenerHijoIzquierdo() const {
    return this-> hijoIzquierdo;
}

NodoKD* NodoKD::obtenerHijoDerecho() const {
    return this->hijoDerecho;
}

void NodoKD::fijarHijoIzquierdo(NodoKD* nodo) {
    this->hijoIzquierdo = nodo;
}

void NodoKD::fijarHijoDerecho(NodoKD* nodo) {
    this->hijoDerecho = nodo;
}
