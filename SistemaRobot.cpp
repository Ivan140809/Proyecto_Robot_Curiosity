#include "SistemaRobot.h"
#include "ArbolKD.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
ListaElementos listaElementos;
ArbolKD arbolKD;
static ListaComandos  listaComandos;
void cargar_comandos(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << nombreArchivo << " no se encuentra o no puede leerse." << endl;
return;
    }

    listaComandos = ListaComandos();

  string linea;
    int cargados = 0;
     while (getline(archivo, linea)) {
     istringstream palabra(linea);

        string token;

        palabra >> token;
  if (token == "avanzar" || token == "girar") {
            string magnStr, unidad;

          palabra >> magnStr >> unidad;

            double magnitud = strtod(magnStr.c_str(), nullptr);

            listaComandos.agregarMovimiento(ComandoMovimiento(token, magnitud, unidad));

            cargados++;
	} else if(token == "fotografiar" || token == "composicion" || token == "perforar") {
	// esta parte del codigo fue asistida por CLAUDE AI para lograr quitar las comillas del comentario y los espacios iniciales
	 string objeto, comentario;
            palabra >> objeto;
            getline(palabra, comentario);
	  size_t ini = comentario.find_first_not_of(" \t");
             comentario = (ini == string::npos) ? "" : comentario.substr(ini); 
	 if (comentario.size() >= 2 && comentario.front() == '\'' && comentario.back() == '\'')
                comentario = comentario.substr(1, comentario.size() - 2);
	 // fin de la parte asistida
            listaComandos.agregarAnalisis(ComandoAnalisis(token, objeto, comentario));
	  cargados++;
  }
    }
    archivo.close();
 if (cargados == 0) {
        cout << "Archivo vacio " << nombreArchivo
             << " no contiene comandos." << endl;
    } else {
        cout << "Resultado exitoso " << cargados
             << " comandos cargados correctamente desde "
             << nombreArchivo << endl;
    }
}

void agregar_movimiento(const string& tipo, double magnitud, const string& unidad) {
    listaComandos.agregarMovimiento(ComandoMovimiento(tipo, magnitud, unidad));
    cout << "El comando de movimiento ha sido agregado exitosamente." << endl;
}

void agregar_analisis(const string& tipo, const string& objeto, const string& comentario) {
    string com = comentario;
	//Funcion derivada de asistencia con IA especificamente de la asistencia de Claude AI
    if (com.size() >= 2 && com.front() == '\'' && com.back() == '\'')
        com = com.substr(1, com.size() - 2);
	//Fin de asistencia
    listaComandos.agregarAnalisis(ComandoAnalisis(tipo, objeto, com));
    cout << "El comando de analisis ha sido agregado exitosamente." << endl;
}

void cargar_elementos(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error con el archivo" << endl;
        return;
    }

    listaElementos = ListaElementos();

    string linea;
    int cargados = 0;

    while (getline(archivo, linea)) {
        istringstream palabra(linea);

        string tipo, tamStr, unidad, xStr, yStr, extra;
        palabra >> tipo >> tamStr >> unidad >> xStr >> yStr >> extra;

        if (tipo.empty() || tamStr.empty() || unidad.empty() || xStr.empty() || yStr.empty() || !extra.empty()) {
            continue;
        }

        bool tipoValido = (tipo == "roca" || tipo == "crater" || tipo == "monticulo" || tipo == "duna");
        bool unidadValida = (unidad == "cm" || unidad == "dm" || unidad == "m" || unidad == "km");

        if (!tipoValido || !unidadValida) {
            continue;
        }

        double tam = strtod(tamStr.c_str(), nullptr);
        double x = strtod(xStr.c_str(), nullptr);
        double y = strtod(yStr.c_str(), nullptr);

        listaElementos.agregar(ElementoInteres(tipo, tam, unidad, x, y));
        cargados++;
    }

    archivo.close();

    if (cargados == 0) {
        cout << "El archivo " << nombreArchivo << " no contiene elementos." << endl;
    } else {
        cout << cargados << " elementos cargados correctamente desde " << nombreArchivo << endl;
    }
}
void agregar_elemento(const string& tipo, double tamano, const string& unidad,
                          double coordX, double coordY) {
    listaElementos.agregar(ElementoInteres(tipo, tamano, unidad, coordX, coordY));
    cout << "El elemento ha sido agregado exitosamente." << endl;
}

void guardar(const string& tipoArchivo, const string& nombreArchivo) {

    if (tipoArchivo == "comandos") {
        if (listaComandos.obtenerLista().empty()) {
            cout << "La informacion requerida no esta almacenada en memoria." << endl;
        }

 	ofstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cout << "Error guardando en " << nombreArchivo << endl;
        	}
	list<OrganizadorComandos>::const_iterator it;
	for (it = listaComandos.obtenerLista().begin(); it != listaComandos.obtenerLista().end(); ++it) {
            if (it->tipo == Tipomovimiento) {
                archivo << it->movimiento.obtenerTipo()     << " "
                        << it->movimiento.obtenerMagnitud() << " "
                        << it->movimiento.obtenerUnidad()   << endl;
 	    } else {
                archivo << it->analisis.obtenerTipo() << " " << it->analisis.obtenerObjeto();
                if (!it->analisis.obtenerComentario().empty())
                    archivo << it->analisis.obtenerComentario();
                archivo << endl;
            }
        }
        archivo.close();
	cout << "La informacion ha sido guardada en"<< nombreArchivo << endl;
   } else if (tipoArchivo == "elementos") {
        if (listaElementos.obtenerLista().empty()) {
            cout << "La informacion requerida no esta almacenada en memoria." << endl;
        }
	ofstream archivo(nombreArchivo);
	if(!archivo.is_open()){
	 cout<<"error con el archivo de escritura"<<endl;
	}
	list<ElementoInteres>::const_iterator itElem;
	  for (itElem = listaElementos.obtenerLista().begin(); itElem != listaElementos.obtenerLista().end(); ++itElem) {
            Punto pos = itElem->obtenerPosicion();
            archivo << itElem->obtenerTipo() << itElem->obtenerTamano()<< itElem->obtenerUnidad()<< pos.obtenerX() << pos.obtenerY()<< endl;
        }
 	archivo.close();
        cout << "La informacion ha sido guardada en " << nombreArchivo << endl;
    }
}

void simular_comandos(double coordX, double coordY) {
    if (listaComandos.obtenerLista().empty()) {
        cout <<" La informacion requerida no esta almacenada en memoria." << endl;
    }

double x= coordX;
    double y= coordY;
    double angulo = 0.0;
list<OrganizadorComandos>::const_iterator itS;
for (itS = listaComandos.obtenerLista().begin(); itS != listaComandos.obtenerLista().end(); ++itS) {
        if (itS->tipo == Tipomovimiento) {
if (itS->movimiento.obtenerTipo() == "avanzar") {
                x += itS->movimiento.aMetros() * cos(angulo);
                y += itS->movimiento.aMetros() * sin(angulo);
            } else {
                angulo += itS->movimiento.aRadianes();
            }
 	} else if (itS->tipo == Tipoanalisis) {
     	
    }
}
 cout << "La simulacion de los comandos, a partir de la posicion ("
         << coordX << "," << coordY << "), deja al robot en la nueva posicion ("
         << x << "," << y << ")" << endl;
}
void ubicar_elementos() {
 if (listaElementos.obtenerLista().empty()) {
        cout << " La información requerida no está almacenada en memoria." << endl;
     return;
    }
    arbolKD.ubicarElementos(listaElementos);
}

void en_cuadrante(double coordX1, double coordX2, double coordY1, double coordY2) {
    if (arbolKD.estaVacio()) {
        cout << "No hay informacion, Los elementos no han sido ubicados todavía con el comando ubicar_elementos." << endl;
        return;
    }

    list<ElementoInteres> encontrados;
    encontrados = arbolKD.enCuadrante(coordX1, coordX2, coordY1, coordY2);

    cout << " Los elementos ubicados en el cuadrante solicitado son:" << endl;
    list<ElementoInteres>::iterator it;
    for (it = encontrados.begin(); it != encontrados.end(); ++it) {
    Punto pos = it->obtenerPosicion();
    cout << it->obtenerTipo() << " " << it->obtenerTamano() << " " << it->obtenerUnidad() << " " << pos.obtenerX() << " " << pos.obtenerY() << endl;
 }
}

