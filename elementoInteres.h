#ifndef ELEMENTO_INTERES_H
#define ELEMENTO_INTERES_H

#include <string>
#include "punto.h"
using namespace std;

// TAD ElementoInteres: representa un punto de interés del terreno marciano.
class ElementoInteres {
private:
string tipo;     // roca | crater | monticulo | duna
double tamano;   // valor real positivo
string unidad;   // cm | dm | m | km
Punto  posicion; // coordenadas (x, y) en el plano

public:
    // Constructores
    ElementoInteres();
    ElementoInteres(const string& tipo, double tamano, const string& unidad,
                    double coordX, double coordY);

    // Gets
    string obtenerTipo()     const;
    double obtenerTamano()   const;
    string obtenerUnidad()   const;
    Punto  obtenerPosicion() const;
    double tamanoEnMetros()  const;
bool estaEnCuadrante(double xMin, double xMax, double yMin, double yMax) const;

    // Sets
    void fijarTipo(const string& nuevoTipo);
    void fijarTamano(double nuevoTamano);
    void fijarUnidad(const string& nuevaUnidad);
    void fijarPosicion(double coordX, double coordY);
};

#endif
