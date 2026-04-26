#include "comandos.h"
#include "ayuda.h"
#include "valParam.h"
#include "SistemaRobot.h"
#include "ArbolKD.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>

using namespace std;

extern ArbolKD arbolKD;
extern ListaElementos listaElementos;

bool comandoexacto(string& linea, const char* entrada) {
    if(linea == string(entrada)) {
        return true;
    }
    return false;
}

bool procesador_linea(string& linea) {

    //funcion salir
    if(comandoexacto(linea, "salir")) {
        return true;
    }

    //funcion ayuda
    if(comandoexacto(linea, "ayuda")) {
        ayuda_print_general();
        return false;
    }

    //funcion ayuda comando
    if (linea.rfind("ayuda ", 0) == 0) {
        istringstream iss(linea);
        string entrada, argum, extra;
        iss >> entrada >> argum >> extra;

        if (entrada != "ayuda" || argum.empty() || !extra.empty()) {
            cout << "Formato invalido usa ayuda o ayuda comando" << endl;
            return false;
        }

        string params[10];
        params[0] = argum;
        if (!validarParametros("ayuda", params, 1)) {
            return false;
        }
        ayuda_print_comando_especifico(argum);
        return false;
    }

    //funcion cargar_comandos
    if (linea.rfind("cargar_comandos ", 0) == 0) {
        istringstream iss(linea);
        string entrada, archivo, extra;
        iss >> entrada >> archivo >> extra;

        string params[10];
        int cantidad = 0;

        if (!archivo.empty()) params[cantidad++] = archivo;
        if (!validarParametros("cargar_comandos", params, cantidad) || entrada != "cargar_comandos" || !extra.empty()) {
            cout << "Comando invalido" << endl;
            return false;
        }
        cargar_comandos(archivo);
        return false;
    }

    //funcion cargar elementos
    if (linea.rfind("cargar_elementos ", 0) == 0) {
        istringstream iss(linea);
        string entrada, archivo, extra;
        iss >> entrada >> archivo >> extra;

        string params[10];
        int cantidad = 0;
        if (!archivo.empty()) params[cantidad++] = archivo;

        if (!validarParametros("cargar_elementos", params, cantidad) || entrada != "cargar_elementos" || !extra.empty()) {
            cout << "Comando invalido" << endl;
            return false;
        }
        cargar_elementos(archivo);
        return false;
    }

    //funcion agregar_movimiento
    if (linea.rfind("agregar_movimiento", 0) == 0) {
        istringstream iss(linea);
        string entrada, tipo, magn, unidad, extra;
        iss >> entrada >> tipo >> magn >> unidad >> extra;

        string params[10];
        int cantidad = 0;
        if (!tipo.empty())  params[cantidad++] = tipo;
        if (!magn.empty())  params[cantidad++] = magn;
        if (!unidad.empty()) params[cantidad++] = unidad;

        if (entrada != "agregar_movimiento" || !extra.empty() || !validarParametros("agregar_movimiento", params, cantidad)) {
            return false;
        }
        double magnitud = strtod(magn.c_str(), nullptr);
        agregar_movimiento(tipo, magnitud, unidad);
        return false;
    }

    //funcion agregar_analisis
    if (linea.rfind("agregar_analisis", 0) == 0) {
        istringstream iss(linea);
        string entrada, tipo, obj, comentario, extra;
        iss >> entrada >> tipo >> obj;
        iss >> comentario;
        iss >> extra;

        string params[10];
        int cantidad = 0;
        if (!tipo.empty()) params[cantidad++] = tipo;
        if (!obj.empty())  params[cantidad++] = obj;
        if (!comentario.empty()) params[cantidad++] = comentario;
        if (entrada != "agregar_analisis" || !extra.empty() || !validarParametros("agregar_analisis", params, cantidad)) {
            return false;
        }
        agregar_analisis(tipo, obj, comentario);
        return false;
    }

    //funcion agregar_elemento
    if (linea.rfind("agregar_elemento", 0) == 0) {
        istringstream iss(linea);
        string entrada, tipo, tam, unidad, x, y, extra;
        iss >> entrada >> tipo >> tam >> unidad >> x >> y >> extra;

        string params[10];
        int cantidad = 0;
        if (!tipo.empty())  params[cantidad++] = tipo;
        if (!tam.empty())   params[cantidad++] = tam;
        if (!unidad.empty()) params[cantidad++] = unidad;
        if (!x.empty())     params[cantidad++] = x;
        if (!y.empty())     params[cantidad++] = y;

        if (entrada != "agregar_elemento" || !extra.empty() || !validarParametros("agregar_elemento", params, cantidad)) {
            return false;
        }
        double tamD = strtod(tam.c_str(), nullptr);
        double xD   = strtod(x.c_str(),   nullptr);
        double yD   = strtod(y.c_str(),   nullptr);
        agregar_elemento(tipo, tamD, unidad, xD, yD);
        return false;
    }

    //funcion en_cuadrante
    if (linea.rfind("en_cuadrante", 0) == 0) {
        istringstream iss(linea);
        string entrada, x1, x2, y1, y2, extra;
        iss >> entrada >> x1 >> x2 >> y1 >> y2 >> extra;

        string params[10];
        int cantidad = 0;
        if (!x1.empty()) params[cantidad++] = x1;
        if (!x2.empty()) params[cantidad++] = x2;
        if (!y1.empty()) params[cantidad++] = y1;
        if (!y2.empty()) params[cantidad++] = y2;

        if (entrada != "en_cuadrante" || !extra.empty() || !validarParametros("en_cuadrante", params, cantidad)) {
            return false;
        }
        double coordX1 = strtod(x1.c_str(), nullptr);
        double coordX2 = strtod(x2.c_str(), nullptr);
        double coordY1 = strtod(y1.c_str(), nullptr);
        double coordY2 = strtod(y2.c_str(), nullptr);
         en_cuadrante(coordX1, coordX2, coordY1, coordY2);
        return false;
    }

    //funcion ubicar_elementos
    if (comandoexacto(linea, "ubicar_elementos")) {
        string params[10];
        if (!validarParametros("ubicar_elementos", params, 0)) {
            return false;
        }
        ubicar_elementos();
        return false;
    }

    //funcion crear_mapa
    if (linea.rfind("crear_mapa", 0) == 0) {
        istringstream iss(linea);
        string entrada, coeficiente, extra;
        iss >> entrada >> coeficiente >> extra;

        string params[10];
        int cantidad = 0;
        if (!coeficiente.empty()) params[cantidad++] = coeficiente;

        if (entrada != "crear_mapa" || !extra.empty() || !validarParametros("crear_mapa", params, cantidad)) {
            return false;
        }
        cout << "Comando valido, Funcion proximamente a implementarse" << endl;
        return false;
    }

    //funcion ruta_mas_larga
    if (comandoexacto(linea, "ruta_mas_larga")) {
        string params[10];
        if (!validarParametros("ruta_mas_larga", params, 0)) {
            return false;
        }
        cout << "Comando valido, Funcion proximamente a implementarse" << endl;
        return false;
    }

    //funcion guardar
    if (linea.rfind("guardar", 0) == 0) {
        istringstream iss(linea);
        string entrada, tipo, archivo, extra;
        iss >> entrada >> tipo >> archivo >> extra;

        string params[10];
        int cantidad = 0;
        if (!tipo.empty()) params[cantidad++] = tipo;
        if (!archivo.empty()) params[cantidad++] = archivo;

        if (entrada != "guardar" || !extra.empty() || !validarParametros("guardar", params, cantidad)) {
            return false;
        }
        guardar(tipo, archivo);
        return false;
    }

    //funcion simular_comandos
    if (linea.rfind("simular_comandos", 0) == 0) {
        istringstream iss(linea);
        string entrada, x, y, extra;
        iss >> entrada >> x >> y >> extra;

        string params[10];
        int cantidad = 0;
        if (!x.empty()) params[cantidad++] = x;
        if (!y.empty()) params[cantidad++] = y;

        if (entrada != "simular_comandos" || !extra.empty() || !validarParametros("simular_comandos", params, cantidad)) {
            return false;
        }
        double xD = strtod(x.c_str(), nullptr);
        double yD = strtod(y.c_str(), nullptr);
        simular_comandos(xD, yD);
        return false;
    }

    //comando desconocido
    cout << "Comando desconocido escribe 'ayuda' para ver la lista de comandos." << endl;
    return false;
}
