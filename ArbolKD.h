#ifndef ARBOLKD_H
#define ARBOLKD_H

#include "NodoKD.h"
#include <list>
#include "ElementoInteres.h"
#include "listaElementos.h"
class ArbolKD {
private:
NodoKD* raiz;

public:
ArbolKD();
~ArbolKD();
bool estaVacio() const;
//manejar la insercion recursivamente
NodoKD* insertar(NodoKD* nodo, ElementoInteres elemento, int nivel);

void ubicarElementos(const ListaElementos& elementos);

void buscarEnCuadrante(NodoKD* Nodo, double xMin, double xMax, double yMin, double yMax, int nivel, std::list<ElementoInteres>& resultado);

std::list<ElementoInteres> enCuadrante(double xMin, double xMax, double yMin, double yMax);

};
#endif
