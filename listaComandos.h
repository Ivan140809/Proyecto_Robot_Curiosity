#ifndef LISTA_COMANDOS_H
#define LISTA_COMANDOS_H

#include <list>
#include "comandoMovimiento.h"
#include "comandoAnalisis.h"
using namespace std;

enum TipoComando {
    Tipomovimiento,
    Tipoanalisis
};

// Funcion asistida con IA claude AI para poder tener un contenedor que aceptara los dos tipos de clases o TADs tanto los comandos de analisis como los de movimientos, estableciendo una estructura contenedora de los elementos y el uso del enum para las constantes, del tipo analisis y del tipo movimiento todo para conservar el orden que llegan los comandos
struct OrganizadorComandos {
    TipoComando       tipo;
    ComandoMovimiento movimiento;
    ComandoAnalisis   analisis;

    OrganizadorComandos(const ComandoMovimiento& mov)
        : tipo(Tipomovimiento), movimiento(mov) {}

    OrganizadorComandos(const ComandoAnalisis& anali)
        : tipo(Tipoanalisis), analisis(anali) {}
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
