#ifndef Comandos_E1_H
#define Comandos_E1_H

#include <string>
#include "listaComandos.h"
#include "listaElementos.h"
using namespace std;

//correspondiente al TAD sistema de la entrega 1.

//comando cargar_comandos nombre_archivo
void cargar_comandos(const string& nombreArchivo);

//cargar_elementos nombre_archivo
void cargar_elementos(const string& nombreArchivo);

//agregar_movimiento tipo magnitud unidad
void agregar_movimiento(const string& tipo, double magnitud, const string& unidad);

// agregar_analisis tipo objeto comentario
void agregar_analisis(const string& tipo, const string& objeto, const string& comentario);

// agregar_elemento tipo tamano unidad coordX coordY
void agregar_elemento(const string& tipo, double tamano, const string& unidad,
                         double coordX, double coordY);

// guardar tipo(comandos||elementos) nombre_archivo
void guardar(const string& tipoArchivo, const string& nombreArchivo);

// simular_comandos coordX coordY
void simular_comandos(double coordX, double coordY);


//correspondiente al TAD sistema de la entrega 2.

//ubicar_elementos
void ubicar_elementos();

//en_cuadrante coordx1, coordX2, coordY1, coordY2
void en_cuadrante(double coordX1, double coordX2, double coordY1, double coordY2);

#endif



