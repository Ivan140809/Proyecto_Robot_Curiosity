#include "app.h"
#include "comandos.h"
#include <iostream>
#include <string>

using namespace std;

void correr_app(){

string linea;

    cout << "   Bienvenido al sistema del robot Curiosity!!!!!"<<endl;
    cout <<" Interactua con la linea de comandos para mostrar sus elementos"<<endl;
    cout<<endl;
    cout << "Escribe 'ayuda' para ver todos los comandos."<<endl;
    cout << "Escribe 'ayuda comando' para ver el uso de un comando."<<endl<<endl;

 while (true) {
 cout<< "$  "; // personalizacion segun linea de comandos del SO

 if (!getline(cin, linea)) { // validacion del comando principal si el usuario escribe algo raro
	 break;
   }

 if (linea.empty()) { // si la linea esta vacia se avanza, si el usuario da enter sobre todo
    continue;
   }

 if(procesador_linea(linea)) { // Procesa la linea retorna true si el usuario pidió salir
   break;
   }

  }
}
