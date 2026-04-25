
#ifndef VAL_PARAM_H
#define VAL_PARAM_H


#include <iostream>
#include <string>
using namespace std;

bool validarParametros(string comando, string params[], int cantidad);

bool validarCargar_comandos(string params[], int cantidad);

bool validarCargar_elementos(string params[], int cantidad);

bool validar_agregar_movimiento(string params[], int cantidad);

bool validar_agregar_analisis(string params[], int cantidad);

bool validar_agregar_elemento(string params[], int cantidad);

bool validar_guardar(string params[], int cantidad);

bool validar_simular(string params[], int cantidad);

bool validar_ubicar(string params[], int cantidad);

bool validar_cuadrante(string params[], int cantidad);

bool validar_crearMapa(string params[], int cantidad);

bool validar_ruta(string params[], int cantidad);

bool validar_ayuda(string params[], int cantidad);

bool validar_salir(string comando);

#endif
