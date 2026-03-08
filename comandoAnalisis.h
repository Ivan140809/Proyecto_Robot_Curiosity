#ifndef COMANDO_ANALISIS_H
#define COMANDO_ANALISIS_H

#include <string>
using namespace std;

// TAD ComandoAnalisis: representa un comando fotografiar, composicion o perforar.
class ComandoAnalisis {
private:
    string tipo;       // fotografiar, composicion o perforar
    string objeto;     // elemento a analizar: roca, crater, monticulo, duna
    string comentario;

public:
    ComandoAnalisis();
    ComandoAnalisis(const string& tipo, const string& objeto, const string& comentario = "");

    string obtenerTipo()       const;
    string obtenerObjeto()     const;
    string obtenerComentario() const;

};

#endif
