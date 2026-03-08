#include "ayuda.h"
#include <iostream>

using namespace std;

void ayuda_print_general(){

cout << "Comandos disponibles: "<<endl;
cout <<endl;

cout << " ayuda" <<endl;
cout << "Descripción: " <<endl;
cout << endl;
cout << "Muestra todos los comandos disponibles para la terminal, con una descripción de su uso" <<endl;
cout << endl;
cout <<endl;

cout << " ayuda comando" <<endl;
cout <<"Descripción: "<<endl;
cout << endl; 
cout << " Muestra la forma de ejecutar cada comando con su forma de ejecutarlo y parametros"<<endl;
cout << endl;
cout << endl;

cout << " cargar_comandos" <<endl;
cout << "Descripción: " <<endl;
cout << endl;
cout << " Carga en memoria los comandos de desplazamiento contenidos el archivo identificado por archivo cargar_comandos"<<endl;  
cout << " es decir, utiliza adecuadamente las estructuras lineales para cargar la información de los comandos en memoria."<<endl;
cout << " Si dentro de la misma sesión de trabajo ya se han cargado otros archivos de comandos (usando el comando cargar_comandos)," <<endl;
cout << " la información debe sobreescribirse en memoria,es decir, no se deben combinar informaciones de comandos de diferentes archivos."<<endl;
cout << endl;
cout << endl;

cout << " cargar_elementos" <<endl;
cout << "Descripción: "<<endl;
cout<< endl;
cout << "Carga en memoria los datos de puntos de interés o elementos contenidos en el archivo identificado por nombre_archivo"<<endl; 
cout << "es decir, utiliza adecuadamente las estructuras lineales para cargar la información de los elementos en memoria." <<endl;
cout << "Si dentro de la misma sesión de trabajo ya se han cargado otros archivos de puntos de interés (usando el comando cargar_elementos) "<<endl; 
cout << "la información debe sobreescribirse en memoria, es decir, no se deben combinar informaciones de elementos de diferentes archivos."<<endl;
cout<<  endl;
cout << endl;

cout << " agregar_movimiento" <<endl;
cout << "Descripción: "<<endl;
cout << endl;
cout << "Agrega el comando de movimiento descrito a la lista de comandos del robot “Curiosity”. El movimiento puede ser de dos tipos: avanzar o girar. " <<endl;
cout << "La magnitud corresponde al valor del movimiento; si es avanzar, el número de unidades que se espera avanzar, si es girar la cantidad de grados que debe girar."<<endl;
cout << "La unidad de medida corresponde a la convención con la que se mide la magnitud del movimiento, de acuerdo a la tabla presentada anteriormente."<<endl;
cout << "Si no se envía la información completa y adecuada del comando de movimiento, éste no puede agregarse a la lista de los comandos que se enviarán al robot desde la tierra" <<endl;
cout << endl;
cout << endl;

cout << " agregar_analisis" <<endl;
cout << "Descripción: " <<endl;
cout << endl;
cout << "Agrega el comando de análisis descrito a la lista de comandos del robot “Curiosity”. El análisis puede ser de tres tipos: fotografiar, composicion o perforar. "<<endl;
cout << "El objeto es el nombre del elemento que se quiere analizar (roca, arena, monticulo, ...). El comentario es opcional y permite agregar más información sobre el elemento o el análisis,"<<endl;
cout << "este comentario estará encerrado entre comillas simples (ejemplo: ’roca_cuadrante_32’). Si no se envía la información completa y adecuada del comando de análisis,"<<endl;
cout << "Este no puede agregarse a la lista de los comandos que se enviarán al robot desde la tierra."<<endl;
cout << endl;
cout << endl;

cout << " agregar_elemento" <<endl;
cout << "Descripción: "<<endl;
cout << endl;
cout << "Agrega el componente o elemento descrito a la lista de puntos de interés del robot “Curiosity”. El tipo de componente puede ser uno entre roca, crater, monticulo o duna."<<endl; 
cout << "El tamaño es un valor real que da cuenta de qué tan grande es el elemento; y la unidad de medida complementa este valor con la convención que se usó para su medición, de acuerdo a la tabla presentada anteriormente."<<endl;
cout << "Finalmente, las coordenadas x y y corresponden a números reales que permiten conocer la ubicación del elemento en el sistema de coordenadas del suelo marciano utilizado por el vehículo."<<endl; 
cout << "Si no se envía la información completa y adecuada del elemento, éste no puede agregarse a la lista de puntos de interés que se enviarán al robot desde la tierra."<<endl;
cout <<endl;
cout <<endl;

cout << " guardar" <<endl; 
cout << "Descripción: "<<endl;
cout << endl;
cout << "Guarda en el archivo nombre_archivo la información solicitada de acuerdo al tipo de archivo: comandos almacena en el archivo la información de comandos de movimiento y de análisis que debe ejecutar el robot"<<endl; 
cout << "elementos almacena en el archivo la información de los componentes o puntos de interés conocidos en el suelo marciano."<<endl;
cout << endl;
cout << endl;

cout << " simular_comandos" <<endl;
cout << "Descripción:" << endl;
cout << endl;
cout << "Permite simular el resultado de los comandos de movimiento que se enviarán al robot “Curiosity” desde la Tierra, facilitando asi la validación de la nueva posición en la que podría ubicarse" <<endl; 
cout << "Para ejecutarse adecuadamente, requiere conocer la posición actual (coordenadas x y y) del vehículo.a partir de la posición actual," <<endl;
cout << "se asume que el “Curiosity” está orientado mirando hacia la parte derecha del eje x en un sistema cartesiano (hacia la derecha)." << endl;
cout << "Los ángulos de giro positivos generan movimiento en el sentido contrario de las manecillas del reloj, mientras que los ángulos de giro negativos generan movimiento en el sentido de las manecillas del reloj."<<endl; 
cout << "Hay que tener en cuenta que sólo los comandos de movimiento son necesarios, no los de análisis."<<endl;
cout <<endl;
cout <<endl;

cout << " ubicar_elementos" <<endl;
cout <<"Descripción: "<<endl;
cout <<endl;
cout << "El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura de datos jerárquica adecuada" <<endl; 
cout << "que permita luego realizar consultas geográficas sobre estos elementos. Si alguno de los elementos no puede agregarse adecuadamente, debe generarse un mensaje de error"<<endl; 
cout << "pero deben procesarse todos los elementos almacenados en memoria."<<endl;
cout <<endl;
cout <<endl;

cout << " en_cuadrante" <<endl;
cout <<"Descripcion: "<<endl;
cout << endl;
cout << "Permite utilizar la estructura creada con el comando anterior para retornar una lista de los componentes o elementos que están dentro del cuadrante geográfico descrito por los límites de coordenadas en x y y."<< endl;
cout << "Es necesario haber ejecutado el comando ubicar_elementos para poder realizar la búsqueda por cuadrantes." <<endl;
cout << "Los límites de coordenadas deben garantizar que coordX1 <coordX2 y coordY1 <coordY2 ."<<endl;
cout <<endl;
cout <<endl;

cout << " crear_mapa" <<endl;
cout <<"Descripción:"<<endl;
cout << endl; 
cout << " El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura no lineal y conectarlos entre sí"<<endl;
cout << "teniendo en cuenta el coeficiente de conectividad dado. El objetivo es que cada elemento esté conectado a los demás elementos más cercanos a él, midiendo la cercanía a través de la distancia euclidiana entre los elementos."<<endl;
cout << "Esta distancia euclidiana también se utiliza como el peso o etiqueta de la conexión entre los elementos."<<endl; 
cout << "Con el coeficiente de conectividad se identifica la cantidad de vecinos que puede tener cada elemento tomando como base el total de elementos que se ubicarán en el mapa" << endl;
cout << "(ejemplo: si se van a ubicar 35 elementos, y el coeficiente de conectividad es 0.4, la cantidad de vecinos que cada elemento debe tener es 35 * 0.4 = 14). "<<endl;
cout <<endl;
cout <<endl;

cout << " ruta_mas_larga" <<endl;
cout <<"Descripción: "<<endl;
cout << endl;
cout << "Con el mapa ya creado, el comando permite identificar los dos componentes más alejados entre sí de acuerdo a las conexiones generadas. "<<endl;
cout << "Es importante aclarar que el comando retorna los elementos más alejados de acuerdo a las conexiones que se encuentran en el mapa, no los elementos que estén a mayor distancia euclidiana entre sí."<<endl; 
cout << "Al encontrar esa ruta más larga dentro del mapa, el comando imprime en pantalla los elementos de origen y destino, la longitud total de la ruta"<<endl; 
cout << "y la secuencia de elementos que hay que seguir para ir del elemento origen al elemento destino."<<endl;
cout<< endl;
cout <<endl;

cout << " salir" <<endl;
cout <<"Descripcion:" <<endl;
cout <<endl;
cout << "Salir del programa del robot Curiosity"<<endl;
}

void ayuda_print_comando_especifico(string& entrada){

if (entrada == "cargar_comandos") {
        cout << "Uso: cargar_comandos nombre_archivo" <<endl;
    } else if (entrada == "cargar_elementos") {
        cout << "Uso: cargar_elementos nombre_archivo" <<endl;
    } else if (entrada == "agregar_movimiento") {
        cout << "Uso: agregar_movimiento tipo_mov magnitud unidad_med"<<endl;
    } else if (entrada == "agregar_analisis") {
        cout << "Uso: agregar_analisis tipo_analisis objeto ['comentario']" <<endl;
        cout << "  El comentario es opcional y va entre comillas simples." <<endl;
    } else if (entrada == "agregar_elemento") {
        cout << "Uso: agregar_elemento tipo_comp tamaño unidad_med coordX coordY " <<endl;
    } else if (entrada == "guardar") {
        cout << "Uso: guardar tipo_archivo nombre_archivo" <<endl;
    } else if (entrada == "simular_comandos") {
        cout << "Uso: simular_comandos coordX coordY" <<endl;
    } else if (entrada == "ubicar_elementos") {
        cout << "Uso: ubicar_elementos" <<endl;
    } else if (entrada == "en_cuadrante") {
        cout << "Uso: en_cuadrante coordX1 coordX2 coordY1 coordY2" <<endl;
    } else if (entrada == "crear_mapa") {
        cout << "Uso: crear_mapa coeficiente_conectividad" <<endl;
    } else if (entrada == "ruta_mas_larga") {
        cout << "Uso: ruta_mas_larga "<<endl;
    } else if (entrada == "salir") {
        cout << "Uso: salir" <<endl;
    } else if (entrada == "ayuda") {
        cout << "Uso: ayuda | ayuda comando"<<endl;
    } else {
        cout << "Comando desconocido, ingresa 'ayuda' para ver los comandos."<<endl;
    }
}
