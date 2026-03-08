#include "comandoMovimiento.h"
#include <cmath>

ComandoMovimiento::ComandoMovimiento() : tipo(""), magnitud(0.0), unidad("") {}

ComandoMovimiento::ComandoMovimiento(const string& tipo, double magnitud, const string& unidad)
    : tipo(tipo), magnitud(magnitud), unidad(unidad) {}

string ComandoMovimiento::obtenerTipo() const {
    return tipo;
}

double ComandoMovimiento::obtenerMagnitud() const {
    return magnitud;
}

string ComandoMovimiento::obtenerUnidad() const {
    return unidad;
}

// Convierte la magnitud a metros
double ComandoMovimiento::aMetros() const {
    if (unidad == "cm")  return magnitud * 0.01;
    if (unidad == "dm")  return magnitud * 0.1;
    if (unidad == "m")   return magnitud;
    if (unidad == "km")  return magnitud * 1000.0;
    return magnitud;
}

// Convierte la magnitud a radianes
double ComandoMovimiento::aRadianes() const {
    if (unidad == "grd"){
     return magnitud * 3.1416 / 180.0;
	}
    if (unidad == "rad") return magnitud;
    return magnitud; 
}
