#include "elementoInteres.h"
//constructor vacio
ElementoInteres::ElementoInteres()
    : tipo(""), tamano(0.0), unidad(""), posicion(Punto(0.0, 0.0)) {}
//constructor de elemento
ElementoInteres::ElementoInteres(const string& tipo, double tamano, const string& unidad,
                                 double coordX, double coordY)
    : tipo(tipo), tamano(tamano), unidad(unidad), posicion(Punto(coordX, coordY)) {}

//gets
string ElementoInteres::obtenerTipo() const {
    return tipo;
}

double ElementoInteres::obtenerTamano() const {
    return tamano;
}

string ElementoInteres::obtenerUnidad() const {
    return unidad;
}

Punto ElementoInteres::obtenerPosicion() const {
    return posicion;
}

double ElementoInteres::tamanoEnMetros() const {
    if (unidad == "cm") return tamano * 0.01;
    if (unidad == "dm")  return tamano * 0.1;
    if (unidad == "m")  return tamano;
    if (unidad == "km")  return tamano * 1000.0;
    return tamano;
}

bool ElementoInteres::estaEnCuadrante(double xMin, double xMax, double yMin, double yMax) const {
    double x = this->posicion.obtenerX();
    double y = this->posicion.obtenerY();
    return x >= xMin && x <= xMax && y >= yMin && y <= yMax;
}


//sets
void ElementoInteres::fijarTipo(const string& nuevoTipo) {
    tipo = nuevoTipo;
}

void ElementoInteres::fijarTamano(double nuevoTamano) {
    tamano = nuevoTamano;
}

void ElementoInteres::fijarUnidad(const string& nuevaUnidad) {
    unidad = nuevaUnidad;
}

void ElementoInteres::fijarPosicion(double coordX, double coordY) {
    posicion = Punto(coordX, coordY);
}
