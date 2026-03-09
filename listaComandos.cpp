#include "listaComandos.h"

void ListaComandos::agregarMovimiento(const ComandoMovimiento& mov) {
  comandos.push_back(NodoComando(mov));
}

void ListaComandos::agregarAnalisis(const ComandoAnalisis& anali) {
         comandos.push_back(NodoComando(anali));
}

const list<NodoComando>& ListaComandos::obtenerLista() const {
       return comandos;
}

