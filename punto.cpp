#include "punto.h"
#include <cmath>

Punto::Punto() : x(0.0), y(0.0) {}

Punto::Punto(double x, double y) : x(x), y(y) {}

double Punto::obtenerX() const {
    return x;
}

double Punto::obtenerY() const {
    return y;
}


void Punto::fijarX(double nuevoX) {
    x = nuevoX;
}

void Punto::fijarY(double nuevoY) {
    y = nuevoY;
}


double Punto::distanciaEuclidiana(const Punto& otro) const {
    double dx = otro.x - x;
    double dy = otro.y - y;

    return sqrt(dx*dx + dy*dy);
}


