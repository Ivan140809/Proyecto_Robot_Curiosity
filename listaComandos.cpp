#include "listaComandos.h"

void ListaComandos::agregarMovimiento(const ComandoMovimiento& mov) {
  comandos.push_back(NodoComando(mov));
}

void ListaComandos::agregarAnalisis(const ComandoAnalisis& anal) {
         comandos.push_back(NodoComando(anal));
}

const list<NodoComando>& ListaComandos::obtenerLista() const {
       return comandos;
}

