#include "listaComandos.h"

void ListaComandos::agregarMovimiento(const ComandoMovimiento& mov) {
  comandos.push_back(OrganizadorComandos(mov));
}

void ListaComandos::agregarAnalisis(const ComandoAnalisis& anali) {
         comandos.push_back(OrganizadorComandos(anali));
}

const list<OrganizadorComandos>& ListaComandos::obtenerLista() const {
       return comandos;
}

