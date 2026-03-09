#ifndef LISTA_COMANDOS_H
#define LISTA_COMANDOS_H

#include <list>
#include "comandoMovimiento.h"
#include "comandoAnalisis.h"
using namespace std;

enum TipoComando {
    TIPO_MOVIMIENTO,
    TIPO_ANALISIS
};

struct OrganizadorComandos {
    TipoComando       tipo;
    ComandoMovimiento movimiento;
    ComandoAnalisis   analisis;

    OrganizadorComandos(const ComandoMovimiento& mov)
        : tipo(TIPO_MOVIMIENTO), movimiento(mov) {}

    OrganizadorComandos(const ComandoAnalisis& anali)
        : tipo(TIPO_ANALISIS), analisis(anali) {}
};

class ListaComandos {
private:
    list<OrganizadorComandos> comandos;

public:
    void agregarMovimiento(const ComandoMovimiento& mov);
    void agregarAnalisis(const ComandoAnalisis& anal);
    const list<OrganizadorComandos>& obtenerLista() const;
};

#endif
