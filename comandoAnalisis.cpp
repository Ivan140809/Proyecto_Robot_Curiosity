#include "comandoAnalisis.h"

ComandoAnalisis::ComandoAnalisis() : tipo(""), objeto(""), comentario("") {}

ComandoAnalisis::ComandoAnalisis(const string& tipo, const string& objeto, const string& comentario)
    : tipo(tipo), objeto(objeto), comentario(comentario) {}

string ComandoAnalisis::obtenerTipo() const {
    return tipo;
}

string ComandoAnalisis::obtenerObjeto() const {
    return objeto;
}

string ComandoAnalisis::obtenerComentario() const {
    return comentario;
}


