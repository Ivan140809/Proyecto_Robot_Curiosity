#include "ArbolKD.h"
#include <sstream>
#include <iostream>

ArbolKD::ArbolKD() {
   this->raiz = nullptr;
}

ArbolKD::~ArbolKD() {
while(this ->raiz != nullptr) {
  delete this -> raiz;
  this->raiz= nullptr;
  }
}

bool ArbolKD::estaVacio() const {
  return this -> raiz== nullptr;
}

NodoKD*ArbolKD::insertar(NodoKD* nodo, ElementoInteres elemento, int nivel) {

if(nodo==nullptr) {
 NodoKD* nuevo = new NodoKD(elemento);
 return nuevo;
}

double xN = elemento.obtenerPosicion().obtenerX();
double yN = elemento.obtenerPosicion().obtenerY();

double xA = nodo->obtenerDato().obtenerPosicion().obtenerX();
double yA = nodo->obtenerDato().obtenerPosicion().obtenerY();

if(nivel % 2==0) {
  if(xN < xA) {
NodoKD* izq = insertar(nodo->obtenerHijoIzquierdo(), elemento, nivel + 1);
nodo-> fijarHijoIzquierdo(izq);
 } else {
  NodoKD* der= insertar(nodo->obtenerHijoDerecho(), elemento, nivel + 1);
  nodo -> fijarHijoDerecho(der);
 }
} else {
  if(yN < yA) {
 NodoKD* izq = insertar(nodo->obtenerHijoIzquierdo(), elemento, nivel + 1);
 nodo->fijarHijoIzquierdo(izq);
} else {
 NodoKD* der= insertar(nodo->obtenerHijoDerecho(), elemento, nivel + 1);
 nodo -> fijarHijoDerecho(der);
     }
  }
  return nodo;
}

void ArbolKD::ubicarElementos(const ListaElementos& elementos) {
const list<ElementoInteres>& listaRef = elementos.obtenerLista();
    int i = 0;
    list<ElementoInteres>::const_iterator it;
    for (it = listaRef.begin(); it != listaRef.end(); ++it) {
        raiz = insertar(raiz, *it, 0);
        i++;
    }
    std::cout << i << " Elementos fueron cargados exitosamente" << std::endl;
}

void ArbolKD::buscarEnCuadrante(NodoKD* nodo, double xMin,double xMax,double yMin, double yMax, int nivel,std::list<ElementoInteres>& resultado) {
 if(nodo == nullptr) {
  return;
}

ElementoInteres actual= nodo-> obtenerDato();
if(actual.estaEnCuadrante(xMin,xMax,yMin,yMax)){
  resultado.push_back(actual);
}

double xA= actual.obtenerPosicion().obtenerX();
double yA= actual.obtenerPosicion().obtenerY();

if(nivel % 2==0) {
   if(xMin < xA) {
   buscarEnCuadrante(nodo -> obtenerHijoIzquierdo(),xMin,xMax,yMin,yMax, nivel +1, resultado);
   }
   if (xMax > xA) {
    buscarEnCuadrante(nodo->obtenerHijoDerecho(),xMin, xMax, yMin, yMax, nivel + 1, resultado);
  }
   } else {
   if( yMin < yA) {
   buscarEnCuadrante(nodo -> obtenerHijoIzquierdo(),xMin,xMax,yMin,yMax, nivel +1, resultado);
  }
 if (yMax > yA){
   buscarEnCuadrante(nodo->obtenerHijoDerecho(),xMin, xMax, yMin, yMax, nivel + 1, resultado);
    }
  }
}

std::list<ElementoInteres> ArbolKD::enCuadrante(double xMin, double xMax, double yMin, double yMax) {
    std::list<ElementoInteres> resultado;
    if (!estaVacio()) {
        buscarEnCuadrante(this->raiz, xMin, xMax, yMin, yMax, 0, resultado);
    }
    return resultado;
}
