#ifndef COMANDO_MOVIMIENTO_H
#define COMANDO_MOVIMIENTO_H

#include <string>
using namespace std;

// TAD ComandoMovimiento: representa un comando avanzar o girar con su magnitud y unidad.
class ComandoMovimiento {
private:
 string tipo;
 double magnitud;
 string unidad;  

public:
 ComandoMovimiento();
 ComandoMovimiento(const string& tipo, double magnitud, const string& unidad);

 string obtenerTipo()     const;
    double obtenerMagnitud() const;
    string obtenerUnidad()   const;


    double aMetros() const;
    double aRadianes() const;
};

#endif
