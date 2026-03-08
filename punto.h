#ifndef PUNTO_H
#define PUNTO_H

// TAD Punto: representa una coordenada en el espacio 2D.

class Punto {
private:
    double x;
    double y;

public:
    // Constructor por defecto
    Punto();

    // Constructor con coordenadas
    Punto(double x, double y);

    // Gets
double obtenerX() const;
double obtenerY() const;
//sets
void fijarX(double nuevoX);
void fijarY(double nuevoY);    

    // Calcula la distancia euclidiana entre este punto y otro.
    double distanciaEuclidiana(const Punto& otro) const;
#endif
